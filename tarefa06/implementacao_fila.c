#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"


typedef struct Deque
{
    p_no ini, fim;   // prox posição livre
    int qtde_medicos, qtde_pacientes;
}Deque;

typedef Deque *p_deque;

enum Preferencia
{
    normal,
    prioridade
};

typedef struct Paciente
{
    char nome[50];
    enum Preferencia status;
    p_lista salas;
} Paciente;

typedef Paciente *p_paciente;

typedef struct No
{
    p_paciente paciente;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;


/**
 * Funções de deque 
 * */
p_deque criar_deque(int qtde_medicos){
    p_deque deque;
    deque = malloc(sizeof(Deque));
    deque->qtde_medicos = qtde_medicos;
    deque->qtde_pacientes = 0;
    deque->ini = deque->fim = NULL;
    return deque;
}

int fila_vazia(p_deque especialidade){
    if (especialidade->qtde_pacientes == 0){
        return 1;
    }
    return 0; //se fila não for vazia, remover pacientes existentes de acordo com qtde de médicos
}
    

//para pacientes prioridade
p_deque insere_incio(p_deque especialidade, p_paciente paciente){

}

//para pacientes normal 
p_deque insere_fim(p_deque especialidade, p_paciente paciente){

}

p_deque insere_paciente(p_deque especialidade, p_paciente paciente){

}


//sempre remove do início
p_deque remove_paciente(p_deque especialidade, p_paciente paciente){

}










/**
 * Funções de paciente
 * */

p_paciente cria_paciente(char *nome, enum Preferencia x, p_lista salas){
    p_paciente paciente;
    paciente = malloc(sizeof(Paciente));
    strcpy(paciente->nome, nome);
    paciente->status = x;
    paciente->salas = salas;
    return paciente;

}


