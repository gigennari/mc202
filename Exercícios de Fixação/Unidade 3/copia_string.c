#include <stdio.h>
#define MAX 100

void copia(char str1[], char str2[]) {
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

int main() {
    char str1[MAX], str2[MAX];
    //primeiro teste
    scanf("%s", str1);
    copia(str1, str2); 
    printf("%s", str2);

    //segundo teste
    scanf("%s", str1);
    copia(str1, str2); 
    printf("%s", str2);
    return 0;
}