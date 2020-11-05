#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

p_no buscar(p_no raiz, int chave){
    if (raiz == NULL || chave == raiz->dado){
        return raiz;
    }
    if (chave < raiz->dado){
        return buscar(raiz->esq, chave);
    }
    if (chave > raiz->dado){
        return buscar(raiz->dir, chave);
    }
}

p_no inserir(p_no raiz, int x){
    if (raiz == NULL){
        p_no novo = malloc(sizeof(No));
        novo->dado = x;
        novo->esq = NULL;
        novo->dir = NULL; 
    }
    else if (x < raiz->dado){
        raiz->esq = inserir(raiz->esq, x);
    }
    else{
        raiz->dir = inserir(raiz->dir, x);
    }

    return raiz;
}

p_no minimo(p_no raiz){
    if(raiz == NULL && raiz->esq == NULL){
        return raiz;
    }
    else{
        return minimo(raiz->esq);
    }
}