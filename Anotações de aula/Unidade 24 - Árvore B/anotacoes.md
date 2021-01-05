# Árvore B 

* A estrututa mais rápida de busca que imosaté agora é hash (O(1)), mas não podemos usar hash quando a ordem dos elementos importa 

* Objetivo: buscar dados 

## Um problema 

* Um problema: trabalhamos com 1mi  de registros e cada um pode ser muito grande (uma foto, por exemplo). POrtanto, não podemos guardá-los todos na memória Toda vez que executamos um programa, temos que executar cerca de 1000 consultas nesse banco de dados. 

* Onde armazenar os dados? -> disco rígido
* Qual estrutura de dados? -> tentativa: árvore binária de busca balanceada (operação de busca O(log n))

* Árvore binaria 
    * Ler um nó no disco por demorar 5 ms
    * A árvore tem 1mi de nós 
    * A altura de log2(1.000.000) = 20 nós

    * 1000 buscas * 20 nós * 5 ms/nó = 100s

## Hierarquia de Memória 
* HDD (hard disk drive) ou SSD (solid-state drive)
    * memória permanente, onde gravamos arquivos

* RAM (random-acess memory)
    * armazena programas em execução 
    * memória volátil, é apagada se o computador é desligado 

* Fita magnética 

* Memória Cache 
    * muito pŕoxima do processador para ter acesso rápido 
    * info é copiada do ram para a cache 

## Estruturas em Disco e Páginas
* queremos armazenar registros na memória secundária: 
    * memória secundária dividida em páginas
    * se a pág está na memória, podemos acessá-la 
    * se não está, precisamos lê-la na memória secundária (mais lento)
    * ler o menor nº possível de pags 

## Pseudocódigo e leitura/escrita de páginas 

*  Se x é ponteiro para um objeto na memória secundária

```
LeDoDisco(x): lê x da memória secundária

EscreveNoDisco(x): grava x na memória secundária

```
## Árvores M-árias de Busca
* aumentar números de filhos para aumentar a base do log e diminuir o tempo de busca na arvore
* Exemplo: uma árvore ternária (com 0, 1, 2 ou 3 filhos)
    * dois elementos a e b em um nó 
    * esq x <= a 
    * meio a < x <= b
    * dir b < x

# Árvores B
* são árvores M-árias de busca com propriedades adicionais 

## Propriedades 
* cada nó x tem os campos:
    - **x.n** - nº de chaves armazenadas em x
    - vetor ordenado - **x.chave[i]** onde i é a iésima chave armazenada nesse nó 
    - folha indica se x é uma folha ou não 

* x contém **n+1 ponteiros** para novos nós (filhos) 
    - **x.c[i]** é o ponteiros para o i-iésimo filho 
    - se a chave k está na subarvore x.c[i], então
        - k < x.chave[1] se i = 1
        - x.chave[x.n] < k se i = x.n + 1
        - x.chave[i-1] < k < x.chave[i] caso contrário (caso geral)

* árvore T
    - T.raiz indica que o nó é raiz da árvore

* **toda folha está à mesma distância h da raiz**
    - h é a altura da árvore

* existe uma constante **t** que o **grau mínimo** da árvore 
    - todo nó exceto a raiz tem pelo menos t-1 chaves
    - ou seja, cada nó interno tem pelo menos t filhos 
    - todo nó tem no máximo 2t-1 chaves
    - cada nó interno tem no máximo 2t filhos
    



