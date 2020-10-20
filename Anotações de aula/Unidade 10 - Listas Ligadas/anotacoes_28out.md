# Listas Ligadas

* alocamos memória confome o necessário 
* guardamos um ponteiro para a estrutura em uma variável 
* o primeiro **nó** aponta para o segundo, o segundo para o terceiro, e assim por diante
* o **último ponteiro** aponta para **null**

## Nó
* nó, node, box, caixa
* elemento alocado dinamicamente que contém:
    - um conjunto de dados
    - um ponteiro para outro nó

## Lista ligada:
* conjunto de nós ligados entre si de maneira sequencial 
* acessada a partir de uma variável local da pilha 
* um ponteiro pode estar vazio 

![criando uma nova lista](./imagens/listasligadas.png)

# Vetores vs listas ligadas

acesso a posição k:
    - v: O(1)
    - ll: O(k) - precisa percorrer a lista

inserção na posição 0:
    - v: O(n) - precisa mover itens para a direita
    - ll: O(1)

remoção da posição 0:
    - v: O(n) - precisa mover itens para a esquerda
    - ll: O(1)

uso de espaço:
    - v: provavelmnete desperdiçará memória
    - ll: não desperdiçã memória, mas cada elemento consome mais memória por causa do ponteiro

Na maioria das vezes compensa utilizar um vetor dinâmico. A lista do python é o que chamamos de vetor dinâmico em C.

