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


/**
Função que substitui os caracteres 'o' (pedaços de barco de tamanho desconhecido) pelos 4 respectivos tipos de barcos existentes ('O', '<>', '<#>', '<##>') quando à volta for tudo '~' ou esses caracteres se encontrem no limite do tabuleiro

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/

int estrategia_4(TAB_BN *estado,STACK *partida){
JOGADAS *tmp=partida->head->head_jogadas;
	int i; int n=-1;
	int lin = estado->n_linhas, col = estado->n_colunas;
	from_unknown_to_submarine(estado, partida);


	for (i=0; i<lin; i++){
		from_unknown_to_whatever_horizontal(estado, partida,i);
		from_unknown_to_middle_horizontal(estado, partida, i);
		if (i>0 || i<estado->n_linhas){
			particular_middleSegment_case_horizontal(estado, partida, i);
		}
	}
	for (i=0; i<col; i++){
		from_unknown_to_whatever_vertical(estado, partida,i);
		from_unknown_to_middle_vertical(estado, partida, i);
		if (i>0 || i<col){
			particular_middleSegment_case_vertical(estado, partida, i);
		}

	}
if(tmp!=partida->head->head_jogadas) n=1;
return n;

}
