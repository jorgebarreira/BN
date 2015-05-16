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
Função para percorrer todo o tabuleiro e sempre que encontrar um segmento preencher agua a volta onde necessario.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.


*/

void estrategia_1(TAB_BN *estado,STACK *partida){
	int i,j;
	for(i=0;i<estado->n_linhas;i++){
		for(j=0;j<estado->n_colunas;j++){
			if(is_segmento(estado->tabuleiro[i][j])){
				if(i==0 || j==0 || i==(estado->n_linhas)-1 || j==(estado->n_colunas)-1)
					preenche_cantos(i,j,estado,partida);
				else
					preenche_meio(i,j,estado,partida);
			}
		}
	}

	estrategia_4(estado, partida);
}

/**
Estrategia que percorre todo o tabuleiro e sempre que a linha/coluna já tiver todos os barcos colocar agua.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/

void estrategia_2(TAB_BN *estado,STACK *partida){
	int i;
	for (i=0;i<(estado->n_linhas);i++){
		arruma_linha(estado, i,partida);
	}
	for (i=0;i<(estado->n_colunas);i++){
		arruma_coluna(estado, i,partida);
	}

	estrategia_4(estado, partida);
	/*if(partida->head->head_jogadas!=NULL && partida->head->head_jogadas->indcom==partida->head->n_com) partida->head->n_com++;*/
}

/**
Estrategia que percorre todo o tabuleiro e sempre que for possivel adiciona o segmento desconhecido('o') na posiçao.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/
void estrategia_3(TAB_BN *estado, STACK *partida){
	int i;
	for (i=0; i<(estado->n_linhas); i++){
		coloca_o_na_linha(estado, i, partida);
	}
	for (i=0; i<(estado->n_colunas); i++){
		coloca_o_na_coluna(estado, i, partida);
	}	
	estrategia_4(estado, partida);
}
