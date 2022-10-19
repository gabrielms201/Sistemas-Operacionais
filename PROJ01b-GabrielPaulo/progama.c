#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define direita (i+1)%numFilo
#define esquerda (i+numFilo-1)%numFilo

const int pensando = 0;
const int fome = 1;
const int comendo = 2;
const int tempoParaPensar = 3;
const int tempoParaComer = 1;
int *filosofos; // array q vai armazenar os filosofos
int *estados; // array q vai armazenar o estado de cada filosofo

sem_t mtx; //semaforo global para todos os filosofos, isso e necessario para controlar quando acessar os recursos
sem_t *semaforos; //array de semaforo para cada filosofo

//Funcoes
void sentarNaMesa(int* indexFilosofo);


int main(int argc, char** argv){
    if(argc != 2){
        printf("Rode o programa com a qntd de filosofos desejado\n");
        exit(1);
    }
    const int numFilo =  atoi(argv[1]);
    filosofos = (int*) malloc(numFilo*sizeof(int)); // alocacao dinamica dos filosofos
    int i;
    for(i = 0;i < numFilo; i++ ){
        filosofos[i] = i; //filosofos ordenados
    }

    estados = (int*) malloc(numFilo*sizeof(int)); // alocacao dinamica dos estados
    semaforos = (sem_t*) malloc(numFilo*sizeof(sem_t)); // alocacao dinamica dos semaforos

    sem_init(&mtx, 0 , 1); // 0 pois estamos utilizando threads e 1 pq é o valor desse semaforo
    // para cada filosofo inicializamos um semaforo:
    i=0;
    for(i = 0;i < numFilo; i++ ){
        sem_init(&semaforos[i], 0, 0); // 0 = valor inicial da thread, o 2º 0 é o valor do semaforo

    }

    pthread_t* arrayThreads = (pthread_t*) malloc(numFilo*sizeof(pthread_t)); //array q vai armazenar todas as threads criadas (utilizamos para ter controle de quais terminaram ou n)
    //precisamos popular o array entao vamos criar uma thread para cada elemento
    i=0;
    for(i = 0;i < numFilo; i++ ){
        int result = pthread_create(&arrayThreads[i], NULL, sentarNaMesa, &filosofos[i]);
    }
    //thread principal irá esperar pelas outras 
    i=0;
    for(i = 0;i < numFilo; i++ ){
        pthread_join(arrayThreads[i], NULL); //cria e armazena o codigo de retorno da criacao da thread 
    }



    free(filosofos);
    free(estados);
    free(semaforos);
    free(arrayThreads);
}
//o parametro deve ser um ponteiro pois estamos trabalhando com threads
void sentarNaMesa(int* indexFilosofo){
    printf("Filosofo de numero %d sentou na mesa\n", *indexFilosofo);
}