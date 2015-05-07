#ifndef ___AUX_TABULEIRO_H___
#define ___AUX_TABULEIRO_H___
#include "estrutura_TAB_BN.h"
#include "estrategias.h"
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
#define FALSE -1
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif

int is_segmento(char );
void preenche_meio(int ,int ,TAB_BN *,STACK *);
void preenche_cantos(int ,int ,TAB_BN *,STACK *);
void arruma_linha(TAB_BN *,int ,STACK *);
void arruma_coluna(TAB_BN *, int ,STACK *);
void coloca_o_na_linha (TAB_BN *estado, int linha, STACK *partida);
void coloca_o_na_coluna (TAB_BN *estado, int coluna, STACK *partida);


