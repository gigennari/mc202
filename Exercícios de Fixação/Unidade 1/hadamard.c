/*
exemplo
entrada:
u = (1, 2, 3)
v = (2, 4, 5)

saída:
u ** v = (2, 8, 15)

*/

#include <stdio.h>
#define MAX 1000

criar_vetor_tamanho_n(n)



void ler_vetor(double v[], int n) {
    vetor = criar_vetor_tamanho_n(n)
    for (i = 0; i < n; i++){
        scanf("%lf", &vetor[i]);
    }
}

imprimir_vetor(double v[], int n){
    for (i = 0; i < n; i++) {
        printf("%lf ", v[i]);
    }
    printf("\n");
}


calcular_produto_hadamard(double u[], double v[], double z[], int n) {
    z = criar_vetor_tamanho_n(n)
    for (i = 0; i < n; i++) {
        z[i] = u[i] * v[i]
    }
}

int main() {
    int n;
    double u[MAX], v[MAX], p[MAX];
    printf("Entre com a dimensão do vetor %d\n:");
    scanf("%d", &n);
    if (n > 100)
    ler_vetor(u, n)
    ler_vetor(v, n)
    p = calcular_produto_hadamard(u, v, n)
    imprimir_vetor(p)
    return 0;
}