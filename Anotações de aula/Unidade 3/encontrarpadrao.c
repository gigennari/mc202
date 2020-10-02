/*
-verificar se padrão ocorre em uma posição do texto 
-imprimir um trecho do texto
-medir o tamanho de uma string 

*/

#include <stdio.h>


int ocorre(char texto[], int pos, char padrao[])
{   //0 se não ocorre, 1 se ocorre
    int j;
    for (j = 0, padrao[j] != '\0', j++)
    {
        if (texto[pos+j] == '\0') || (texto[pos+j] != padrao[j] && padrao[j] != '*'))
            return 0;   //retorna falso se a posição é espaço ou coringa 
        return 1;  
    } 
}

void imprime(char texto[], int ini, int tam) {
    int j;
    printf("%d: ", ini);
    for (j = 0, j < tam; j++)
        printf("%c", texto[ini+j]);
    printf("\n");
}

int tamaho(char string[]) {
    int i;
    for (i = 0, string[i] != '\0'; i++);
    return i;
}

int main() {
    int i;
    char texto[MAX], padrao[MAX];
    scanf("%s ", padrao);   //espaço serve para ignorar espaços fora do padrão
    fgets(texto, MAX, stdin);   //lê uma linha incluindo espaços
    printf("Procurando por %s no texto: %s\n", padrao, texto);
    for (i = 0; texto[i]!= '\0'; i++)
        if(ocorre(texto, i padrao))
            imprime(texto, i, tamanho(padrao));
    return 0;
}