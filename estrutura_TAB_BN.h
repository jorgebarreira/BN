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
#define MAX_SIZE 100
typedef struct tab_bn{
    int n_linhas;
    int n_colunas;
    int info_colunas[MAX_SIZE];
    int info_linhas[MAX_SIZE];
    char tabuleiro[MAX_SIZE][MAX_SIZE];
} TAB_BN;

typedef struct JOGADAS{
  int indcom;
  int linha ;
  int coluna;
  char modificado;
  struct JOGADAS *proxima;
} JOGADAS;

typedef struct JOGO{
  TAB_BN estado;
  int n_elementos;
  int n_com;
  JOGADAS *head_jogadas;
  struct JOGO *proximo;
} JOGO;

typedef struct STACK_L{
      JOGO *head;
      int tamanho;
}STACK;

