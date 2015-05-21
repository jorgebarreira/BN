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
Função para percorrer todo o tabuleiro e sempre que encontrar um segmento preencher agua a volta onde necessario.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return Devolve 1 se fez algo, -1 caso contrario.
*/

int estrategia_1(TAB_BN *estado,STACK *partida){
JOGADAS *tmp=partida->head->head_jogadas;
	int i,j;
	int n=-1;
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
	if(tmp!=partida->head->head_jogadas) n=1;
	return n;
}

/**
Estrategia que percorre todo o tabuleiro e sempre que a linha/coluna já tiver todos os barcos colocar agua.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return Devolve 1 se fez uma modificaçao, -1 caso contrario.

*/

int estrategia_2(TAB_BN *estado,STACK *partida){
JOGADAS *tmp=partida->head->head_jogadas;
	int i;
	int n = -1;
	for (i=0;i<(estado->n_linhas);i++){
		arruma_linha(estado, i,partida);
		
	}
	
	for (i=0;i<(estado->n_colunas);i++){
		arruma_coluna(estado, i,partida);
			
	}
	if(tmp!=partida->head->head_jogadas) n=1;
	/*estrategia_4(estado, partida);*/
	/*if(partida->head->head_jogadas!=NULL && partida->head->head_jogadas->indcom==partida->head->n_com) partida->head->n_com++;*/
	return n;
}

/**
Estrategia que percorre todo o tabuleiro e sempre que for possivel adiciona o segmento desconhecido('o') na posiçao.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return Devolve 1 se fez modificaçoes, -1 se nao fez nada.

*/
int estrategia_3(TAB_BN *estado, STACK *partida){
JOGADAS *tmp=partida->head->head_jogadas;
	int i;
	int n=-1;
	for (i=0; i<(estado->n_linhas); i++){
		coloca_o_na_linha(estado, i, partida);
		
	}
	
	for (i=0; i<(estado->n_colunas); i++){
		coloca_o_na_coluna(estado, i, partida);
		
	}
	estrategia_4(estado, partida);
	if(tmp!=partida->head->head_jogadas) n=1;
	return n; 
}
