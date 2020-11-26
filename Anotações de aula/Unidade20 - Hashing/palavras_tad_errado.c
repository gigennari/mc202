#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PALAVRA 30


typedef struct no *p_no;

struct no{
    char chave[MAX_PALAVRA];
    int ocorrencias;
    p_no prox;
};

p_no inserir(p_no lista, char *palavra){
    p_no novo = malloc(sizeof(*novo));
    strcpy(novo->chave, palavra);
    novo->ocorrencias = 1;
    novo->prox = lista;
    return novo;
}

p_no buscar(p_no lista, char *palavra){
    for(p_no  no = lista; no != NULL; no = no->prox){
        if(strcmp(no->chave, palavra) == 0){
            return no;
        }
    }
    return NULL; 
}

int main(){
    char palavra[MAX_PALAVRA];
    p_no lista = NULL;
    while(scanf("%s ", palavra) == 1){
        p_no no = buscar(lista, palavra);
        if(no == NULL){
            lista = inserir(lista, palavra);
        }
        else{
            no->ocorrencias++;
        }
    }

    for(p_no  no = lista; no != NULL; no = no->prox){
        printf("%d\n", no->ocorrencias);
    }
    return 0;
}