#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"

p_fp aloca_fprio(int capacidade)
{
    p_fp fprio;
    fprio = malloc(sizeof(FP));
    fprio->capacidade = capacidade;
    fprio->n = 0;
    fprio->v = malloc(capacidade * sizeof(p_cliente));
    return fprio;
}

p_cliente aloca_e_cria_cliente(char *nome, long double estrelas, p_pos partida, p_pos destino)
{
    p_cliente cliente;
    cliente = malloc(sizeof(Cliente));
    cliente->nome = malloc(16 * sizeof(char));
    strcpy(cliente->nome, nome);
    cliente->estrelas = estrelas;
    cliente->partida = partida;
    cliente->destino = destino;
    return cliente;
}

void libera_cliente(p_cliente cliente)
{
    free(cliente->partida);
    free(cliente->destino);
    free(cliente);
}

void libera_fprio(p_fp fprio){
    for(int i = 0; i < fprio->capacidade; i++){
        
            free(fprio->v[i]);     
    }
    free(fprio);
}

p_pos aloca_e_cria_posicao(int x, int y)
{
    p_pos pos;
    pos = malloc(sizeof(Pos));
    pos->x = x;
    pos->y = y;
    return pos;
}

int pai(int filho)
{
    return (filho - 1) / 2;
}

int filho_esq(int pai)
{
    return 2 * pai + 1;
}

int filho_dir(int pai)
{
    return 2 * pai + 2;
}

void troca(p_cliente *c1, p_cliente *c2)
{
    p_cliente aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}

void sobe_no_heap(p_fp fprio, int k)
{
    if (k > 0 && fprio->v[k]->estrelas > fprio->v[pai(k)]->estrelas) //a qtde de estrelas do atual é maior, trocar
    {
        troca(&fprio->v[k], &fprio->v[pai(k)]);
        sobe_no_heap(fprio, pai(k));
    }
}

void desce_no_heap(p_fp fprio, int k)
{
    int maior_filho;
    if (filho_esq(k) < fprio->n)
    {
        maior_filho = filho_esq(k);
        if (filho_dir(k) < fprio->n &&
            fprio->v[filho_esq(k)]->estrelas < fprio->v[filho_dir(k)]->estrelas) // se o filho esq for menor q o dir
        {
            maior_filho = filho_dir(k);
        }
        if (fprio->v[k]->estrelas < fprio->v[maior_filho]->estrelas)
        {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

p_fp inserir_heap(p_fp fprio, char *nome, long double estrelas, p_pos partida, p_pos destino)
{
    p_cliente cliente = aloca_e_cria_cliente(nome, estrelas, partida, destino);
    fprio->v[fprio->n] = cliente; //coloca na última posição
    fprio->n++;                   //aumenta tamanho na struct
    sobe_no_heap(fprio, fprio->n - 1);
    return fprio;
}

p_cliente extrai_max(p_fp fprio)
{
    p_cliente cliente = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n-1]); //troca ponteiros dos clientes
    fprio->n--;
    desce_no_heap(fprio, 0); //corige raiz, que falha propriedade de max heap

    return cliente;
}

p_fp remover_heap(p_fp fprio, char *nome)
{

    for (int i = 0; i < fprio->n; i++)
    {
        if (strcmp(fprio->v[i]->nome, nome) == 0)
        {
            troca(&fprio->v[i], &fprio->v[fprio->n-1]);
            fprio->n--;
            desce_no_heap(fprio, i);
            break;
        }
        
    }
    return fprio;
}
