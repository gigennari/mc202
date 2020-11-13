#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implementacao_fila.c"



//devolve lista nula 
p_lista criar_lista();

//insere à direita as novas salas
p_lista add_direita(p_lista lista, int c);

//remove da esquerda salas já visitadas
p_lista eliminar_esquerda(p_lista num);

//libera memória de uma lista de nós
void liberar_memoria_lista(p_lista lista);

//cria um "nó" de paciente com seus dados
p_paciente criar_paciente(char *nome, Preferencia x, p_lista salas, int posicao);

//coloca pacientes lidos em um deque em um vetor 
void colocar_pacientes_vetor(p_paciente *vetor, p_deque pacientes, int num_pacientes);

//cria um deque com a quantidade de médico daquela especilidade
p_deque criar_deque(int qtde_medicos);

//verifica se uma fila está vazia, antes de fazer algum tipo de remoção
int fila_vazia(p_deque especialidade);

//libera memória alocada para uma fila e todos os seus pacientes
void liberar_memoria_deque(p_deque fila);

//verifica prioridade e insere paciente em outro deque
void inserir_paciente(p_deque especialidade, p_paciente paciente);

//remove paciente do final 
p_paciente remover_paciente(p_deque especialidade);


