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


/**
Função que substitui os caracteres 'o' (pedaços de barco de tamanho desconhecido) pelos 4 respectivos tipos de barcos existentes ('O', '<>', '<#>', '<##>') quando à volta for tudo '~' ou esses caracteres se encontrem no limite do tabuleiro

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/

void estrategia_4(TAB_BN *estado,STACK *partida){

	if (estado->n_linhas > 3 && estado->n_colunas > 3){
		from_unknown_to_submarine(estado, partida);
	}

	if (estado->n_linhas > 4 && estado->n_colunas > 4){
		from_unknown_to_destroyer(estado, partida);
	}

	if (estado->n_linhas > 5 && estado->n_colunas > 5){
		from_unknown_to_cruiser(estado, partida);
	}

	if (estado->n_linhas > 6 && estado->n_colunas > 6){
		from_unknown_to_battleship(estado, partida);
	}


}
