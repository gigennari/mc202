/*
Palavras: na vertical ou horizontal, nunca na diagonal 

Entrada:
n m q (linhas, colunas, numero de palavra buscadas)
n linhas com m caracteres
q linhas com as palvras que devem ser buscadas

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    /**
     * Aloca memoria dinamicamente
     * */
    char **texto, *palavras_buscadas;
    texto = aloca_matriz(n, m);
    palavras_buscadas = aloca_vetor(q, 20);

    ler_texto(texto, n, m);
    ler_palavras(palavras_buscadas, q);

    caca_palavras(palavras_buscadas, texto, q, n, m);

    /**
     * Libera memoria 
     * */
    libera_matriz(texto, n, m);
    libera_vetor(palavras_buscadas, q, 20);

    return 0;
}



