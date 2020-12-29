#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int calcula_distancia_e_insere_arestas(p_grafo g, p_ponto *pontos)
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

/**
 * Elimina distâncias da linha e coluna do lugia que já foi atingifo
 * */
p_grafo elimina_pontos_lugia(p_grafo g, int lugia){
    for (int i = 0; i < g->n; i++){
        for (int j = 0; j < g->n; j++){
            if(i == lugia || j == lugia){
                g->adj[i][j] = 0;
            }
        }
    }
    return g;
}


int busca_recur(p_grafo g, int *visitados, int v, int fim, int tam)
{
  int w; 
  //se v = fim, econtramos o caminho
    if (v == fim)
  {
      return 1;
  }
    
  //caso contario, marca que visitou
  visitados[v]= 1;
  //percorre vizinhos 
  for(w = 0; w < g->n; w++){
      //se a distancia for menor que o tamanho
      if(g->adj[v][w] <= tam && g->adj[v][w] != 0 && !visitados[w]){
          if(busca_recur(g, visitados, w, fim, tam)){
              return 1; 
          }
          
      }
  }
    return 0; 
}

/** Faz uma busca em profundidade,
 * que devolve 1 se há um caminho em que 
 * maior distancia é menor do que x
 * ou 0 se a distância é maior
 * */
int existe_caminho(p_grafo g, int ini, int fim, int tam)
{
    int encontrou, i, *visitado = malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
    {
        visitado[i] = 0;
    }
    encontrou = busca_recur(g, visitado, ini, fim, tam);
    free(visitado);
    return encontrou;
}

/** Devolve a menor maior distância
 * para a qual a busca em profundidade não falha
 * */

int busca_binaria(p_grafo g, int ini, int fim, int min, int max)
{

    int tam_atual, retorno;
    tam_atual = (min + max) / 2;
    retorno = existe_caminho(g, ini, fim, tam_atual);
    
    //se a diferença entre max e min é 1, é pq não existe menor ou igual ao mínimo, mas ao máx sim 
    if(max - min == 1){
        return max;
    }

    //existe caminho menor
    if(retorno == 1){
        return busca_binaria( g,  ini, fim, min, tam_atual);
    }
    //existe caminho maior 
    else{
        return busca_binaria( g, ini, fim, tam_atual, max);
    }   
}

void busca_por_lugia(p_grafo g, int inicio, int *lugias, int num_lugias, int maior_distancia)
{
    
    //acha menor maior distância para cada lugia e coloca em vetor
    int *menor_maior_distancia = malloc(num_lugias * sizeof(int));
    for (int i = 0; i < num_lugias; i++)
    {
        menor_maior_distancia[i] = busca_binaria(g, inicio, lugias[i], 0, maior_distancia);
        g = elimina_pontos_lugia(g, i);
    }
    
    //percorre vetor, caso haja mais de um lugia, para devolver menor distancia 
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
    scanf("%d, %d", &ponto_inicial->x, &ponto_inicial->y);
    
    scanf("%d", &componente_x);
    do
    {
        char categoria[10];
        pontos[i]->x = componente_x;

        scanf(" %d", &(pontos[i]->y));
        scanf("%s ", categoria);

        //identifica Lugias
        if (strcmp(categoria, "Lugia") == 0)
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
        i++;

    } while (retorno != -1);

    //cria grafo
    p_grafo g = criar_grafo(i);

    //calcula distâncias e insere em grafo
    maior_distancia = calcula_distancia_e_insere_arestas(g, pontos);

    //faz busca para cada lugia
    busca_por_lugia(g, inicio, lugias, num_lugias, maior_distancia);

    return 0;
}
