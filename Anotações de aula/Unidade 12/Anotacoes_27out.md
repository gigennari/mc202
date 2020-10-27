# Filas

* Serve para guardar uma coleção de elemento
* **FIFO** first-in first-out: primeiro a entrar é o primeiro a sair 
* fila de impressão 
* buffer do teclado
* escalonamento de processos 
* comunicação entre aplicativos/computadores


### Operações:
* enfileira (queue): add item no fim 
* desenfileira (dequeue): remove item do início

### Implementação com lista ligada
* lista ligada com um cabeça (início) e uma cauda (fim)
* olhar ```fila.c```

### Implementação com vetor

Primeira ideia:
    * inserimos no final do vetor O(1)
    * removemos do começo O(n)

Segunda ideia:
    * variáveis ini e fim que indicam começo e final da fila 
    * add = aumenta fim 
    * remover = diminui fim

    * quando queremos enfileirar um elemento, mas chegamos ao final da lista, movemos os elementos para a esquerda 
    * diferença para lista ligada: há uma CAPACIDADE máxima para um vetor 

Terceira ideia
    * variáveis ini e fim 
    * ao chegar ao final do vetor, começa a preencher ele de novo do começo - **fila circular** 
    * posição + 1, tira o resto por 10, dá a posição seguinte

* olhar ``` fila_vetor.c ```

# Pilhas
* remove primeiro objetos inseridos há menos tempo
* **LIFO** last-in first-out: o último a entrar é o primeiro a sair
* pilha de pratos  
* balanceamento de parenteses: linguagens de programação, expressões matemáticas, html
* cálculo e conversão de notações
* percurso de estruturas de dados complexas (grafos)
* recursão

### Operações 
* Empilha (push): add no topo da pilha 
* Desempilha (pop): remove do topo da pilha 

### Implementação com vetor 
* olhar ``` pilha_vetor.c ```

### Implementação com lista ligada
* olhar ``` pilha_listas_ligadas.c ```