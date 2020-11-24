/*
Lista legal --> para todo elemento x pertencente à lista, 
existe exatamente x cópias de x 

Entrada: uma lista de números
(Obs: a lista da entrada pode não ser uma lista legal, então 
queremos descobrir qual a menor quantidade de elementos a serem removidos
para que ela seja uma lista legal)

Saída: menor quantidade de números que devem ser removidos para 
a  lista ser uma lista legal

*/

#include <stdio.h>
#include <stdlib.h>

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


p_no inserir(p_no raiz, int chave){

}

int contar_chaves(p_no raiz, int chave){

}

int menor_qtde_remover(p_no raiz){
    
}

void liberar_arvore(p_no raiz){

}

int main(){
    int qtde_inicial, num_op;
    p_no raiz = NULL;

    scanf("%d %d", &qtde_inicial, &num_op);

    for(int i = 0; i < qtde_inicial; i++){
        int chave;
        scanf("%d ", &chave);
        raiz = inserir(raiz, chave);
    }

    for(int i = 0; i < num_op; i++){
        int operacao;
        scanf("%d ", &operacao);
        
        if(operacao == 1){
            int chave;
            scanf("%d ", &chave);
            raiz = inserir(raiz, chave);
        }
        else if(operacao == 2){
            int chave, contagem;
            scanf("%d ", &chave);
            contagem = contar_chaves(raiz, chave);
            printf("%d\n", contagem);
        }
        else{
            int menor_qtde;
            menor_qtde = menor_qtde_remover(raiz);
        }
    }

    liberar_arvore(raiz);

    return 0;
}