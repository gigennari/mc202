typedef struct pilha
{
    int *v;
    int topo;   // prox posição livre
}Pilha;

typedef Pilha *p_pilha;

void empilhar(p_pilha p, int i){
    p->v[p->topo] = i;
    p->topo++;
}

int desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

