// ********  versão 5
// ********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_OF_STRING 40000
#define MAX_STRING_SIZE 20

int tem_underscores(char v[],int l);
void escreve_oculta(char v[],int l);
void escreve_vector (char vector[][80], int tamanho);

int main() {
	 //Apresentação e explicação de como o jogo funciona
	printf("\t\t\t\t\t Bem-vindo(a) ao Jogo da Forca.\n");
	printf(" Explicação-Regras do jogo: \n");
	printf(" -Este jogo consiste em ir tentando adivinhar as letras contituintes de uma certa palavra gerada pelo computador.\n ");
	printf("-Para tal, já recebes uma dica: o número de letras da plavra. \n");
	printf(" -Inicias o jogo com 10 créditos, por cada letra que insiras que não pertenca à palavra perdes um crédito...Cuidado!\n");
	printf(" Boa sorte e diverte-te! :D\n ");
	
   int i,conta; // contadores
   int total_linhas;
   int j;   //linha_escolhida 
   int comprimento;
   char palavra_selecionada[MAX_STRING_SIZE]; char s[40000][20];
   char palavra_advinha[MAX_STRING_SIZE]; char letra[1];
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

   // a preencher a string com underscores
   for(i = 0; i < comprimento; i++)
       palavra_advinha[i]='_';

   escreve_oculta(palavra_advinha,comprimento);
   conta=10;//tentativas
   while ((tem_underscores(palavra_advinha,comprimento)==1) && (conta>=1))
     {
        fflush(stdin);      // esvazia o buufer do teclado
        printf("\n\n Tem %i tentativas. Tente uma letra ?\n",conta);
        //scanf("%s ",letra);
        letra[0]=getchar();//para funcionar bem quando o jogador insere a letra 
        for(i = 0; i < comprimento; i++)
           {
             if (letra[0]==palavra_selecionada[i])
                 palavra_advinha[i]=letra[0];

           }
        escreve_oculta(palavra_advinha,comprimento);
        i++;
        conta--;
}
if (conta<=1)
   printf("\n\n Acabaram as tuas tentativas... :c");
else
   printf("\n\n Terminaste em %i tentativas. P A R A B E N S :D ",10-conta);
}
// -----------------------------------------------------------------------Funcoes
 int tem_underscores(char v[],int l){
int i;
int teste=0;
for(i = 0; i < l; i++)
  {
     if (v[i]=='_' )
       {
         teste=1;
       }

  }
   return teste;
}
 void escreve_oculta(char v[],int l){
int i;
printf("\n     ");
for(i = 0; i < l; i++)
  {
     printf("%c",v[i]);
     printf(" ");
  }
}


void escreve_vector (char vector[][80],int tamanho)
{
   int i;
   printf("\n A escrever Array de strings:\n");
   for(i = 0; i < tamanho; i++)
      printf("\n%s", vector[i]);

}
