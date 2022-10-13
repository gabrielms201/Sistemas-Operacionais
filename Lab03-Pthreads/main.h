#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables
int thread_count = 4; // default value
int m, n; // Line, columns

double** A; // Matrix
double* x; // Vector
double* y; // Result
// Functions
void* Pth_mat_vec(void* rank);
void printVector();
void fillMatrix();
void printMatrix();
void printResult();
void fillVector();