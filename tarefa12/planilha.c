#include <stdio.h>
#include <stdlib.h>

typedef struct Token
{
    int valor;
    char *expressao;

} Token;

typedef struct Planilha
{
    Token **planilha;
    int **visitados;
    int m, n;

} Planilha;

typedef struct Planilha *p_planilha;

p_planilha aloca_planilha(int m, int n)
{
    p_planilha p = malloc(sizeof(Planilha));
    
    p->m = m;
    p->n = n;

    p->planilha = malloc(m * sizeof(Token *));

    for (int i = 0; i < m; i++)
    {
        p->planilha[i] = malloc(n * sizeof(Token));
    }

    p->visitados = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        p->visitados[i] = calloc(n, sizeof(int));
    }
    
    return p;
}



void le_linha(p_planilha p, char *linha, int num_linha)
{
}

p_planilha le_arquivo()
{

    FILE *arquivo = fopen("planilha.csv", "r");

    char linha[256];
    int linha_atual = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        le_linha(linha, strlen(linha), linha_atual);
        linha_atual++;
    }

    fclose(arquivo);

    return
}

int main()
{

    //lê nome do arquivo e dimensões da planilha
    char nome[25];
    int m, n;
    scanf("%s %d %d", nome, m, n);

    //aloca planilha
    p_planilha p = aloca_planilha(m, n);

    //lê arquivo csv

    //lê e realiza operações


    return 0;
}