#include <stdio.h>
#include <stdlib.h>

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

int main(){
    p_ponto inicio = malloc(sizeof(Ponto));
    scanf("%d, %d", inicio->x, inicio->y);


    return 0;
}