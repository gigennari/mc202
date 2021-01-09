#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct Deque
{
    int tamanho;
    p_no ini, fim;

} Deque;

typedef struct Deque *p_deque;

p_deque insere_inicio(p_deque d, p_no no)
{

    if (d->tamanho == 0)
    {
        d->ini = no;
        d->fim = no;
    }
    else
    {
        no->ant = NULL;
        no->prox = d->ini;
        d->ini->ant = no;
        d->ini = no;
    }
    d->tamanho += 1;

    return d;
}

p_deque insere_fim(p_deque d, p_no no)
{
    if (d->tamanho == 0)
    {
        d->ini = no;
        d->fim = no;
    }
    else
    {
        no->ant = d->fim;
        no->prox = NULL;
        d->fim->prox = no;
        d->fim = no;
    }
    d->tamanho += 1;
    return d;
}

p_no remover_incio(p_deque d)
{
    if (d != NULL)
    {

        p_no aux = d->ini;
        d->ini = d->ini->prox;
        d->tamanho -= 1;

        return aux;
    }
    return NULL; 
}

p_no remover_fim(p_deque d)
{
    if (d != NULL)
    {

        p_no aux = d->fim;
        d->fim = d->fim->prox;
        d->tamanho -= 1;

        return aux;
    }
    return NULL; 
}


