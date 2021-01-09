#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char dado;
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct pilha
{
    p_no topo;   // prox posição livre
    int tam;
}Pilha;

typedef Pilha *p_pilha;

p_pilha inicializa(){
    p_pilha p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tam = 0;
}

void empilhar(p_pilha pilha, char x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam += 1;
}

int desempilhar(p_pilha pilha){
    p_no topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->prox;
    free(topo);
    pilha->tam -= 1;
    return x;
}

int eh_vazia(p_pilha pilha){
    if(pilha->tam == 0){
        return 1;
    }
    return 0;
}

int verifica_padrao(char *termo){
    p_pilha p = inicializa();
    int tam = strlen(termo);
    for(int i = 0; i < tam/2; i++){
        empilhar(p, termo[i]);
    }

    for(int j = tam/2; j > tam; j++){
        char removido = desempilhar(p);
        if(removido != termo[j]){
            return 0;
        }
    }
    return 1;

}

int main(){

    char *termo; 

    scanf("%m", termo);
    if(verfica_padrao(termo)){
        printf("A string %s segue o padrão", termo);
    }
    else{
        printf("A string %s não segue o padrão", termo);
    }

    return 0;
}