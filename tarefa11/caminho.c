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

//grafo usando matriz
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

/** Devolve a menor maior distância
 * para a qual a busca em profundidade não falha
 * */

int busca_binaria(){

}

/** Faz uma busca em profundidade, usando 
 * pilha, que devolve 1 se há um caminho 
 * menor do que a distância dada
 * ou 0 se não há
 * */
int busca_em_profundidade(){

}

int main(){
    
    
    p_ponto inicio = malloc(sizeof(Ponto));
    scanf("%d, %d", inicio->x, inicio->y);

    int maior_distancia; 



    return 0;
}