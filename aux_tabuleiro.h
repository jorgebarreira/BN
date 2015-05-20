/* Condiçao #ifndef flag que permite controlar a compilaçao das condiçoes entro este e o #endif.*/
#ifndef ___AUX_TABULEIRO_H___
/** Flag para a condiçao de processamento das outras flags.*/
#define ___AUX_TABULEIRO_H___
/* Inclusão do ficheiro onde estao definido as estruturas usadas.*/
#include "estrutura_TAB_BN.h"
/* Inclusão do ficheiro onde estao definido as estrategias.*/
#include "estrategias.h"
/* Inclusão do ficheiro onde estao definido as estrategias mais avançadas.*/
#include "estrategias_auxiliares.h"
/* Inclusão do ficheiro de leitura e escrita (entre outros) definido nas bibliotecas de C.*/
#include <stdio.h>
/* Inclusão dum ficheiro das bibliotecas predefinidas do C .*/
#include <stdlib.h>
/* Inclusão do ficheiro para o processamento de strings das bibliotecas C.*/
#include <string.h>
/* Inclusão do ficheiro onde estao definido os comandos de escrita ,leitura e verificaçoes.*/
#include "stel.h"
/* Inclusão do ficheiro onde estao definido as funçoes que permitem a aplicaçao das estrategias.*/
#include "aux_tabuleiro.h"
/* Inclusão do ficheiro onde esta definido o main, isto é, a funçao chamadora.*/
#include "Main.h"
/* Inclusão do ficheiro onde estao definido os comandos para mudar o tabuleiro.*/
#include "aux_muda_tab.h"
/* Inclusão do ficheiro onde estao definidoas funçoes de trabalho sobre a stack.*/
#include "aux_stack.h"
/* Inclusão do ficheiro onde estao definido as funçoes para defazer os comandos.*/
#include "desf_f.h"
/* Inclusão do ficheiro onde estao definido as funçoes para fazer uma jogada aleatoria.*/
#include "rand_.h"
/* Inclusão do ficheiro onde esta definido o interpretador.*/
#include "interpretador.h"
/* Inclusão do ficheiro sobre o tempo das bibliotecas C. As suas funçoes sao aqui usadas para a criaçao de numeros aleatorios.*/
#include <time.h>
/** Flag cujo o valor é 1.*/
#define TRUE 1
/** Flag cujo o valor é 0. */
#define FALSE 0
/** Flag usado para o tamanho dos nossos vetores, tendo valor 105.*/
#define MAX_SIZE 105
/** Flag usado para o tamanho maximo que podera ser lido num ficheiro, tendo valor 1024.*/
#define MAX_LINHA 1024

/* Fim da condiçao if do inicio.*/
#endif

int is_segmento(char );
int preenche_meio(int ,int ,TAB_BN *,STACK *);
int preenche_cantos(int ,int ,TAB_BN *,STACK *);
int arruma_linha(TAB_BN *,int ,STACK *);
int arruma_coluna(TAB_BN *, int ,STACK *);
int coloca_o_na_linha (TAB_BN *, int , STACK *);
int coloca_o_na_coluna (TAB_BN *, int , STACK *);
int from_unknown_to_submarine(TAB_BN *, STACK *);
int from_unknown_to_whatever_horizontal(TAB_BN *, STACK *, int );
int from_unknown_to_whatever_vertical(TAB_BN *, STACK *, int );
int from_unknown_to_middle_horizontal(TAB_BN *, STACK *, int );
int from_unknown_to_middle_vertical(TAB_BN *, STACK *, int );
int particular_middleSegment_case_horizontal(TAB_BN *, STACK *, int);
int particular_middleSegment_case_vertical(TAB_BN *, STACK *, int);
int verifica_info(TAB_BN *);
int verifica_char(TAB_BN *, int , int , char );
int verifica_char_esp(TAB_BN *, int , int , char );
int verifica_lado(TAB_BN *, int, int);
int verifica_cantos(int, int, TAB_BN *);
int verifica_meio(int , int , TAB_BN *);




