/*
A = aceitou solicitação e deixou em espera --> inserir no heap
F = finalizou corrida atual --> remover topo
C = cliente indicado cancelou solicitação --> buscar e remover
T = o motorista indicou o término de sua viagem e deseja saber o rendimento total

Entradas

tipo A
-nome 
-avaliação (nº estrelas)
-posição x e y do cliente (ponto de partida)
-posicao x e y do destino do cliente
-cliente é inserido na lista 

tipo F
-corrida corrente é removida da lista
-incrementar ganho 

tipo C
-nome do cliente
-buscar cliente e remover
-incrementar taxa de compensação

*/

#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"

#define ALUGUEL 57.00

double calcular_gasolina(int distancia_em_km){
    return 4.104 * (distancia_em_km / 10);
}




int main(){

    f_prio heap = aloca_fprio(50);
    


    return 0;
}