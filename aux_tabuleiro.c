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
Funçao que verifica se o caracter é um segmento de barco ou submarino.

@param a: Character que vai ser testado.

@return : Devolve TRUE (1) caso o caracter corresponde a um submarino ou segmento de barco, FALSE (0) caso contrario.
*/
int is_segmento(char a){
	if (a=='O' || a=='<' || a=='>' || a=='#' || a=='^' || a=='v' || a=='o')
		return TRUE;
	else 
		return FALSE;
}

/**
Função que preenche os cantos do tabuleiro em função do caracter presente.

@param i: Indice da linha que se quer preencher.

@param j: Indice da coluna que se quer preencher.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/


void preenche_cantos(int i, int j, TAB_BN *estado,STACK *partida){
	if(i==0 && j==0){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='o')
			altera_estado(estado,i+1,j+1,'~',partida);
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==0){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='#'){
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o'){
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
		}
	}
	else if(i==(estado->n_linhas)-1 && j==0){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o')
			altera_estado(estado,i-1,j+1,'~',partida);
	}
	else if(i==(estado->n_linhas)-1 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j]=='O'){
				altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i,j+1,'~',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
				altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
				if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
					altera_estado(estado,i,j+1,'o',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);

		}
		else if(estado->tabuleiro[i][j]=='>'){
				altera_estado(estado,i-1,j-1,'~',partida);
				if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
					altera_estado(estado,i,j-1,'o',partida);
				altera_estado(estado,i,j+1,'~',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='#'){
				altera_estado(estado,i-1,j-1,'~',partida);
				if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
					altera_estado(estado,i,j-1,'o',partida);
				if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
					altera_estado(estado,i,j+1,'o',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
				altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i,j+1,'~',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
					altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
		}
	}
	else if(i==(estado->n_linhas)-1 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j]=='O'){
				altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='>'){
				altera_estado(estado,i-1,j-1,'~',partida);
				if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
					altera_estado(estado,i,j-1,'o',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);

		}
		else if(estado->tabuleiro[i][j]=='o')
			altera_estado(estado,i-1,j-1,'~',partida);
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);

		}
		else if(estado->tabuleiro[i][j]=='>'){
			altera_estado(estado,i-1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='#'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
		}
	}
	else if(i==0 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);

		}
		else if(estado->tabuleiro[i][j]=='>'){
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o')
			altera_estado(estado,i+1,j-1,'~',partida);
	}
	else if(i==0 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='>'){
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='#'){
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		}
		else if(estado->tabuleiro[i][j]=='o'){
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
		}
	}
}

/**
Função que preenche lugares dentro do tabuleiro em função do caracter presente.

@param i: Indice da linha que se quer preencher.

@param j: Indice da coluna que se quer preencher.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/
void preenche_meio(int i, int j, TAB_BN *estado, STACK *partida){
	if(estado->tabuleiro[i][j]=='O'){
		altera_estado(estado,i-1,j-1,'~',partida);
		altera_estado(estado,i,j-1,'~',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		altera_estado(estado,i+1,j,'~',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		altera_estado(estado,i,j+1,'~',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='<'){
		altera_estado(estado,i-1,j-1,'~',partida);
		altera_estado(estado,i,j-1,'~',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		altera_estado(estado,i+1,j,'~',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='>'){
		altera_estado(estado,i-1,j-1,'~',partida);
		if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		altera_estado(estado,i+1,j,'~',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		altera_estado(estado,i,j+1,'~',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='#'){
		altera_estado(estado,i-1,j-1,'~',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='^'){
		altera_estado(estado,i-1,j-1,'~',partida);		
		altera_estado(estado,i,j-1,'~',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		altera_estado(estado,i,j+1,'~',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='v'){
		altera_estado(estado,i-1,j-1,'~',partida);		
		altera_estado(estado,i,j-1,'~',partida);		
		altera_estado(estado,i+1,j-1,'~',partida);		
		altera_estado(estado,i+1,j,'~',partida);		
		altera_estado(estado,i+1,j+1,'~',partida);		
		altera_estado(estado,i,j+1,'~',partida);		
		altera_estado(estado,i-1,j+1,'~',partida);	
		if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);	
	}
	else if(estado->tabuleiro[i][j]=='o'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
	}
}


/*
Funções usadas na Estrategia 2
*/
/**
Função que caso a linha seja completa,isto é, ja estao todos os segmentos metidos na linha, preencha os lugares desconhecidas ('.') por agua ('~').

@param linha: Indice da linha que se quer testar.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/
void arruma_linha(TAB_BN *estado, int linha, STACK *partida){
	int j;
	int count_boats=0;
	for (j=0;j<(estado->n_colunas);j++){
		if ((estado->tabuleiro[linha][j]!='.') && (estado->tabuleiro[linha][j]!='~')){
			count_boats++;
		}
	}

	if (count_boats==(estado->info_linhas[linha])){
		for (j=0;j<(estado->n_colunas);j++){
			if (estado->tabuleiro[linha][j]=='.')
				altera_estado(estado,linha,j,'~',partida);
			
		}
	}
}

/**
Função que caso a coluna seja completa, isto é, ja estao todos os segmentos metidos na coluna, preencha os lugares desconhecidos ('.') por agua ('~').

@param coluna: Indice da coluna que se quer testar.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/
void arruma_coluna(TAB_BN *estado, int coluna, STACK *partida){
	int i;
	int count_boats=0;
	for (i=0;i<(estado->n_linhas);i++){
		if ((estado->tabuleiro[i][coluna]!='.') && (estado->tabuleiro[i][coluna]!='~')){
			count_boats++;
		}
	}

	if (count_boats==(estado->info_colunas[coluna])){
		for (i=0;i<(estado->n_colunas);i++){
			if (estado->tabuleiro[i][coluna]=='.')
				altera_estado(estado,i,coluna,'~',partida);
				
			
		}
	}
}

/**
Função que verifica o conteudo de uma linha e caso seja possivel mete o caracter 'o' nos lugares desconhecidos ('.').

@param linha: Indice da linha que se quer testar.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/
void coloca_o_na_linha (TAB_BN *estado, int linha, STACK *partida){
	int j;
	int count = 0;
	for (j=0; j<(estado->n_colunas); j++){
		if (estado->tabuleiro[linha][j]=='~')
			count ++;
	}

	count = (estado->n_colunas) - count;
	if (count == estado->info_linhas[linha]){
		for (j=0; j<(estado->n_colunas); j++){
			if (estado->tabuleiro[linha][j]=='.')
				altera_estado(estado, linha, j, 'o', partida);
		}
	}
}
/**
Função que verifica o conteudo de uma coluna e caso seja possivel mete o caracter 'o' nos lugares desconhecidos ('.').

@param coluna: Indice da coluna que se quer testar.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/

void coloca_o_na_coluna (TAB_BN *estado, int coluna, STACK *partida){
	int i;
	int count = 0;
	for (i=0; i<(estado->n_linhas); i++){
		if (estado->tabuleiro[i][coluna]=='~')
			count ++;
	}

	count = (estado->n_linhas) - count;
	if (count == estado->info_colunas[coluna]){
		for (i=0; i<(estado->n_linhas); i++){
			if (estado->tabuleiro[i][coluna]=='.')
				altera_estado(estado, i, coluna, 'o', partida);
		}
	}
}



/**
Função que substitui os caracteres 'o' (pedaços de barco de tamanho desconhecido) por submarinos ('O') quando à volta for tudo '~' ou esse caracter se encontre no limite do tabuleiro

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

*/


void from_unknown_to_submarine(TAB_BN *estado, STACK *partida){
	int j;
	int i;


	for (i=1; i<estado->n_linhas-1; i++){
		for (j=1; j<estado->n_colunas-1; j++){
			if (estado->tabuleiro[i][j]=='o' && estado->tabuleiro[i-1][j]=='~' && estado->tabuleiro[i+1][j]=='~' && estado->tabuleiro[i][j-1]=='~' && estado->tabuleiro[i][j+1]=='~' )
				altera_estado(estado, i, j, 'O', partida);
		}
	}


	i=0;
	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[i][j]=='o' && estado->tabuleiro[i][j+1]=='~' && estado->tabuleiro[i][j-1]=='~' && estado->tabuleiro[i+1][j]=='~'){
				altera_estado(estado, i, j, 'O', partida);
		}		
	}

	i=estado->n_linhas-1;
	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[i][j]=='o' && estado->tabuleiro[i][j+1]=='~' && estado->tabuleiro[i][j-1]=='~' && estado->tabuleiro[i-1][j]=='~'){
				altera_estado(estado, i, j, 'O', partida);
		}		
	}

	j=0;
	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][j]=='o' && estado->tabuleiro[i+1][j]=='~' && estado->tabuleiro[i-1][j]=='~' && estado->tabuleiro[i][j+1]=='~'){
				altera_estado(estado, i, j, 'O', partida);
		}		
	}

	j=estado->n_colunas-1;
	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][j]=='o' && estado->tabuleiro[i+1][j]=='~' && estado->tabuleiro[i-1][j]=='~' && estado->tabuleiro[i][j-1]=='~'){
				altera_estado(estado, i, j, 'O', partida);
		}		
	}

	if (estado->tabuleiro[0][0]=='o' && estado->tabuleiro[0][1]=='~' && estado->tabuleiro[1][0]=='~' )
		altera_estado(estado,0,0,'O', partida);

	if (estado->tabuleiro[estado->n_linhas-1][0]=='o' && estado->tabuleiro[estado->n_linhas-2][0]=='~' && estado->tabuleiro[estado->n_linhas-1][1]=='~' )
		altera_estado(estado,estado->n_linhas-1,0,'O', partida);

	if (estado->tabuleiro[0][estado->n_colunas-1]=='o' && estado->tabuleiro[0][estado->n_colunas-2]=='~' && estado->tabuleiro[1][estado->n_colunas-1]=='~' )
		altera_estado(estado,0,estado->n_colunas-1,'O', partida);

	if (estado->tabuleiro[estado->n_linhas-1][estado->n_colunas-1]=='o' && estado->tabuleiro[estado->n_linhas-1][estado->n_colunas-2]=='~' && estado->tabuleiro[estado->n_linhas-2][estado->n_colunas-1]=='~' )
		altera_estado(estado,estado->n_linhas-1,estado->n_colunas-1,'O', partida);
}



/**
Função que substitui os caracteres 'o' (pedaços de barco de tamanho desconhecido) por barcos de tamanho N ('<#...N#>') horizontalmente quando à volta for tudo '~' ou esses caracteres se encontrem no limite do tabuleiro

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param linha : Linha do tabuleiro sobre a qual a função vai exercer efeito.


*/

void from_unknown_to_whatever_horizontal(TAB_BN *estado, STACK *partida, int linha){
	int i=0;
	int j=0;
	int begin=0;

	for (j=0; j<estado->n_colunas; j++){
		if ( (is_segmento(estado->tabuleiro[linha][j]) == FALSE) && (i==0) ) {
			continue;
		}

		if (is_segmento(estado->tabuleiro[linha][j]) == FALSE && (i==1)) {
			i=0;
			continue;
		}

		else if (is_segmento(estado->tabuleiro[linha][j])){
			i++;
		}

		if ( (is_segmento(estado->tabuleiro[linha][j]) == FALSE) && (i>1) ) {
			begin=j-i;
			for (i=begin ; i<j; i++){
				altera_estado(estado,linha, i, 'B', partida);
			}
			i=0;
			begin = 0;
		}


		
		if (i>1 && j == estado->n_colunas-1){
			begin = j-i;
			for (i=begin+1 ; i<estado->n_colunas; i++){
				altera_estado(estado,linha, i, 'B', partida);
			}
		}
	}


	i=0;
	j=0;
	begin=0;


	if (estado->tabuleiro[linha][estado->n_colunas-1]=='B')
		altera_estado(estado,linha, estado->n_colunas-1, '>', partida);

	if (estado->tabuleiro[linha][0]=='B')
		altera_estado(estado,linha, 0, '<', partida);


	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[linha][j]=='B' && estado->tabuleiro[linha][j-1]=='~'){
			altera_estado(estado,linha, j, '<', partida);
		}
		if (estado->tabuleiro[linha][j]=='B' && estado->tabuleiro[linha][j+1]=='~'){
			altera_estado(estado,linha, j, '>', partida);
		}
	}

	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[linha][j]=='B' && estado->tabuleiro[linha][j+1]=='B'){
			altera_estado(estado,linha, j, '#', partida);
		}
	}

	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[linha][j]=='B'){
			altera_estado(estado,linha, j, 'o', partida);
		}
	}


}

/**
Função que substitui os caracteres 'o' (pedaços de barco de tamanho desconhecido) por barcos de tamanho N ('<#...N#>') verticalmente quando à volta for tudo '~' ou esses caracteres se encontrem no limite do tabuleiro

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param coluna : Coluna do tabuleiro sobre a qual a função vai exercer efeito.


*/



void from_unknown_to_whatever_vertical(TAB_BN *estado, STACK *partida, int coluna){
	int j=0;
	int i=0;
	int begin=0;

	for (i=0; i<estado->n_linhas; i++){
		if ( (is_segmento(estado->tabuleiro[i][coluna]) == FALSE) && (j==0) ) {
			continue;
		}


		if (is_segmento(estado->tabuleiro[i][coluna]) == FALSE && (j==1)) {
			j=0;
			continue;
		}

		else if (is_segmento(estado->tabuleiro[i][coluna])){
			j++;
		}

		if ( (is_segmento(estado->tabuleiro[i][coluna]) == FALSE) && (j>1) ) {
			begin=i-j;
			for (j=begin ; j<i; j++){
				altera_estado(estado, j, coluna, 'B', partida);
			}
			j=0;
			begin = 0;
		}

		if (j>1 && i == estado->n_linhas-1){
			begin = i-j;
			for (j=begin+1 ; j<estado->n_linhas; j++){
				altera_estado(estado,j, coluna, 'B', partida);
			}
		}
	}


	i=0;
	j=0;
	begin=0;


	if (estado->tabuleiro[estado->n_linhas-1][coluna]=='B')
		altera_estado(estado,estado->n_linhas-1, coluna, 'v', partida);

	if (estado->tabuleiro[0][coluna]=='B')
		altera_estado(estado,0, coluna, '^', partida);


	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][coluna]=='B' && estado->tabuleiro[i-1][coluna]=='~'){
			altera_estado(estado, i, coluna, '^', partida);
		}
		if (estado->tabuleiro[i][coluna]=='B' && estado->tabuleiro[i+1][coluna]=='~'){
			altera_estado(estado,i, coluna, 'v', partida);
		}
	}

	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][coluna]=='B' && estado->tabuleiro[i+1][coluna]=='B'){
			altera_estado(estado,i, coluna, '#', partida);
		}
	}

	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][coluna]=='B'){
			altera_estado(estado,i, coluna, 'o', partida);
		}
	}

}



/**
Função que substitui os caracteres 'o' (de meios de barcos) por caracteres '#' horizontalmente.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param linha : Linha do tabuleiro sobre a qual a função vai exercer efeito.


*/


void from_unknown_to_middle_horizontal(TAB_BN *estado, STACK *partida, int linha){
	int j;
	for (j=1; j<estado->n_colunas-1; j++){
		if (estado->tabuleiro[linha][j]=='o' && is_segmento(estado->tabuleiro[linha][j-1]) && is_segmento(estado->tabuleiro[linha][j+1])){
			altera_estado(estado, linha, j, '#', partida);
		}
	}
}



/**
Função que substitui os caracteres 'o' (de meios de barcos) por caracteres '#' horizontalmente.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param coluna : Coluna do tabuleiro sobre a qual a função vai exercer efeito.


*/

void from_unknown_to_middle_vertical(TAB_BN *estado, STACK *partida, int coluna){
	int i;
	for (i=1; i<estado->n_linhas-1; i++){
		if (estado->tabuleiro[i][coluna]=='o' && is_segmento(estado->tabuleiro[i-1][coluna]) && is_segmento(estado->tabuleiro[i+1][coluna])){
			altera_estado(estado, i, coluna, '#', partida);
		}
	}
}






int verifica_info(TAB_BN *estado){
	int i,j;
	int resultado=1;
	int contador_linhas=0;
	int contador_colunas=0;
	for(i=0;i<estado->n_linhas;i++){
		for(j=0;j<estado->n_colunas;j++){
			if(estado->tabuleiro[i][j] != '~' && estado->tabuleiro[i][j] != '.')
				contador_linhas++;
			if(estado->tabuleiro[j][i] != '~' && estado->tabuleiro[j][i] != '.')
				contador_colunas++;
		}
		if(contador_linhas > (estado->info_linhas[i]) || contador_colunas > (estado->info_colunas[i]))
			resultado=0;
		contador_linhas=0;
		contador_colunas=0;
	}
	return resultado;
}

int verifica_char(TAB_BN *estado, int i, int j, char a){
	if(estado->tabuleiro[i][j] == a || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == 'o' || estado->tabuleiro[i][j] == '.')
		return 0;
	else
		return 1;
}

int verifica_lado(TAB_BN *estado, int i, int j){
	if(estado->tabuleiro[i][j] == '~' || estado->tabuleiro[i][j] == '.')
		return 0;
	else
		return 1;
}

int verifica_cantos(int i, int j, TAB_BN *estado){
	int resultado = 1;
	if(i==0 && j==0){
		if(estado->tabuleiro[i][j] == '>' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == 'v')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1))
				resultado = 0;
		}
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==0){
		if(estado->tabuleiro[i][j] == '>')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1, '>') || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}	
	}
	else if(i==(estado->n_linhas)-1 && j==0){
		if(estado->tabuleiro[i][j] == '>' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_char(estado, i, j+1, '>') || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_char(estado, i-1, j, '^') )
				resultado = 0;
		}
	}
	else if(i==(estado->n_linhas)-1 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_char(estado, i, j+1, '>') || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_char(estado, i, j+1, '>') || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
	}
	else if(i==(estado->n_linhas)-1 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i-1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i-1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v') || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i-1, j))
				resultado = 0;
		}
	}
	else if(i==0 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<' || estado->tabuleiro[i][j] == 'v' || estado->tabuleiro[i][j] == '#')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v'))
				resultado = 0;
		}
	}
	else if(i==0 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j] == 'v')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1))
				resultado = 0;
		}
	}
	return resultado;
}


int verifica_meio(int i, int j, TAB_BN *estado){
	int resultado = 1;
	if(estado->tabuleiro[i][j] == 'O'){
		if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '<'){
		if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1,'>') || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '>'){
		if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '#'){
		if(verifica_lado(estado, i-1, j-1) || verifica_char(estado, i, j-1, '<') || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_char(estado, i, j+1, '>') || verifica_lado(estado, i-1, j+1) || verifica_char(estado, i-1, j, '^'))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == 'v'){
		if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_lado(estado, i+1, j) || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_char(estado ,i-1, j, '^'))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '^'){
		if(verifica_lado(estado, i-1, j-1) || verifica_lado(estado, i, j-1) || verifica_lado(estado, i+1, j-1) || verifica_char(estado, i+1, j, 'v') || verifica_lado(estado, i+1, j+1) || verifica_lado(estado, i, j+1) || verifica_lado(estado, i-1, j+1) || verifica_lado(estado, i-1, j))
			resultado = 0;
	}
	return resultado;
}




