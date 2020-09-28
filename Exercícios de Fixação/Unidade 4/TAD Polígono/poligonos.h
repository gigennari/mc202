/*
Contém conjunto de operações do TAD
*/
typedef struct ponto{
    double x;
    double y;
}ponto;

typedef struct poligono{
    int num_vertices;
    ponto pontos[];
}poligono;

poligono poligono_le();

double area_poligono(poligono p);

double resolve_determinante(ponto a, ponto b, ponto c);

poligono transaladar(poligono p, double incremento_x, double incremento_y);