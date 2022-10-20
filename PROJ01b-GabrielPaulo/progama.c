// Gabriel Augusto Ribeiro Gomes, 32134762
// Paulo Henrique Braga Cechinel, 32151128




#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define true 1
#define false 0
#define direita (indexFilosofo+1)%numFilo
#define esquerda (indexFilosofo+numFilo-1)%numFilo

int numFilo;

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
void tentar_pegar_garfos(int indexFilosofo);
void tentar_comer(int indexFilosofo);
void largar_garfos(int indexFilosofo);


int main(int argc, char** argv){
    if(argc != 2){
        printf("Rode o programa com a qntd de filosofos desejado\n");
        exit(1);
    }
    numFilo =  atoi(argv[1]); // pegando valor dos parametros do programa
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
    while (true)
    {
        printf("Filosofo de numero %d esta pensando\n", *indexFilosofo);
        sleep(tempoParaPensar);
        // Apos pensar o filosofo vai tentar comer
        tentar_pegar_garfos(*indexFilosofo);
        // Apos comer, o filosofo vai largar o garfo
        largar_garfos(*indexFilosofo);
    }
}

void tentar_pegar_garfos(int indexFilosofo){
    sem_wait(&mtx); // Agora e feito um down no mutex global, pois estamos entrando em uma regiao critica (down)
    estados[indexFilosofo] = fome; // Filosofo esta com fome (acabou o tempo de pensar, e o recurso esta disponivel)
    printf("Filosofo %d esta com fome, e ira tentar comer!\n", indexFilosofo);
    tentar_comer(indexFilosofo);
    sem_post(&mtx); // saindo da regiao critica, recurso liberado (up)
    sem_wait(&semaforos[indexFilosofo]); // caso ele nao consiga comer, o recurso fica bloqueado ate o mesmo poder 
    //(quando for chamado pelos outros filosofos na funcao tentar_comer, que deixa o semaforo como up). Portanto, ai esperamos (down)
    sleep(1);
}

void tentar_comer(int indexFilosofo){
    // se o filosofo em questao estiver com fome, e os adjacentes nao estao comendo, logo ele vai poder comer (ja que vao haver garfos liberados)
    if (estados[indexFilosofo] == fome && estados[direita] != comendo && estados[esquerda] != comendo){
        estados[indexFilosofo] = comendo;
        printf("Filosofo %d esta comendo!\n", indexFilosofo);
        sleep(tempoParaComer);
        // Apos comer, o semaforo dessa filosofo fica disponivel (up)
        sem_post(&semaforos[indexFilosofo]);
    }
}

void largar_garfos(int indexFilosofo){
    sem_wait(&mtx); // Bloqueia o mutex global para largar o garfo (regiao critica) (down)
    // Agora que o filosof largou o garfo, o mesmo estara pensando
    estados[indexFilosofo] = pensando;

    // quando esse filoso estiver pensando, os filosofos adjacentes precisam comer tambem, portanto chamamos o metodo que faz isso:
    tentar_comer(esquerda);
    tentar_comer(direita);

    //agora, precisamos liberar o semaforo global, ja que nao precisamos mais desse recurso e estamos saindo da regiao critica (up)
    sem_post(&mtx);
}