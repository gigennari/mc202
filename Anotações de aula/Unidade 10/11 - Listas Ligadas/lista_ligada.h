#include <stdio.h>
#include "lista_ligada.c"
#include "listas_circulares.c"

/**
 * Guarda o registro inteiro 
 * */
typedef struct No{
    int dado;
    struct No *prox;
} No;


/**
 * Guarda o enedereço de um registro
 * */
typedef struct No *p_no; 

p_no criar_lista();

p_no adicionar_elemento(p_no lista_antiga, int x);

p_no buscar_no(p_no lista, int x);

p_no remover_elemento(p_no lista, int x);

void imprime_iter(p_no lista);

void imprime_recur(p_no lista);

void imprime_lista_inversa(p_no lista);

void destruir_lista(p_no lista);

/**
 * Circulares
 * */

p_no inserir_circular(p_no lista, int x);
