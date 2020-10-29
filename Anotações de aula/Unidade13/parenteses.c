/*
Uma sequência de delimitadores é balancedada se 
-vazia
-ou []
-ou ()
-ou a concatenação de duas sequências balanceadas

*/

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
    p_no topo; // prox posição livre
    int tamanho;
} Pilha;

typedef Pilha *p_pilha;

void empilhar(p_pilha pilha, char x)
{
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho += 1;
}

int desempilhar(p_pilha pilha)
{
    p_no topo = pilha->topo;
    char x = topo->dado;
    pilha->topo = pilha->topo->prox;
    pilha->tamanho -= 1;
    free(topo);
    return x;
}

int esta_balanceado(char *str, p_pilha pilha)
{
    int ok = 1;

    for (int i = 0; ok && str[i] != '/0'; i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            empilhar(pilha, str[i]);
        }
        else if (pilha->tamanho == 0){
            ok = 0;
            break;
        }
        else if (str[i] == ')' || str[i] == ']')
        {
            char lido = desempilhar(pilha);
            if (str[i] == ']' && lido != '['){
                ok = 0;
                break;
            if (str[i] == ')' && lido != '('){
                ok = 0;
            }
        }
    }

    return ok;
}

int main()
{
    char str[] = {'(', '[', ']', ')', '\0'};

    p_pilha pilha;
    pilha->tamanho = 0;

    int ok = esta_balanceado(*str, pilha);
    printf("%d", ok);

    return 0; 
}