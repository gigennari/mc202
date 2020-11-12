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

p_lista criar_lista()
{
    return NULL;
}

p_lista add_direita(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista));
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

p_lista eliminar_esquerda(p_lista num)
{
    if (num != NULL)
    {
        p_no aux = num->ini;
        num->ini = num->ini->prox;
        free(aux);
        return num;
    }
}

void liberar_memoria(p_lista lista)
{
    if (lista != NULL)
    {
        p_no no;
        no = lista->ini;
        while (no != NULL)
        {
            p_no aux = no;
            no = no->prox;
            free(aux);
        }
        free(lista);
    }
}