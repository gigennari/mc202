#include <stdio.h>

int main() {
    int segundos;
    int horas, minutos;
    printf("Quantos segundos quer converter?\n");
    scanf("%ds", &segundos);
    horas = segundos / 3600;    //divisão é inteira pq operandos são inteiros
    segundos = segundos % 3600; //pega o resto
    minutos = segundos / 60;
    segundos = segundos % 60;
    printf("%dh %dmin %ds", horas, minutos, segundos);
}