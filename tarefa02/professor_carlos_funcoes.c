/*
Implementação 
*/

#include <stdio.h>
#include <professor_carlos.h>

Aluno desempate_lexicografico(Aluno A, Aluno B)
{
    Aluno C;
    int diferenca = 0;
    for (int i = 0; A.nome[i] != '\0' && B.nome[i] != '\0'; i++)
    {
        diferenca = 'A.nome[i]' - 'B.nome[i]';
        if (diferenca > 0)
        {
            C = B;
            break;
        }
        else if (diferenca < 0)
        {
            C = A;
            break;
        }
        else if (diferenca == 0 && (A.nome[i + 1] == '\0' || B.nome[i + 1] == '\0'))
        {
            if (A.nome[i + 1] == '\0' && B.nome[i + 1] != '\0')
                C = A;
            else if (A.nome[i + 1] != '\0' && B.nome[i + 1] == '\0')
                C = B;
            else if (A.nome[i + 1] == '\0' && B.nome[i + 1] == '\0')
            {
                for (int i = 0; A.sobrenome[i] != '\0' && B.sobrenome[i] != '\0'; i++)
                {
                    diferenca = 'A.sobrenome[i]' - 'B.sobrenome[i]';
                    if (diferenca > 0)
                    {
                        C = B;
                        break;
                    }
                    else if (diferenca < 0)
                    {
                        C = A;
                        break;
                    }
                }
            }
        }
        return C;
    }
}

Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j)
{
    Aluno mais_novo;
    mais_novo = t[j].alunos[0];
    for (int i = 1; i < t[j].qtd; i++)
    {
        if (t[j].alunos[i].nascimento.ano > mais_novo.nascimento.ano)
            mais_novo = t[j].alunos[i];
        else if (t[j].alunos[i].nascimento.ano == mais_novo.nascimento.ano)
        {
            if (t[j].alunos[i].nascimento.mes > mais_novo.nascimento.mes)
                mais_novo = t[j].alunos[i];
            else if (t[j].alunos[i].nascimento.mes == mais_novo.nascimento.mes)
            {
                if (t[j].alunos[i].nascimento.dia > mais_novo.nascimento.dia)
                    mais_novo = t[j].alunos[i];
                else if (t[j].alunos[i].nascimento.dia == mais_novo.nascimento.dia)
                {
                    mais_novo = desempate_lexicografico(t[j].alunos[i], mais_novo);
                }
            }
        }
    }
    return mais_novo;
}

Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j)
{

    Aluno mais_velho;
    mais_velho = t[j].alunos[0];
    for (int i = 1; i < t[j].qtd; i++)
    {
        if (t[j].alunos[i].nascimento.ano < mais_velho.nascimento.ano)
            mais_velho = t[j].alunos[i];
        else if (t[j].alunos[i].nascimento.ano == mais_velho.nascimento.ano)
        {
            if (t[j].alunos[i].nascimento.mes < mais_velho.nascimento.mes)
                mais_velho = t[j].alunos[i];
            else if (t[j].alunos[i].nascimento.mes == mais_velho.nascimento.mes)
            {
                if (t[j].alunos[i].nascimento.dia < mais_velho.nascimento.dia)
                    mais_velho = t[j].alunos[i];
                else if (t[j].alunos[i].nascimento.dia == mais_velho.nascimento.dia)
                {
                    mais_velho = desempate_lexicografico(t[j].alunos[i], mais_velho);
                }
            }
        }
        return mais_velho;
    }
}

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas)
{
    Aluno mais_novo;
    qtd_turmas += 1;
    for(int i = 0; i < qtd_turmas - 1; i++){    //procura o mais velho em cada turma
        t[qtd_turmas].alunos[i] = procura_novo_na_turma(t, qtd_turmas, qtd_turmas);
    }
    mais_novo = procura_novo_na_turma(t, qtd_turmas, qtd_turmas);
    qtd_turmas -= 1;
    return mais_novo;
}

Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas)
{
    Aluno mais_velho;
    qtd_turmas += 1;
    for(int i = 0; i < qtd_turmas - 1; i++){    //procura o mais velho em cada turma
        t[qtd_turmas].alunos[i] = procura_velho_na_turma(t, qtd_turmas, qtd_turmas);
    }
    mais_velho = procura_velho_na_turma(t, qtd_turmas, qtd_turmas);
    qtd_turmas -= 1;
    return mais_velho;
}

int ocorre(char nome[], int pos, char padrao[])
{
    for (int j = 0; padrao[j] != '\0'; j++)
        if ((nome[pos + j] == '\0') || (nome[pos + j] != padrao[j] && padrao[j] != '*'))
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
