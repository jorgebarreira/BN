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
#include "Trabalho.h"
#include "aux_muda_tab.h"
#include "aux_stack.h"
#include "desf_f.h"
#define TRUE 1
#define FALSE -1
#define MAX_SIZE 100
#define MAX_LINHA 1024


#endif


/* Cria uma caixa jogo e poe-a como sendo a nova cabeça da stack */

int newJOGO(TAB_BN *estado,STACK *partida){
      int n=1;
      JOGO *nova = malloc( sizeof(struct JOGO) );
      if( nova != NULL)
		{
		if(partida->head== NULL){
		  nova->proximo = partida->head ;
                  partida-> head= nova;
					}
		else {
			partida->head->estado = *estado;
			nova->proximo = partida->head ;
                  	partida-> head= nova;
                	}
		}
      else
	   {
            printf("Memória insuficiente.");
            n=-1;
            };
	return n;
}

/* Cria uma caixa de jogadas e poe-ha como sendo a nova cabeça de jogada*/
int newJOGADA(JOGO *head){
    JOGADAS *s; int n =1;
    JOGADAS *tmp = head->head_jogadas;
    s = malloc ( sizeof(struct JOGADAS) );
    if(s == NULL) n =-1;
    else {
		s->proxima = tmp;
    		head->head_jogadas= s;
    		head->n_elementos ++;
	}
 	return n;
}

/*if ( ()== NULL ) return tmp;else { }*/

/* cria uma "caixa" e initializa-a */
int initJOGO(TAB_BN *estado,STACK *partida){
      int n=1;
      if ( (newJOGO(estado,partida)) == -1 ) n=-1;
      else      {
                  partida->head->head_jogadas = NULL;
                  partida->head->n_elementos=0;
                  partida->head->n_com=0;
                  partida->head->estado= *estado;
	          partida->tamanho++;
                  }
      return n;
}


/* Funçao que ira retirar um elemento a stack, caso nao haja elementos nessa e existem tabuleiros anteriores tera que carregá-los */

int popStack(TAB_BN *estado,STACK *partida){
    int i = 1; JOGO *tmp = partida->head;
     if(partida->head == NULL) i=-1;
     else {
           if(partida->head->n_elementos== 0) {  
			if(partida->head->proximo!=NULL){
						 partida->head=partida->head->proximo;
					         tmp->proximo=NULL;
                                                 free(tmp);
					         *estado= partida->head->estado;
						 aplicaCmd(partida);
						 partida->tamanho--;
							 }
			else printf("Comando invalido.Primeiro tabuleiro introduzido.\n");
						/* */
                                              }
           else  desfCmd(estado, partida);

     }
     return i;
}


/* Altera o estado do tabuleiro e guarda o character anterior */

void altera_estado(TAB_BN *estado,int linha, int coluna, char symbol, STACK *partida){
	push(linha,coluna, estado, partida);
	estado->tabuleiro[linha][coluna]= symbol;

}


/* Introduz as modificaçoes aportadas ao tabuleiro antes de essas serem feitas */
int push(int linha, int coluna, TAB_BN *estado, STACK *partida){
	int n=1;	
	 if( newJOGADA(partida->head) == -1) n =-1; 
	 else{
		partida->head->head_jogadas->linha= linha;
		partida->head->head_jogadas->coluna= coluna;
		partida->head->head_jogadas->modificado= estado->tabuleiro[linha][coluna];
		partida->head->head_jogadas->indcom= partida->head->n_com;
	    }
	return n;

}


