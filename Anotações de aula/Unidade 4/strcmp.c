/*
Exemplos do uso de strcmp copiado de http://linguagemc.com.br/a-biblioteca-string-h/
*/

#include <stdio.h>
#include <string.h>//necessário para strcmp

int main (void)
{
    char str1[10] = "Emanoel";
    char str2[10] = "Tiago";
    int retorno;
    
    retorno = strcmp(str1, str2);
    printf("retorno = %d\n", retorno);
    //mostra o retorno da função strcmp  
    
    return 0;
}