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

Função que irá recolher no ecrã toda a informação relativa ao tabuleiro do jogo.

@param estado: Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param partida: Endereço da nossa stack, onde estao guardados todas as informaçoes correspondente as jogafas efetuadas.

@return Devolve 1 no final se correr bem.
    Devolve -1 caso nao haja informaçao que chega

*/
int cmd_c(TAB_BN *estado, STACK *partida){
    int lin;
    int r=1; /* permite tirar os varios returns. O seu resultado nao mudará se não houver problemas durante a execução.*/
    int col;
    char linha_lida[MAX_LINHA];
    char resto_linha[MAX_LINHA];
    if(partida->head != NULL) initJOGO(estado,partida);
    if(fgets(linha_lida, MAX_LINHA, stdin)!=NULL)
    		sscanf(linha_lida, "%d %d", &estado->n_linhas, &estado->n_colunas);else return -1;
    if(fgets(linha_lida, MAX_LINHA, stdin)!=NULL)
    	for (lin=0; lin<estado->n_linhas; lin++){
        	sscanf(linha_lida, "%d %[^\n]", &estado->info_linhas[lin],resto_linha);
       		strcpy(linha_lida,resto_linha);
    	}else return -1;

    if(fgets(linha_lida, MAX_LINHA, stdin)!=NULL)
    	for (col=0; col<estado->n_colunas; col++){
        	sscanf(linha_lida, "%d %[^\n]", &estado->info_colunas[col],resto_linha);
        	strcpy(linha_lida,resto_linha);
    		} else return -1;
   			
    for (lin=0; lin<estado->n_linhas; lin++){
        if(fgets(linha_lida, MAX_LINHA, stdin)!=NULL)
        	for (col=0; col<estado->n_colunas; col++){
            	estado->tabuleiro[lin][col] = linha_lida[col];
        	} else return -1;
    }
    if(partida->head == NULL)  initJOGO(estado,partida);
    return r;
}



/**
Função que irá apresentar no ecrã o estado onde se encontra o tabuleiro.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@return Devolve 1 no final. 

Nota: Nao vejo possíveis erros que possam ocorrer durante a impressão.
*/
int cmd_m(TAB_BN *estado){
       int indLinha,indCol; /*2 indices, um para as linha e outro para as colunas do tabuleiro */
       /* printf("%d %d\n",estado->n_linhas,estado->n_colunas);*/ /* 1º imprima-se os 2 inteiros que representam o tamanho do tabuleiro.
    Inutil. Nao se precisa dessa informaçao */
        for(indLinha=0;indLinha<=estado->n_linhas;indLinha++) /* 2º Cria-se um ciclo que faz variar o indice das linha. O <= é explicado mais abaixo. */
        {
            if(indLinha==estado->n_linhas) 
            {   int nlin;
              for(nlin=0;nlin<2;nlin++){
                if(nlin==0){
                            for(indCol=0;indCol<estado->n_colunas;indCol++)
                                if(estado->info_colunas[indCol]>=10) printf("%d",estado->info_colunas[indCol]/10);
                                else printf("%d",estado->info_colunas[indCol]%10);
                            putchar('\n');
                          };
                if(nlin==1) {
                            for(indCol=0;indCol<estado->n_colunas;indCol++)
                                if(estado->info_colunas[indCol]>=10) printf("%d",estado->info_colunas[indCol]%10);
                                else putchar(' ');
                            putchar('\n');
                            };

                                        }  
            } 
                else for(indCol=0;indCol<=estado->n_colunas;indCol++){ 
                /* 2º ciclo for. É introduzido como dependente do if pois, uma vez que o indice das linhas chegou ao seu pico,
                     nao se quer imprimir algo que se desconhece. Este ciclo faz variar o indice da coluna com um indice de linha unico em cada ciclo. */
                  if(indCol==estado->n_colunas) printf(" %d\n",estado->info_linhas[indLinha]);
                  /* Uma vez chegado ao numero n_colunas, ele imprime a direita da linha as informaçoes correspondente a esta.*/
                  else printf("%c",estado->tabuleiro[indLinha][indCol]); 
                  /* Ao longo do ciclo, ele vai imprimindo no ecra o caracter relativo a linha [indLinha] e coluna [indCol] */
                 };

        
        }
    return 1;
}

/**

Função que irá escrever no ficheiro escolhido o tabuleiro assim como todas as informações relativas a este.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param fp: Ficheiro que foi aberto e onde vai ser escrito o tabuleiro.
*/
void imprimeTab(TAB_BN *estado,FILE *fp) {
    int indLinha,indCol;
    fprintf(fp, "%d %d\n",estado->n_linhas, estado->n_colunas);

    for(indLinha=0; indLinha < estado->n_linhas; indLinha++)
         if(indLinha != (estado->n_linhas-1)) fprintf(fp,"%d ",estado->info_linhas[indLinha]);
         else fprintf(fp,"%d\n",estado->info_linhas[indLinha]);

    for(indCol=0; indCol < estado->n_colunas; indCol++)
           if(indCol != (estado->n_colunas-1)) fprintf(fp, "%d ",estado->info_colunas[indCol]);
           else fprintf(fp, "%d\n", estado->info_colunas[indCol]);
          
    for(indLinha=0;indLinha<estado->n_linhas;indLinha++) 
          {
             for(indCol=0;indCol<estado->n_colunas;indCol++)
                      fprintf(fp,"%c",estado->tabuleiro[indLinha][indCol]);
            fputc('\n',fp);
          };

}


/**
Função que escreve o tabuleiro num ficheiro.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param ficheiro: string que contem o nome do ficheiro onde se quer escrever. Este pode ja existir sendo aberto neste caso, ou nao existir ,criando-se um novo.

@return Devolve 1 se conseguiu escrever dentro do ficheiro, -1 caso nao foi possivel abrir este. 

*/

int cmd_e(TAB_BN *estado, char ficheiro[]) {
    int r = 1;
    FILE *fp;
    if((fp = fopen(ficheiro,"w")) == NULL){
                                      printf("Impossível abrir/criar o ficheiro\n");
                                      r=-1;
    }else imprimeTab( estado, fp);
    fclose(fp); /* é preciso fechar o ficheiro !! */
    return r;

}

/**

Função que irá ler as informaçoes presentes no ficheiro aberto.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param fp: Ficheiro onde vai ser lido a informaçao sob o tabuleiro.

@return Devolve 1 se nao houver problemas, -1 caso haja uma anomalia.


*/
int ler_ficheiro(FILE *fp,TAB_BN *estado){
    int lin;
    int r=1; /* permite tirar os varios returns. O seu resultado nao mudará se não houver problemas durante a execução.*/
    int col;
    char linha_lida[MAX_LINHA];
    char resto_linha[MAX_LINHA];
    if(fgets(linha_lida, MAX_LINHA,fp) == NULL) return -1;
    sscanf(linha_lida, "%d %d", &estado->n_linhas, &estado->n_colunas);
/*if(estado->n_linhas!= estado->n_colunas) { printf("O tabuleiro tem que ser quadrado."); return -1;};*/
    if(fgets(linha_lida, MAX_LINHA, fp)!=NULL)
      for (lin=0; lin<estado->n_linhas; lin++){
          sscanf(linha_lida, "%d %[^\n]", &estado->info_linhas[lin],resto_linha);
          strcpy(linha_lida,resto_linha);
      }else return -1;

    if(fgets(linha_lida, MAX_LINHA, fp)!=NULL)
      for (col=0; col<estado->n_colunas; col++){
          sscanf(linha_lida, "%d %[^\n]", &estado->info_colunas[col],resto_linha);
          strcpy(linha_lida,resto_linha);
        } else return -1;
        
    for (lin=0; lin<estado->n_linhas; lin++){
        if(fgets(linha_lida, MAX_LINHA, fp)!=NULL)
          for (col=0; col<estado->n_colunas; col++){
              estado->tabuleiro[lin][col] = linha_lida[col];
          } else return -1;
    }
    return r;
}

/**

Função que irá abrir o ficheiro ,caso existe, e vai lê-lo.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

@param ficheiro: String com o nome do ficheiro contendo as informaçoes sobre o tabuleiro que se quer carregar.

@param partida: Stack onde vai ser carregada e iniciado este novo tabuleiro.

@return Devolve 1 se conseguiu ler o ficheiro, -1 caso nao foi possivel abrir este. 
*/

int cmd_l(TAB_BN *estado,char ficheiro[], STACK *partida){
    int r=1;
    FILE *fp;
    fp=fopen(ficheiro,"r");
    if(fp != NULL){
		 if(partida->head != NULL)  initJOGO(estado,partida);
                  	r=ler_ficheiro(fp, estado);
		 if(partida->head == NULL) initJOGO(estado,partida);
		  }
    else r = -1;
    if (fp!=NULL) fclose(fp); /* é preciso fechar o ficheiro !! */
    return r;
}
/**
Comando que veriifica se o nosso tabuleiro esta valido ou nao.

@param estado - Apontador da estrutura que contém toda a informação sob o tabuleiro.


@return Devolve 1. 
*/


int cmd_V(TAB_BN *estado){
  int i,j;
  int res,res2 = 1,res3= 1;
  res=verifica_info(estado);
  if(res==1){
    for(i=0;i<estado->n_linhas;i++){
      for(j=0;j<estado->n_colunas;j++){
        if(is_segmento(estado->tabuleiro[i][j])){
          if(i==0 || j==0 || i==(estado->n_linhas)-1 || j==(estado->n_colunas)-1){
            res2=verifica_cantos(i,j,estado);
            if(res2==0){
              i=estado->n_linhas;
              j=estado->n_colunas;
            }
          }
          else{
            res3=verifica_meio(i,j,estado);
            if(res3==0){
              i=estado->n_linhas;
              j=estado->n_colunas;
            }
          }
        }
      }
    }
  }
  if(res && res2 && res3)
    printf("SIM\n");
  else
    printf("NAO\n");
  return 1;
}
