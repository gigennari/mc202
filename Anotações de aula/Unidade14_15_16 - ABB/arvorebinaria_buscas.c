#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

p_no buscar(p_no raiz, int chave)
{
    if (raiz == NULL || chave == raiz->dado)
    {
        return raiz;
    }
    if (chave < raiz->dado)
    {
        return buscar(raiz->esq, chave);
    }
    if (chave > raiz->dado)
    {
        return buscar(raiz->dir, chave);
    }
}

p_no buscar_iter(p_no raiz, int chave)
{
}

p_no inserir(p_no raiz, int x)
{
    if (raiz == NULL)
    {
        p_no novo = malloc(sizeof(No));
        novo->dado = x;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    else if (x < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, x);
    }
    else
    {
        raiz->dir = inserir(raiz->dir, x);
    }

    return raiz;
}

p_no sucessor(p_no x){
    if (x->dir != NULL){
        return minimo(x->dir);
    }
    else
    {
        return ancestral_a_direita(x);
    }
}

p_no ancestral_a_direita(p_no x){
    if (x == NULL){
        return NULL;
    }
    if (x->pai == NULL || x->pai->esq == x){
        return x->pai;
    }
    else{
        return ancestral_a_direita(x->pai);
    }
}

p_no minimo(p_no raiz)
{
    if (raiz == NULL && raiz->esq == NULL)
    {
        return raiz;
    }
    else
    {
        return minimo(raiz->esq);
    }
}

void remove_sucessor(p_no raiz)
{
    p_no min = raiz->dir; //será o minimo da subarvore direita
    p_no pai = raiz;      //pai do nó mínimo
    while (min->esq != NULL)
    {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
    {
        pai->esq = min->dir;
    }
    else
    {
        pai->dir = min->dir;
    }
    raiz->dado = min->dado;
}

p_no remover_rec(p_no raiz, int dado)
{

    if (raiz == NULL)
    {
        return NULL;
    }
    else if (dado < raiz->dado)
    {
        raiz->esq = remover_rec(raiz->esq, dado);
    }
    else if (dado > raiz->dado)
    {
        raiz->dir = remover_rec(raiz->dir, dado);
    }
    else if (raiz->esq == NULL)
    {
        return raiz->dir;
    }
    else if (raiz->dir == NULL)
    {
        return raiz->esq;
    }
    else
    {
        remove_sucessor(raiz);
    }
    return raiz;
}

/**
 * Imprimir inordem
 * */
void imprimir_ordem_crescente(p_no raiz)
{
    if (raiz != NULL)
    {

        imprimir_ordem_crescente(raiz->esq);
        printf(raiz->dado);
        imprimir_ordem_crescente(raiz->dir);
    }
}

void imprimir_ordem_decrescente(p_no raiz)
{
    if (raiz != NULL)
    {

        imprimir_ordem_decrescente(raiz->dir);
        printf(raiz->dado);
        imprimir_ordem_decrescente(raiz->esq);
    }
}