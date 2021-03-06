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
Funçao que percorre a linha até encontrar um '.' devolvendo a localizaçao desse na linha.

@param estado: Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param linha: Numero da linha que vai ser percorrida.

@return: A coluna que pode ser modificada na linha ou -1 caso a linha ja esta preenchida.
*/
int encontra_posicao(TAB_BN *estado,int linha){
int r=-1;
int i;
int max=0;
int a =estado->n_colunas;
for(i=0;i<a;i++){
int test=0;
	if(estado->tabuleiro[linha][i] == '.') {
			if(i!=0 && estado->tabuleiro[linha+1][i-1]=='.') test++;
			if(i!=a-1 && estado->tabuleiro[linha+1][i+1]=='.') test++;
			if(linha!=0 && i!=0 && estado->tabuleiro[linha-1][i-1]=='.') test++;
			if(linha!= estado->n_colunas-1 && i!= a-1 && estado->tabuleiro[linha+1][i+1]=='.') test++;
			if(test > max) {max=test;r=i;}
				}
}

return r;
}

/**
Funçao que devolve um numero entre 0 e o seu argumento incluido.

@param n: Inteiro que serve a criar o intervalo dos numeros que serao devolvidos.

@return Devolve um inteiro aleatorio entre 0 e n.
*/
int rand_to(int n){
int w= RAND_MAX/(n+1);
int limit= w*(n+1);
int r;
do
 r=rand();
while(r>=limit);
return (r/w);
}

/**
Funçao que faz uma jogada semi-aleatoria, ponde na coluna mais apropriado de uma linha aleatoria onde ha um '.' um segmento de barco desconhecido.


@param estado: Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return Devolve o endereço da nossa jogada ou NULL caso nao foi efetuada.
*/

JOGADAS *jogada_aleatoria(TAB_BN *estado, STACK *partida){
JOGADAS *tmp1=NULL; int linha; int ciclo=-1; int coluna; int count= 0;
srand((unsigned int) time (NULL));
do{

linha=rand_to(estado->n_linhas-1);
coluna=encontra_posicao(estado,linha);
if(coluna!=-1){
	altera_estado(estado, linha,coluna,'o',partida);
	ciclo=1;
	tmp1 = partida->head->head_jogadas;
	      }
else count++;
}while(ciclo==-1 && count !=100);

return tmp1;
}


