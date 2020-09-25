#Problema: Como achar o centroide de um conjunto de pontos?

*Podemos criar um tipo, uma estrutura e registros

*O comando **typedef** 

#Tipo Abstrato de Dados - TAD

*conjunto de valores associado a um conjunto de operações permitidas
    -Interface: conjunto de operações de um TAD
    -Implementação: conjunto de algoritmos que realizam as operações
    -Cliente: código que utiliza/chama uma operação

*Em C:
    -um TAD é declarado como uma **struct**
    -a interface manipula a struct

##Compilação por partes (Usar makefile)
*cliente: cliente.c --> cliente.o
*implmentação --> complexos.h --> complexos.o
*linkagem entre cliente.o e complexo.o