#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int *v;
    int ini, fim, tam_max, tamanho;
} Fila;

typedef struct Fila *p_fila;

p_fila criar_fila(int tam_max)
{
    p_fila f;
    f = malloc(sizeof(Fila));
    f->v = malloc(tam_max * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->tam_max = tam_max;
    f->tamanho = 0;

    return f;
}

void enfileira(p_fila f, int x)
{
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->tam_max;
    f->tamanho++;
}

int desenfileira(p_fila f)
{
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->tam_max;
    f->tamanho--;
    return x;
}

int fila_vazia(p_fila f)
{
    if(f->tamanho == 0){
        return 1;
    }
    return 0;
}

int fila_cheia(p_fila f){
    if(f->tamanho == f->tam_max){
        return 1;
    }
    return 0;
}

int main()
{
    
}
