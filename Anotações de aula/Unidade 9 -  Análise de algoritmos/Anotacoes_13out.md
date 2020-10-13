# Noções de Eficiência de Algoritmos (Complexidade)

Devemos analisar o pior caso do algoritmo

## Busca sequencial e consumo de tempo
* Entrada: vetor 
* Saída: a posição de um valor no vetor 

Depende: 
* da posição de x no vetor 
    - melhor caso: 1ª posição
    - pior caso: última ou não está no vetor)
* do tamanho do vetor (10 X 10000)

```C
int busca(int *v, int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (v[i] == x)
            return i;
        return -1;
    }
}
```

### Quantas instruções esse algoritmo tem?
* linha 2: tempo c2 (declaração de variável)
* linha 3: (n+1) * tempo c3 (atrbuiçãoes, acessos e comparação) --> condição do if falha na execução n+1
* linha 4: n * tempo c4 (condicional)
* linha 5: tempo c5 (acesso e return)
* linha 6: tempo c6(return)

Quando a 5 é excutada, a 6 não é e vice-versa. Mas vamos analisar por cima.

```
Tempo = c2 + (n+1) c3 + n c4 + c5 + c6
```

Considerando que c_i não depende de n, apenas do computador, ela leva um tempo constante.

Seja a = c2 + c3 + c5 + c6, b = c3 + c4 e d = a + b

Se n>=1, 
c2+c3(n+1)+c4 * n+c5+c6 = c2+c3+c5+c6+(c3+c4) * n = a+b*n

```
**a+b * n <= a * n + b * n = d * n**
```

**Ordem de n**: De modo geral, o tempo de execução é linearmente dependente do tamanho da entrada - f(n) = n.
c2 + (n+1) c3 + n c4 + c5 + c6 = O(n)



## Busca Binária
* Busca ordenada
*Entrada: um vetor de números em ordem crescente
*Saída: posição de um valor no vetor

```C
int busca_binaria(int *dados, int l, int r, int x){
    int m = (1 + r) / 2;
    if (l > r)
        return -1;
    if (dados[m] == x)
        return m;
    else if (dados[m] < x)
        return busca_binaria(dados, m + 1, r, x);
    else
    return busca_binaria(dados, l, m - 1, x);
        
}

```

### Ordem

| n | # chamadas |  
|---|------------|
| 0 | 1          |     
| 1 | 2          |     
| 2 | 3          |  
| 3 | 3          |   
| 4 | 4          |   
| 5 | 4          |      
| 6 | 4          |    
| 7 | 4          |   
| 8 | 5          |   
|t-1| n/2^(t-1)  |


1ª chamada: vetor com tamanho n
2ª: n/2
3ª: n/4
4ª: n/8
5ª: n/16

Enquanto n = r-l+1 for maior que 0,
A cada chamada, n é divido por 2

**n/ 2^(t-1) --> vetor vazio**

Só paramos em n/2^t < 1 <= n/ 2^(t-1)
Multiplicando por 2^t,
n < 2^t <= n/2n
Aplicando log,
log_2 (2^t) <= log_2 (2n)

t <= log_2 (2) + log_2 (n)

Ou seja, t <= 1 + log_2 (n)

**Ordem de n**: O(lg n)


# Comparações 

## Primeira ideia
* Comparar funções verificando se **f(n) <= g(n)** para **todo** n
* 10n > n^2 para n < 10
* Para n suficientemente grande, n^2 > 10n


## Segunda ideia 
* Comparar funções verificando se **f(n) <= g(n)** para **n>=n_0** 
* ignorar constantes e termos menos importantes

n + 5
n
5n/4

# Notação Assintótica
* Dizemos que **f(n) = O(g(n))** se
    - existe uma cte c 
    - existe uma constante n_0

tal que 

**f(n) <= c*g(n)** 

para todo n >= n_0, com n suficientemente grande.

Se g(n) já é maior do que f(n), basta escolher c = 1.

Exemplos:
* Constante
1 = O(1)
1000000 = O(1)
Ex: atribuição e leitura de variável, operações aritméticas, comparações, operadores booleanos, acesso a uma posição de vetor

* Linear
5n + 2 = O(n)
    - quando n dobra, o tempo dobra
Ex: busca linear, econtrar máximo/mínimo de um vetor, produto interno de dois vetores

* Quadrático
5n^2 + 5n + 2 = O(n^2)
    - quando n dobra, o tempo quadruplica
Ex: bubble sort, slecrion sort, insertion sort

* Cúbico
n^3 + 10 = O(n^3)
    - quando n dobra, o tempo octuplica 
Ex: multiplicação de matrizes

* Logarítmico
log_2(n) = O(log(n))

log n/ log 2 = (1/log 2) * log n
OU seja, (1/log 2) é uma constante 

    - todos os logaritmos tê, a mesma ordem de grandeza; não depende da base
    - lg indica log_2
    - quando n dobra, o tempo aumenta em uma constante 

Ex: busca binária

* O(n lg n):
    - quando n dobra, o tempo um pouco mais que dobra
Ex: algoritmos de ordenação que veremos

