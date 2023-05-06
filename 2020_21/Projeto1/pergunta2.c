/*
 * Projeto 1 de Métodos de Programação I 2020/2021
 * Margarida Rodrigues - 2020223166
 * 2- Vamos agora inverter os papéis: é o computador quem deve adivinhar 
 * em sete tentativas o número em que o utilizador está a pensar.
 * Em cada jogada, o utilizador deve indicar se o número tentado é maior 
 * ou menor do que o número em que pensou. Construa o seu programa de forma que o computador ganhe sempre.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	//Explicação do jogo ao jogador: 
	printf("Este jogo consiste numa adivinha.\n");
	printf("Agora é o computador quem deve adivinhar, em 7 tentativas, o número inteiro em que o utilizador está a pensar entre 1 e 100.\n");
	
	srand(time(NULL));
	int n, i, min = 1, max = 100; 
	i=min+((max-min)/2); //i é a fórmula que o computador deve usar para depois tentar adivinhar o número, de acordo com a estratégia vencedora.
	
	printf("Introduza um numero: ");
	scanf("%d",&n);

    printf(" Primeira tentativa: ");
    i=min+((max-min)/2); 
	if(n == i)
	 { 
	  printf("Acertou.\n"); //Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0; 
	  }  
	else {
	   if((n > i))
	   {  i=min+((max-min)/2); 
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	}
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max=i;
	     } }
	      
		printf(" Segunda tentativa: ");  
		i=min+((max-min)/2);  
	 if(n == i)
	 {
	  printf("Acertou.\n"); //Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0;
	   }
	else {
	   if( n > i)
	   {
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	}
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;
	     } }	
		printf(" Terceira tentativa: "); 
		i=min+((max-min)/2); 
	 if(n == i)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0; 
	  } 
	else {
	   if( n > i)
	   { 
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	  }
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;
	    }  }
		printf(" Quarta tentativa: "); 
		i=min+((max-min)/2);            
	 if(n == i)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0;
	   } 
	else {
	   if( n > i)
	   {
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min=i;
	   }
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;      
	    }  }
		printf(" Quinta tentativa: "); 		
		i=min+((max-min)/2);            
	 if(n == i)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0;
	   } 
	else {
	   if( n > i)
	   {
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	   }
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;
	}  }
	
		printf(" Sexta tentativa: "); 
		i=min+((max-min)/2);          
	 if(n == i)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0; 
	  }
	else {
	   if( n > i) 
	   {
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	}
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;
	 } }	  
		printf(" Sétima tentativa: "); 
		i=min+((max-min)/2);           
	 if(n == i)
	 {
	  printf("Acertou.\n");//Se o número sugerido pelo computador for igual ao escolhido pelo utilizador aparece esta informação e acaba o jogo!
	  return 0; 
	  } 
	else {
	   if( n > i) 
	   {
	    printf("O número que o computador sugeriu está abaixo do número escolhido pelo utilizador\n\n ");
	    min = i;
	   }
	   else
	   {
	      printf("O número que o computador sugeriu está acima do número escolhido pelo utilizador\n\n");
	      max = i;
	 } }	    
	return 0;
}

