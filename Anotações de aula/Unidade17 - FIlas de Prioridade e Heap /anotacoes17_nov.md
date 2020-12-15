# Fila de Prioridades 

## Operações básicas
* inserir um novo elemento 
* remover o elemento com maior ou menor chave (prioridade)
* supomos que todos os elementos têm prioridades distintas

* uma **pilha** é como uma **fila de prioridades**:
    * elemento com maior chave é sempre o último

* uma **fila** é como uma **fila de prioridades**:
    * o elemento com maior chave é sempre o primeiro inserido 

* fila de prioridade é uma generalização desses duas estruturas


# Implementação com vetor 

## Funções

```C


typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct {
    Item *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;

void troca(int *a, int *b); 

p_fp criar_filaprio(int tam);

void insere(p_fp fprio, Item item);

Item extrai_maximo(p_fp fprio);

int vazia(p_fp fprio);

int cheia(p_fp fprio);

```

##= Implementação com Árvores Binárias Completas

* uma árvore binária é uma estrutura hierarquica em que cada nó tem 2 subconjuntos associados
* uma árvore binária é dita completa se:
    * todos os níveis, exceto o último, estão cheios
    * os nós do último nível estão o mais à esquerda possível 
    
* quantos níveis tem uma árvore binária completa com n nós?
    * 1 <= n <= 1 --> 1 nível  
    * 2 <= n <= 3 --> 2 nível  
    * 4 <= n <= 7 --> 3 nível  
    * 8 <= n <= 15 --> 4 nível  

    Note, portanto, que numero_niveis = log2(n+1) arrdonda p cima --> O(log(n))

* Como sabemos que pra preencher uma árovore completa sempre preenchemos na ordem, da esquerda para a direita, não precisamos uar nós para preencher essa árvore. 
* Basta ir add em um vetor

## O que cada nó será no vetor

![Desenho]{https://ibb.co/By9RZJB}

* Genericamente, em relação a v[i]

    * filho esquerdo é **v[2*i+1]** --> valor ímpar
    * o pai do filho esquerdo é **v[(i-1)/2]**
    * filho direito é **v[2*i+2]** --> valor par
    * o pai do filho direito é **v[(i-2)/2]** -> podemos usar a mesma fórmula do filho esquerdo, pois a divisão é inteira em C

* Como saber que um nó não tem filho direito ou esquerdo?
    * verificar se a posição calculada existe no vetor 

## Max Heap 

* as chaves dos filhos são menores ou iguais ao pai 
* ou seja, a raiz é o máximo 

* se percorremos a árvore em ordem de largura (não de profundidade), teremos a ordem do vetor 
* note que não é uma árvore binária de busca 
* estamos interessados apenas no máximo

### Inserção 
* cuidado na hora de inserir, pois uma chave nunca pode ser maior que o pai 
* se o número inserido na última posição for maior que sei pai, troca ele com o pai até o pai ser maior 

### Extraindo o máximo 
* trocamos a raiz com o último elemento do heap 
* descemos no heap arrumando 
    * trocamos com o maior dos dois filhos 

### Mudando a prioridade
* se **aumentar**, sobe no heap 
* se **diminuir**, desce no heap

### Posição do item no heap 

1) Alteramos a struct heap 
* criamos um vetor de n posições
* esse vetor armazena a posição do item no heap
* em O(1) encontramos a posição do heap 
* atenção, todas as funções devem ser modificadas para alterar esse vetor quando alteramos a posição de itens 

2) Atribuir um id na struct item e ir alterando 

3) Estrutura de dados para encontrar o id rapidamente, como ABBs ou tabela de Hashing 


