#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int *v;
    int ini, fim, N, tamanho;
} Fila;

typedef struct Fila *p_fila;

p_fila criar_fila(int N)
{
    p_fila f;
    f = malloc(sizeof(Fila));
    f->v = malloc(N * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
}

void enfileira(p_fila f, int x)
{
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho++;
}

int desenfileira(p_fila f)
{
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho--;
    return x;
}

int fila_vazia(p_fila f)
{
    return f->tamanho == 0;
}

int main()
{
    
}
