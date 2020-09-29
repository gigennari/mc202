# PONTEIROS

* Toda variável tem um endereço de memória
* Cada posição de um vetor ou membro de um registro também tem um endereço

* Um **ponteiro** é uma **variável que armazena um endereço** 

##Registro: 
```C
typedef struct Aluno{
    char nome[30];
    int ano;
}aluno;
```
## Arquitetura de Von Neumann
!(https://lh3.googleusercontent.com/proxy/u9HgDspS3yjcDlPJtUjHCUsaEauACFpjHUPjl3PTu1xO4jPpR9HnlBlso-JOYItVrfqoox087nZbDnr9inMTahDT4gLaUBII3gNxQSQtuUriRGWrjLYz)

* Ram - código do programa, dados transformados
* CPU - registradores, operações, 32bits
* cada variável tem uma posição na memória

## Ponteiro: variável apontadora

* o endereço de uma variável também pode ser armazendo em uma variável, que também tem um endereço

- int *p --> declara ponteiro para inteiro
- double *q --> declara ponteiro para double
- char *c
- struct data *d

# Operações Básicas com ponteiros 

* & retorna endereço de memória de uma variável ou posição de um vetor 
    -&x
    -&v[i]
    -&data.mes
    -p = &x
* \* acessa o conteúdo do ponteiro
    - *p onde p é ponteiro
    - x = *p


* int v[100] é alocado estaticamente
* v == &v[0] --> aponta para o primeiro int do vetor

* nós alocamos e liberamos a região de memória --> do tamanho que desejarmos 

## sizeof, malloc e free

* sizeof(int) --> no geral, 4 bytes
* sizeof(struct data)

* malloc aloca dinamicamente a qtde de bytes informada
```C
v = malloc(10 * sizeof(int));
```

* free libera a região na memória alocada dinamicamente

## Aritmética de ponteiros 

* somar ou subtrair
    - somar 1 em um ponteiro para int faz com que o endereço pule sizeof(int) 
* incremento ou decremento

## Ponteiro e vetores

* Se tivermos um ponteiro p, podemos escrever p[i], como se fosse um vetor. É o mesmo que escrever *(v + i) --> iésimo elemento de p

# Organização da Memória

* Pilha: onde são armazenadas as variáveis
* Heap: onde são armazenados outros dados (tamanho da memória RAM disponível)

## Alocação estática
* o compilador reserva espaço
* acessada por um nome bem definido 
* espaço é liberado quando a função termina 
* não é possível devolver uma variável 

## Alocação Dinâmica
* malloc reserva númeor de bytes no heap
* guardar o endereço da variável com um ponteiro
* espaço deve ser liberado usando free
* alocação dinâmica permite devolver a variável 

## Recita para alocação dinâmica de vetores

* Incluir a biblioteca stdlib.h
* 
