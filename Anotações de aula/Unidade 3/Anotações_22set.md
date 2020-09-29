# STRINGS/CARACTERES

## Cifra de César
* forma de criptografia
* dado um parâmetro k, cada letra é trocada pela k-ésima letra após ela 

* tipo: **char** com carctere ASCII
    -nº inteiro, 8 bits (-128;127)
    -podemos somar, subtrair, multiplicar e dividir
    -aspas simples --> 'a' 'b' 
* como ler e imprimir (scanf/printf): %c
    -printf(letra: %c, código: %d, 'a', 'a')
    -imprime: letra: a, código: 97
* como converter as letras de maneira prática:

### ASCII
* 0-31: caracteres de controle 
* 32 a 126: caracteres
* obs: não tem acento
* \t (9- tab) e \n (12- quebra de linha)

## Operações

* não existe bool 
    -0 é falso
    -outros valores, verdadeiro

* comparação: <,  >, >=, <=, =

## String: um vetor de chars

e x e m p l o \0 l i x o
12 posições
str exemplos tem 7 carateres

* str termina em \**\0**

## Biblioteca string.h

strlen
strcmp --> comparar lexicograficamente
strcpy - copia str
strcat - concatena duas strs
