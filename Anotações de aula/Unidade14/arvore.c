#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;


/**
 * Cria uma nova árvore com as duas subárvores 
 * existentes
 * */ 
 p_no criar_arvore(int x, p_no esq, p_no dir){
    p_no novo = malloc(sizeof(No));
    novo->esq = esq;
    novo->dir = dir;
    novo->pai = NULL;
    return novo; 
}

/**
 * Devolve um nó da árvore com o valor x 
 * ou NULL se não houver
 * */
p_no procurar_no(p_no raiz, int x){
    if(raiz == NULL || x == raiz->dado){
        return raiz;
    }
    else{
        p_no aux;
        aux = procurar_no(raiz->esq, x);  
        if (aux != NULL){
            return aux;
        }  
        aux = procurar_no(raiz->dir, x);
        if(aux != NULL){
            return aux;
        }
        else{
            return NULL;
        }
    }
}

int numero_nos(p_no raiz){
    if (raiz == NULL){
        return 0;
    }
    else{
        return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1; 
}

int altura(p_no raiz){
    int h_esq, h_dir, maior;
    if (raiz = NULL){
        return 0;
    }

    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);
    
    if (h_esq > h_dir){
        maior = h_esq;
    }
    else{
        maior = h_dir;
    }
    return 1 + maior;
}


void pre_ordem(p_no raiz){
    if (raiz != NULL){
        printf("%d, raiz->dado");
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(p_no raiz){
    if (raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d", raiz->dado);
    }
}

void inordem(p_no raiz){
    if (raiz != NULL){
        inordem(raiz->esq);
        printf("%d", raiz->dado);
        inordem(raiz->dir);
    }
}

/**
 * funções de pilha na unidade anterior
 * */
void pre_ordem_iter(p_no raiz){
    p_pilha p;
    p = criar_pilha();
    empilhar(p, raiz);
    while(!pilha_vazia(p)){
        raiz = desempilhar(p);
        if(raiz != NULL){
            empilhar(p, raiz->dir);
            empilhar(p, raiz->esq);
            printf("%d", raiz->dado);
        }
    }
    destruir_pilha(p);
}

void percorre_largura(p_no raiz){
    p_fila f;
    f = criar_fila();
    enfileirar(f, raiz);
    while(!fila_vazia(f)){
        raiz = desenfileirar(f);
        if (raiz != NULL){
            enfileirar(f, raiz->esq);
            enfileirar(f, raiz->dir);
            printf("%d", raiz->dado);
    }    
    }
    destruir_fila(f);
}

int main(){
    return 0;
}