
#include <stdio.h>
#include <stdlib.h>

typedef struct Pos{
    int x, y;
} Pos;

typedef Pos *p_pos;

typedef struct Cliente{
    char *nome;
    long double estrelas;
    p_pos partida, destino;

}Cliente;

typedef Cliente *p_cliente;

typedef struct FP
{
    p_cliente *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;


p_fp aloca_fprio(int capacidade);
p_cliente aloca_e_cria_cliente(char *nome, long double estrelas, p_pos partida, p_pos destino);
void libera_cliente(p_cliente cliente);
void libera_fprio(p_fp fprio);
p_pos aloca_e_cria_posicao(int x, int y);

p_fp inserir_heap(p_fp fprio, char *nome, long double estrelas, p_pos partida, p_pos destino);
p_fp remover_heap(p_fp fprio, char *nome);
p_cliente extrai_max(p_fp fprio); 
