/*

*/

#include <stdio.h>

struct turma_s
{
    double *notas; //ao invés de alocar todo o espaço para o vetor, guarda espaço para o ponteiro
    int num_alunos;
    double maior_nota;
};

struct turma_s *nova_turma()
{
    struct turma_s *p_turma;

    p_turma = malloc(sizeof(struct turma_s));
    scanf("%d ", &p_turma->num_alunos);

    p_turma->notas = malloc(sizeof(double) * p_turma->num_alunos);

    for (int i = 0; i < p_turma->num_alunos; i++)
    {
        scanf("%lf", &p_turma->notas[i]);
    }
    return p_turma;
}

void liberar_turma(struct turma_s *p_turma)
{
    free(p_turma->notas);   //dar free na ordem inversa de malloc 
    free(p_turma);
} 

void calcular_maior_nota(struct turma_s *p_turma)
{ //passar ponteiro para alterar original, não cópia

    p_turma->maior_nota = p_turma->notas[0];
    for (int i = 1; i < p_turma->num_alunos; i++)
    {
        if (p_turma->notas[i] > p_turma->maior_nota)
        {
            p_turma->maior_nota = p_turma->notas[i];
        }
    }
}

int main()
{
    struct turma_s *p_ed;
    p_ed = nova_turma();
    calcular_maior_nota(&p_ed);
    printf("Maior: %lf\n", p_ed->maior_nota);
    liberar_turma(&p_ed);
    return 0;
}