#include <stdio.h>
#include <stdlib.h>
#define MAX 1783

typedef struct {
    char chave[30];
    int dado;
    struct No *prox;

}No;

typedef struct {
    No vetor[MAX]; 

}Hash;

typedef struct Hash *p_hash;

int hash(int chave){
    int i, n = 0;
    for(i = 0; i < strlen(chave); i++){
        n = (256 * n + chave[i]) % MAX;
    }
    return n;
}


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

int hash_string(char *palavra){

}


int main(){

    return 0;
}