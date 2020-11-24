# Ordenação 

* Entrada: conjunto de dados não ordenado representado como um vetor 

* Saída: vetor ordenado (permutação dos elmentos)

* Vamos ordenar vetores de int, mas é fácil alterar para comparar double ou string ou ainda comparar uma struct por algum de seus campos 


# Bubble Sort
* do fim para o começo, vamos trocando pares de elementos invertidos 
* em algum momento, encontramos o elemento mais leve
* ele será trocado com os elementos que estiverem antes 

```C
void bubblesort(int *v, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) //invariante de laço
    {
        for (j = n - 1; j > 1; j--)
        {
            if (v[j] < v[i])
            {
                troca(&v[j-1], &v[j]);
            }
        }
    }
}

```

* No melhor ou pior caso, o i percorre de 1 a n-2 e o j percorre de n-1 a i+1 para cada laço de i. O que muda é a quantidade de vezes que chamamos a função troca. 

* Pior caso: vetor invertido 
* **O(n²)**

* Para cada combinação de i e j, fazemos uma comparação 
* Muito lento. Leva 1s para ordenar 30000 elementos

# Insertion Sort 

* 
```C
void insertionsort(int *v, int n)
{
    int comparacoes = 0, trocas = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = i; j > 0; j--)
        {
            comparacoes++;
            if (v[j] < v[j - 1])
            {
                troca(&v[j], &v[j - 1]);
                trocas++;
            }
        }
    }
    printf("Comparações = %d\n", comparacoes);
    printf("Trocas = %d\n", trocas);
}
```

* **O(n²)**
* Cerca de 0,2s para ordenar 30000 elementos. É muito lento.  

# Selection Sort 

*

```C


```

* **O(n²)**

# Heap Sort
* O(n logn)