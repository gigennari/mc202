/*
Vamos eleger um líder entre N pessoas
começamos a contar da primeira pessoa 
contamos M pessoas
eliminamos a m+1-ésima pessoa 
continuamos da proxima pessoa
ciclamos quando chegamos ao final


n = 5
m = 2

0 1 2 3 4 

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main(){
    int M = 2, N = 5;

    //criar uma lista circular
    p_no lista = criar_lista_circular();
    //inserir numeros de 0 a n-1
    for(int i = 0; i < N; i++){
        lista = inserir_circular(lista, i);
    }


    //enquanto houver mais de um elemento na lista:
    //  ando m posições com o ponteiro da lista 
    //  removo o próximo 

    while (lista->prox != lista)
    {
        for (int i = 0; i < M; i++){
            lista = lista->prox;
        }
        p_no temp = lista->prox;
        lista->prox = temp->prox;
        free(temp);
    }
    

    //imprimo o num do único elemento que sobrou 
    printf("%d\n", lista->dado);

    free(lista);

    return 0;
}