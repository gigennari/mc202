#include <stdio.h>
#include <stdlib.h>

// 0 representa o vermelho e 1, o preto
enum Cor
{
    VERMELHO,
    PRETO
};

typedef struct No
{
    int chave;
    enum Cor cor;
    struct No *esq, *dir;
} No;

typedef No *p_no;

int ehVermelho(p_no x)
{
    if (x == NULL)
    {
        return 0;
    }
    else
    {
        return x->cor == VERMELHO;
    }
}

int ehPreto(p_no x)
{
    if (x == NULL)
    {
        return 0;
    }
    else
    {
        return x->cor == PRETO;
    }
}

p_no rotaciona_para_esquerda(p_no raiz)
{
    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

p_no rotaciona_para_direita(p_no raiz)
{
    p_no x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

//um preto não pode ter dois vermelhos, sobe as cores
void sobe_vermelho(p_no raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

p_no inserir_rec(p_no raiz, int chave)
{
    p_no novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->cor = VERMELHO;
        return novo;
    }
    if (chave < raiz->chave)
    {
        raiz->esq = inserir_rec(raiz->esq, chave);
    }
    else
    {
        raiz->dir = inserir_rec(raiz->dir, chave);
    }
    return raiz;
}

p_no inserir(p_no raiz, int chave){
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    //ainda precisamos corrigir as propriedades da raiz 
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq)){
        raiz = rotaciona_para_esquerda(raiz);
    }
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)){
        raiz = rotaciona_para_direita(raiz);
    }
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir)){
        sobe_vermelho(raiz);
    }

    return raiz;
    
}

