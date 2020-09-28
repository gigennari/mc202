/*
O livro "Algoritmos geométricos e relacionamentos topológicos" de Clodoveu A. Davis Jr.
e Gilberto Ribeiro de Queiroz foi usado como referência.

Visitado em 28/09/2020: [http://www.dpi.inpe.br/livros/bdados/cap2.pdf]
*/

typedef struct ponto{
    double x;
    double y;
}ponto;

typedef struct poligono{
    int num_vertices;
    ponto pontos[];
}poligono;


poligono poligono_le(poligono p){
    scanf("%d ", &p.num_vertices);
    int i;
    for(i = 0; i < p.num_vertices; i++){
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
}

double area_poligono(poligono p){
    double area = 0;
    int n;
    int i = 1;

    for(n = 0; n < p.num_vertices; n++){
        area += 0.5 * resolve_determinante(p.pontos[0], p.pontos[i], p.pontos[i+1]);
        i++;

    return area;
    }
}

double resolve_determinante(ponto a, ponto b, ponto c){
    double det;
    det = (a.x * b.y + a.y * c.x + b.x * c.y - (c.x * b.y + c.y * a.x + b.x * a.y));
    return det;
}

poligono transaladar(poligono p, double incremento_x, double incremento_y){
    int i;
    for (i = 0, i < p.num_vertices; i++){
        p.pontos[i].x += incremento_x;
        p.pontos[i].y += incremento_y;
    }
    return p;
}