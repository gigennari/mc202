/*
Cliente
*/

#include <stdio.h>
#include "professor_carlos.h"
#define N 50 //numero máx de turmas
#define M 40 //numero max de alunos por turma
#define K 50 //numero max de operacoes

Aluno ler_aluno()
{
    Aluno A;
    scanf("%s %s %d %d %d\n", (A.nome), (A.sobrenome), &(A.nascimento.dia), &(A.nascimento.mes), &(A.nascimento.ano));
    return A;
}

void criar_turmas(Turma turmas[], int num_turmas)
{
    for (int i = 0; i < num_turmas; i++)
    {
        int qtd_alunos;
        scanf("%d\n", &qtd_alunos);
        turmas[i].qtd = 0;  //inicialiaza qtde de alunos na turma i como 0, 1ª posição do 1º aluno

        for (int j = 0; j < qtd_alunos; j++)
        {
            Aluno A;
            A = ler_aluno();
            add_aluno(turmas, A, i);
            
        }
    }
}

void realizar_operacoes(Turma turmas[], int qtd_turmas, int num_operacoes)
{
    for (int i = 0; i < num_operacoes; i++)
    {
        int operacao;
        int j;
        scanf("%d", &operacao);
        Aluno A;

        if (operacao == 1)
        {
            scanf("%d", &j);
            A = procura_novo_na_turma(turmas, qtd_turmas, j);
            printf("%s\n", A.nome);
        }
        else if (operacao == 2)
        {
            scanf("%d", &j);
            A = procura_velho_na_turma(turmas, qtd_turmas, j);
            printf("%s\n", A.sobrenome);
            
        }
        else if (operacao == 3)
        {
            A = procura_velho_todas_turmas(turmas, qtd_turmas);
            printf("%s\n", A.nome);
        }
        else if (operacao == 4)
        {
            A = procura_novo_todas_turmas(turmas, qtd_turmas);
            printf("%s\n", A.sobrenome);
        }
        else if (operacao == 5)
        {
            char padrao[5];
            scanf("%s", padrao);
            j = conta_substrings(turmas, qtd_turmas, padrao);
            printf("%d\n", j);
        }
        else if (operacao == 6)
        {
            int alunos_restantes;
            scanf("%d", &j);
            A = ler_aluno();
            alunos_restantes = add_aluno(turmas, A, j);
            printf("%d\n", alunos_restantes);
        }
        else if (operacao == 7)
        {
            int alunos_restantes;
            scanf("%d", &j);
            alunos_restantes = remove_aluno(turmas, j);
            printf("%d\n", alunos_restantes);
        }
        else
        {
            printf("Essa operacao nao eh valida.\n");
        }
    }
}

int main()
{
    int qtd_turmas, num_operacoes;
    Turma turmas[N];
    scanf("%d %d\n", &qtd_turmas, &num_operacoes);
    criar_turmas(turmas, qtd_turmas);
    realizar_operacoes(turmas, qtd_turmas, num_operacoes);
    return 0;
}