/*
Aloca dinamicamente um matriz MxN

A matriz pode ser vista como um vetor de ponteiros 
[0] -> [a00, a01, ..., a0n]
[1] -> [a10, a11, ..., a1n]
.
.
.
[m] -> [am0, am1, ..., amn]

int **
*/
#include <stdio.h>
#include <stdlib.h>

int ** aloca_matriz(int M, int N){
    int **matriz = malloc(M* sizeof(int *));
    if (matriz == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++){
        matriz[i] = malloc(N * sizeof(int));
        if (matriz == NULL){
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }
    }
    return matriz;
}

int main(){
    int M, N, **matriz;
    scanf("%d %d", &M, &N);
    matriz = aloca_matriz(M, N);
}