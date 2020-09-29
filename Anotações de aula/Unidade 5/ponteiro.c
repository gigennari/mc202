/*
vetor[0] é o int cujo endereço é &vetor[0]

*/

#include <stdio.h>

int main(){
    int vetor[5] = {1, 2, 3, 4, 5};
    int *ponteiro;
    ponteiro = vetor + 2; //aponta para o 3
    ponteiro++; //aponta para 4
    printf("%d %d %d", *vetor, *(ponteiro-1), *ponteiro); //imprime 1, 3, 4
}