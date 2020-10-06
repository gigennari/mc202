/*
seu eu passo o endereço de inteiro p a função, recebo um ponteiro para inteiro

se eu passo um vetor, que é um ponteiro para int (por exemplo), recebo ponteiro para ponteiro para int -> int **v
*/

#include <stdio.h>
#include <stdlib.h>

void zera(int *v){
    *v = 0;
}

void aloca_e_zera(int **v, int n){
    int i;
    *v = malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
        (*v)[i] = 0;
    }
}


int main(){
    int n = 3;
    int *vetor;
    aloca_e_zera(&vetor, n);
    printf("%d\n", n);
}