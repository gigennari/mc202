/*
casa/0
strlen conta caracteres antes do /0, mas como a string começa em 0, subtrai 1
i começa em 3 (letra a do casA)
vai do final para o começo

k começa em zero 
vai do começo para o final 

*/

#include <stdio.h>
#include <string.h>
#define TAM_MAX 10

void inverte_string(char *palavra, char *inverso)
{
    int k = 0;
    for (int i = strlen(palavra) - 1; i >= 0; i--, k++)
    {
        inverso[k] = palavra[i];
    }
    inverso[k] = '0';
}

int main()
{
    char palavra[TAM_MAX];
    char inverso[TAM_MAX];

    scanf("%s", palavra);
    inverte_string(palavra, inverso);
    printf('\n');
}