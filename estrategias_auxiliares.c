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
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif

/**
funcao para percorrer todo o tabuleiro e sempre que encontrar um segmento preencher agua a volta onde necessario.
*/

void estrategia_4(TAB_BN *estado,STACK *partida){
	from_unknown_to_submarine(estado, partida);
	from_unknown_to_destroyer(estado, partida);
}
