/*
Funções extremamente inseguras: nunca usar no mundo real, só nas tarefas
para entradas válidas

Uma entrada maliciosa pode sobreescrever seu programa e instalar vírus

Jeito correto: fgets(texto, MAX, stdin);

%s
Lê apenas a primeira palvras, antes do primeiro espaço

caractere por caractere
*/

#include <stdio.h>
#define MAX 10

int main() {
    char string[MAX];
    char lido;
    int i = 0;

    scanf("%s ", string);
    printf("Lendo com %%s: \"%s\"\n", string);

    do {
        scanf("%c", &lido);
        string[i] = lido;
        
    }
}