#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam)
{
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->capacidade = tam;
    return fprio;
}

void insere(p_fp fprio, Item item)  //O(1)
{
    fprio->v[fprio->n] = item;
    fprio->n++;
}

Item extrai_maximo(p_fp fprio)  //O(n)
{
    int j, max = 0;
    for (j = 1; j < fprio->n; j++)
    {
        if (fprio->v[j].chave > fprio->v[max].chave)
        {
            max = j;
        }
    }
    troca(&(fprio->v[max]), &(fprio->v[fprio->n - 1]));
    fprio->n--;
    return fprio->v[fprio->n];
}

int vazia(p_fp fprio)
{
    if(fprio->n == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int cheia(p_fp fprio)
{
    if (fprio->n == fprio->capacidade){
        return 1;
    }
    else{
        return 0;
    }
}

void libera_fprio(p_fp fprio)
{

    free(fprio);
}