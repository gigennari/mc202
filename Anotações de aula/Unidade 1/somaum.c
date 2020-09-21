#include <stdio.h>

void soma_um(int v[], int n) {
    int i;
    for (i = 0; i < n; i++)
        v[i]++;    
}

int main() {
    int i, v[5] = {1, 2, 3, 4, 5};
    soma_um(v, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", v[i]);
    return 0;
}