#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_fila.h"


/**
 * Funções para lista de salas com cabeça e cauda
 * */
p_lista criar_lista()
{
    return NULL;
}

p_lista add_direita(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista));
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho = 1;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->tamanho += 1;
    }
    return lista;
}

void eliminar_esquerda(p_lista lista)
{
    if (lista != NULL)
    {
        if (lista->tamanho == 1)
        {
            free(lista);
        }
        else
        {
            p_no aux = lista->ini;
            lista->ini = lista->ini->prox;
            free(aux);
            lista->tamanho -= 1;
    
        }
    }
}

void liberar_memoria_lista(p_lista lista)
{
    if (lista != NULL)
    {
        p_no no;
        no = lista->ini;
        while (no != NULL)
        {
            p_no aux = no;
            no = no->prox;
            free(aux);
        }
        free(lista);
    }
}

/**
 * Funções de paciente ("nó")
 * */

p_paciente criar_paciente(char *nome, Preferencia x, p_lista salas, int posicao)
{
    p_paciente paciente;
    paciente = malloc(sizeof(Paciente));
    strcpy(paciente->nome, nome);
    paciente->status = x;
    paciente->salas = salas;
    paciente->posicao = posicao;
    paciente->prox = paciente->ant = NULL; //definimos prox e ant na hora de inserir na fila
    return paciente;
}

void colocar_pacientes_vetor(p_paciente *vetor, p_deque pacientes, int num_pacientes)
{
    for (int i = 0; i < num_pacientes; i++)
    {
        vetor[i] = pacientes->ini;
        pacientes->ini = pacientes->ini->prox;
    }
}

/**
 * Funções de deque 
 * */
p_deque criar_deque(int qtde_medicos)
{
    p_deque deque;
    deque = malloc(sizeof(Deque));
    deque->qtde_medicos = qtde_medicos;
    deque->qtde_pacientes = 0;
    deque->ini = deque->fim = NULL;
    return deque;
}

void liberar_memoria_deque(p_deque fila)
{
    while (fila->ini != fila->fim->prox)
    {
        p_paciente aux = fila->ini;
        fila->ini = fila->ini->prox;
        free(aux);
    }
    free(fila);
}

int fila_nao_vazia(p_deque especialidade)
{
    if (especialidade->qtde_pacientes > 0)
    {
        return 1;  
    }
    return 0; 
}

//para pacientes prioridade
void insere_incio(p_deque especialidade, p_paciente paciente)
{
    if (especialidade->qtde_pacientes == 0)
    {
        especialidade->ini = paciente;
        especialidade->fim = paciente;
    }
    else
    {
        paciente->prox = especialidade->ini;
        especialidade->ini->ant = paciente;
        especialidade->ini = paciente;
    }
    especialidade->qtde_pacientes += 1;
}

//para pacientes normal
void insere_fim(p_deque especialidade, p_paciente paciente)
{
    if (especialidade->qtde_pacientes == 0)
    {
        especialidade->ini = paciente;
        especialidade->fim = paciente;
    }
    else
    {
        paciente->ant = especialidade->fim;
        especialidade->fim->prox = paciente;
        especialidade->fim = paciente;
    }
    especialidade->qtde_pacientes += 1;
}

//sempre remove do início
p_paciente remover_paciente(p_deque especialidade)
{
    p_paciente aux = especialidade->ini;
    if (especialidade->qtde_pacientes == 1)
    {
        especialidade->ini = NULL;
        especialidade->fim = NULL;
    }
    else
    {
        especialidade->ini = especialidade->ini->prox;
        especialidade->ini->ant = NULL;
    }
    especialidade->qtde_pacientes -= 1;
    aux->prox = NULL;
    return aux;
}

void inserir_paciente(p_deque especialidade, p_paciente paciente)
{
    if (paciente->status == normal)
    {
        insere_fim(especialidade, paciente);
    }
    else
    {
        insere_incio(especialidade, paciente);
    }
}
