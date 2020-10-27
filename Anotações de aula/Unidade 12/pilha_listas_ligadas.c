#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct pilha
{
    p_no topo;   // prox posição livre
}Pilha;

typedef Pilha *p_pilha;


void empilhar(p_pilha pilha, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(p_pilha pilha){
    p_no topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->prox;
    free(topo);
    return x;
}