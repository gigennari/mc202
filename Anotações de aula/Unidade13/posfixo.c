/*
Cálculo de expressão pós e pré fixa

infixa


pré fixada

pós fixada
2 2 1 + 4 * 1 + *

coloca na pilha 
+
1
2
2
pega os dois anteriores e soma --> 2 + 1 = 3; atualiza pilha 
*
4
3
2
pega os dois últimos e multiplica --> 4 * 3 = 12
+
1
12
2
pega os dois últimos e multiplica --> 1 + 12 --> 13
*
13
2
pega os dois últimos e multiplica --> 2 * 13 = 26
26

Temos o resultado na pilha

*/

#include <stdio.h>
#include <stdlib.h>

