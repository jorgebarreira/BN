#ifndef ___AUX_TABULEIRO_H___
#define ___AUX_TABULEIRO_H___
#include "estrutura_TAB_BN.h"
#include "estrategias.h"
#include "estrategias_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stel.h"
#include "aux_tabuleiro.h"
#include "Main.h"
#include "aux_muda_tab.h"
#include "aux_stack.h"
#include "desf_f.h"
#include "interpretador.h"
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif


/**
Funçao que inicializa um estado inicial assim como a stack, passando o endereço destas quando chamar o interpretador.

@return : Devolve 0.
*/
int main(){
    TAB_BN estado;
    STACK partida;
    estado.n_linhas =0;
    estado.n_colunas = 0;
    partida.head = NULL;
    partida.tamanho=0;
    interpretador(&estado, &partida);
    return 0;
}
