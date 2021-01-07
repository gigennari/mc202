/**
 Nessa estrutura, os nós dummies aponta para o último elemento
 da linha ou coluna em que está se houver um valor diferente
 de 0 naquela posição da matriz.
 Caso não haja nenhum valor diferente de 0, ele aponta para 
 ele mesmo. 

 */

typedef struct No
{
    int m, n;
    int dado;
    struct No *prox, *ant;
} No;

typedef struct No *p_no;

int encontra_elemento(p_no linha, int coluna){

    p_no atual = linha->prox;

    while(atual != linha){
        if(atual->n == coluna){
            return atual->dado;
        }
        else{
            atual = atual->prox;
        }
    }
}