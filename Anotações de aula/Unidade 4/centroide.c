#include <stdio.h>
#define MAX 1000

int main (){
    //leia os pontos
    double x[MAX], y[MAX];
    //inicializa centroide
    double cx, cy;

    int n;
    scanf("%d ", &n);
    
    //para cada ponto i, some a coordenada x e a coordenada y 
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf\n", &x[i], &y[i]);
    }

    cx = 0;
    cy = 0;
    for (int i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
    }

    //divisão do cx e cy
    cx = cx / n;
    cy = cy / n;
    

    //mostre o centroide cx, cy 
    printf("%lf %lf\n", cx, cy);
    return 0;
    
}