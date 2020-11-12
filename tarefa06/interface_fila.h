#include <stdio.h>
#include <stdlib.h>
#include "implementacao_fila.c"

typedef struct No_int
{
    int sala;
    struct No *prox;
} No_int;

typedef No_int *p_no_int;

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
    struct No_int *salas;
} Paciente;




//cria um deque com a quantidade de médico daquela especilidade
p_deque criar_deque(int qtde_medicos);

//verifica se uma fila está vazia, antes de fazer algum tipo de remoção
int fila_vazia(p_deque especialidade);

//verifica prioridade e insere paciente em outro deque
p_deque insere_paciente(p_deque especialidade, p_paciente paciente);