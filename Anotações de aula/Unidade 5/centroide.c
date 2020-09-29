#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    double x, y;
}ponto;

ponto ler_ponto(){
    ponto p;
    scanf("%lf %lf", &p.x, &p.y);
}

ponto calcular_centroide(ponto vetor[], int n){
    ponto c;
    c.x = 0;
    c.y = 0;
    for (int i = 0; i < n; i++){
        c.x += vetor[i].x / n;
        c.y += vetor[i].y / n;
    }
    return c;
}

void imprimir_ponto(ponto p){
    printf("P = (%lf, %lf)\n", &p.x, &p.y);
}

int main(){
    ponto *pontos;
    ponto centroide;
    int n;
    scanf("%d, &n");

    pontos = malloc(n * sizeof(ponto));
    if (pontos == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);    
    }
    
    for (int i = 0; i < n; i++){
        pontos[i] = ler_ponto();
    }
    
    centroide = calcular_centroide(pontos, n);
    imprimir_ponto(centroide);
    free(pontos);

}