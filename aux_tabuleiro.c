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

int is_segmento(char a){
	if (a=='O' || a=='<' || a=='>' || a=='#' || a=='^' || a=='v')
		return TRUE;
	else 
		return FALSE;
}

/*
Funções usadas na Estrategia 1
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
			altera_estado(estado,i,j+1,'.',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i+1,j,'.',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
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
			altera_estado(estado,i,j+1,'.',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'.',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'.',partida);
		}
		if(estado->tabuleiro[i][j]=='#'){
			altera_estado(estado,i+1,j,'.',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'.',partida);
		}
	}
	else if(i==(estado->n_linhas)-1 && j==0){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='<'){
			altera_estado(estado,i,j+1,'.',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			altera_estado(estado,i-1,j,'.',partida);
		}
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
					altera_estado(estado,i,j+1,'.',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
					altera_estado(estado,i-1,j,'~',partida);

		}
		else if(estado->tabuleiro[i][j]=='>'){
					altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'.',partida);
					altera_estado(estado,i,j+1,'~',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
					altera_estado(estado,i-1,j,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='#'){
					altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'.',partida);
					altera_estado(estado,i,j+1,'.',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
					altera_estado(estado,i-1,j,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='v'){
				altera_estado(estado,i-1,j-1,'~',partida);
					altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i,j+1,'~',partida);
					altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'.',partida);
		}
	}
	else if(i==(estado->n_linhas)-1 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j]=='O'){
					altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
					altera_estado(estado,i-1,j,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='>'){
				altera_estado(estado,i-1,j-1,'~',partida);
				/*estado->tabuleiro[i-1][j-1]='~';*/
					altera_estado(estado,i,j-1,'.',partida);
				/*estado->tabuleiro[i][j-1]='.';*/
				altera_estado(estado,i-1,j,'~',partida);
				/*estado->tabuleiro[i-1][j]='~';*/
		}
		if(estado->tabuleiro[i][j]=='v'){
				altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i-1,j,'.',partida);

		}
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
			altera_estado(estado,i,j-1,'.',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
				altera_estado(estado,i+1,j,'.',partida);
			altera_estado(estado,i-1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='v'){
				altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
				altera_estado(estado,i-1,j,'.',partida);
		}
		if(estado->tabuleiro[i][j]=='#'){
			altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
				altera_estado(estado,i+1,j,'.',partida);
			altera_estado(estado,i-1,j,'.',partida);
		}
	}
	else if(i==0 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);

		}
		else if(estado->tabuleiro[i][j]=='>'){
			altera_estado(estado,i,j-1,'.',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
		}
		else if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
		}
	}
	else if(i==0 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j]=='O'){
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
				altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='<'){
				altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
				altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
				altera_estado(estado,i,j+1,'.',partida);
		}
		if(estado->tabuleiro[i][j]=='>'){
				altera_estado(estado,i,j-1,'.',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
				altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
				altera_estado(estado,i,j+1,'~',partida);
			
		}
		if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'.',partida);
				altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='#'){
				altera_estado(estado,i,j-1,'.',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
				altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
				altera_estado(estado,i,j+1,'.',partida);
		}
	}
}


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
		altera_estado(estado,i,j+1,'.',partida);
altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='>'){
altera_estado(estado,i-1,j-1,'~',partida);
		altera_estado(estado,i,j-1,'.',partida);
altera_estado(estado,i+1,j-1,'~',partida);
		altera_estado(estado,i+1,j,'~',partida);
altera_estado(estado,i+1,j+1,'~',partida);
		altera_estado(estado,i,j+1,'~',partida);
altera_estado(estado,i-1,j+1,'~',partida);
		altera_estado(estado,i-1,j,'~',partida);
	}
	else if(estado->tabuleiro[i][j]=='#'){
altera_estado(estado,i-1,j-1,'~',partida);
altera_estado(estado,i,j-1,'.',partida);
altera_estado(estado,i+1,j-1,'~',partida);
altera_estado(estado,i+1,j,'.',partida);
altera_estado(estado,i+1,j+1,'~',partida);
altera_estado(estado,i,j+1,'.',partida);
altera_estado(estado,i-1,j+1,'~',partida);
altera_estado(estado,i-1,j,'.',partida);
	}
	else if(estado->tabuleiro[i][j]=='^'){
altera_estado(estado,i-1,j-1,'~',partida);
		
altera_estado(estado,i,j-1,'~',partida);
		
altera_estado(estado,i+1,j-1,'~',partida);
		
altera_estado(estado,i+1,j,'.',partida);
		
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
altera_estado(estado,i-1,j,'.',partida);
		
	}
}


/*
Funções usadas na Estrategia 2
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

