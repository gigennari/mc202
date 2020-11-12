#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.c"

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct Lista
{
    int tamanho;
    p_no ini, fim;

} Lista;

//devolve lista nula 
p_lista criar_lista();

//insere à direita as novas salas
p_lista add_direita(p_lista lista, int c);

//remove da esquerda salas já visitadas
p_lista eliminar_esquerda(p_lista num);

//libera memória de uma lista de nós
void liberar_memoria_lista(p_lista lista);