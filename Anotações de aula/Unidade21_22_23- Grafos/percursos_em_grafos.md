# Caminhos em grafos 

## Grafo de Petersen

Um caminho se s para t em um grafo é:

![Grafo de Petersen](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Petersen1_tiny.svg/200px-Petersen1_tiny.svg.png)

* uma sequência sem repetição de vértices vizinhos 
* começando em s e terminando em t 
* v_0 = s e v_k = t
* {v_i, v_{i+1}} é uma aresta para todo 0 =< i > k-1
* v_i != v_j 

## Componentes Conexas 
* um grafo pode ter várias partes

## Ciclos em Grafos 
* uma sequência de vértices vizinhos sem repetição exceto pelo primeior e último vértices que são idênticos

Exemplos:
* 5, 6, 7, 8, 6 é ciclo 
* 1, 2, 3 não é ciclo 
* 1, 2, 7, 6, 1, 0 ,1 não é ciclo, pois há arestas repetidas

## Árvores, Florestas e Subgrafos

* Uma **árvore** é um grafo **conexo acíclico** (no máximo uma componente conexa)
* Uma **floresta** é um grafo **acíclico** (olhando para uma componente conexa, temos uma árvore, ou seja, uma floresta é um conjunto de árvores)

* Um **subgrafo** é um grafo obtido através da remoção de vértices e arestas
    *Podemos considerar tambḿe árvores/florestas que são subgrafos de um grafo dado  

