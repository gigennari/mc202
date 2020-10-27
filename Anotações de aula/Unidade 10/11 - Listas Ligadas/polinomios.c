/*
Suponhamos dois polinômios p e q como entrada 
p(x) = x² + 2
q(x) = 4x⁴ + 2x²+x

A saída deve ser a soma desses polinômios
s(x) = 4x⁴ + 3x² + x + 2

Estrutura de dados:
O polinômio é representado por uma lista ligada não vazia de monômios
tal que os graus estão em ordem.
Um monômio é um registro do tipo struct nó (abaixo).
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"
/**
 * podemos referenciar o ponteiro antes de criar a struct, 
 * pois todos os ponteiros têm o msm tamanho
 * 
 * */
typedef struct No *p_no; 
typedef struct lista *p_li

typedef struct No
{
    double coeficiente;
    int grau;
    p_no prox;
} No;

struct lista
{
    p_no cabeca;
};


p_no criar_lista()
{
    return NULL;
}

p_lista criar_lista()
{
    p_lista lista = malloc(sizeof(*lista));
    return NULL;
}

void liberar_lista(p_lista lista){
    p_no no;
    no = lista->cabeca;
    while (no != NULL)
    {
        p_no aux = no;
        no = no->prox;
        free(aux);
    }
    free(lista);
    
}

void adicionar_no(p_lista lista, int x){
    p_novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;
    novo->prox = *p_lista;
    *p_lista = novo; 
}

/**
 * Adiciona elemento no começo das listas ligadas 
 * Então a primeira lista vira a segunda
 *  O(n)
 * */
p_no adicionar_elemento(p_no lista_antiga, int coef, int grau)
{
    p_no novo;
    novo = malloc(sizeof(No)); //No ou *novo -> tamanho do registro
    novo->coeficiente = coef;
    novo->grau = grau;
    novo->prox = lista_antiga; //a lista antiga é o próximo nó
    return novo;
}

p_no copiar_lista(p_no lista)
{
    if (lista == NULL)
    {
        return NULL;
    }
    else
    {
        p_no novo = malloc(sizeof(No));
        novo->coeficiente = lista->coeficiente;
        novo->grau = lista->grau;
        novo->prox = copiar(lista->prox);
        return novo;
    }
}

p_no somar_polinomio(p_no p, p_no q){       
    if (p == NULL){
        return copiar_lista(q);
    }
    else if (q == NULL){
        return copiar_lista(p);
    }
    else
    {
        p_no novo;
        p_no r, s;
        if (p->grau < q->grau)
        {
            novo->grau = p->grau;
            novo->coeficiente = p->coeficiente;
            r = p->prox;
            s = q;
        }
        else if (p->grau > q->grau)
        {
            novo->grau = q->grau;
            novo->coeficiente = q->coeficiente;
            r = q->prox;
            s = p;
        }
        else
        {
            novo->grau = p->grau;
            novo->coeficiente;
            r = p->prox;
            s = q->prox
        }
        novo->prox = somar_polinomios(r, s);
        return novo;        
    }
}


int main(){
    p_no p = criar_lista();
    p_no q = criar_lista();


    p = adicionar_elemento(p, 1, 2);
    p = adicionar_elemento(p, 2, 0);
    q = adicionar_elemento(q, 4, 4);
    q = adicionar_elemento(q, 3, 2);
    q = adicionar_elemento(q, 1, 1);
    q = adicionar_elemento(q, 2, 0);

    
    p_no s = somar_polinomio(p_no p, p_no q);
    
    imprime_recur(s);

    return 0;
}