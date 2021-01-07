#include <stdio.h>
#include <stdlib.h>
#define letra_A 65

typedef struct Token
{
    int valor;
    char expressao[56];

} Token;

typedef struct Planilha
{
    Token **planilha;
    int **visitados;
    int m, n;

} Planilha;

typedef struct Planilha *p_planilha;

p_planilha aloca_planilha(int m, int n)
{
    p_planilha p = malloc(sizeof(Planilha));

    p->m = m;
    p->n = n;

    p->planilha = malloc(m * sizeof(Token *));

    for (int i = 0; i < m; i++)
    {
        p->planilha[i] = calloc(n, sizeof(Token));
    }

    p->visitados = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        p->visitados[i] = calloc(n, sizeof(int));
    }

    return p;
}

p_planilha zera_visitados(p_planilha p)
{
    for (int i = 0; i < p->m; i++)
    {
        for (int j = 0; j < p->n; j++)
        {
            p->visitados[i][j] = 0;
        }
    }
}

void le_linha(p_planilha p, char *linha, int num_linha)
{
    char auxiliar[56];
    char caractere;
    int i = 0, coluna = 0, pos = 0;

    for (caractere = linha[i]; i < strlen(linha); i++)
    {
        //se for vírgula
        if (caractere == ",")
        {
            auxiliar[pos] = "\0";

            //se começar com "=" é expressão
            if (auxiliar[0] == "=")
            {
                auxiliar[0] = "\0"; //elimina o =
                strcpy(p->planilha[num_linha][coluna].expressao, auxiliar);
            }

            //caso contrário, é número
            else
            {
                int valor = atoi(auxiliar);
                p->planilha[num_linha][coluna].valor = valor;
            }
            coluna++;
            pos = 0;
        }
        //caso contrário, copiar caractere se for diferente de espaço
        else
        {
            if (caractere != " ")
            {
                auxiliar[pos] = caractere;
                pos++;
            }
        }
    }
}

p_planilha le_arquivo(p_planilha p, char *nome_arquivo)
{

    FILE *arquivo = fopen(nome_arquivo, "r");

    char linha[256];
    int linha_atual = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        le_linha(linha, strlen(linha), linha_atual);
        linha_atual++;
    }

    fclose(arquivo);

    return p;
}

int resolve_expressao(p_planilha p, char *expressao)
{
}

void leitura_e_calculo(p_planilha p, int linha, int coluna)
{

    //se for um número, a expressao é vazia
    if (strlen(p->planilha[linha][coluna - letra_A].expressao) == 0)
    {
        printf("%c%d: %d", coluna, linha, p->planilha[linha][coluna].valor);
    }

    //se for uma expressão
    else
    {
        int resultado = resolve_expressao(p, p->planilha[linha][coluna - letra_A].expressao);
    }
}

void atualizacao(p_planilha p, int linha, int coluna, int novo_valor)
{
}

int main()
{

    //lê nome do arquivo e dimensões da planilha
    char nome_arquivo[56];
    int m, n;
    scanf("%s %d %d", nome_arquivo, m, n);

    //aloca planilha
    p_planilha p = aloca_planilha(m, n);

    //lê arquivo csv
    p = le_arquivo(p, nome_arquivo);

    //lê e realiza operações
    int retorno = 1;
    char operacao;

    scanf("%c", operacao);
    do
    {

        //lê célula
        char celula[4];
        int linha, coluna;
        scanf("%s", celula);

        //coluna a partir da letra (subtrair A na hora de procurar na matriz)
        coluna = celula[0];

        //calcula linha copiando o restante da str e usando atoi
        int tam = strlen(celula);
        char aux[4];
        for (int i = 1; i < tam; i++)
        {
            aux[i - 1] = celula[i];
        }

        linha = atoi(aux);

        //operacao de leitura e calculo do valor atual
        if (operacao == "G")
        {
            leitura_e_calculo(p, linha, coluna);
        }
        //operacao de atualizar célula e calcular novo valor
        else
        {
            int novo_valor;
            scanf("%d", &novo_valor);

            atualizacao(p, linha, coluna, novo_valor);
        }

        //lê próxima operação se existir
        retorno = scanf("%c", operacao);

    } while (retorno != EOF);

    return 0;
}