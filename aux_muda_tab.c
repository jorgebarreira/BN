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

Função que invoca a estrategia apropriada.

@param indice: Inteiro correspondente ao numero da estrategia que se quer aplicar.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return retorna 1 caso tudo correr bem.Só devolvará 0 se o caracter dado nao pertencer a lista definida.
*/

int cmd_E(int indice, TAB_BN *estado,STACK *partida){
    int n=1;
switch (indice){
case 1:
    estrategia_1(estado,partida);
    break;
case 2:
    estrategia_2(estado,partida);
    break;
case 3:
    estrategia_3(estado,partida);
    break;
case 4:
    estrategia_4(estado,partida);
    break;
default:
	 n=-1;
	 break;
}
    return n;
}

/*if(indice==1)  
	 estrategia_1(estado,partida);
else if(indice==2)
	estrategia_2(estado,partida);
   
else if(indice==3)
        estrategia_3(estado,partida);
    
else if(indice==4)
    	estrategia_4(estado,partida);
else n=-1;
	

*/

/**
Função que testa o caracter dado pelo jogador. O inteiro de retorno é um boleano.

@param caracter : Caracter que vai ser testado para verificar se pertence à lista de caracteres definida no jogo.

@return retorna 1 caso tudo correr bem.Só devolvará 0 se o caracter dado nao pertencer a lista definida.
*/
int pertence(char caracter) {
    int i;
    char s[10]=".~oO<>#^v";
    for(i=0;s[i]!='\0';i++)
        if(s[i]==caracter) return 1;
    return 0;
}

/**
Função que põe na linha (arg2) e na coluna(arg2) escolhida pelo jogador,o caracter por ele fornecido.
Este caracter está contido no array comando indice 1.

@param comando: Array que contém  o comando usado no indice 0 e o caracter a introduzir no indice 1.

@param l1: corresponde ao número da linha onde o jogador quer mudar o caracter.

@param c2: corresponde à coluna onde o jogador quer mudar o caracter.

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.

@param partida: Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return retorna 1 caso tudo correr. Só devolvará -1 se a linha dada for maior do que a do número de linha definido.
*/
int cmd_p(char comando[],int l1,int c2, TAB_BN *estado, STACK *partida){
    int r =1;
    if(pertence(comando[1])){
            if( ((l1-1) < estado->n_linhas) && ((l1-1)>=0) && ((c2-1) < estado->n_colunas) && (c2-1)>=0 )
		      altera_estado(estado, l1-1,c2-1,comando[1],partida);
	}
    else r =-1;

    return r;
}



/**
Função para transformar os elementos não determinados de uma linha em água.
 
@param estado : Contém toda a informação relativa ao tabuleiro usado.

@param num_linha : corresponde ao número da linha que o jogador quer modificar.

@param partida: Corresponde a stack onde esta contida os diferentes caracteres, e posições correspondentes, alteradas pelos comandos já efetuados.

@return retorna 1 caso tudo correr.Só devolvará -1 se a linha dada for maior do que a do numero de linha definido.
*/
int cmd_h(TAB_BN *estado, int num_linha,STACK *partida) {  /* transforma todos os elementos nao determinado como águas. */
    int i, n=1;
	if((num_linha - 1) >= estado->n_linhas || (num_linha-1)<0 ) n=-1;
    else for(i=0;i<estado->n_colunas;i++){ /* vai-se da coluna 0 da linha num_linha até a ultima coluna determinada no estado (n_colunas); */
       	
	if(estado->tabuleiro[num_linha-1][i]=='.') altera_estado(estado,num_linha-1,i,'~',partida); 
    /* caso seja '.' isto é indeterminado, muda-se para agua.Senao nao se muda nada. */
    }
    return n; /* se tudo correr bem, o tabuleiro tera esta linha com '~'. */
}

/**

Função para transformar os elementos não determinados de uma coluna em água.

@param estado : Contém toda a informação relativa ao tabuleiro usado.

@param num_coluna : corresponde ao número da coluna que o jogador quer modificar.

@param partida : endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return retorna 1 caso tudo correr.Só devolvará -1 se a linha dada é maior do que a do numero de colunas definido.
*/
int cmd_v(TAB_BN *estado, int num_coluna, STACK *partida){ /* Variante de cmd_h so que desta vez, em vez de modificar as linhas modifica uma coluna */
    int i =1; /* indice usado para o for, permitindo mudar de linha */
	if((num_coluna - 1) >= estado->n_colunas || (num_coluna-1)<0 ) return -1;
    for(i=0;i<estado->n_linhas;i++){ /* Ciclo que permita o processamento de todas as linhas do tabuleiro */
        if(estado->tabuleiro[i][num_coluna-1]=='.') altera_estado(estado,i,num_coluna-1,'~',partida);
        /* o numero da coluna nao muda pois quera-se modificar os caracteres nessa. */
    }
    return i;
}

