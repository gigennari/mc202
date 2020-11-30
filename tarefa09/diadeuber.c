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
#define TAXA_UBER 0.25
#define PAGAMENTO_UBER 1.40
#define TAXA_CANCELAMENTO 7.00
#define LITRO_GASOLINA 4.104


int distancia_mahattan(p_pos p1, p_pos p2){
    return abs(p1->x - p2->x) + abs(p1->y - p2->y);
}

int calcula_distancia_viagem(p_cliente cliente){
    return distancia_mahattan(cliente->partida, cliente->destino);
}

int calcula_distancia_total(p_pos pos_motorista, p_cliente cliente){
    int distancia = 0;
    distancia += distancia_mahattan(pos_motorista, cliente->partida);
    distancia += calcula_distancia_viagem(cliente);
    return distancia;
}

p_pos atualiza_pos_motorista(p_pos pos_motorista, p_cliente cliente){
    pos_motorista->x = cliente->destino->x;
    pos_motorista->y = cliente->destino->y;
    return pos_motorista;
}

double calcula_despesas(int distancia_viagens, int distancia_total){
    double despesas = 0;
    double distancia = distancia_total;
    despesas += LITRO_GASOLINA * (distancia / 10);
    despesas += ALUGUEL;
    return despesas;

}
double calcula_rendimento_bruto(int distancia_viagens, int num_cancelamentos){
    double rendimento = 0;
    rendimento += distancia_viagens * PAGAMENTO_UBER;
    rendimento += num_cancelamentos * TAXA_CANCELAMENTO;
    return rendimento;
}

int main(){

    p_fp heap;
    heap = aloca_fprio(200);   //aloca vetor suficientemente grande para as solicitações simultâneas
    p_pos pos_motorista = aloca_e_cria_posicao(0, 0);
    int distancia_total = 0; //considerar deslocamento entre destino do cliente anterior e partida do seguinte
    int distancia_viagens = 0;
    int num_cancelamentos = 0;

    p_cliente cliente_atual = NULL;
    
    char operacao;
    do{
        scanf("%c ", &operacao);
        //inserir cliente no heap
        if(operacao == 'A'){
            char *nome = malloc(16 * sizeof(char)); 
            long double estrelas;
            int x, y, w, z;
            scanf("%s", nome);
            scanf("%Lf ", &estrelas);
            scanf("%d %d %d %d ", &x, &y, &w, &z);
            p_pos partida = aloca_e_cria_posicao(x, y);
            p_pos destino = aloca_e_cria_posicao(w, z);
    
            printf("Cliente %s foi adicionado(a)\n", nome);
            if(cliente_atual == NULL){
                cliente_atual = aloca_e_cria_cliente(nome, estrelas, partida, destino);
            }
            else{
                heap = inserir_heap(heap, nome, estrelas, partida, destino);
            }

            free(nome);

        }
        //finalizar uma corrida, contabilzar distâncias, atualizar posição, encontrar proximo cliente
        else if(operacao == 'F'){
            
            distancia_total += calcula_distancia_total(pos_motorista, cliente_atual);
            distancia_viagens += calcula_distancia_viagem(cliente_atual);
            pos_motorista = atualiza_pos_motorista(pos_motorista, cliente_atual);

            printf("A corrida de %s foi finalizada\n", cliente_atual->nome);
            p_cliente aux = cliente_atual;
            if (aux != NULL){
            free(aux->partida);
            free(aux->nome);
            free(aux->destino);
            free(aux);
            }
            //encontrar pŕoximo cliente
            if(heap->n > 0){
                cliente_atual = extrai_max(heap);
            }
            else{
                cliente_atual = NULL;
            }
        }
        else if(operacao == 'C'){
            char *nome = malloc(16 * sizeof(char));
            scanf("%s ", nome);
            num_cancelamentos += 1;
            printf("%s cancelou a corrida\n", nome);
            heap = remover_heap(heap, nome);
            free(nome);

        }
        else {
            double rendimento_bruto = calcula_rendimento_bruto(distancia_viagens, num_cancelamentos);
            double despesas = calcula_despesas(distancia_viagens, distancia_total);
            printf("\n");
            printf("Jornada finalizada. Aqui esta o seu rendimento de hoje\n");
            printf("Km total: %d\n", distancia_total);
            printf("Rendimento bruto: %.2lf\n", rendimento_bruto);
            printf("Despesas: %.2lf\n", despesas);
            printf("Rendimento liquido: %.2lf\n", rendimento_bruto * (1-TAXA_UBER) - despesas);
        }

    } while(operacao != 'T');

    free(cliente_atual);
    free(pos_motorista);
    libera_fprio(heap);


    return 0;
}