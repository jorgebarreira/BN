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



int esta_resolvido(TAB_BN *estado){
	int i,j;
for(i=0;i<estado->n_linhas;i++)
	for(j=0;j<estado->n_colunas;j++)
		if(estado->tabuleiro[i][j]=='.') return 0;
return 1;
}


void desfazer_ate_g(TAB_BN *estado,STACK *partida,JOGADAS *g){
        /*int i;*/ JOGADAS *tmp;
        /*i= partida->head->head_jogadas->indcom ;*/
      
       	 while((partida->head->head_jogadas!=NULL) && (partida->head->head_jogadas!=g ) ){

             int l = partida->head->head_jogadas->linha, col = partida->head->head_jogadas->coluna;

             estado->tabuleiro[l][col] = partida->head->head_jogadas->modificado;
             tmp = partida->head->head_jogadas; /* uma vez desfazido é preciso libertar a memoria;*/
             partida->head->head_jogadas=partida->head->head_jogadas->proxima; /* modifica-se a cabeça da lista;*/
             
             free(tmp); /* liberta-se a antiga cabeça.*/
             partida->head->n_elementos--;
            }
}



void cmd_R(TAB_BN *estado, STACK *partida){
/*TAB_BN tmp = *estado;*/ JOGADAS *g[MAX_SIZE]; int n=0;
int ciclo=1; int controlo=0;
while(ciclo==1) {

while(( (estrategia_1(estado,partida) == 1 )|| (estrategia_2(estado,partida) == 1 ) ||(estrategia_3(estado,partida) == 1) || (estrategia_4(estado,partida) ==1) ))
	controlo++; 
	
	n=cmd_V(estado,0);
	if( esta_resolvido(estado) && (  n==1 ) ) ciclo = 0;
	else if( controlo >=100) ciclo=0;	
         	     if(n==1) g[n++]=jogada_aleatoria(estado,partida);
		     else desfazer_ate_g(estado,partida,g[--n]);

}

}






