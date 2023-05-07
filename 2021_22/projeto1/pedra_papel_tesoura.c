#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int opcaoUser, opcaoPC;
	
	//introdução e explicação do programa/jogo
	printf(" JOGO DO PEDRA, PAPEL E TESOURA \n");
	printf("A cada numero corresponde uma opcao de jogo.\n");
	printf("0-Pedra // 1-Papel // 2-Tesoura\n");
	printf("Qual a sua jogada?\n");
	scanf("%d", &opcaoUser);
	
	if ( opcaoUser < 0 || opcaoUser > 2) {
		printf("ERRO! Volte a tentar! Introduza um número entre 0 e 2.\n");
		printf("Qual a sua jogada?\n");
	    scanf("%d", &opcaoUser);
	  }
	srand(time(NULL));//função que gera um número aleatório
    opcaoPC = rand() % 3;
	printf("%d\n",opcaoPC);
	
	if((opcaoUser == 0 && opcaoPC == 2) || (opcaoUser == 1 && opcaoPC == 0) || (opcaoUser == 2 && opcaoPC == 1))
		printf("Ganhou! Parabens!!!");
	else {if (opcaoUser == opcaoPC)
			printf("Empataram!");
		    else printf("Oh...o computador ganhou. Volte a tentar!");
	}
	
	return 0;
}
