#include <stdio.h>
#include <stdlib.h>
#include "interface_fila.h"
#define NUM_ESPECIALIDADES 9

int HORARIO[] = {0, 8, 0, 0};

p_deque cria_hospital(p_deque hospital[]){
    hospital[0] = criar_deque(10);
    hospital[1] = criar_deque(2);
    hospital[2] = criar_deque(5);
    hospital[3] = criar_deque(3);
    hospital[4] = criar_deque(4);
    hospital[5] = criar_deque(7);
    hospital[6] = criar_deque(2);
    hospital[7] = criar_deque(1);
    hospital[8] = criar_deque(4);

    return hospital;

}


void atualiza_horario(){
    //caso seja minuto 50, hora vira (2 casos)
    if (HORARIO[2] == 5){
        HORARIO[2] = 0;
        if (HORARIO[1] < 9){
            HORARIO[1] += 1;
        }
        else{
            HORARIO[0] += 1;
            HORARIO[1] = 0;
        }
    }
    else{
        HORARIO[2] += 1;
    }
}

void imprime_horario(){
    for(int i = 0; i < 4; i++){
        if(i == 2){
            printf("%c", ':');  //imprimir dois pontos quando chegar nos minutos
        }
        printf("%d", HORARIO[i]);
    }
}

p_deque le_pacientes(p_deque pacientes){
    do{
        char nome[50];
        char aspas;
        char status [11];
        p_no_int salas = criar_lista();
        p_paciente paciente;

        scanf("%[^\"]", &nome);
        scanf("%s", &status);
        enum Preferencia x = status;
        
        do{
            int num;
            scanf(" %d", &num);
            salas = adicionar_direita(salas, num);
        }while(num != '\n');

        scanf("%*c"); // lê quebra de linha
        int retorno = scanf("%c", &aspas);

        paciente = criar_paciente(nome, x, salas);
        pacientes = insere_paciente(pacientes, paciente);


    }while(retorno != EOF);

    return pacientes;
}

//atualiza deques do vetor hospital 
p_deque add_pacientes_fila(p_deque hospital[], p_deque pacientes){

}

p_deque roda_filas(){
    atualiza_horario();
    p_deque temporario;
    
    //para cada especialidade (elemento do vetor hospital)

    //se fila não estiver vazia
        //remover qtde_medicos pacientes ou até a fila esvaziar
            //se o paciente removido ainda tiver uma sala para visitar
                //inserir em um deque temporário
            //caso contrário, imprimir o horário de saída e paciente->nome    
    //inserir pacientes do deque temporário nas filas
}


int main(){
    struct Deque *hospital[NUM_ESPECIALIDADES];
    hospital[NUM_ESPECIALIDADES] = cria_hospital(hospital);
    p_deque pacientes;
    pacientes = criar_deque;
    pacientes = le_entrada(pacientes);

    hospital[NUM_ESPECIALIDADES] = add_pacientes_fila(hospital, pacientes);
    roda_filas();


    return 0;
}