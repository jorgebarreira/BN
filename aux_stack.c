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
Adiciona um novo jogo a stack e põe o endereço deste como sendo a nova cabeça da stack. Este novo jogo terá o endereço do tabuleiro anterior.

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return retorna 1 caso tudo correr. Só devolvará -1 se não houver memoria suficiente para a criaçao do novo jogo.
*/
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

/**
Cria uma nova jogada tendo na posição "proxima" o endereço da ultima modificação guardada. Esta nova jogada passa ser a cabeça da nossa
stack de jogadas.

@param head: endereço da struct JOGO , onde estamos e onde vai ser criada a nova jogada.

@return 1 caso há memoria suficiente para a criaçao da nova jogada; -1 caso isso nao acontecer.

*/
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
/**
Chama a funçao 'newJOGO' para a criação de uma struct, e faz a inicialização dessa, guardando o novo tabuleiro introduzido. 

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.


@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return 1 se não há problemas; -1 caso a função 'newJOGO' devolver '-1' signalizando um problema na sua execução.

*/
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



/**
Função que ira retirar um elemento a stack, caso nao haja elementos nessa e existem tabuleiros anteriores fara o carregamento desses. 

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.


*/
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




/**

Altera o estado do tabuleiro e guarda o character anterior.

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param linha: Indice no array correspondente a linha onde introduzir o caracter.

@param coluna: Indice no array correspondente a coluna onde introduzir o caracter.

@param symbol: Caracter que sera introduzido no tabuleiro na posiçao linha, coluna, caso o caracter nesta posiçao for differente de symbol.


*/
void altera_estado(TAB_BN *estado,int linha, int coluna, char symbol, STACK *partida){
if(estado->tabuleiro[linha][coluna]!= symbol){
	push(linha,coluna, estado, partida);
	estado->tabuleiro[linha][coluna]= symbol;
}
}


/**
Guarda o caracter do tabuleiro na posiçao [linha][coluna] antes de esse  ser modificado.

@param estado: Contém toda a informaçao relativo ao tabuleiro usado.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@param linha: Indice no array correspondente a linha onde se situa o caracter a guardar.

@param coluna: Indice no array correspondente a coluna onde se situa o caracter a guardar.
*/
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


