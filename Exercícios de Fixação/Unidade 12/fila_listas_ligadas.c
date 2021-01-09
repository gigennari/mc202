#include <stdio.h>
#include <stdlib.h>


typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct Fila{
    p_no ini;
    p_no fim;
}Fila;

typedef struct Fila *p_fila;


p_fila criar_fila(){
    p_fila f;
    f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void enfileira(p_fila f, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;
    if (f->ini == NULL){
        f->ini = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
    
}

void desenfileira(p_fila f){

}