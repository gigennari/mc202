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

typedef struct Lista
{
    int tamanho;
    p_no ini, fim;

} Lista;

typedef struct Lista *p_lista;

p_no insere_em_ordem(p_no lista, int num)
{

    p_no atual = lista;
    while (atual->prox != NULL)
    {
        if (atual->dado < num && atual->prox->dado > num)
        {

            p_no aux = atual->prox;
            p_no novo = malloc(sizeof(No));
            novo->dado = num;
            novo->prox = aux;
            atual->prox = novo;
            return lista;
        }
        else
        {
            atual = atual->prox;
        }
    }
    //se chegar no null e ainda não tiver devolvido, insere no final
    p_no novo = malloc(sizeof(No));
    novo->dado = num;
    novo->prox = NULL;
    atual->prox = novo;
    return lista;
}

/**
 * Se a lista tiver cabeça e cauda --> complexidade O(2)
 * Se 2 lista não tiver cabeça e cauda --> O(n), 
 * pois é necessário percorrer uma lista inteira para 
 * ligá-la na seguinte 
 */
p_no concatena_listas(p_no lista1, p_no lista2)
{
    p_no atual = lista1;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }
    atual->prox = lista2;
    return lista1;
}

p_lista concatena_listas(p_lista lista1, p_lista lista2)
{
    lista1->fim->prox = lista2->ini;
    return lista1;
}

/**
 * Para concatenar duas listas ordenadas temos que ir comparando os nós 
 * até que uma das listas acabe 
 */
p_no concatena_em_ordem(p_no lista1, p_no lista2)
{

    p_no atual1 = lista1;
    p_no atual2 = lista2;
    p_no lista3 = malloc(sizeof(No));

    if (atual1->dado < atual2->dado)
    {
        lista3 = atual1;
        atual1 = atual1->prox;
    }
    else
    {
        lista3 = atual2;
        atual2 = atual2->prox;
    }
    p_no atual3 = lista3;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->dado < atual2->dado)
        {
            atual3->prox = atual1;
            atual1 = atual1->prox;
        }
        else
        {
            atual3->prox = atual2;
            atual2 = atual2->prox;
        }
    }

    //verifica qual chegou ao fim e copia o resto a outra até terminar
    if(atual1 == NULL){
        atual3->prox = atual2;
    }
    else{
        atual3->prox = atual1;
    }
}

/**
 * Caso as listas da entradas não sejam ordenadas, ao invés de 
 * compararmos os elementos dois a dois, podemos percorrer a lista 
 * 3 e inserir quando encontrar um antecessor menor e um 
 * sucessor maior 
 * (Demora muito mais ) 
 */