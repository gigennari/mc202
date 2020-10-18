/*
As damas se movem em linhas retas pelas fileiras,cokunas e diagonais 
no tabuleiro. assim, uma disposição de damas para que nenhuma delas
corra risco, é não ter damas na diagonal, na mesma linha ou mesma
coluna.
Ou seja, elas precisam estar na diagonal.

Nesse programa:
n - total de damas (no máximo 8)

*/

#include <stdio.h>

void damas(int n, int m, int* damas) {
    int *v; // pilha (guarda o vetor das damas)
    int m; // num de damas fixas
    // inicializa primeira dama
    m = 0;
    v[m] = 0;
    enquanto nao fixou todas {
    // aqui, v[m] é a última posicao testada para m
    // procura uma posicao diferente para dama m entre v[m]+1 e n
    // se encontrou posicao viável, fixa posicao
    // e inicializa proxima dama
    // se nao encontrou, desafixa posicao
    }
    // imprime tabuleiro
    for (int i = 0; i < n; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}

int main(){
    int n, m, *fixas;
    scanf("%d %d", &n, &m);

    damas(n);
    return 0;

}