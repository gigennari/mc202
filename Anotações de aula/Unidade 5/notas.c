/*
Ao invés de alocarmos a memória com um tamanho fixo pré definido, 
perguntamos antes ao usuario o tamanho desejado para o vetor nesse caso

Liberar a memória tão logo voce nao precise mais dela 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    double media, *notas;
    int i, n;
    scanf("%d", &n);
    notas = malloc(n * sizeof(double)); // malloc procura um espaço livre na memória e devolve o endereço da primeira posição
    
    if (notas == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);    //termina o programa abruptamente em qualquer função 
    }
    
    for (i = 0; i < n; i++)
        scanf("%lf", &notas[i]);
    media = 0;
    
    for (i = 0; i < n; i++)
        media += notas[i] / n;
    
    printf("Média: %lf\n", media);
    free(notas);
    return 0;
}