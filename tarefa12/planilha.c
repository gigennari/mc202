#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define letra_A 65

typedef struct Token
{
    int valor;
    char *expressao;

} Token;

typedef struct Resultado
{
    int valor, visitado;

} Resultado;

typedef struct Resultado *p_resultado;

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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p->planilha[i][j].expressao = calloc(56, sizeof(char));
        }
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
    return p;
}

void le_linha(p_planilha p, char *linha, int num_linha, int colunas)
{
    char auxiliar[56];
    
    for (int i = 0; i < colunas; i++)
    {
        sscanf(linha, "%[^,]", auxiliar);

        if (auxiliar[0] == '=')
        {

            // remove =
            auxiliar[0] = ' ';

            strcpy(p->planilha[num_linha][i].expressao, auxiliar + 2);
        }
        else
        {
            p->planilha[num_linha][i].valor = atoi(auxiliar);
        }

        linha += strlen(auxiliar) + 1;
    }
}

p_planilha le_arquivo(p_planilha p, char *nome_arquivo, int colunas)
{

    FILE *arquivo = fopen(nome_arquivo, "r");

    char linha[256];
    int linha_atual = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        le_linha(p, linha, linha_atual, colunas);
        linha_atual++;
    }

    fclose(arquivo);

    return p;
}

/**
int resolve_expressao(p_planilha p, int linha, int coluna)
{
    //calcula coluna a partir da letra
    int col = coluna - 'A';

    char *expressao = p->planilha[linha][col].expressao;

    //marca que visitou
    p->visitados[linha][col] = 1;

    
   
    //caso básico apenas um termo
    
    if (strlen(expressao) == 0 || expressao[0] != '(')
    {

        //se for numero
        if (strlen(expressao) == 0)
        {
            //devolve valor
            p->visitados[linha][col] = 0;
            return p->planilha[linha][col].valor;
        }
        //se for expressão,
        else
        {
            int nova_col = expressao[0];
            
            expressao[0] = ' ';
            int nova_linha = atoi(expressao);
            expressao[0] = nova_col + 'A';

            if(p->visitados[nova_linha - 1][nova_col - 'A'] != 1){
                 //return leitura_e_calculo(p, nova_linha, nova_col);
            }
            else{
                printf("#ERRO#\n");
            }
           
        }
    }

   
    //recursão
    else
    {
        //eliminar parênteses
        for (int i = 0; i < tam - 1; i++)
        {
            if (i == tam - 2)
            {
                expressao[i] = '\0';
            }
            else
            {
                expressao[i] = expressao[i + 1];
            }
        }

        tam = strlen(expressao);

        //percorrer normal e de trás p frente até achar o primeiro mais ou menos
        int i = 0;
        int j = tam;
        int y = 0;
        char parcela1[56];
        char parcela2[56];
        char operacao;

        while (i < tam && j > 0)
        {

            //fazer chamadas recursivas

            if (expressao[i] == '+' || expressao[i] == '-')
            {
                operacao = expressao[i];
                strncpy(parcela1, expressao, i - 1);
                //copia restante da expressao
                for (int x = i + 1; x < tam; x++)
                {
                    parcela2[y] = expressao[x];
                    y++;
                }
            }

            if (expressao[j] == '+' || expressao[j] == '-')
            {
                operacao = expressao[j];
                strncpy(parcela1, expressao, j - 1);
                //copia restante da expressao
                for (int x = j + 1; x < tam; x++)
                {
                    parcela2[y] = expressao[x];
                    y++;
                }
            }

            i++;
            j--;

            if (operacao == '+')
            {
                return resolve_expressao(p, parcela1) + resolve_expressao(p, parcela2);
                break;
            }
            else
            {
                return resolve_expressao(p, parcela1) - resolve_expressao(p, parcela2);
                break;
            }
        }
    }
    
    return 0;
}
*/

int leitura_e_calculo(p_planilha p, int linha, int coluna)
{
    char *expressao = p->planilha[linha - 1][coluna - 'A'].expressao;
    
    //se for um número, a expressao é vazia
    if (strlen(expressao) == 0)
    {
        return p->planilha[linha - 1][coluna - 'A'].valor;
    }

    //se for uma expressão
    else if (expressao[0] == '(')
    {
        char termo1[28], termo2[28];
        char operacao;
        

        sscanf(expressao, "%*c %s %c %s %*c", termo1, &operacao, termo2);

        int col1 = termo1[0];
        termo1[0] = ' ';
        int lin1 = atoi(termo1);

        int col2 = termo2[0];
        termo2[0] = ' ';
        int lin2 = atoi(termo2);
        
        if (operacao == '+'){
            return leitura_e_calculo(p, lin1, col1) + leitura_e_calculo(p, lin2, col2);
        }
        else{
             return leitura_e_calculo(p, lin1, col1) - leitura_e_calculo(p, lin2, col2);
        }
        
    }
    else
    {

        
        int nova_col = expressao[0];
        expressao[0] = ' ';
        int nova_linha = atoi(expressao);
        expressao[0] = nova_col;
        return leitura_e_calculo(p, nova_linha, nova_col);
    }
}


p_planilha atualizacao(p_planilha p, int linha, int coluna, int novo_valor)
{

    int valor_antigo = p->planilha[linha - 1][coluna - 'A'].valor;
    p->planilha[linha - 1][coluna - 'A'].valor = novo_valor;

    printf("%c%d: %d -> %d\n", coluna, linha, valor_antigo, novo_valor);
    return p;
}

void libera_planilha(p_planilha p, int linhas, int colunas)
{

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++){
            free(p->planilha[i][j].expressao);
        }    
    }
    for (int i = 0; i < linhas; i++){
        free(p->planilha[i]);
        free(p->visitados[i]);
    }
        
    free(p->planilha);
    free(p->visitados);
    free(p);
}

int main()
{

    //lê nome do arquivo e dimensões da planilha
    char nome_arquivo[56];
    int colunas, linhas;
    scanf("%s %d %d ", nome_arquivo, &colunas, &linhas);

    //aloca planilha
    p_planilha p = aloca_planilha(linhas, colunas);

    //lê arquivo csv
    p = le_arquivo(p, nome_arquivo, colunas);

    //lê e realiza operações
    int retorno = 1;
    char operacao;

    scanf("%c ", &operacao);
    do
    {

        //lê célula
        char celula[4];
        int linha, coluna;
        scanf("%s ", celula);

        //coluna a partir da letra (subtrair A na hora de procurar na matriz)
        coluna = celula[0];
        //calcula linha copiando o restante da str e usando atoi
        celula[0] = ' ';
        linha = atoi(celula);

        //operacao de leitura e calculo do valor atual
        if (operacao == 'G')
        {
            
            int r = leitura_e_calculo(p, linha, coluna);
            
            printf("%c%d: %d\n", coluna, linha, r);
            
            
        }
        //operacao de atualizar célula e calcular novo valor
        else
        {
            int novo_valor;
            scanf("%d ", &novo_valor);

            p = atualizacao(p, linha, coluna, novo_valor);
        }

        //lê próxima operação se existir
        retorno = scanf("%c", &operacao);

    } while (retorno != EOF);

    libera_planilha(p, linhas, colunas);
    return 0;
}