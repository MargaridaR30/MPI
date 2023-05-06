//Programa correspondente à pergunta 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_OF_STRING 40000
#define MAX_STRING_SIZE 20

int tem_underscores(char v[],int l);
int ocorrencias(char p[], int l, char c, int ind[]);
void escreve_oculta(char v[],int l);
void escreve_vector (char vector[][80], int tamanho);

int main() {
   int i;
   int total_linhas;
   int j;   //linha_escolhida 
   int comprimento;
   char palavra_selecionada[MAX_STRING_SIZE]; char s[40000][20];
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
   //printf("\nPalavra escolhida para advinhar: %s ", palavra_selecionada); //apenas usei para confirmar a palavra e o seu comprimento
   printf("\n A palavra escolhida tem %d caracteres.",comprimento);

return 0;}
