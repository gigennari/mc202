/*
a) operações de inserir e remover abaixo

b) documentação nas funções

c) Em uma lista encadeada simples com acesso ao nó inicial, mas sem 
acesso ao final, leva O(n) para inserir um elemento no final, onde n
é o número de elementos que a lista ligada contém. 
É possível realizar essa operação em O(1) de duas maneiras:
1 - incluir um ponteiro para o final da lista na struct lista
2 - usar uma lista duplamente encadeada, onde o primeiro elemento
pode acessar o último em O(1)

*/

#include <stdio.h>
#include <stdlib.h>

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

typedef struct Lista *p_lista;

/**
 * @brief Adiociona um nó no final de uma lista duplamente ligada
 * com cabeça e causa
 * 
 * @param lista (passado por referência)
 * @param c (passado por valor)
 * @return p_lista 
 */
p_lista add_direita(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No)); //memória alocada dentro da função
    novo->dado = c;
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista)); //memória alocada dentro da função
        novo->dado = c;
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

/**
 * @brief Adiociona um nó no início de uma lista duplamente ligada
 * com cabeça e causa
 * 
 * @param lista (passado por referência)
 * @param c (passado por valor)
 * @return p_lista 
 */
p_lista add_esquerda(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No)); //memória alocada dentro da função
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista)); //memória alocada dentro da função
        novo->dado = c;
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho = 1;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = lista->ini;
        novo->ant = NULL;
        lista->ini->ant = novo;
        lista->ini = novo;
        lista->tamanho += 1;
    }
    return lista;
}

/**
 * @brief Elimina o nó de um determiando valor em uma lista 
 * duplamente ligada, com cabeça e cauda, percorrendo de frente
 * para trás e de trás para frente
 * 
 * @param lista (passado por referência)
 * @param num (passado por valor)
 * @return p_lista 
 */
p_lista remover_elemento(p_lista lista, int num)
{
    p_no esq = lista->ini;
    p_no dir = lista->fim;

    for (int i = 0; i < lista->tamanho / 2; i++)
    {
        if (esq->dado == num)
        {
            p_no anterior = esq->ant;
            p_no proximo = esq->prox;
            anterior->prox = proximo;
            proximo->ant = anterior;
            free(esq);  //ponteiro do número removido precisa ser liberado para não vazar memória
            return lista;
        }
        else if (dir->dado == num)
        {
            p_no anterior = dir->ant;
            p_no proximo = dir->prox;
            anterior->prox = proximo;
            proximo->ant = anterior;
            free(dir);
            return lista;
        }
        else
        {
            esq = esq->prox;
            dir = dir->ant;
        }
    }
}