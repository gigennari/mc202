#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome1[] = {'g', 'i', '\0', 'g', 'e', 'n', 'n', 'a', 'r', 'i', '\0', 'j', 'u','n','g','k', 'l','a','u','s', '\0', '\0', 'a', 'b', 'c', 'i', 'u'};
    


    for(int i = 0; i < 27; i++){
        
        printf("%c", nome1[i]);
        if (nome1[i] == '\0' && nome1[i+1] == '\0'){
            break;
        }
    }
    printf("%c", '\n');

    printf("%s", nome1);
    printf("%c", '\n');
}