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
Funçao que verifica se a soma das informaçoes para as linhas e colunas correspondem.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@return TRUE caso o tabuleiro é valido, FALSE caso contrario.
*/

int soma_informacoes(TAB_BN *estado){
	int i , j;
	int soma_l=0, soma_c=0;
for(i=0;i< estado->n_linhas; i++){
	soma_l += estado->info_linhas[i];
	
}
for(j=0;j<estado->n_colunas;j++){
	soma_c += estado->info_colunas[j];
}
return (soma_c==soma_l);
}


/**
Funçao que devera verificar se a soluçao do tabuleiro é valida tendo em conta as varias regras.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@return 0 caso a soluçao esta errada, 1 caso a soluçao esta correta.
*/
int verificar_solucao(TAB_BN *estado){
int i,j;
int n=0;
int c= estado->n_colunas;
int l= estado->n_linhas;
n= verifica_info(estado);
if(n==0) return 0;
else{
for(i=0;i<l;i++){
	for(j=0;j<c;j++){
		if(i==0 || j==0 || j == c-1 || i == l-1){ if(verifica_cantos(i,j,estado)==0) return 0; }		
		else if (verifica_meio(i,j,estado)==0 ) return 0;
			}
		}
     }

return 1;

}


/**
Funçao que percorre o tabuleiro a procura de elementos desconhecidos ('.'), conta o numero de elementos desconhecidos a sua volta e em funçao destes decide se poe la um 'o' ou nao.

@param estado: Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return: -1 caso nao encontrou elementos desconhecidos, 1 caso encontrou e decidiu por la um segmento de barco desconhecido.
*/

int poe_um_segmento_no_tab(TAB_BN *estado,STACK *partida){
int r=-1;
int linha,c, max=0,test=0;
int ind_col =estado->n_colunas;
int ind_linha= estado->n_linhas;
int l1=-1,c1=-1;

for(linha=0;linha<ind_linha;linha++)
{
	for(c=0; c < ind_col;c++)
		{
	 
		if(estado->tabuleiro[linha][c] == '.') {
				if(c!=0 && linha!=(ind_linha-1) && estado->tabuleiro[linha+1][c-1]=='.') test++;
				if(c!=ind_col-1 && linha!=(ind_linha-1) && estado->tabuleiro[linha+1][c+1]=='.') test++;
				if(linha!=0 && c!=0 && estado->tabuleiro[linha-1][c-1]=='.') test++;
				if(linha!= 0 && c!= ind_col-1 && estado->tabuleiro[linha-1][c+1]=='.') test++;
				if(linha!= 0 && c!= ind_col-1 && estado->tabuleiro[linha][c+1]=='.') test++;
				if(linha!= 0 && c!= ind_col-1 && estado->tabuleiro[linha][c-1]=='.') test++;
				if(test > max  ) { 	max=test;	l1=linha; 	c1=c;	}
				test=0;
						       }
		}
}
if (l1!=-1 && c1!=-1)	{  r=1; altera_estado(estado, l1,c1,'o',partida); }

return r;
}

/** 
Verifica se ainda existem peças desconhecidas no puzzle/tabuleiro .

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@return  Devolve 1 caso o tabuleiro é completo, 0 caso contrario.
*/


int esta_resolvido(TAB_BN *estado){
	int i,j; char a;
for(i=0;i<estado->n_linhas;i++)
	for(j=0;j<estado->n_colunas;j++){
					a = estado->tabuleiro[i][j];
					if(a=='.' || a == 'o') return 0;
					}

return 1;
}
/**
Funçao que desfaz os elementos da stack ate o endereço dado como argumento.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@param g: Endereço de paragem da funçao.
*/

void desfazer_ate_a(TAB_BN *estado,STACK *partida,JOGADAS *g){
	 JOGADAS *tmp;   
      
       	 while( partida->head->head_jogadas!=g  ){

             int l = partida->head->head_jogadas->linha, col = partida->head->head_jogadas->coluna;

             estado->tabuleiro[l][col] = partida->head->head_jogadas->modificado;
             tmp = partida->head->head_jogadas; 
             partida->head->head_jogadas=partida->head->head_jogadas->proxima; 
             
             free(tmp); 
             partida->head->n_elementos--;
            }
}
/**
Funçao que aplica as estrategias disponiveis.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return Devolve 1 caso pelo menos uma das nossas estrategias foi aplicada, 0 caso contrario. 
*/

int resolver(TAB_BN *estado, STACK *partida){
int a,b,c,d,n=0;

a=estrategia_1(estado,partida);
b=estrategia_2(estado,partida);
c=estrategia_3(estado,partida);
d=estrategia_4(estado,partida);

if( (a!=-1 || b!= -1 ) && ( c!= -1 || d!= -1) ) n=1;
return n;
}



/**
Comando que ira resolver o tabuleiro.

@param estado : Contém toda a informaçao relativo ao tabuleiro usado.

@param partida : Endereço da nossa stack, onde vão ser guardadas as modifficaçoes feitas no nosso tabuleiro.

@return 0 se nao for possivel, 1 caso contrario.
*/
int cmd_R(TAB_BN *estado, STACK *partida){
	int n,r=1; JOGADAS *tmp ; 
	while ((esta_resolvido(estado)) == 0) {
		tmp = partida->head->head_jogadas; 
		n = verificar_solucao(estado);
if (n == 0)  r= 0;
else{

while(resolver(estado,partida));
if (tmp == partida->head->head_jogadas) {
		jogada_aleatoria(estado,partida);
		n = cmd_R (estado,partida);
		if (n == 0) {
		if (partida->head->head_jogadas != tmp)  desfazer_ate_a(estado,partida, tmp);
		  estado->tabuleiro[partida->head->head_jogadas->linha][partida->head->head_jogadas->coluna] = '~';
			    } else return r;
		}
	}
     }
return r;
}


/*
int resolver_tab(TAB_BN *estado, STACK *partida){
 JOGADAS *g=partida->head->head_jogadas;
int n=-1;
if(esta_resolvido(estado) ) n=1;
else{
	while(resolver(estado,partida));
	g=jogada_aleatoria(estado,partida);
	if( cmd_V(estado,0) == 0 && g!=NULL ) desfazer_ate_a(estado,partida,g->proxima);
	n = resolver_tab(estado,partida);

}
return n;
}
*/

/*


int cmd_R(TAB_BN *estado, STACK *partida){
TAB_BN tmp1= *estado, tmp2=*estado;
STACK partida1 ;
STACK partida2 ;
int n;
do{
	partida1 = *partida;
	partida2 = *partida;
	resolver_tab(&tmp1,  partida1);
	resolver_tab(&tmp2, partida2);
	if( ( esta_resolvido(&tmp1)|| cmd_V(&tmp1) ) && respeita_prop(&tmp1 ) ) { *estado=*tmp; ciclo=0; };
	else if ( ( esta_resolvido(&tmp2) || cmd_V(&tmp2) ) && respeita_prop(&tmp2) ) { *estado =*tmp;; ciclo=0};


}while(ciclo==1)
return 1;

}



*/
/* Conselho do stor de teorica -> A ordem como se aplica as estrategias pode mudar os tabuleiros que se obtem, criando uma lista com essas possibilidades, corta-se os tabuleiros invalidos e que se repetem guardando as corretas -> repetindo esta estrategia, no fim sendo as soluçoes unicas so teremos uma possibilidade que é a soluçao!
Cuidado: Nao se esquecer libertar para nao causar problemas.*/


/*
int cmd_R(TAB_BN *estado, STACK *partida){
TAB_BN tmp = *estado; JOGADAS *g=partida->head->head_jogadas;
int n=0;
int ciclo=1;
int test2=0;
do {
int controlo=0;

while(resolver(estado,partida) && controlo++<500);
	n=cmd_V(estado,0);
	if( (esta_resolvido(estado) &&   n==1 ) || test2++< 100) ciclo = 0;
	else  g =jogada_aleatoria(estado,partida);
	if(n==0) desfazer_ate_a(estado,partida,g);

}while(ciclo==1);

}

*/











