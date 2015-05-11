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
		if(estado->tabuleiro[i][j]=='#'){
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			altera_estado(estado,i-1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
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
		if(estado->tabuleiro[i][j]=='#'){
				altera_estado(estado,i-1,j-1,'~',partida);
				if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
					altera_estado(estado,i,j-1,'o',partida);
				if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
					altera_estado(estado,i,j+1,'o',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='v'){
				altera_estado(estado,i-1,j-1,'~',partida);
				altera_estado(estado,i,j-1,'~',partida);
				altera_estado(estado,i,j+1,'~',partida);
				altera_estado(estado,i-1,j+1,'~',partida);
				if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
					altera_estado(estado,i-1,j,'o',partida);
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
				if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
					altera_estado(estado,i,j-1,'o',partida);
				altera_estado(estado,i-1,j,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='v'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);

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
		if(estado->tabuleiro[i][j]=='#'){
			altera_estado(estado,i-1,j-1,'~',partida);
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
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
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		}
		if(estado->tabuleiro[i][j]=='>'){
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
			
		}
		if(estado->tabuleiro[i][j]=='^'){
			altera_estado(estado,i,j-1,'~',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			altera_estado(estado,i,j+1,'~',partida);
		}
		if(estado->tabuleiro[i][j]=='#'){
			if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
			altera_estado(estado,i+1,j-1,'~',partida);
			altera_estado(estado,i+1,j,'~',partida);
			altera_estado(estado,i+1,j+1,'~',partida);
			if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
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
		if(is_segmento(estado->tabuleiro[i][j-1]) == 0)
				altera_estado(estado,i,j-1,'o',partida);
		altera_estado(estado,i+1,j-1,'~',partida);
		if(is_segmento(estado->tabuleiro[i+1][j]) == 0)
				altera_estado(estado,i+1,j,'o',partida);
		altera_estado(estado,i+1,j+1,'~',partida);
		if(is_segmento(estado->tabuleiro[i][j+1]) == 0)
				altera_estado(estado,i,j+1,'o',partida);
		altera_estado(estado,i-1,j+1,'~',partida);
		if(is_segmento(estado->tabuleiro[i-1][j]) == 0)
				altera_estado(estado,i-1,j,'o',partida);
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
Função que testa no interior do tabuleiro (exclui-se os cantos por serem casos especiais) se for possivel substituir segmentos desconhecidos de barcos por submarinos.


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

void from_unknown_to_destroyer(TAB_BN *estado, STACK *partida){
	int j;
	int i;

	for (i=0; i<estado->n_linhas; i++){
		for (j=1; j<((estado->n_colunas)-2); j++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && (estado->tabuleiro[i][j-1] == '~') && (estado->tabuleiro[i][j+2] == '~') ){
				altera_estado(estado, i, j, '<', partida);
				altera_estado(estado, i, j+1, '>', partida);
			}
		}
	}



	for (j=0; j<estado->n_colunas; j++){
		for (i=1; i<((estado->n_colunas)-2); i++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && (estado->tabuleiro[i-1][j] == '~') && (estado->tabuleiro[i+2][j] == '~') ){
				altera_estado(estado, i, j, '^', partida);
				altera_estado(estado, i+1, j, 'v', partida);
			}
		}
	}


	j=0;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && estado->tabuleiro[i][j+2]=='~'){
			altera_estado(estado, i, j, '<', partida);
			altera_estado(estado, i, j+1, '>', partida);
		}
	}

	i=0;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && estado->tabuleiro[i+2][j]=='~'){
			altera_estado(estado, i, j, '^', partida);
			altera_estado(estado, i+1, j, 'v', partida);
		}
	}


	j=estado->n_colunas-1;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j-1]) && estado->tabuleiro[i][j-2]=='~' ){
			altera_estado(estado, i, j, '>', partida);
			altera_estado(estado, i, j-1, '<', partida);
		}
	}

	i=estado->n_linhas-1;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i-1][j]) && estado->tabuleiro[i-2][j]=='~'){
			altera_estado(estado, i, j, 'v', partida);
			altera_estado(estado, i-1, j, '^', partida);
		}
	}
}


void from_unknown_to_cruiser(TAB_BN *estado, STACK *partida){
	int j;
	int i;

	for (i=0; i<estado->n_linhas; i++){
		for (j=1; j<((estado->n_colunas)-3); j++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && is_segmento(estado->tabuleiro[i][j+2]) && (estado->tabuleiro[i][j-1] == '~') && (estado->tabuleiro[i][j+3] == '~') ){
				altera_estado(estado, i, j, '<', partida);
				altera_estado(estado, i, j+1, '#', partida);
				altera_estado(estado, i, j+2, '>', partida);
			}
		}
	}

	for (j=0; j<estado->n_colunas; j++){
		for (i=1; i<((estado->n_colunas)-3); i++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && is_segmento(estado->tabuleiro[i+2][j]) && (estado->tabuleiro[i-1][j] == '~') && (estado->tabuleiro[i+3][j] == '~') ){
				altera_estado(estado, i, j, '^', partida);
				altera_estado(estado, i+1, j, '#', partida);
				altera_estado(estado, i+2, j, 'v', partida);
			}
		}
	}

	j=0;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && is_segmento(estado->tabuleiro[i][j+2]) && estado->tabuleiro[i][j+3]=='~'){
			altera_estado(estado, i, j, '<', partida);
			altera_estado(estado, i, j+1, '#', partida);
			altera_estado(estado, i, j+2, '>', partida);
		}
	}

	i=0;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && is_segmento(estado->tabuleiro[i+2][j]) && estado->tabuleiro[i+3][j]=='~'){
			altera_estado(estado, i, j, '^', partida);
			altera_estado(estado, i+1, j, '#', partida);
			altera_estado(estado, i+2, j, 'v', partida);
		}
	}

	j=estado->n_colunas-1;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j-1]) && is_segmento(estado->tabuleiro[i][j-2]) && estado->tabuleiro[i][j-3]=='~'){
			altera_estado(estado, i, j, '>', partida);
			altera_estado(estado, i, j-1, '#', partida);
			altera_estado(estado, i, j-2, '<', partida);
		}
	}

	i=estado->n_linhas-1;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i-1][j]) && is_segmento(estado->tabuleiro[i-2][j]) && estado->tabuleiro[i-3][j]=='~'){
			altera_estado(estado, i, j, 'v', partida);
			altera_estado(estado, i-1, j, '#', partida);
			altera_estado(estado, i-2, j, '^', partida);
		}
	}
}

void from_unknown_to_battleship(TAB_BN *estado, STACK *partida){

	int j;
	int i;

	for (i=0; i<estado->n_linhas; i++){
		for (j=1; j<((estado->n_colunas)-4); j++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && is_segmento(estado->tabuleiro[i][j+2]) && is_segmento(estado->tabuleiro[i][j+3]) && (estado->tabuleiro[i][j-1] == '~') && (estado->tabuleiro[i][j+4] == '~') ){
				altera_estado(estado, i, j, '<', partida);
				altera_estado(estado, i, j+1, '#', partida);
				altera_estado(estado, i, j+2, '#', partida);
				altera_estado(estado, i, j+3, '>', partida);
			}
		}
	}

	for (j=0; j<estado->n_colunas; j++){
		for (i=1; i<((estado->n_colunas)-4); i++){
			if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && is_segmento(estado->tabuleiro[i+2][j]) && is_segmento(estado->tabuleiro[i+3][j]) && (estado->tabuleiro[i-1][j] == '~') && (estado->tabuleiro[i+4][j] == '~') ){
				altera_estado(estado, i, j, '^', partida);
				altera_estado(estado, i+1, j, '#', partida);
				altera_estado(estado, i+2, j, '#', partida);
				altera_estado(estado, i+3, j, 'v', partida);
			}
		}
	}


	j=0;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j+1]) && is_segmento(estado->tabuleiro[i][j+2]) && is_segmento(estado->tabuleiro[i][j+3]) && estado->tabuleiro[i][j+4]=='~'){
			altera_estado(estado, i, j, '<', partida);
			altera_estado(estado, i, j+1, '#', partida);
			altera_estado(estado, i, j+2, '#', partida);
			altera_estado(estado, i, j+3, '>', partida);
		}
	}


	i=0;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i+1][j]) && is_segmento(estado->tabuleiro[i+2][j]) && is_segmento(estado->tabuleiro[i+3][j]) && estado->tabuleiro[i+4][j]=='~'){
			altera_estado(estado, i, j, '^', partida);
			altera_estado(estado, i+1, j, '#', partida);
			altera_estado(estado, i+2, j, '#', partida);
			altera_estado(estado, i+3, j, 'v', partida);
		}
	}

	j=estado->n_colunas-1;
	for (i=0; i<estado->n_linhas; i++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i][j-1]) && is_segmento(estado->tabuleiro[i][j-2]) && is_segmento(estado->tabuleiro[i][j-3]) && estado->tabuleiro[i][j-4]=='~'){
			altera_estado(estado, i, j, '>', partida);
			altera_estado(estado, i, j-1, '#', partida);
			altera_estado(estado, i, j-2, '#', partida);
			altera_estado(estado, i, j-3, '<', partida);
		}
	}

	i=estado->n_linhas-1;
	for (j=0; j<estado->n_colunas; j++){
		if (is_segmento(estado->tabuleiro[i][j]) && is_segmento(estado->tabuleiro[i-1][j]) && is_segmento(estado->tabuleiro[i-2][j]) && is_segmento(estado->tabuleiro[i-3][j]) && estado->tabuleiro[i-4][j]=='~'){
			altera_estado(estado, i, j, 'v', partida);
			altera_estado(estado, i-1, j, '#', partida);
			altera_estado(estado, i-2, j, '#', partida);
			altera_estado(estado, i-3, j, '^', partida);
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

int verifica_cantos(int i, int j, TAB_BN *estado){
	int resultado = 1;
	if(i==0 && j==0){
		if(estado->tabuleiro[i][j] == '>' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == 'v')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~')
				resultado = 0;
		}
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==0){
		if(estado->tabuleiro[i][j] == '>')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1, '>') || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}	
	}
	else if(i==(estado->n_linhas)-1 && j==0){
		if(estado->tabuleiro[i][j] == '>' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(verifica_char(estado, i, j+1, '>') || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado, i-1, j, '^') )
				resultado = 0;
		}
	}
	else if(i==(estado->n_linhas)-1 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || verifica_char(estado, i, j+1, '>') || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || verifica_char(estado, i, j+1, '>') || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
	}
	else if(i==(estado->n_linhas)-1 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<' || estado->tabuleiro[i][j] == '#' || estado->tabuleiro[i][j] == '^')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i-1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i-1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
	}
	else if((i!=0 && i!=(estado->n_linhas)-1) && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v') || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == 'v'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || verifica_char(estado, i-1, j, '^'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i-1][j] != '~')
				resultado = 0;
		}
	}
	else if(i==0 && j==(estado->n_colunas)-1){
		if(estado->tabuleiro[i][j] == '<' || estado->tabuleiro[i][j] == 'v' || estado->tabuleiro[i][j] == '#')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' )
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v'))
				resultado = 0;
		}
	}
	else if(i==0 && (j!=0 && j!=(estado->n_colunas)-1)){
		if(estado->tabuleiro[i][j] == 'v')
			resultado = 0;
		else if(estado->tabuleiro[i][j] == 'O'){
			if(estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '<'){
			if(estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '>'){
			if(verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~')
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '#'){
			if(verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1, '>'))
				resultado = 0;
		}
		else if(estado->tabuleiro[i][j] == '^'){
			if(estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~')
				resultado = 0;
		}
	}
	return resultado;
}


int verifica_meio(int i, int j, TAB_BN *estado){
	int resultado = 1;
	if(estado->tabuleiro[i][j] == 'O'){
		if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '<'){
		if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1,'>') || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '>'){
		if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '#'){
		if(estado->tabuleiro[i-1][j-1] != '~' || verifica_char(estado, i, j-1, '<') || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || verifica_char(estado, i, j+1, '>') || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado, i-1, j, '^'))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == 'v'){
		if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || estado->tabuleiro[i+1][j] != '~' || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || verifica_char(estado ,i-1, j, '^'))
			resultado = 0;
	}
	else if(estado->tabuleiro[i][j] == '^'){
		if(estado->tabuleiro[i-1][j-1] != '~' || estado->tabuleiro[i][j-1] != '~' || estado->tabuleiro[i+1][j-1] != '~' || verifica_char(estado, i+1, j, 'v') || estado->tabuleiro[i+1][j+1] != '~' || estado->tabuleiro[i][j+1] != '~' || estado->tabuleiro[i-1][j+1] != '~' || estado->tabuleiro[i-1][j] != '~')
			resultado = 0;
	}
	return resultado;
}




