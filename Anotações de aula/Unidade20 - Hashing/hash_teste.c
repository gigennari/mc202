#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 2000


void hash_string(char *palavra){
    int hash = 0;
    for (int i; i < strlen(palavra); i++){
        hash = (256 * hash + palavra[i]) % M;
    } 
    printf("%d\n", hash);
}

int main(){

    int num_texto;
    scanf("%d", &num_texto);

    for (int i = 0; i < num_texto; i++)
    {
        char palavra[30];
        scanf("%s", palavra);
        hash_string(palavra);
        
    }
    

    return 0;
}