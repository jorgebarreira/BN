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

int is_segmento(char );
void preenche_meio(int ,int ,TAB_BN *,STACK *);
void preenche_cantos(int ,int ,TAB_BN *,STACK *);
void arruma_linha(TAB_BN *,int ,STACK *);
void arruma_coluna(TAB_BN *, int ,STACK *);
void coloca_o_na_linha (TAB_BN *, int , STACK *);
void coloca_o_na_coluna (TAB_BN *, int , STACK *);
void from_unknown_to_submarine(TAB_BN *, STACK *);
void from_unknown_to_destroyer(TAB_BN *, STACK *);
void from_unknown_to_cruiser(TAB_BN *, STACK *);
int verifica_info(TAB_BN *);
int verifica_char(TAB_BN *, int , int , char );
int verifica_cantos(int, int, TAB_BN *);
int verifica_meio(int , int , TAB_BN *);


