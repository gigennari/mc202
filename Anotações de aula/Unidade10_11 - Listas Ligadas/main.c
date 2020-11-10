#include <stdio.h>
#include "lista_ligada.h"

int main(){
    int x;
    x = 0;
    x = x + 5;
    
    p_no lista;
    lista = criar_lista();
    lista = adicionar_elemento(lista, 5);
    lista = adicionar_elemento(lista, 4);
    imprime_lista_inversa(lista);
}