#include <stdio.h>

float get_pow(float num, int exp) {

    float value = 1;

    for (int i = 0; i< exp; i++)
        value *= num;
    
    return value;
}

int main () {
    float num;
    int exp;
    printf("Insira o num e o expoente:\n");
    scanf("%f ",  &num);
    scanf("%d ", &exp);
    printf("%f", get_pow(num, exp));
    return 0;

}