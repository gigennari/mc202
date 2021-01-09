typedef struct pilha
{
    int *v;
    int topo, tam_max;   // prox posição livre
}Pilha;

typedef Pilha *p_pilha;


p_pilha inicializa(int tam){
    p_pilha p = malloc(sizeof(Pilha));
    p->topo = 0;
    p->tam_max = tam;
    p->v = calloc(tam, sizeof(int));

    return p; 
}

void empilhar(p_pilha p, int i){
    p->v[p->topo] = i;
    p->topo++;
}

int desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

int eh_cheia(p_pilha p){
    if (p->topo - 1 == p->tam_max){
        return 1;
    }
    return 0; 
}

int eh_vazia(p_pilha p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}