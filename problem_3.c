#include <stdio.h>
#include <stdlib.h>

/* 
    Teste Técnico P&D - Problema 3
    Autor: Raiziell F Lima 
*/

//Fez-se uso do tipo enum para referenciar os estados/eventos de 
//forma mais clara. Ambos iniciam em 1 para seguir o enunciado do problema.
enum states{
    link_down = 1,
    sending_start,
    start_received,
    link_ok
};

enum events{
    interface_nok = 1,
    interface_ok,
    packet_ok_rcv,
    packet_nok_rcv,
    no_response_rcv
};

// Cada valor da matriz representa o próximo estado,
// O zero representa uma transição inválida.
int state_machine_table[4][5] = {{1, 2, 1, 1, 1},
                                 {1, 0, 3, 2, 2},
                                 {1, 0, 4, 3, 2},
                                 {1, 0, 4, 2, 2}};

// Conforme o requisito listado, a função recebe o estado atual e um evento associado
int get_next_state(int cur_state, int ass_event){

    // Um é subtraído visto que as enumerações iniciam em 1, 
    // mas os índices em zero.
    int next_state = state_machine_table[cur_state - 1][ass_event - 1];
    switch (next_state){
        case link_down:
            //link_down();
            break;
        
        case sending_start:
            //sending_start();
            break;
        
        case start_received:
            //start_received();
            break;

        case link_ok:
            //link_ok();
            break;

        default:
            // O zero representa uma transição inválida.
            printf("Invalid transition, nothing will be done.\n");
            break;
    }
    return next_state;

};

int main(){
    int next_state; 

    // Exemplo de chamada da função
    next_state = get_next_state(start_received, packet_ok_rcv);

    if (next_state){
        printf("The next state is %d.\n", next_state);
    }
    
    return 0;
}