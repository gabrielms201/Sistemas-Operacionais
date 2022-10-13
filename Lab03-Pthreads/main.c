#include "main.h"

int main()
{
    int i;
    long thread;
    pthread_t thread_pool[thread_count];
    printf("Digite o valor de M: \n");
    scanf("%d", &m);
    printf("Digite o valor de N: \n");
    scanf("%d", &n);
    thread_count = n > m? n : m;
    printf("Rodando com %d threads...\n", thread_count);
    
    x = calloc(n, sizeof(double));
    y = calloc(m, sizeof(double));
    A = calloc(m, sizeof(double));
    // Allocating matrix
    for (i = 0; i < m; i++)
        A[i] = (double*)malloc(n * sizeof(double));
    // Filling Matrix
    fillMatrix();
    // Printing Matrix
    printMatrix();
    // Filling Vector
    fillVector();
    // Printing Vector
    printVector();

    // Now we have to create our threads...
    // Como estamos utilizando uma thread pool, vamos realizar o create para cada thread da nossa pool.
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_create(&thread_pool[thread], NULL, Pth_mat_vec, (void*) thread);
    }
    // Waiting for the other threads to finish:
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_pool[thread], NULL);
    }
    printResult();
    // releasing heap allocated memory
    free(x);
    free(y);
    for (i = 0; i < m; i++)
        free(A[i]);
    free(A);

}


void printResult()
{
    printf("RESULT (y[]): \n");
    int i;
    for (i = 0; i < m; i++)
    {
        printf("%.2lf ", y[i]);
    }
    printf("\n");
}

void printVector()
{
    // Imprimindo o vetor com  os dados informados pelo usuário
    printf("x[]: \n");
    int i;
    for (i = 0; i < n; i++)
        printf("%2lf ", x[i]);
    printf("\n");
}
void fillVector()
{
    // Preenchendo o vetor com os dados informados pelo usuário
    printf("Por favor digites os valores do vetor de %d elementos: \n", n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%2lf", &x[i]);
    }
}
void fillMatrix()
{
    // Preenchendo a matriz com os dados informados pelo usuário
    int i;
    int j;
    printf("Por favor digite os valores da sua matriz %dx%x: \n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
}
void printMatrix()
{
    // Imprimindo a matriz
    printf("A[][]:\n");
    int i;
    int j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%.2lf ", A[i][j]);
        printf("\n");
    }
}

void* Pth_mat_vec(void* rank)
{
    long my_rank = (long) rank;
    int i;
    int j;
    int local_m = m / thread_count;
    
    int my_first_row = my_rank*local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++)
    {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
            y[i] += A[i][j] * x[j];
    }
    return NULL;
}