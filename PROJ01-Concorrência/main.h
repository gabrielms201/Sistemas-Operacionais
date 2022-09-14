#pragma once

// Includes && boolean defines
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/shm.h>
#include <memory.h>
#include <sys/sem.h>
#include <fcntl.h>
#define true 1
#define false 0

// Enums
typedef enum
{
    THINKING,
    EATING,
    TRYING_TO_EAT
} State;

typedef enum
{
    SIMPLE,
    FULL,
} LogLevel;

// Structs
typedef struct
{
    int id;
    int waited;
    int eated;
    State state;
} Philosopher;

// Function declarations
// Utils
void logger(LogLevel level, int pid, const char* message);
void printPhilosophers(Philosopher const * arr, int size);
const char* stateToString(State state);
void printPhilosopherInfo(Philosopher const* philosopher);
void fillPhilosophers(int quantity);
void afterFinish();

// Philosophers actions
void tryToEat(int philosopherProcess);
void grabForks();
void dropForks();

// Processes related
void work();
void startWorking(int isMain);
int createProcesses();

// Semaphores and mutex semaphores
int sems_down(int sem, int isMutex);
int sems_up(int sem, int isMutex);
int sems_init(int sem, int value, int isMutex);
