/*
Palavras: na vertical ou horizontal, nunca na diagonal 

Entrada:
n m q (linhas, colunas, numero de palavra buscadas)
n linhas com m caracteres
q linhas com as palvras que devem ser buscadas

*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 20

char **aloca_matriz(int n, int m)
{
    char **matriz = malloc(n * sizeof(char *));
    if (matriz == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        matriz[i] = malloc(m * sizeof(char));
        if (matriz[i] == NULL)
        {
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }
    }
    return matriz;
}

void libera_matriz(char **matriz, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
}

void ler_matriz(char **matriz, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }
}

int procura_recur(char *palavra, char **texto, int n, int m, int chamada, int i, int j)
{

    if (chamada = 0)
    {
        for (int linha = i; linha < n; linha++)
        {
            for (int coluna = j; coluna < m; coluna++)
            {
                if (texto[i][j] = palavra[chamada])
                {
                    i = linha;
                    j = coluna;
                    return procura_recur(palavra, texto, n, m, chamada + 1, i, j);
                }
                else
                {
                    return 0;
                }



            }
        }
    }
    if (chamada > 0){
        if(texto[i+1][j] = palavra[chamada]){
            i += 1;
            return procura_recur(palavra, texto, n, m, chamada + 1, i, j);
        }
        else if(texto[i-1][j] = palavra[chamada]){
            i -= 1;
            return procura_recur(palavra, texto, n, m, chamada + 1, i, j);            
        }
        else if(texto[i][j+1] = palavra[chamada]){
            j += 1;
            return procura_recur(palavra, texto, n, m, chamada + 1, i, j);
        }
        else if(texto[i][j-1] = palavra[chamada]){
            j -= 1;
            return procura_recur(palavra, texto, n, m, chamada + 1, i, j);
        }
        else{
            return 0;
        }
        
    }
}

void caca_palavras(char **palavras, char **texto, int qtd, int n, int m)
{
    for (int q = 0; q < qtd; q++)
    {
        int chamada = 0, i = 0, j = 0;
        if (procura_recur(palavras[q][TAM], texto, n, m, chamada, i, j))
        {
            printf("sim");
        }
        else
        {
            printf("nao");
        }
    }
}

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    /**
     * Aloca memoria dinamicamente
     * */
    char **texto, *palavras_buscadas;
    texto = aloca_matriz(n, m);
    palavras_buscadas = aloca_matriz(q, TAM);

    ler_matriz(texto, n, m);
    ler_matriz(palavras_buscadas, q, TAM);

    caca_palavras(palavras_buscadas, texto, q, n, m);

    /**
     * Libera memoria 
     * */
    libera_matriz(texto, n, m);
    libera_matriz(palavras_buscadas, q, TAM);

    return 0;
}
