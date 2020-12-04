#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"
#define M 1735

//Insere nó no início de uma lista ligada 
p_no inserir_lista(p_no lista_antiga, char *palavra)
{
    p_no novo;
    novo = malloc(sizeof(No)); //No ou *novo -> tamanho do registro
    strcpy(novo->palavra, palavra);
    novo->prox = lista_antiga; //a lista antiga é o próximo nó
    return novo;
}

//Insere nó na hash table 
void inserir(p_hash t, char *chave, int dado){
    int n = hash(chave);
    t->v[n] = inserir_lista(t->v[n], chave);
}

//Busca nó em lista ligada 
p_no buscar_lista(p_no lista, char palavra)
{
    for (p_no atual = lista; atual != NULL; atual = atual->prox)
    {
        if (strcmp(atual->palavra, palavra) == 0)
            return atual;
    }
    return NULL;
}

//Busca nó em hash table 
p_no buscar(p_hash t, char *chave, int dado){
    int n = hash(chave);
    p_no buscado = buscar_lista(t->v[n], chave);
    return buscado;
}

//Calcula hash de uma string pelo método da divisão
int hash_string(char *palavra){
    int hash = 0;
    for (int i; palavra[i] != '\0'; i++){
        hash += (palavra[i] % M);
        if(palavra[i+1] != '\0'){
            hash *= 256;
        }  
    } 
    return hash;
}


