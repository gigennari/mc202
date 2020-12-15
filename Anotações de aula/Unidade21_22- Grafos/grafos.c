#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **adj;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n)
{
    int i, j;
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        g->adj
    }
}

int existe_caminho(p_grafo g, int s, int t){
    int encontrou, i, *visitado = malloc(g->n * sizeof(int));
    for (i = 0; i < g-> n; i++){
        visitado[i] = 0;
    }
    encontrou = busca_rec(g, visitado, s, t);
    free(visitado);
    return encontrou;
}

int busca_rec(p_grafo g, int *visitado, int s, int t){

}

