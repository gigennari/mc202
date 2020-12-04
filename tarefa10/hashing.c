#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"


p_no inserir_lista(p_no lista_antiga, char *palavra)
{
    p_no novo;
    novo = malloc(sizeof(No)); //No ou *novo -> tamanho do registro
    strcpy(novo->palavra, palavra);
    novo->prox = lista_antiga; //a lista antiga é o próximo nó
    return novo;
}


void inserir(p_hash t, char *chave, int dado){
    int n = hash(chave);
    t->v[n] = inserir_lista(t->v[n], chave);
}

