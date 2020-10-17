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
        free(matriz[i]);
    }
    free(matriz);
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

int fora_do_limite(int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int procura_recur(char *palavra, char **texto, int n, int m, int chamada, int i, int j)
{

    /**
     * Retornamos 1 (verdadeiro) quando chegamos ao final da palavra e nenhuma chamada falhou)
     * */
    if (palavra[chamada] == '\0')
    {
        return 1;
    }
    /**
     * Retornamos 0 (falso) quando está fora do limite da matriz, se a posição não é a proxima letra ou se já visitamos a posição
     * */

    else if (fora_do_limite(n, m, i, j) || texto[i][j] != palavra[chamada] || texto[i][j] == '-')
    {
        return 0;
    }
    else if (texto[i][j] == palavra[chamada])
    {
        char aux = texto[i][j];
        texto[i][j] = '-';

        if (procura_recur(palavra, texto, n, m, chamada + 1, i + 1, j))
        {
            texto[i][j] = aux;
            return 1;
        }
        else if (procura_recur(palavra, texto, n, m, chamada + 1, i - 1, j))
        {
            texto[i][j] = aux;
            return 1;
        }

        else if (procura_recur(palavra, texto, n, m, chamada + 1, i, j + 1))
        {
            texto[i][j] = aux;
            return 1;
        }
        else if (procura_recur(palavra, texto, n, m, chamada + 1, i, j - 1))
        {
            texto[i][j] = aux;
            return 1;
        }
    }
    return 0;
}

int encontra_primeira_letra(char *palavra, char **texto, int n, int m, int chamada, int i, int j)
{

    for (int linha = 0; linha < n; linha++)
    {
        for (int coluna = 0; coluna < m; coluna++)
        {
            if (texto[linha][coluna] == palavra[chamada])
            {
                char aux = texto[linha][coluna];
                texto[linha][coluna] = '-';
                i = linha;
                j = coluna;
                if (procura_recur(palavra, texto, n, m, chamada + 1, i, j))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                texto[linha][coluna] = aux;
            }
        }
    }
    return 0;
}

void caca_palavras(char **palavras, char **texto, int qtd, int n, int m)
{
    int q;
    for (q = 0; q < qtd; q++)
    {
        int chamada = 0, i = 0, j = 0;
        if (encontra_primeira_letra(palavras[q], texto, n, m, chamada, i, j))
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
    char **texto, **palavras_buscadas;
    texto = aloca_matriz(n, m);
    palavras_buscadas = aloca_matriz(q, TAM);

    ler_matriz(texto, n, m);
    ler_matriz(palavras_buscadas, q, TAM);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%c", palavras_buscadas[i][j]);
        }
        printf("\n");
        }

    caca_palavras(palavras_buscadas, texto, q, n, m);

    /**
     * Libera memoria 
     * */
    libera_matriz(texto, n, m);
    libera_matriz(palavras_buscadas, q, TAM);

    return 0;
}
