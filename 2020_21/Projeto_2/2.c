// ********  versão pergunta 2.a) e 2.b)
// ********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_OF_STRING 40000
#define MAX_STRING_SIZE 20

int ocorrencias(char p[], int l, char c, int ind[]);

int main() {
	//Apresentação e explicação de como o jogo funciona
	printf("\t\t\t\t\t Bem-vindo(a) ao Jogo da Forca.\n");
	printf(" Explicação-Regras do jogo: \n");
	printf(" -Este jogo consiste em ir tentando adivinhar as letras contituintes de uma certa palavra gerada pelo computador.\n ");
	printf("-Para tal, já recebes uma dica: o número de letras da plavra. \n");
	printf(" -Inicias o jogo com 10 créditos, por cada letra que insiras que não pertenca à palavra perdes um crédito...Cuidado!\n");
	printf(" Boa sorte e diverte-te! :D\n ");

   int i; // contadores
   int total_linhas;
   int j;   //linha_escolhida
   int comprimento;
   char palavra_selecionada[MAX_STRING_SIZE]; char s[NUMBER_OF_STRING][MAX_STRING_SIZE];
   char letra;
   int indice[80];
   FILE *fp;                                   // declaração do file pointer
   fp = fopen("dicionario.txt","r");                   // abrir o ficheiro
   if (!fp)
    {
       printf("----- ERRO -------\n");// a verificar se existe erro na abertura do ficheiro inexistente
       exit(0);
    }

   i=0;
   while (!feof(fp))                   // ciclo para ler ficheiro para o vector s
     {
        fscanf(fp,"%s",s[i]);
        i++;
     }

   total_linhas=i;
   srand((unsigned) time(NULL));
   j=(rand()%total_linhas );

   strcpy(palavra_selecionada,s[j]);   //  Copia a string do vetor para a var com a palavra a advinhar
   comprimento=strlen(palavra_selecionada);


   // a escrever valores para verificação
   // escreve_vector (s,i);
   printf("\nTotal de linhas lidas: %d",total_linhas);
   printf("\nNumero da linha escolhida: %d",j+1);
   //printf("\nPalavra escolhida para advinhar: %s ", palavra_selecionada);//apenas usei para confirmar a palavra e o seu comprimento
   printf("     Com %d caracteres.",comprimento);

  printf("\n\n Escreva uma letra:");
  letra=getchar();//para funcionar bem quando o jogador insere a letra
  int numero=110;
  numero=ocorrencias(palavra_selecionada,comprimento,letra,indice);

  printf("\n\n Numero de ocorrencias da letra %c = %i nas posicoes:",letra, numero);
  for(i = 0; i < numero; i++)
   	  printf ("%i ",indice[i]);
}
// ----- Função
int ocorrencias(char p[], int l, char c, int ind[])
{
	int i;
	int j=0;
	int conta=0;
	for(i = 0; i < l; i++)
     {
       if (p[i]==c )
         {
           ind[j]=i;
           j++;
           conta++;
        }
     }
   return conta;
}
