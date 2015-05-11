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

Função que irá recolher no ecrã toda a informação relativa ao tabuleiro do jogo.

@param estado - Apontador da estrutura que contém toda a informação sobre o tabuleiro.

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


void imprimeTab(TAB_BN *estado,FILE *fp) {
    int indLinha,indCol;
    fprintf(fp, "%d %d\n",estado->n_linhas, estado->n_colunas);

    for(indLinha=0; indLinha <= estado->n_linhas; indLinha++)
         if(indLinha != estado->n_linhas) fprintf(fp,"%d ",estado->info_linhas[indLinha]);
         else fprintf(fp,"%d\n",estado->info_linhas[indLinha]);

    for(indCol=0; indCol <= estado->n_colunas; indCol++)
           if(indCol != estado->n_colunas) fprintf(fp, "%d ",estado->info_colunas[indCol]);
           else fprintf(fp, "%d\n", estado->info_colunas[indCol]);
          
    for(indLinha=0;indLinha<estado->n_linhas;indLinha++) 
          {
             for(indCol=0;indCol<estado->n_colunas;indCol++)
                      fprintf(fp,"%c",estado->tabuleiro[indLinha][indCol]);
            fputc('\n',fp);
          };

}
/* O tabuleiro escrito tem o formato do Output */
int cmd_e(TAB_BN *estado, char ficheiro[]) {
    int r = 1;
    FILE *fp;
    if((fp = fopen(ficheiro,"w")) == NULL){
                                      printf("Impossível criar o ficheiro\n");
                                      r=-1;
    }else imprimeTab( estado, fp);
    fclose(fp); /* é preciso fechar o ficheiro !! */
    return r;

}




int ler_ficheiro(FILE *fp,TAB_BN *estado){
    int lin;
    int r=1; /* permite tirar os varios returns. O seu resultado nao mudará se não houver problemas durante a execução.*/
    int col;
    char linha_lida[MAX_LINHA];
    char resto_linha[MAX_LINHA];
    if(fgets(linha_lida, MAX_LINHA,fp) == NULL) return -1;
    sscanf(linha_lida, "%d %d", &estado->n_linhas, &estado->n_colunas);
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

int cmd_l(TAB_BN *estado,char ficheiro[], STACK *partida){
    int r=1;
    FILE *fp;
    fp=fopen(ficheiro,"r");
    if(fp != NULL){
		 if(partida->head != NULL) initJOGO(estado,partida);
                  	r=ler_ficheiro(fp, estado);
		 if(partida->head == NULL) initJOGO(estado,partida);
		  }
    else r = -1;
    if (fp!=NULL) fclose(fp); /* é preciso fechar o ficheiro !! */
    return r;
}
