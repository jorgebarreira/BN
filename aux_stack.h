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

int popStack(TAB_BN *,STACK *);
int newJOGO(TAB_BN *, STACK* );
int newJOGADA(JOGO *);
int initJOGO(TAB_BN *, STACK *);
void altera_estado(TAB_BN *,int , int , char , STACK *);
int push(int , int , TAB_BN *, STACK *);

