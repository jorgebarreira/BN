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
#include "R_prototipo.h"
/* Fim da condiçao if do inicio.*/
#endif
#define MAX_SIZE 105

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
/** Indice do jogada, indice identicos corresponde a modificaçoes feitos pelo mesmo comando.*/
  int indcom;
/** Linha modificada. */
  int linha ;
/** Coluna modificada. */
  int coluna;
/** Ligaçao a modificaçao anterior*/
  struct JOGADAS *proxima;
/** Caracter que foi modificado. */
  char modificado;
} JOGADAS;

/**
Estrutura de dados que guarda o tabuleiro de jogada onde estou, e possui uma lista interligada de jogadas assim como o endereço para o jogo anterior.
*/
typedef struct JOGO{
/** Tabuleiro onde estamos a jogar */
  TAB_BN estado;
/** Numero de jogadas efetuadas */
  int n_elementos;
/** Indice dos comandos.*/
  int n_com;
/** Cabeça das jogadas, isto é, das modificaçoes que ja foram feitas no tabuleiro.*/
  JOGADAS *head_jogadas;
/** Endereço do jogo anterior. */
  struct JOGO *proximo;
} JOGO;
/**
Estrutura de dados que representa a stack usada para guardar os jogos que foram feitos.
*/
typedef struct STACK_L{
/** Cabeça da stack representando o jogo que estamos a resolver. */
      JOGO *head;
/** Tamanho da stack, isto é, o numero de tabuleiros que ja foram carregados e possivelmente resolvidos. Permite ter uma ideia do numero de jogos ja feitos */
      int tamanho;
}STACK;


