#include <stdio.h>
#define MAX 1000

typedef struct ponto
{
    double x, y;
} ponto;

int main() {
    ponto v[MAX], centroide;
    int i, n;
    scanf("%d ", &n);
    for (i = 0; i < n; i++) {
        scanf("%ls %lf", &v[i].x, &v[i].y);
    }
    centroide.x = 0;
    centroide.y = 0;
    for (i = 0; i < n; i++){
        centroide.x += v[i].x/n;
        centroide.y += v[i].y/n;
    }
    printf("%lf %lf\n", centroide.x, centroide.y);
    return 0;
}
