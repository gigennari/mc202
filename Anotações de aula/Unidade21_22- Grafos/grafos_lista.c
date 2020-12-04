#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int v;
    struct No *prox;
} No;

typedef No *p_no;

typedef struct
{
    p_no *adj;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n)
{
    int i;
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g->adj[i] = NULL;
    return g;
}

void destroi_grafo(p_grafo g)
{
}

void insere_na_lista(p_no lista, int v)
{
}

void remove_na_lista(p_no lista, int v)
{
}

void insere_aresta(p_grafo g, int u, int v)
{
}

void remove_aresta(p_grafo g, int u, int v)
{
}

int tem_aresta(p_grafo g, int u, int v)
{
    p_no t;
    for (t = g->adj[u]; t != NULL; t = t->prox)
    {
        if (t->v == v)
        {
            return 1;
        }
    }
    return 0;
}

void imprime_arestas(p_grafo g)
{
}


int existe_caminho(p_grafo g, int s, int t)
{
    int encontrou, i, *visitado = malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
    {
        visitado[i] = 0;
    }
    encontrou = busca_recur(g, visitado, s, t);
}

/**
 * Devolve 1 se houver um caminho de s até t
 * sem passar por vértices já visitados; 
 * Devolve 0 caso contrário.
 **/ 
int busca_recur(p_grafo g, int *visitado, int s, int t){
    //se s==t, devolve sim 
    if(s==t){
        return 1;
    }
    //se s != t
    else{
        //marque s
        visitado[s] = 1;
        p_no no;
        //para cada vizinho de s, 
        for (no = g->adj[s]; no != NULL; no = no->prox){
            //se v não foi visitado ainda e existe caminho de v até t 
            if (!visitado[no->v] && busca_recur(g, visitado, no->v, t))
            {
                    return 1;
            }      
        }      
    }   
    return 0;  
}   