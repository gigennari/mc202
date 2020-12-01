# TAD - Conjuntos Dinâmicos 

## Operações Básicas
* inserir elemento
* remover elemento
* buscar elemento 

Dependendo do TAD, há uma maneira de diferente de fazer a inserção e remoção

|                               | vetor | lista ligada | abb balanceada |
|-------------------------------|-------|--------------|----------------|
| inserir                       | O(1)  | O(1)         | O(lg n)        |
| remover (se conheço elemento) | O(1)  | O(1)         | O(lg n)        |
| buscar                        | O(n)  | O(n)         | O(lg n)        |
|                               |       |              |                |


## Problema: númeor de ocorrências de cada palavra da biblioteca 
* português: 435.000 palavras
* mas, no total da nossa contagem, há milhões de ocorrências

### Usando um tad errado
* lista ligada simples
* olhar ``` palavras_tad_errado.c ```

Casos de teste:
* 1º caso de teste: 10 100 --> real    0m0,001s
* 2º caso de teste: 100000 72000 --> real    0m1,464s
* 3º caso de teste: 100000 720000 --> real    3m13,638s

* 86micro segundos

(testes criados com ``` criar.py``` na pasta)

### Estimativa para contar a biblioteca da unicamp 

10^6 livros * 72 * 10^3 palavras/livros * 5* 10^6 acessos/palavras * 2* 10^-9 segundo/acesso = 720*10^6

* Ou seja, levaria 22 anos 

* Se usassemos uma ABB balanceada, sairíamos de alguns anos para alguns meses

* Será que conseguimos fazer com O(1)?

# Hash Table - Tabela de Espelhamento 

### Caso fácil:
* se cada palavra começasse com uma letra distinta
* bastaria associar a letra à posição do vetor (a0, b1, c2...)

### Palavras que começam com a mesma letra
* para cada posição no vetor, criamos uma lista 
* se a palavra começa com a fica na lista de v[0]
* se a palavra começa com b fica na lista de v[1]
* e assim por diante

* quando a lista ainda é nula, basta inserir a palavra 
* e se a lista já tem um elemento?
* se inseríssemos na ordem que lemos, a tabela é degenarada em lista, pois ainda teríamos que percorrer todas as palavra com aquela inicial para achar a palavra 

## Espalhamento com Encadeamento Separado 
* para corrigir: espalhar melhor as palavras entre os índices do vetor
* para isso, vamos usar um hash da chave (palavra) 
* associamos a chave a um número inteiro

Uma **função de hashing** associa:
    * um elemento de um conjunto (strings, numeros)
    * a um número inteirio 

Uma **tabela de espelhamento** é um TAD para conjuntos dinâmicos:
    * dados acessados por meio de um vetor de tamanho conhecido 
    * a posição do vetor é calculada por uma função de hashing 


**Restrições**:
* estimativa do tamanho do conjunto de dados dever ser conhecida
* conhecer os bits da chave 
    * em uma ABB, basta uma função de ocmparação 

Tempo das operações:
* depende da função de hashing escolhida 
* chaves bem espalhadas: tempo quase O(1)
    * se temos n itens e uma tabela de tamanho M, tempo de acesso é o tempo de calcular a função de hashing O(n/m)

* chaves muito agrupadas: pior caso de tempo O(n)

### Uma boa função de hashing 
* a probabilidade de uma chave ter um hash específico é aproximadamente 1/M
* ou seja, esperamos que cada lista tenha n/M elementos

# Métodos genéricos 
* divisão e multiplicação 

* **Hashing perfeito**: se conhecermos todas as chaves a priori, é possível encontrar uma função de hashing injetora 
    * isto é, não temos colisões 
    * funções difíceis de encontrar

### Interpretando chaves
* pressuposmos que as chaves são números inteiros
* se não forem (string, por exemplo), reinterpretamos a chave como uma sequência de bits 

* para uma palavra, somamos o valor da tabela ASC de cada caractere
    * "bala" --> 1.650.551.905
    * o número pode explodir rapidamente, então devemos corrigir isso 

## Método da divisão
* obtemos o resto da divisão pelo tamanho M do hashing 
* h(x) = x mod M

* bala = 1.650.551.905 mod 1783 = 277

    ### Escolhendo M:
        * não é uma boa ideia escolher M como uma potência de 2, pois os últimos digitos são ignorados (considera bits menos significativos)
        * normalmente escolhemos M como um número prim longe de uma potência de 2 

### Para strings:

x = 'b'* 256^3 + 'a'* 256^2 + 'l'*256^1 + 'a' * 256^0
x = ((('b') 256 + 'a') * 256 + 'l') * 256 + 'a'

Mas x poderia ser um número muito grande, então, ao invés de calcular x mod M, calculamos 

((('b'mod M)* 256+ 'a' mod M)*256 + 'l'mod M) * 256 + 'a' mod M

## Método da multiplicação 

* multiplicamos por um certo valor real A e obtemis a parte fracionária 
* escolhemos A convenienye (número áureo) --> A = (sqrt(5) - 1) / 2
    * resto tem que ser diferente de 0 
    * número transcendental não tem múltiplos e divisores bem definidos
    * O uso da razão áurea como valor de A é sugestão de Knuth 
* posição relativa no vetor não depende de M (pode ser M = 1024, potência de 2)

**h(x) = [M(A*x mod 1)]**

* número entre parenteses vale entre 0 e 1 
* [] ignora parte fracionária, pega piso 

Exemplo:
h("bala") = [1024 * [((sqrt(5) - 1) / 2 * 1.650.551.905) mod 1]]
= [1024 * 1020097177,4858876 mod 1]
= [1024 * 0,4858876] = 497

* 497 vai ser o índice que contém a lista na qual a palavra bala deve ser inserida 

## Quebrando um programa que usa hashing
* Pode prejudicar o programa se inserir muitos elementos com o mesmo hash
* Para nos porteger de um adversário malicioso, podemos escolher uma função de hashing aleatória 

### Uma boa função de hashing aleatória 
* fixe p um primo maior do que M 
* escolha a que pertence a {1, ..., p} e b que pertence a {0,...,p}
* defina h_{a,b}(k) = = ((ak+b)mod p)mod M
* sabemos que a função espalha bem
    * probabilidade de colisão é no máximo 1/M
    * hashing universal 

# Endereçamento aberto 
* existe uma alternativa para a implementação de tabela de espalhamento 
* alocação dinâmica é muito mais lenta do que alocação estática na pilha 
* queremos evitar a todo custo dar malloc, diferentemente do jeito que vimos anteriormente, onde cada chave recebia um malloc para o nó da lista ligada 

O endereçamento aberto:
* os dados são guardados no próprio vetor (única chamada para malloc)
* colisões são colocadas em posições livres da tabela 

Características:
* evita percorrer usando ponteiro e alocação e desalocação de memória 
* se a tabela encher, deve recriar uma tabela maior e reindexar os elementos da tabela e mudar a função de hashing 
* a remoção é mais complicada

## Com sondagem linear 

### Inserir: 
    * procuramos posição; 
    * se houver espaço, guardamos;
    * senão, procuramos a próxima posição livre (modulo M)

### Busca: 
    * calcula o índice do hash 
    * percorrer a tabela em sequência, a partir do índice, procurando pela chave 
    * se encontrar, devolvo
    * se encontrar um espaço vazio, devolvo NULL, porque o elemento já deveria estar no índice dele ou antes de um outro vazio 
    * o que é um espaço vazio em um vetor? é um valor não incializado?
        * se for um vetor de ponteiros, pode ser NULL
        * se não for, precisa ser ume elemento dummy 
        *passe por cima de itens removidos 
        * pare ai encontrar uma posição vazia

### Remoção 
    * não podemos apenas remover os elementos da tabela, pois vai surgir um espaço vazio que não era p estar vazio 
    * então marcamos aquela posição com uma flag de que a posição já foi ocupada para não falhar a busca 
    
## Hashing duplo
* É como a sondagem linear 
* estratégia mais geral para lidar com conflitos 
* ao invés de saltarmos sepre de 1 em 1, slatamos de hash2(k) em hash2(k), onde hash2 é uma segunda função de hashing 

**h(k,i) = (hash1(k) + i*hash2(k)) mod M**

* Busca pula de hash2 em hash2

Cuidados:
    * hash2 não pode ser 0
    * hash2 precisa ser coprimo com M
        * garante que as sequências são longas

Sugestão:
* escolha M como uma potência de 2 e faça que hash2 seja sempre ímpar
* escolha M como um num primo e hash2 < M


## Sondagem linear
* Número de acessos médios por busca

| n/M         | 1/2 | 2/3 | 3/4 | 9/10 |
|-------------|-----|-----|-----|------|
| com sucesso | 1.5 | 2.0 | 3.0 | 5.5  |
| sem sucesso | 2.5 | 5.0 | 8.5 | 55.5 |

## Hash Duplo
* Número de acessos médios por busca
| n/M         | 1/2 | 2/3 | 3/4 | 9/10 |
|-------------|-----|-----|-----|------|
| com sucesso | 1.4 | 1.  | 1.8 | 2.6  |
| sem sucesso | 1.5 | 2.0 | 3.0 | 5.5  |


