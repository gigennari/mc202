/*
Um deque (double-ended queue) é uma estrutura de dados com as 
operações:

* insere_inicio
* insere_fim
* remove_incio
* remove_fim 

Nesse exercício, vamos implementar essa estrutura com listas 
duplamente ligadas
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct pilha
{
    p_no ini, fim;   // prox posição livre
}Pilha;

typedef Pilha *p_pilha;

void insere_inicio(p_pilha pilha, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->ini;
    pilha->ini = novo;
    
}

void insere_fim(p_pilha pilha, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->ini;
    pilha->fim->prox = novo;
}

int remove_incio(p_pilha pilha){
    p_no aux;
    aux = pilha->ini;
    int x = aux->dado;
    pilha->ini = pilha->ini->prox;
    free(aux);
    return x;
}

int remove_fim(p_pilha pilha){
    p_no aux;
    aux = pilha->fim;
    int x = aux->dado;
    pilha->fim = pilha->fim->ant;
    free(aux);
    return x;
}