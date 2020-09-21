#include <stdio.h>
#define MAX 1000

void le_matriz_quadrada()


void multiplica_quadradas(double A[][MAX], double B[][MAX]), double C[][MAX], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {   //essa chave poderia ser omitida
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][j] * B[i][j];
            }
        }
    }
}

void imprime_matriz_quadrada(double M[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0, j < n, j++)
            printf("%lf ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];   // A é um vetor de vetores de doubles com MAX linhas e MAX colunas
    scanf("%d", &n);    //lê a dimensão das matrizes
    le_matriz_quadrada(A, n);
    le_matriz_quadrada(B, n);
    multiplica_quadradas(A, B, C, n);
    imprime_matriz_quadrada(C, n);
    return 0;
}