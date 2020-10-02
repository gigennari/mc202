/*
Implementação 
*/

#include <stdio.h>
#include <professor_carlos.h>


Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j)
{
}

int ocorre(char nome[], int pos, char padrao[])
{
    for (int j = 0; padrao[j] != '\0'; j++)
        if ((nome[pos + j] == '\0') || (nome[pos+j] != padrao[j] && padrao[j] != '*'))
            return 0;
        return 1;        
}

int conta_substrings(Turma t[], int qtd_turmas, char *padrao)
{
    int ocorrencias = 0;
    for (int j = 0; j < qtd_turmas; j++) // para cada turma
    {
        for (int i = 0; i < t[j].qtd; i++) //para cada aluno da turma
        {
            for (int c = 0; t[j].alunos[i].nome[c] != '\0'; c++)
            {
                if (ocorre(t[j].alunos[i].nome, c, *padrao))
                {
                    ocorrencias += 1;
                }
            }
        }
    }

    return ocorrencias;
}

int add_aluno(Turma t[], Aluno A, int j)
{
    t[j].alunos[t[j].qtd] = A;
    t[j].qtd++;
    return t[j].qtd;
}

int remove_aluno(Turma t[], int j)
{
    t[j].qtd--;
    return t[j].qtd;
}
