#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct lista
{
    int tamanho;
    int ini, fim;
    struct Lista *p_lista;
} Lista;

typedef struct Lista *p_lista;





int main()
{
    int num_operacoes;
    char *vetor_1, *vetor_2, operacao;
    p_lista num1, num2;

    scanf("%d", num_operacoes);
    for (int i = 0; i < num_operacoes; i++)
    {
        scanf("%c", operacao);
        scanf("%s %s", vetor_1, vetor_2);

        num1 = converte_str(vetor_1);
        num2 = converte_str(vetor_2);

        executa_operacao(operacao, num1, num2);
    }

    return 0;
}