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
#include "Trabalho.h"
#include "aux_muda_tab.h"
#include "aux_stack.h"
#include "desf_f.h"
#define TRUE 1
#define FALSE -1
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif
int cmd_l(TAB_BN *,char *,STACK *);
int cmd_c(TAB_BN *, STACK *);
int cmd_m(TAB_BN *);
void imprimeTab(TAB_BN *,FILE *);
int cmd_e(TAB_BN *, char *) ;
int ler_ficheiro(FILE *,TAB_BN *);
