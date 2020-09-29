# FUNÇÃO 
tipo nome (tipo parametro1, tipo parametro2)    #estaticamente tipada

## Função main
```C
int main() {
    ...
}
```

* Sempre devolve um int
* Se devolver 0, 

## IMPRESSÃO

**printf**

* Imprime uma str na tela 
* Começa e termina com aspas duplas ""
* Aspas simples são difinição de um caractere
* %d --> siginifica % valor int, d é decimal
* %f --> ponto flutuante
* %s --> string 

* A substituição é feita da esq para a dir

Ex: printf("Maior: %d\n", maior);

## LEITURA

**scanf**

* String diz quantos valores serão lidos e os seus tipos 
* Precisa passar o endereço da variável usando operador &
* Ignora espaços em branco, tabs e quebras de linha

Ex: scanf("%d %d", &a, &b);

# INTEIROS

* tipo int - números inteiros 32 bits [-2^31; 2^31 - 1]

## Operações
* \+
* \-
* \*
* / divisão é sempre inteira 8/5 = 1, só devolve float se as entradas são float
* a % b resto da divisão
* +=
* -=
* *=
* /=

a++ ou ++a é +=1

a-- ou --a é +=1

o primeiro devolve o a antes de ser implementado, e o segundo, depois de ser implementados

# BLOCOS
Delimitado por {}, não por identação igual em python, mas a identação ajuda a entender 
A maioria das linhas de instrução terminam em ;

**Protótipo da função** é a função sem o bloco, com a linha terminando com ;

# CONDICIONAIS

**Opções de if**

*if 
*if/else
*if/else if/else

# VARIÁVEIS

A variável precisa ser declarada, no início da função, antes de ser usada
* int i; 
* int i, prod = 1 --> Declara várias variáveis de um mesmo tipo e inicializa prod com valor 1

* **Importante**: variáveis não inicializadas começam com um valor lixo

# LAÇOS

* Não há for ... in igual em python

**Laços em C**

* while (condicao) {...} --> testa e depois executa
* do {...} while (condicao) --> executa e depois testa
* for (inicializacao; condicao; atualizacao) --> a atualização é executada após o bloco


# FORMATAR
Ctrl + Shift + i
