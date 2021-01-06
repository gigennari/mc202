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

p_planilha aloca_matriz(int m, int n)
{
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

    //aloca matriz

    //lê arquivo csv

    //lê e realiza operações
    

    return 0;
}