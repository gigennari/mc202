#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main(){
    int num;
    p_no lista; 
    lista = criar_lista();
    do {
        scanf("%d", &num);
        if (num > 0){
            lista = adicionar_elemento(lista, num);
        }
    } while (num > 0);

    return 0;
}

