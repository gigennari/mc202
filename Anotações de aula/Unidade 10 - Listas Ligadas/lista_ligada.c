#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"


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

/**
 * Na primeira lista, p_no aponta para NULL 
 * */
p_no criar_lista(){
    return NULL;
}

/**
 * Adiciona elemento no começo das listas ligadas 
 * Então a primeira lista vira a segunda
 *  O(n)
 * */
p_no adicionar_elemento(p_no lista_antiga, int x){
    p_no novo;
    novo = malloc(sizeof(No));  //No ou *novo -> tamanho do registro
    novo->dado = x;
    novo->prox = lista_antiga; //a lista antiga é o próximo nó
    return novo;

}

/**
 * Impressão iterativa 
 * */
void imprime_iter(p_no lista){
    p_no atual;
    for(atual = lista; atual != NULL; atual = atual->prox){
        printf("%d\n", atual->dado);
    }
}

void imprime_recur(p_no lista){
    if(lista != NULL){
        printf("%d\n", lista->dado);
        imprime_recur(lista->prox);
    }

}

void imprime_lista_inversa(p_no lista){
    if (lista != NULL){
        imprimir_lista_inversa(lista->prox);
        printf("%d\n", lista->dado)
    }
}

/**
 * Libera listas ligadas recursivamente (de trás pra frente)
 * */
void destruir_lista(p_no lista){
    if (lista != NULL){
        destruir_lista(lista->prox);
        free(lista);
    }
}

/**
 * Busca elemento x em uma lista ligada
 * */
p_no buscar_no(p_no lista, int elemento){
    for (p_no atual = lista; atual != NULL; atual = atual->prox){
        if (atual->dado == elemento)
            return atual; 
    }
    return NULL;
}

p_no remover_elemento(p_no lista, int x){
    if (lista == NULL){
        return lista;
    }
    else if (lista->dado == x){
        p_no aux = lista;
        lista = lista->prox;
        free(aux);
        return lista;
    }
    else{
        lista->prox = remover_elemento(lista->prox, x);
    }
}


int main(){
    p_no lista;
    lista = criar_lista();

    return 0;
}