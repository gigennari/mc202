/*
Cliente
*/

#include <stdio.h>
#include <professor_carlos.h>
#define N 50 //numero máx de turmas
#define M 40 //numero max de alunos por turma
#define K 50 //numero max de operacoes

Aluno ler_aluno()
{
    Aluno A;
    int dia, mes, ano;
    ("%c %c %d %d %d", &A.nome, &A.sobrenome, &dia, &mes, &ano);
    A.nascimento.dia = dia;
    A.nascimento.mes = mes;
    A.nascimento.ano = ano;
    return A;
}

Turma criar_turmas(Turma turmas[], int num_turmas)
{
    for (int i = 0; i < num_turmas; i++)
    {    
        int qtd_alunos = 0;
        scanf("%d ", &qtd_alunos);
        for (int j = 0; j < qtd_alunos; j++)
        {
            Aluno A;
            A = ler_aluno();
            add_aluno(turmas, A, i);
        }
    }
}

int realizar_operacoes(Turma turmas[], int qtd_turmas, int num_operacoes)
{
    for (int i = 0; i < num_operacoes; i++)
    {
        int operacao;
        scanf("%d ", &operacao);
        if (operacao == 1)
        {
            int j;
            scanf("%d ", &j);
            procura_novo_na_turma(turmas, qtd_turmas, j);
        }
        else if (operacao == 2)
        {
            int j;
            scanf("%d ", &j);
            procura_velho_na_turma(turmas, qtd_turmas, j);
        }
        else if (operacao == 3)
        {
            /* code */
        }
        else if (operacao == 4)
        {
            /* code */
        }
        else if (operacao == 5)
        {
            /* code */
        }
        else if (operacao == 6)
        {
            /* code */
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
    scanf("%d %d", &qtd_turmas, num_operacoes);
    criar_turmas(turmas, qtd_turmas);
    realizar_operacoes(turmas, qtd_turmas, num_operacoes);
}