#include <stdio.h>
#include <stdlib.h>

typedef struct No_normal
{
    int sala;
    struct No *prox;
    struct No *ant;
} No_normal;

typedef No_normal *p_no_normal;

typedef struct No
{
    struct Paciente paciente;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

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
    struct No *salas;
} Paciente;

typedef Paciente *p_paciente;

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

p_deque insere_paciente(p_deque especialidade, p_paciente paciente){

}

p_deque remove_paciente(p_deque especialidade, p_paciente paciente){

}

