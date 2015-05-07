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
#define FALSE -1
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif


/* Funçao que ira desfazer o ultimo comando executado */

int cmd_D(TAB_BN *estado,STACK *partida){
      int n=1;
      if(partida->head==NULL && partida->tamanho==1) n=-1;
      else popStack(estado,partida);
      return n;
}



/*
desfaz um comando / jogada até ao anterior ;
*/

void desfCmd(TAB_BN *estado,STACK *partida){
        int i; JOGADAS *tmp;
        i= partida->head->head_jogadas->indcom ;
        
        while((partida->head->head_jogadas!=NULL) && (partida->head->head_jogadas->indcom==i ) ){

             int l = partida->head->head_jogadas->linha, col = partida->head->head_jogadas->coluna;

             estado->tabuleiro[l][col] = partida->head->head_jogadas->modificado;
             tmp = partida->head->head_jogadas; /* uma vez desfazido é preciso libertar a memoria;*/
             partida->head->head_jogadas=partida->head->head_jogadas->proxima; /* modifica-se a cabeça da lista;*/
             
             free(tmp); /* liberta-se a antiga cabeça.*/
             partida->head->n_elementos--;
            }
}


/*aplica os cmd das jogadas ao tabuleiro que foi carregado. Esta funçao tera que saber se tem ou nao de aplicar as modificaçoes
*/

void aplicaCmd( STACK *partida){
	JOGADAS *tmp = partida->head->head_jogadas;

while( partida->head->head_jogadas!=NULL){

	int linha=partida->head->head_jogadas->linha;
	int coluna=partida->head->head_jogadas->coluna;

partida->head->estado.tabuleiro[linha][coluna]=partida->head->head_jogadas->modificado;
partida->head->head_jogadas=partida->head->head_jogadas->proxima;

					}
partida->head->head_jogadas= tmp;
}


