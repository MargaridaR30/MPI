/*
 * Projeto 1 de Métodos de Programação I 2020/2021
 * Margarida Rodrigues - 2020223166
 * 1-Escreva um programa que implemente um jogo em que o objetivo do jogador
 *  é adivinhar, em 7 tentativas, um número inteiro aleatório entre 1 e 100,
 *  gerado pelo computador. 
 *  Em cada jogada o computador deve informar se o número introduzido está
 *  abaixo ou acima do número que se pretende adivinhar.Há uma estratégia vencedora?
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	
	 
	//Explicação do jogo ao jogador: 
	printf("Este jogo consiste numa adivinha.\n");
	printf("Deve adivinhar, em 7 tentativas, um número inteiro aleatório entre 1 a 100, gerado pelo computador.\n");
	printf("Espero que se divirta!\n");
	 
	srand(time(NULL));
	int x, i;
	i = rand() % 100;
	scanf("%d", &x);
	 
printf(" Primeira tentativa: ");
	if(i == x)
	 { 
	  printf("Acertou.\n"); //Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0; 
	  }  
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	      }
	      
		printf(" Segunda tentativa: ");   
		scanf("%d", &x);        
	 if(i == x)
	 {
	  printf("Acertou.\n"); //Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0;
	   }
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	      }	
		printf(" Terceira tentativa: "); 
		scanf("%d", &x);           
	 if(i == x)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0; 
	  } 
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	      }
		printf(" Quarta tentativa: "); 
		scanf("%d", &x);           
	 if(i == x)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0;
	   } 
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");      
	      }
		printf(" Quinta tentativa: "); 		
		scanf("%d", &x);           
	 if(i == x)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0;
	   } 
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	  }
	
		printf(" Sexta tentativa: "); 
		scanf("%d", &x);           
	 if(i == x)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0; 
	  }
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	  }	  
		printf(" Sétima tentativa: "); 
		scanf("%d", &x);           
	 if(i == x)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo utilizador for igual ao escolhido pelo computador aparece esta informação e acaba o jogo!
	  return 0; 
	  } 
	else {
	   if( i > x)
	    printf("O número introduzido está abaixo do número gerado\n\n ");
	   else
	      printf("O número introduzido está acima do número gerado\n\n");
	  }	  
	  
	return 0;
}
