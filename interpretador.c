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
#include "R_prototipo.h"
/* Fim da condiçao if do inicio.*/
#endif

/** 
Interpreta um comando passado numa linha 

@param linha: Endereço do array/string que contem as informaçoes que foram escritas no standart input.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return -1 caso o comando introduzido é invalido, podendo nao pertencer as instruçoes possiveis ou ter informaçao erradas.O valor de retorno tambem pode ser 0 caso o comando a ser executado é a saida do programa. O valor 1 sera retornado quando nao houver problemas na realizaçao da instrução.

*/

int interpretar(TAB_BN *estado, char *linha, STACK *partida) {
    char comando[MAX_LINHA];
    char arg1[MAX_LINHA];
    char arg2[MAX_LINHA];
    int nargs;
    int n = -1;
    nargs = sscanf(linha , "%s %s %s", comando, arg1, arg2 );
 
    if (strcmp(comando , "c") == 0 && nargs == 1){
         n= cmd_c(estado,partida);
          /*if( initJOGO( estado, partida) == -1) printf("Memoria insuficiente"); */
          }
    else if (strcmp(comando, "m") == 0 && nargs == 1)
               n = cmd_m(estado);
    else if (strcmp(comando, "h") == 0 && nargs == 2 && partida->head!=NULL) {
          partida->head->n_com++;
          n= cmd_h(estado, atoi (arg1),partida);
      }
    else if (strcmp(comando, "v") == 0 && nargs == 2 && partida->head!=NULL){
       	       partida->head->n_com++;
               n = cmd_v(estado, atoi(arg1),partida);
        
          }
    else if (comando[0] == 'p' && nargs == 3 && partida->head!=NULL){
        partida->head->n_com++;
        n=cmd_p(comando, atoi(arg1) , atoi(arg2) ,estado,partida);
        
        }
    else if(strcmp(comando,"l") == 0 && nargs ==2) {
          n=cmd_l(estado, arg1,partida);
         /* if(n!=-1) initJOGO( estado, partida) ; */
        }
    else if(strcmp(comando,"e")== 0 && nargs==2)
            n=cmd_e(estado,arg1);
    else if (strcmp(comando , "q") == 0){
            if(partida->head!=NULL) free(partida->head);
            n = 0;  
          }
    else if ( comando[0]=='E' && nargs == 1 && partida->head != NULL){
	partida->head->n_com++;
        n=cmd_E( atoi(comando+1) , estado,partida);
	
	}
  else if((strcmp(comando , "V") == 0) && nargs == 1)
        n=cmd_V(estado,1);
    else if (strcmp(comando,"D") == 0 && nargs==1)
                   n = cmd_D(estado,partida);
  else if( strcmp(comando,"R")== 0 && nargs==1 && partida->head != NULL) { 
		partida->head->n_com++;		
		cmd_R(estado,partida);n=1;
		}
  else  n = -1;
 
    /*else printf("Comando Invalido\n"); Erro comando nao existe*/
    return n;
}


/**
Interpretador de comandos.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.
*/
void interpretador(TAB_BN *estado, STACK *partida) {
    int resultado = 0;
    char buffer[MAX_LINHA];
    int ciclo = 1;
    while(ciclo && fgets(buffer, MAX_LINHA, stdin) != NULL){
            resultado = interpretar(estado,buffer, partida);
              if(resultado == 0)
                                ciclo = 0;
	      if(resultado == -1)
				printf("Comando Invalido\n");
    }
}
