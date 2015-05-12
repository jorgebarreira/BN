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
#define MAX_SIZE 100

/**
Estrutura de dados contendo todas as informações relativas ao tabuleiro de jogo.
*/
typedef struct tab_bn{
    int n_linhas;
    int n_colunas;
    int info_colunas[MAX_SIZE];
    int info_linhas[MAX_SIZE];
    char tabuleiro[MAX_SIZE][MAX_SIZE];
} TAB_BN;

/**
Estrutura de dados que contem informaçao sob o local onde um novo caracter foi introduzido no tabuleiro.
*/
typedef struct JOGADAS{
  int indcom;
  int linha ;
  int coluna;
  struct JOGADAS *proxima;
  char modificado;
} JOGADAS;

/**
Estrutura de dados que guarda o tabuleiro de jogada onde estou, e possui uma lista interligada de jogadas assim como o endereço para o jogo anterior.
*/
typedef struct JOGO{
  TAB_BN estado;
  int n_elementos;
  int n_com;
  JOGADAS *head_jogadas;
  struct JOGO *proximo;
} JOGO;
/**
Estrutura de dados que representa a stack usada para guardar os jogos que foram feitos.
*/
typedef struct STACK_L{
      JOGO *head;
      int tamanho;
}STACK;


