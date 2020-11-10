# Árvores Binárias de Busca

# Tempo para inserção, remoção e busca 

Usando **listas duplamente ligadas**
* podemos inserir e remover em O(1)
* buscar demora O(n)

Usando **vetores não-ordenados**
* inserir ou remover no conjunto O(1)
    * remove um número e coloca o último no lugar dele 
* busca demora O(n)

Usando **vetores ordenados**
* inserir ou remover O(n)
    * necessidade de mover todo mundo 
* busca binária O(log2(n))

Usando **árvore binárias de busca**
* primeiro uma versão simples
* versão sofisticada: as 3 operações levam O(log2(n))

# Árvores Binárias de Busca (ABB)

* é uma árvore binária em que cada nó contém um elemento de um conjunto ordenável 

Cada nó **r**, com subarvores *

## Operações

```C

typedef struct No{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

p_no criar_arvore();

void destruir_arvore(p_no raiz);

p_no inserir(p_no raiz, int chave);

p_no remover(p_no raiz, int chave);

p_no buscar(p_no raiz, int chave);

p_no minimo(p_no raiz);

p_no maximo(p_no raiz);

p_no sucessor(p_no x);

p_no antecessor(p_no x);

```

### Busca 
* valor buscado tá na raiz
* valor buscado é:
    * menor que raiz --> procura subarvore esquerda 
    * maior que raiz --> procura subarvore direita 
* tempo de busca depende da forma da árvore
    * melhor caso O(lg n)
    * pior caso O(n)


### Remover sucessor 




```C
void remove_sucessor(p_no raiz){
    p_no min = raiz->dir;   //será o minimo da subarvore direita
    p_no pai = raiz;    //pai do nó mínimo
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min){
        pai->esq = min->dir;
    }
    else{
        pai->dir = min->dir;
 
    }
    raiz->chave = min->chave;
}
```
