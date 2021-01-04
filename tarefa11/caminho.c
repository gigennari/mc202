#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Ponto
{
    double x, y;
} Ponto;

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

void libera_grafo(p_grafo g){
    for (int i = 0; i < g->n; i++)
    {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

int distancia_euclidiana(Ponto p1, Ponto p2)
{
    return ceil(sqrt(abs(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0))));
}

int calcula_distancia_e_insere_arestas(p_grafo g, Ponto *pontos)
{

    int maior_distancia = 0;
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            if (i != j)
            {
                int x = distancia_euclidiana(pontos[i], pontos[j]);
                g->adj[i][j] = x;
                if (x > maior_distancia){
                    maior_distancia = x;
                }
            }
            else {
                g->adj[i][j] = 0;
            }
        }
    }
    return maior_distancia;
}

int eh_lugia(const int *categorias, int pos){

    return categorias[pos];

}

int busca_recur(p_grafo g, int *visitados, int vertice, int tam, const int *categorias)
{
  int w; 
  //se v = fim, econtramos o caminho
    if (eh_lugia(categorias, vertice))
  {
      return 1;
  }
    
  //caso contario, marca que visitou
  visitados[vertice] = 1;

  //percorre vizinhos 
  for(w = 0; w < g->n; w++){
      //se a distancia for menor que ou igual ao tamanho atual e o vizinho ainda não foi visitado
      if(g->adj[vertice][w] <= tam && g->adj[vertice][w] != 0 && !visitados[w]){
          if(busca_recur(g, visitados, w, tam, categorias)){
              return 1; 
          }
          
      }
  }
    return 0; 
}

/** Chama busca em profundidade,
 * que devolve 1 se há um caminho em que 
 * maior distancia é menor do que x
 * ou 0 se a distância é maior
 * */
int existe_caminho(p_grafo g, int ini, int tam, const int *categorias)
{
    int *visitado = malloc(g->n * sizeof(int));
    int encontrou, i;
    for (i = 0; i < g->n; i++)
    {
        visitado[i] = 0;
    }
    encontrou = busca_recur(g, visitado, ini, tam, categorias);
    free(visitado);
    return encontrou;
}

/** Devolve a menor maior distância
 * para a qual a busca em profundidade não falha
 * */

int busca_binaria(p_grafo g, int ini, int min, int max, const int *categorias)
{

    int tam_atual, retorno;

    tam_atual = ceil((min + max) / 2);
    retorno = existe_caminho(g, ini, tam_atual, categorias);
    
    //se a diferença entre max e min é 1, é pq não existe menor ou igual ao mínimo, mas ao máx sim 
    if(max - min == 1){
        return max;
    }

    //se passou, pode existir existe caminho menor
    if(retorno){
        return busca_binaria(g, ini, min, tam_atual, categorias);
    }
    //se não passou, existe caminho maior 
    else{
        return busca_binaria(g, ini, tam_atual, max, categorias);
    }   
}


int main()
{

    int maior_distancia, retorno;
    int i = 0, inicio = -1, menor_distancia = 0;
    double componente_x;

    //armazena todos os pontos lidos antes de inserir na matriz do grafo
    Ponto *pontos = malloc(500 * sizeof(Ponto));
    int *categorias = calloc(500, sizeof(int));

    //lê entrada
    Ponto ponto_inicial;

    scanf("%lf %lf ", &(ponto_inicial.x), &(ponto_inicial.y));
    scanf("%lf", &componente_x);

    do
    {
        char categoria[10];

        pontos[i].x = componente_x;

        scanf(" %lf ", &(pontos[i].y));
        scanf("%s ", categoria);

        //identifica Lugias
        if (strcmp(categoria, "Lugia") == 0)
        {
            categorias[i] = 1;
        }

        //identifica início
        if (inicio == -1)
        {
            if (ponto_inicial.x == pontos[i].x && ponto_inicial.y == pontos[i].y)
            {
                inicio = i;
            }
        }

        retorno = scanf("%lf", &componente_x);
        if (retorno != EOF){
            i++;
        }
        

    } while (retorno != EOF);

    //cria grafo com matriz i x i
    p_grafo g = criar_grafo(i);

    //calcula distâncias e insere em grafo
    maior_distancia = calcula_distancia_e_insere_arestas(g, pontos);

    //faz busca binária para achar a menor maior distância entre o início e um lugia
    int distancia = busca_binaria(g, inicio, menor_distancia, maior_distancia, categorias);
    printf("%d\n", distancia);

    libera_grafo(g);
    free(pontos);
    free(categorias);

    return 0;
}
