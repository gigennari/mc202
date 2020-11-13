#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_fila.h"

#define NUM_ESPECIALIDADES 9

int HORARIO[] = {0, 8, 0, 0};

void cria_hospital(p_deque *hospital)
{
    hospital[0] = criar_deque(10);
    hospital[1] = criar_deque(2);
    hospital[2] = criar_deque(5);
    hospital[3] = criar_deque(3);
    hospital[4] = criar_deque(4);
    hospital[5] = criar_deque(7);
    hospital[6] = criar_deque(2);
    hospital[7] = criar_deque(1);
    hospital[8] = criar_deque(4);
}

void atualiza_horario()
{
    //caso seja minuto 50, hora vira (2 casos)
    if (HORARIO[2] == 5)
    {
        HORARIO[2] = 0;
        if (HORARIO[1] < 9)
        {
            HORARIO[1] += 1;
        }
        else
        {
            HORARIO[0] += 1;
            HORARIO[1] = 0;
        }
    }
    else
    {
        HORARIO[2] += 1;
    }
}

void imprime_horario()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 2)
        {
            printf("%c", ':'); //imprimir dois pontos quando chegar nos minutos
        }
        printf("%d", HORARIO[i]);
    }
}

p_deque le_entrada(p_deque pacientes)
{
    scanf("%*c");
    int retorno = 1, posicao = 1;
    do
    {
        char nome[50];
        char aspas;
        char status[11];
        p_lista salas;
        salas = criar_lista();
        p_paciente paciente;

        scanf("%[^\"]%*c", nome);
        scanf("%s", status);
        Preferencia x;
        if (status[0] == 'n')
        {
            x = normal;
        }
        else
        {
            x = prioridade;
        }

        int num;
        int ret = 1;

        do
        {
            ret = scanf("%d", &num);
            if (ret == 1)
            {
                salas = add_direita(salas, num);
            }
        } while(ret == 1);

        retorno = scanf("%c", &aspas);

        paciente = criar_paciente(nome, x, salas, posicao);
        inserir_paciente(pacientes, paciente);
        posicao += 1;
    } while (retorno != 0);

    return pacientes;
}

//devolve 1
int entrou_antes(p_paciente p1, p_paciente p2){
    if (p1->posicao > p2->posicao){
        return 1; //retorna p2 que tem menor posição
    }
    else
    {
        return -1; //retorna p1 que tem menor posição
    }
}

p_deque add_pacientes_fila(p_deque hospital[], p_paciente *vetor, int num_pacientes){
    for (int sala = 0; sala < NUM_ESPECIALIDADES; sala++){
        p_paciente sala_atual[num_pacientes];   //num_pacientes é o maximo que precisa, caso todos vao p mesma sala
        int qtde = 0;
        //percorre pacientes de um vetor e verifica proxima sala
        for (int p = 0; p < num_pacientes; p++){
            //se a proxima sala for a que estamos visitando (1° for), add em um vetor sala_atual
            if (vetor[p]->salas->ini == sala){
                sala_atual[qtde] = vetor[p];
                vetor[p]->salas = eliminar_esquerda(vetor[p]->salas);

                qtde += 1;
        }

        //ordena pessoas que vão p fila da mesma especilidade por ordem de quem entrou primeiro
        qsort(sala_atual, qtde, sizeof(p_paciente), entrou_antes);

        //add pessoas na fila 
        for (int a = 0; a < qtde; a++){
            inserir_paciente(hospital[sala], sala_atual[a]);
        }
    }

}

//atualiza deques do vetor hospital 
p_deque roda_filas()
{
    atualiza_horario();
    
    //para cada especialidade (elemento do vetor hospital)

    //se fila não estiver vazia
        //remover qtde_medicos pacientes ou até a fila esvaziar
            //se o paciente removido ainda tiver uma sala para visitar
                //inserir em um deque temporário
            //caso contrário, imprimir o horário de saída e paciente->nome    
    //inserir pacientes do deque temporário nas filas
}

int main()
{
    p_deque hospital[NUM_ESPECIALIDADES];
    cria_hospital(hospital);
    p_deque pacientes;
    pacientes = criar_deque(0); //esse deque não tem uma qtde de médicos p add
    pacientes = le_entrada(pacientes);

    int num_pacientes = pacientes->fim->posicao;    //a posicao do ultimo paciente é o total de pacientes

    p_paciente vetor_todos_pacientes[num_pacientes];
    colocar_pacientes_vetor(vetor_todos_pacientes, pacientes, num_pacientes);

    add_pacientes_fila(hospital, vetor_todos_pacientes, num_pacientes);

    p_paciente restantes[num_pacientes];
    while (num_pacientes > 0)
    {
        roda_filas(hospital, restantes, num_pacientes);
        add_pacientes_fila(hospital, restantes, num_pacientes);
    }    

    return 0;
}