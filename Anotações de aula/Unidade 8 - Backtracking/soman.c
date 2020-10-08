/*


*/

#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        printf("%d", vetor[i]);
    }
    printf('\n');

}

int soma(int vetor[], int n){
    int soma = 0;
    for (int i = 0; i < n; i++){
        soma += vetor[i];
    }
    return soma;
}

/**
 * Lista todas as sequencias
 * */
void imprimir_sequencia(int *vetor, int m, int n, int soma, int C){
    //se o vetor já está todo fixado
    if (n == m){
        if (soma == C){
            imprime_vetor(vetor, n);
        }
        
        return ;
    }
    //se a posição m de vetor está livre
    for (int i = 0; i <= C - soma; i++){    // ao fazer C - soma, descartamos muitas tentaivas 
        vetor[m] = i;
        imprimir_sequencia(vetor, m+1, n, soma + i, C);

    }
}


int main(){
    int *vetor, n, C;
    printf("Escreva n: ");
    scanf("%d", &n);
    scanf("%d", &C);
    printf("Escreva n: ");

    vetor = malloc(n * sizeof(int));

    imprimir_sequencia(vetor, 0, n, 0, C);

    free(vetor);
}