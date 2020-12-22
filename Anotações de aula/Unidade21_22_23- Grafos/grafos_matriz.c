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
        g->adj[i] = malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void destroi_grafo(p_grafo g)
{
    int i;
    for (i = 0; i < g->n; i++)
    {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

//insere aresta em grafo não direcionado
void insere_aresta_nao_dir(p_grafo g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

//insere aresta de digrafo
void insere_aresta_dir(p_grafo g, int u, int v)
{
    g->adj[u][v] = 1;
}

void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v)
{
    return g->adj[u][v]; //se usar uma struct, devolver campo aresta
}

p_grafo le_grafo()
{

    int n, m, i, u, v; //n é tam, m é qtde de arestas
    p_grafo g;
    scanf("%d %d", &n, &m);
    g = criar_grafo(n);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        insere_aresta_nao_dir(g, u, v);
    }
    return g;
}

void imprime_arestas(p_grafo g)
{
    int u, v;
    for (u = 0; u < g->n; u++)
    {
        for (v = u + 1; v < g->n; v++)
        {
            if (g->adj[u][v])
            {
                printf("{%d, %d}\n", u, v);
            }
        }
    }
}

//devolve o número de vizinhos (grau) de um vértice; soma todos os 1s da linha
int grau(p_grafo g, int u)
{
    int v, grau = 0;
    for (v = 0; v < g->n; v++)
    {
        if (g->adj[u][v])
        {
            grau++;
        }
    }
    return grau;
}

//devolve o vértice com maior grau
int mais_popular(p_grafo g)
{
    int u, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(g, 0);
    for (u = 1; u < g->n; u++)
    {
        grau_atual = grau(g, u);
        if (grau_atual > grau_max)
        {
            grau_max = grau_atual;
            max = u;
        }
    }
    return max;
}

void imprime_recomendacoes(p_grafo g, int u)
{
    int v, w;
    for (v = 0; v < g->n; v++)
    {
        if (g->adj[u][v]) {
                for (w = 0; w < g->n; w++)
                {
                    if (g->adj[v][w] && w != u && !g->adj[u][w])
                    {
                        printf("%d\n", w);
                    }
                }
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
    encontrou = busca_rec(g, visitado, s, t);
    free(visitado);
    return encontrou;
}

/** Devolve 1 se houver um caminhos de s até t
 * que não passa por vértices já visitados
 * e 0 caso contrário 
 * */
int busca_rec(p_grafo g, int *visitado, int v, int t)
{
    int w;
    //se v = t, encontramos o caminho
    if (v == t){
        return 1;
    }
    //caso contrário, existe um primeiro vértice depois de s
    visitado[v] = 1;    //marca que visitou v
    //percorre vizinhos
    for (w = 0; w < g->n; w++){
        //se for vizinho e ainda não foi visitado
        if (g->adj[v][w] && !visitado[w]){
            //se existe caminho
            if (busca_rec(g, visitado, w, t)){
                return 1;
            }
        }
    }
    return 0; 
}

