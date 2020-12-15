#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"
#define M 8627 
#define A (sqrt(5) - 1) / 2


p_hash criar_hash(){
    p_hash t;
    t = malloc(sizeof(Hash));
    t->v = malloc(M * sizeof(p_no));
    return t;
}


//Calcula hash de uma string pelo método da divisão
int hash_string(char *palavra){
    int hash = 0;
    for (int i; palavra[i] != '\0'; i++){
        hash = (256 * hash + palavra[i]) % M;
    } 
    return hash;
}


//Insere nó no início de uma lista ligada 
p_no inserir_lista(p_no lista_antiga, char *palavra)
{
    p_no novo;
    novo = malloc(sizeof(No)); //No ou *novo -> tamanho do registro
    novo->palavra = malloc(26 * sizeof(char));
    strcpy(novo->palavra, palavra);
    novo->prox = lista_antiga; //a lista antiga é o próximo nó
    return novo;
}

//Insere nó na hash table 
p_hash inserir(p_hash t, char *chave){
    int n = hash_string(chave);
    t->v[n] = inserir_lista(t->v[n], chave);
    return t;
}

//Busca nó em lista ligada 
p_no buscar_lista(p_no lista, char *palavra)
{
    for (p_no atual = lista; atual != NULL; atual = atual->prox)
    {
        if (strcmp(atual->palavra, palavra) == 0)
            return atual;
    }
    return NULL;
}

//Busca nó em hash table 
p_no buscar(p_hash t, char *chave){
    int n = hash_string(chave);
    p_no buscado = buscar_lista(t->v[n], chave);
    return buscado;
}


void destruir_lista(p_no lista)
{
    if (lista != NULL)
    {
        destruir_lista(lista->prox);
        free(lista->palavra);
        free(lista);
    }
}

void destruir_hash(p_hash t){
    for(int i = 0; i < M; i++){
        if(t->v[i] != NULL){
            destruir_lista(t->v[i]);
        }
    }
    free(t->v);
    free(t);
}
