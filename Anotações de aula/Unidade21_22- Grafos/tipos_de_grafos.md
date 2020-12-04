# Grafos 

* Um grafo é um conjunto de objetos ligados entre si 
* chamamos esses objetos de **vértices**
    - pessoas em uma rede social 
* chamamos as conexões entre os objetos de **arestas**
    - relação de amizade na rede social 


* Matematicamnete, um grafo G é uma par ordenado (V, E)
* V é conjunto de vértices
    - v = {0, 1, 2, 3, 4}
* e é o conjunto das as arestas
    - E = {{1,2}, {2,3}, {3,4}}

## Matriz de Adjacências
* Se o grafo tem n vértices, os vértices serão numerados de 0 a n-1
* A matrix é nxn
* adjacencia[u][v] = 1 -> se u e v são vizinhos
* adjacencia[u][v] = 0 -> se u e v são não vizinhos

Propriedades:
    * simétrica (A = A^T)
    * diagonal de 0, pq não existe um par (u,u)

```C

typedef struct {
    int **adj;
    int n;
}Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n);

```

# Grafos dirigidos 
* representar seguidores e quem sigo 

* tem um conjunto de vértices
* concetados através de um conjunto de **arcos** (arestas dirigidas)

* Matematicamnete, um grafo G é uma par (V, A)
* V é conjunto de vértices
    - v = {0, 1, 2, 3, 4}
* A é o conjunto de arcos
    - u é a cauda ou origem de (u,v)
    - v é a cabeça ou destino (u, v)
    * podemos ter laços: arcos da forma (u, u)
    * existe no máximo um arco (u, v)

* Podemos usar uma matriz de adjacências para representar um digrafo (cada aresta é considerada como dois arcos)
* Matriz não é mais simétrica

# Número de arestas de um grafo

* 0, 1, 3, 6, 10
* **n (n-1)/2** = O(n^2) arestas

### Facebook 
* tem 2,2bi de usuários 
* uma matriz de adjacências teria 2,2bi^2 = 4,84*10^18 posições
* 605 petabytes (usando um bit por posição)
* verificar de duas pessoas são amigas leva O(1)
* imprimir todos os amigos de uma pessoa leva O(n)
* facebook limita 5000 amigos 
* então o máximo de arestas é 5,5*10^12

# Grafos esparsos
* dizemos que um grafo é esparso se ele tem "poucas" arestas

    * grafos cujos vertices têm o mesmo grau d (cte)
    * grafos com O(lg n) arestas

* uma representação mais econômica é 

## Lista de adjacência
* temos uma lista ligada para cada vértice 
* a lista armazena quais são os vizinhos do vértice 

```C
typedef struct No {
    int v;
    struct No *prox;
} No;

typedef No * p_no;

typedef struct {
    p_no *adjacencia;
    int n;
} Grafo;

typedef Grafo * p_grafo;

p_grafo criar_grafo(int n);

void destroi_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);

void remove_aresta(p_grafo g, int u, int v);

int tem_aresta(p_grafo g, int u, int v);

void imprime_arestas(p_grafo g);

```

# Multigrafos 
* Problema: 7 pontes de kaliningrado 

* podemos ter arestas paralelas ou múltiplas 
* ao invés de um conjunto de arestas, temos um multiconjunto 
* pode ser representada por lista de adjacência


# Comparação Matriz x Lista 

|                      | Matriz     | Listas           |
|----------------------|------------|------------------|
| Armazenamento        | O(\|V\|^2) | O(\|V\| + \|E\|) |
| Inserir              | O(1)       | O(1)             |
| Remover              | O(1)       | O(d(v))          |
| Aresta existe?       | O(1)       | O(d(v))          |
| Percorrer vizinhança | O(\|V\|)   | O(d(v))          |


* As suas permitem representar grafos, digrafos e multigrafos, mas multigrafos é mais fácil com listas de adjacência

* Qual usar? 
    * Depende das operações que vou precisar e se o grafo é esparso (trade-offs, balancear prós e contras)

### Importância dos grafos 
* grafos são amplamente usados na computação e na matemática para a modelagem de problemas:

* Redes sociais: representar uma relação

* Mapas: cidades como grafos e  menor caminho como arestas  

* Páginas na internet: links são arcos de uma página para a outro - podemos ver qual é a página mais popular 

* Redes de computadores: a topologia de uma rede de computadores é um grafo 

* Circuitos eletrônicos: podemos criar algortimos para ver se há curto-circuito por exemplo 

