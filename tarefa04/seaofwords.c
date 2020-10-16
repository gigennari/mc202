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

char **aloca_matriz(int n, int m){
    char **matriz = malloc(n* sizeof(char *));
    if (matriz == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        matriz[i] = malloc(m * sizeof(char));
        if (matriz[i] == NULL){
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }
    }
    return matriz;
}

void libera_matriz(char **matriz, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
}


int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    /**
     * Aloca memoria dinamicamente
     * */
    char **texto, *palavras_buscadas;
    texto = aloca_matriz(n, m);
    palavras_buscadas = aloca_matriz(q, TAM);

    ler_texto(texto, n, m);
    ler_palavras(palavras_buscadas, q, TAM);

    caca_palavras(palavras_buscadas, texto, q, n, m);

    /**
     * Libera memoria 
     * */
    libera_matriz(texto, n, m);
    libera_matriz(palavras_buscadas, q, TAM);

    return 0;
}



