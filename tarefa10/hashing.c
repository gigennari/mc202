#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"
#define MAX  



/**
 * Usar funções de lista ligada para inserir, remover e buscar 
 * */

void inserir(p_hash t, char *chave, int dado){
    int n = hash(chave);
    t->vetor[n] = inserir_lista(t->vetor[n], chave, dado);
}

void remover(p_hash t, char *chave, int dado){
    int n = hash(chave);
    t->vetor[n] = remover_lista(t->vetor[n], chave, dado);
}

void buscar(p_hash t, char *chave, int dado){
    int n = hash(chave);
    t->vetor[n] = buscar_lista(t->vetor[n], chave, dado);
}
