/*
Exemplos: ana, ovo, arara, osso, radar

É igual de trás pra frente 
*/

/**Devolve 1 se palavra for palíndromo
 * e 0 caso contrário
 * */

#include <stdio.h>
#include <stdlib.h>

/* Devolve 1 se a substring palavra[i...j] 
* for palindrimo e 0 caso contrario
*/

int eh_palindromo(char *palavra, int i, int fim)
{
    if (fim <= i) //fim é menor na str vazia e igual qdo tem uma letra
    {
        return 1;
    }
    else{
        if (palavra[i] == palavra[fim] && eh_palindromo(*palavra, i + 1, fim - 1);)
    }
        
}

int main()
{
    char palavra[20];
    scanf("%s", palavra);
    if (eh_palindromo(palavra, 0, 19))
    {
        printf("É palíndromo!\n");
    }
}