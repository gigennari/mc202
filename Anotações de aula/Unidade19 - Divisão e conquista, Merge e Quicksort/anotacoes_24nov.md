# Ordenação 

| Algoritmo | MergeSort                 | QuickSort               |
|-----------|---------------------------|-------------------------|
| Divisao   | -                         | particionamos o vetor   | 
| Recursao  | resolvemos subproblemas   | resolvemos subproblemas |   
| Conquista |intercalamos os subvetores | -                       |    
   

## Estratégia: recursão

* Como ordenar a primeira metade do vetor?
    * usamos uma função ``` ordenar(int *v, int l, int r)```
    * ordena o vetor das posições l a r (inclusive)
    * poderia ser um dos algoritmos vistos anteriormente
    * mas faremos algo mais simples e melhor

* executamos ordenar(v, 0, 4);

* para a segunda metade, executamos ordenar(v, 5, 9);

Supondo um vetor com suas duas metades já ordenadas, basta ir comparando início com início e ir inserindo em um vetor 

## Intercalando 
* percorremos os dois subvetores
* compara e acha mínimo 
* insere mínimo em vetor auxiliar 

* quando um subvetor acaba, basta copiar o restou no outro subvetor 

# Divisão e Conquista 
* a recursão parte do princípio de que é mais fácil resolver problemas mais simples 

* divisão: quebramos o problema em subproblemas menores
* combinaos  a solução dos problemas menores (iterativo)

# MergeSort
* os dois subvetores estão armazenados em v
    * o 1º de l até m
    * o 2º de m+1 até r 
* precisamos de um vetor auxiliar do tamanho do vetor 
* vamos considerer que o amior vetor tem tamanho MAX

```C

//ordena
void mergesort(int *v, int l, int r){
    
    int m = (l+r) / 2;
    //divisão
    mergesort(v, l, m);
    mergesort(v, m+1, r);
    //conquista
    merge(v, l, m, r);
}

void merge(int *v, int l, int m. int r)
{

    // intercala
    int aux[MAX];
    int i = l, j = m+1, k = 0;
    while(i <= m && j <=r)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    
    // copia o resto do subvetor que não terminou 
    while(i <= m)
    {
        aux[k++] = v[i++];
    }
    while(j <= r)
    {
        aux[k++] = v[j++];
    }

    //copia de volta para v
    for(i = 1, k = 0; i<= r; i++, k++){
        v[i] = aux[k];
    }

}

```

* Nº de comparações: no máximo, n = r - l + 1
* As chamadas da função mergesort podem ser desenhadas como uma árvore

# QuickSort

* escolhemos um pivô
* colocamos 
    * os elementos menores que o pivô na esquerda 
    * oc elementos maiores que o pivô na direira
* o pivô está na posição correta 
* o lado esquerdo e o direito podem ser ordenado independentemente
* olhar ``` quicksort.c ```


```C
//devolve inteiro índice do pivô 
int partition(int *v, int l, int r){
    int i, pos = r + 1;
    //escolhe pivô
    int pivo = v[1];
    
    //coloca menores à esquerda e maiores à direta 

    for (i = r; i >= 1; i--){
        if(v[i] >= pivo){
            pos--;
            troca(&v[i], &v[pos]);
        }
    }

    //devolve poisção final do pivô 
    return pos;
}

void quicksort(int *v, int l, int r){
    int i;
    if(r <= l){
        return;
    }
    i = partition(v, l, r);
    quicksort(v, l, i-1);
    quicksort(v, i+1, r);
}
```

* Pior Caso: considerando o pivô como o primeiro elemento, se o pivo for o menor elemento de todos, vamos ter apenas um subvetor. (Funciona como bubblesort).

* **O(n²)**

* Se o vetor for uma permutação aleatória de n números, entao o tempo médio do QuickSort é O(n log n)

## Mediana de Três
* No quicksort, escolhemos como pivô o elemento da esquerda
* Poderíamos escolher a mediana dos elementos da esquerda, do meio e da direita 

* É o melhor

## Aleatório
* escolher pivô aleatoriamente

# Comparação Assintótica dos Algoritmos de Ordenação 

![Comparação Assíntótica]{https://ibb.co/d7zRTQX}