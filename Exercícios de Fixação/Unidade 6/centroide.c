#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ** aloca_matriz(int M, int N){
    int **matriz = malloc(M* sizeof(int *));
    if (matriz == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++){
        matriz[i] = malloc(N * sizeof(int));
        if (matriz == NULL){
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }
    }
    return matriz;
}

void libera_matriz(int **matriz, int M, int N){
    for(int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            free(matriz[i][j]);
        }
        free(*matriz[i]);
    }
}

int * aloca_e_zera__vetor(int N){
    int *vetor = malloc(N * sizeof(int));
    if (vetor == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    for (int j = 0; j < N; j++){
        vetor[j] = 0;
    }
    return vetor;

}

void libera_vetor(int *vetor, int N){
    for (int j = 0; j < N; j++){
        free(vetor[j]);
    }
}


void ler_pontos(int **matriz, int M, int N){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int calcula_centroide(int *centroide, int **matriz, int M, int N){
    for(int j = 0; j < N; j++){
        for (int i = 0; i < M; i++){
            centroide += (matriz[i][j] / M);
        }
    }
    return centroide;
}

int soma_distancias(int *centroide, int **matriz, int M, int N){
    int soma_distancias = 0;
    int soma = 0;
    for (int i = 0; i < M; i++){
        soma = 0;
        for (int j = 0; j < N; j++){
            soma += pow(centroide[j] - matriz[i][j], 2);
        }
        soma_distancias += sqrt(soma);
    }
    return soma_distancias;
}


int main(){
    int num_pontos, dim_pontos, soma_distancias, **matriz, *centroide;
    scanf("%d %d", &dim_pontos, &num_pontos);
    
    /**
     * Aloca memória dinamicamente
     * */
    matriz = aloca_matriz(num_pontos, dim_pontos);
    centroide = aloca_e_zera_vetor(dim_pontos);

    ler_pontos(matriz, num_pontos, dim_pontos);
    centroide = calcula_centroide(centroide, matriz, num_pontos, dim_pontos);
    soma_distancias = calcula_soma_distancias(centroide, matriz, num_pontos, dim_pontos);
    printf("O centroide é: ");
    for (int j = 0; j < dim_pontos; j++){
        printf("%d", centroide[j]);
    }
    printf('\n');
    printf("A soma das distancias de todos os potntos até o centroide é: %d", soma_distancias);
    

    /**
     * Libera memória
     * */
    void libera_matriz(matriz, num_pontos, dim_pontos); 
    void libera_vetor(vetor, dim_pontos);
    return 0;
}