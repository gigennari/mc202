
#include <stdio.h>
#include <stdlib.h>

typedef struct Pos{
    int x, y;
} Pos;

typedef Pos *p_pos;

typedef struct Cliente{
    char nome[16];
    long double estrelas;
    p_pos partida, destino;

}Cliente;

typedef struct FP
{
    Cliente *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;


p_fp aloca_fprio(int capacidade);