/*
Para cada vértice, há uma lista ligada que armazena
quais são os vizinhos do vértice 
*/
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
    p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = calloc(n, sizeof(p_no));
    return g;

    
}

void libera_lista(p_no lista){
    if(lista!= NULL){
        libera_lista(lista->prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g)
{
    for (int i = 0; i < g->n; i++){
        libera_lista(g->adj[i]);
    }
    free(g->adj);
    free(g);
    
}

p_no insere_na_lista(p_no lista, int v)
{
    p_no novo = malloc(sizeof(No));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v)
{
    g->adj[v] = insere_na_lista(g->adj[v], u);
    g->adj[u] = insere_na_lista(g->adj[u], v);
}

p_no remove_na_lista(p_no lista, int v)
{
    p_no proximo;
    if(lista == NULL){
        return NULL;
    }
    else if (lista->v == v){
        proximo = lista->prox;
        free(lista);
        return proximo;
    }
    else{
        lista->prox = remove_da_lista(lista->prox, v);
        return lista;
    }
}


void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[v] = remove_na_lista(g->adj[v], u);
    g->adj[u] = remove_na_lista(g->adj[u], v);
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
    int u;
    p_no t;
    for (u = 0; u < g->n; u++){
        for(t = g->adj[u]; t != NULL; t = t->prox){
            printf("{%d, %d}\n", u, t->v);
        }
    }
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

int * encontra_componentes(p_grafo g){
    int s, c = 0, *componenetes = malloc(g->n * sizeof(int));
    for (s = 0; s < g-> n; s++){
        componenetes[s] = -1;
    }
    for (s = 0; s < g->n; s++){
        if(componenetes[s] == -1){
            visita_rec(g, componenetes, c, s);  //marca com c todos os vértices atingíveis a partir de s
            c++;
        }
    }
    return componenetes;
}

void visita_rec(p_grafo g, int *componentes, int comp, int v){
    p_no t;
    componentes[v] = comp;
    for(t = g->adj[v]; t != NULL; t = t->prox){
        if (componentes[t->v] == 1){
            visita_rec(g, componentes, comp, t->v);
        }
    }
}