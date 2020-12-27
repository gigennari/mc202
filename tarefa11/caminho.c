#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum
{
    pokestop,
    lugia
} Categoria;

typedef struct Ponto{
    int x, y;
    int aresta;
    Categoria categoria;
    struct Ponto *prox;
} Ponto;

typedef Ponto *p_ponto;

typedef struct Grafo{
    p_ponto *adj;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n)
{
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = calloc(n, sizeof(p_ponto));
    return g;  
}


int distancia_euclidiana(p_ponto p1, p_ponto p2){
    return sqrt(abs(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
}

int main(){
    
    
    p_ponto inicio = malloc(sizeof(Ponto));
    scanf("%d, %d", inicio->x, inicio->y);

    int maior_distancia; 



    return 0;
}