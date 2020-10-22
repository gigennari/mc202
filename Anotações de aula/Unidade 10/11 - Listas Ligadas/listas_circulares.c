#include <stdio.h>
#include <stdlib.h>


/**
 * Guarda o registro inteiro 
 * */
typedef struct No
{
    int dado;
    struct No *prox;
} No;

/**
 * Guarda o enedereço de um registro
 * */
typedef struct No *p_no;


p_no inserir_circular(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    if (lista == NULL){
        novo->prox = novo;
        lista = novo;
    }
    else{
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

p_no remover_circular(p_no lista, p_no no){
    p_no ant;
    if (no->prox == no){
        free(no);
        return NULL;
    }
    for(ant = no->prox; ant->prox != no; ant = ant->prox)   //O(n)
    {
        ant->prox = no->prox;
        if (lista == no)
        {
            lista = ant;    //se o no eliminado for a identidade da lista, a nova identidade será o prox do penúltimo
        }
        free(no);
        return lista; 
    }
}

void imprimir_lista_circular(p_no lista){
    p_no p;
    p = lista->prox;
    do{
        printf("%d\n", p->dado);
        p = p->prox;
    } while(p != lista->prox);

}