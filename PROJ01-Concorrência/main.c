#include "main.h"

// Global pre processor defines
#define TIME_TO_THINK 2
#define TIME_TO_EAT 1
#define PHILOSOPHER_COUNT 5
// Global variables
Philosopher* philosophers;
int mutex;
int semaphores;
int processCounter;

// The dinning philosophers problem
int main(int argc, char** argv)
{
    // Private key, block count, create if doesn't exists, file permissions |  https://man7.org/linux/man-pages/man2/semget.2.html
    mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0644);
    semaphores = semget(IPC_PRIVATE, PHILOSOPHER_COUNT, IPC_CREAT | 0644); // One semaphore foreach philosopher
    
    // Initiate all mutexes
    sems_init(mutex, 1, true);
    for (int i = 0; i < PHILOSOPHER_COUNT; i++ ) // initiate semaphores foreach semaphore
    {
        sems_init(i, 1, false);
    }

    // Create shared memory for philosophers array
    // Private key, block with philosopher count, create if doesn't exists, 0644 file permissions | https://man7.org/linux/man-pages/man2/shmget.2.html
    int sharedPhilosophersMemoryID = shmget(IPC_PRIVATE, PHILOSOPHER_COUNT, IPC_CREAT | 0644);
    if (sharedPhilosophersMemoryID == -1)
    {
        printf("Error creating shared memory for philosophers\n");
        exit(1);
    }
    // Attach the block to a pointer
    philosophers = (Philosopher*) shmat(sharedPhilosophersMemoryID, NULL, 0);

    // Fill our array with philosophers
    fillPhilosophers(PHILOSOPHER_COUNT);

    // Create our child processes
    int pid = createProcesses();
    // Start working foreach process
    startWorking(pid);
}
// After finish signal handler
void afterFinish()
{
    // This function is called after a term signal. 
    // Then we each philosopher's info
    printPhilosopherInfo(&(philosophers[processCounter]));
    exit(0);
}
// Work foreach philosopher (called foreach child process of the main process)
void work()
{
    // 
    signal(SIGINT, afterFinish); // https://man7.org/linux/man-pages/man2/signal.2.html
    logger(SIMPLE, 0, "Started Working");
    while (true)
    {
        // First, he'll think till he get's hungry (trying to eat state)
        logger(SIMPLE, 0, "Currently thinking");
        sleep(TIME_TO_THINK);
        logger(SIMPLE, 0, "Finished Thinking");
        // Then he well grab a fork and try to eat
        grabForks();
        // If he got the forks, then he is eating
        logger(SIMPLE, 0, "Eating");
        sleep(TIME_TO_EAT);
        dropForks();
    }
}
// Simple logger function foreach process
// level : log level
// isMain : is main process or child
// message: message to log
void logger(LogLevel level, int isMain, const char* message)
{
    const char* processType = (isMain == 0) ? "WORKER" : "MAIN";
    switch (level)
    {
    case SIMPLE:
        printf("[%s : %d] [COUNTER = %d] %s\n", processType, getpid(), processCounter, message);
        break;
    case FULL:
        printf("[%s : %d : %d] [COUNTER = %d] %s\n", processType, getpid(), getppid(), processCounter, message);
    default:
        break;
    }
    
}

// Filter the process: if is a child one, call work, if is not, wait for the others to finish
void startWorking(int pid)
{
    if (pid == 0)
    {
        work();
    }
    else if (pid < 0)
    {
        printf("ERROR trying to create processes\n");
        exit(1);
    }
    else
    {
        while(wait(NULL) != -1 || errno != ECHILD);
        printf("\n\n--> WORKERS FINISHED. RESULT: \n\n");
        printPhilosophers(philosophers, PHILOSOPHER_COUNT);
    }
}
// Creates N processes (based on philosophers number)
int createProcesses()
{
    int pid;
    for (processCounter = 0; processCounter < PHILOSOPHER_COUNT; processCounter++ )
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }
    return pid;
}
void printPhilosophers(Philosopher const* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        Philosopher philosopher = arr[i];
        printPhilosopherInfo(&philosopher);
    }
}
// Populate all the philosophers array
void fillPhilosophers(int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        Philosopher philosopher =
        {
            i,
            0,
            0,
            THINKING
        };
        philosophers[i] = philosopher;
    }
}
// Simple enum to string function
const char* stateToString(State state)
{
    switch (state)
    {
    case EATING:
        return "EATING";
    case THINKING:
        return "THINKING";
    case TRYING_TO_EAT:
        return "TRYING TO EAT";
    default:
        return "null";
    }
}
void printPhilosopherInfo(Philosopher const*  philosopher)
{
    printf("Philosofer | [ID: %d] [EATED: %d] [WAITED: %d] [STATE: %s] \n", 
            philosopher->id, philosopher->eated, philosopher->waited, stateToString(philosopher->state));
}
// Current process (philosopher) tries to grab a fork
void grabForks()
{
    sems_down(mutex, true); // down mutex [critical region]
    philosophers[processCounter].state = TRYING_TO_EAT;
    tryToEat(processCounter); // philosopher will now try to eat
    sems_up(mutex, true); // up mutex [critical region]
    sems_down(processCounter, false); // down | We must wait to grab the forks
}
// Current process (philosopher) tries to eat, if it's possible
void tryToEat(int philosopherProcess)
{
    int left = (processCounter == 0 ) ? PHILOSOPHER_COUNT-1 : processCounter-1;
    int right = (processCounter+1) % PHILOSOPHER_COUNT;

    // If the left and right philosophers aren't eating, then he can eat
    int eatingCondition = (philosophers[philosopherProcess].state == TRYING_TO_EAT &&
                                    philosophers[left].state != EATING &&
                                    philosophers[right].state != EATING);
    if (eatingCondition)
    {
        philosophers[philosopherProcess].state = EATING;
        philosophers[philosopherProcess].eated++;
        sems_up(philosopherProcess, false); // Unlocking the forks (up)
    }
    else
    {
        philosophers[philosopherProcess].waited+=1;
    }
}
// Current process (philosopher) drops his forks after eating
void dropForks()
{
    int right = (processCounter+1) % PHILOSOPHER_COUNT;
    int left = (processCounter == 0 ) ? processCounter : processCounter-1;
    sems_down(mutex, true); // down
    philosophers[processCounter].state = THINKING;
    tryToEat(left); // Now we call for the neighbors philosophers
    tryToEat(right); // // Now we call for the neighbors philosophers
    sems_up(mutex, true); // up
}

// Since we are working with processes instead of threads, we had chosen to use semop and semctl
// We could have used sem_init with pshared, too: https://man7.org/linux/man-pages/man3/sem_init.3.html 
int sems_init(int sem, int value, int isMutex) // https://man7.org/linux/man-pages/man2/semctl.2.html
{
    int err;
    // Control operation. Set shared memory value of sem
    if (isMutex) 
        err = semctl(mutex, sem, SETVAL, value);
    else
        err = semctl(semaphores, sem, SETVAL, value);
    return err;
}
int sems_up(int sem, int isMutex) // https://man7.org/linux/man-pages/man2/semop.2.html
{
    struct sembuf semops;
    semops.sem_num = sem; // // operating on sem
    semops.sem_op = 1; // 1 : Up | -1: Down
    semops.sem_flg = 0;
    int err;
    if (isMutex)
        err = semop(mutex, &semops, 1);
    else
        err = semop(semaphores, &semops, 1);
    return err;
}
int sems_down(int sem, int isMutex) // https://man7.org/linux/man-pages/man2/semop.2.html
{
    struct sembuf semops;
    semops.sem_num = sem; // operating on sem
    semops.sem_op = -1; // 1 : Up | -1: Down
    semops.sem_flg = 0;
    int err;
    // Operating the semaphore acording to given values above
    if (isMutex)
        err = semop(mutex, &semops, 1); 
    else
        err = semop(semaphores, &semops, 1);
    return err;
}