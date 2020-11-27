#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"


p_fp aloca_fprio(int capacidade){
    p_fp fprio = malloc(sizeof(FP));
    fprio->capacidade = capacidade;
    fprio->n = 0;
    fprio->v = malloc(capacidade * sizeof(Cliente));
    return fprio;
}

p_cliente aloca_e_cria_cliente(char *nome, long double estrelas, p_pos partida, p_pos destino){
    p_cliente cliente = malloc(sizeof(Cliente));
    strcpy(cliente->nome, nome);
    cliente->estrelas = estrelas;
    cliente->partida = partida;
    cliente->destino = destino;
    return cliente;
}

void libera_cliente(p_cliente cliente){
    free(cliente->partida);
    free(cliente->destino);
    free(cliente);
}

p_pos aloca_e_cria_posicao(int x, int y){
    p_pos pos = malloc(sizeof(Pos));
    pos->x = x;
    pos->y = y;
    return pos;
}

int pai(int filho){
    return (filho - 1) / 2;
}

int filho_esq(int pai){
    return 2 * pai + 1;
}

int filho_dir(int pai){
    return 2 * pai + 2;
}

void troca(p_cliente c1, p_cliente c2)
{
    p_cliente aux = c1;
    c1 = c2;
    c2 = aux;
    free(aux);
}

