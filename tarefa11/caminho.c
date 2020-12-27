#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto
{
    int x, y;
} Ponto;

typedef Ponto *p_ponto;

//grafo usando matriz
typedef struct Grafo
{
    int **adj; //armazena distâncias entre os pontos[i][j]
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

int distancia_euclidiana(p_ponto p1, p_ponto p2)
{
    return sqrt(abs(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
}

p_grafo calcula_distancia_e_insere_arestas(p_grafo g, p_ponto *pontos)
{

    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            if (i != j)
            {
                g->adj[i][j] = distancia_euclidiana(pontos[i], pontos[j]);
            }
        }
    }
}

void busca_por_lugia(p_grafo g, int inicio, int *lugias, int num_lugias)
{
    int menor_maior_distancia[num_lugias];
    for (int i = 0; i < num_lugias; i++)
    {
        menor_maior_distancia[i] = busca_binaria();
    }
    int menor;
    menor = menor_maior_distancia[0];
    if (num_lugias > 1)
    {
        for (int i = 1; i < num_lugias; i++)
        {
            if(menor_maior_distancia[i] < menor){
                menor = menor_maior_distancia[i];
            }
        }
    }

    printf("%d\n", menor);
}

/** Devolve a menor maior distância
 * para a qual a busca em profundidade não falha
 * */

int busca_binaria()
{
}

/** Faz uma busca em profundidade,
 * que devolve 1 se há um caminho 
 * menor do que a distância dada
 * ou 0 se não há
 * */
int existe_caminho(p_grafo g, int ini, int fim)
{
    int encontrou, i, *visitado = malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
    {
        visitado[i] = 0;
    }
    encontrou = busca_rec(g, visitado, ini, fim);
    free(visitado);
    return encontrou;
}

int busca_recur()
{
    
}

int main()
{

    int maior_distancia, componente_x, retorno;
    int i = 0, num_lugias = 0, inicio = -1;

    //armazena linha/coluna de lugias; vamos testar para cada um deles
    int *lugias = malloc(10 * sizeof(int));

    //armazena todos os pontos lidos antes de inserir na matriz do grafo
    p_ponto *pontos = malloc(500 * sizeof(Ponto));

    //lê entrada
    p_ponto ponto_inicial = malloc(sizeof(Ponto));
    scanf("%d, %d", ponto_inicial->x, ponto_inicial->y);
    scanf("%d", &componente_x);
    do
    {
        char *categoria;
        pontos[i]->x = componente_x;

        scanf(" %d", &(pontos[i]->y));
        scanf("%s ", categoria);

        //identifica Lugias
        if (categoria == "Lugia")
        {
            lugias[num_lugias] = i;
            num_lugias++;
        }

        //identifica início
        if (inicio == -1)
        {
            if (ponto_inicial->x == pontos[i]->x && ponto_inicial->y == pontos[i]->y)
            {
                inicio = i;
            }
        }

        retorno = scanf("%d", &componente_x);

    } while (retorno != -1);

    //cria grafo
    p_grafo g = criar_grafo(i);

    //calcula distâncias e insere em grafo
    calcula_distancia_e_insere_arestas(pontos, g);

    //faz busca para cada lugia
    busca_por_lugia(g, inicio, lugias, num_lugias);

    return 0;
}