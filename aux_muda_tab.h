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


int cmd_E(int , TAB_BN *,STACK *);
int cmd_p(char *,int ,int , TAB_BN *, STACK *);
int cmd_h(TAB_BN *, int , STACK *);
int cmd_v(TAB_BN *, int , STACK *);
int pertence(char );
