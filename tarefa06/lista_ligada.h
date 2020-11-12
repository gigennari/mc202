#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.c"

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct Lista
{
    int tamanho;
    p_no ini, fim;

} Lista;
