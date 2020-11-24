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

* trocar v[0] com o mínimo de v[0] a v[n-1]
* trocar o v[1] com o mínimo de v[1] a v[n-1]
* e assim por diante 


* **O(n²)**

## Selection com heap 
* Podemos usar um max heap para encontrar o máximo em o(log n)
* Assim, nosso tempo de execução passaria de O(n²) para O(n log n)
* Para isso, criamos um vetor adicional para o heap, mas podemos transformar um vetor em um heap rapidamente

## Vetor para Heap 
* olhar para o vetor como uma árvore binária completa --> todos os níveis estão cheios, e, no último nível, os nós estão deslocados para a esquerda 
* os últimos dois elementos do vetor não têm filhos 

* filho esquerdo **v[2*i+1]** 
* filho direito **v[2*i+2]** 
*  pai **v[(i-1)/2]**
    

# Heap Sort
* O(n logn)