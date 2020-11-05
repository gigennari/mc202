# Árvores Binárias

```Def: árvore binária é ou um conjunto vazio ou um nó com duas subárvores; é uma estrutura hierarquica
```

* pai -> filho dir ou esq -> neto dir ou est
* cada nó pode ter 0, 1 ou 2 filhos
* 0 -> terminal ou folha 
* podemos relacionar os nós:
    * descendentes
    * ancestrais 
    * irmão 
    * tio 
* subárvore esquerda e direita 
* nº níveis = altura **h**


* ordem dos filhos é relevante 

## Para que servem
* armazenar conjuntos dinâmicos 
* criar hierarquias

* se a altura é **h**:
    * no mínimo, h nós
    * no máximo, N = 2^0 + 2^1 + ... + 2^(h-1) = **2^h - 1** 

* se a árvore tem n >= 1 nós, qual a menor altura?
    * n =< N = 2^h - 1
    2^h >= n+1
    **h = log2(n+1)**

## Implementação 
1. 
![Árvore](https://ibb.co/nb9bhVg)

* ruim para identificar pai do nó 


2. 
![Árvore](https://ibb.co/S01BQGJ)

Funções 

```C
typedef struct No{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

p_no criar_arvore(int x, p_no esq, p_no dir);

p_no procurar_no(p_no raiz, int x);

int numero_nos(p_no raiz);

int altura(p_no raiz);
```

Olhar **arvore.c**

## Percorrendo os nós recursivamente

### Pré ordem 
* começa pela raiz 
* depois a subarvore esquerda recursivamente
* depois a direita recur

### Pós ordem 
* esquerda 
* direita 
* raiz 

### Inordem 
* primeira visita a subarvore esquerda
* depois a raiz
* por último a subarvore da direita

### Percurso em profundidade e expressões
![Exemplo](https://ibb.co/cKBg7YC)

* Pré-fixa = / + 7 - - 3 9 ^ * 3 9 2 
* Pós fixa: 7 3 - 9 - + 3 9 * 2
* Infixa: 7 + -3 -9 / 3 * 9 ^ 2

## Percorrendo os nós com pilha 
* condição de parada: **pilha** estar vazia

### Pré-ordem
* armazena esq na pilha, depois direito na pilha 
* quando um nó não tem filhos, tira da pilha e vai p o próxima


## Percorrendo em largura 
* visita os nós por níveis 
* da direita p esquerda 

* processa assim que descobre
* **fila**: quem eu colocar primeiro, sai primeiro (FIFO)
