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

### Espalhamento com Encadeamento Separado 
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

## Métodos genéricos 
* divisão e multiplicação 

* **Hashing perfeito**: se conhecermos todas as chaves a priori, é possível encontrar uma função de hashing injetora 
    * isto é, não temos colisões 
    * funções difíceis de encontrar

## Interpretando chaves
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

Ao invés de calcular x mod M, 

x = 'b'* 256^3 + 'a'* 256^2 + 'l'*256^1 + 'a' * 256^0
x = ((('b') 256 + 'a') * 256 + 'l') * 256 + 'a'



## Método da multiplicação 

