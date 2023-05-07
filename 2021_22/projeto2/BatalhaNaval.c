#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <time.h>

void gerar_navio(int linha, int coluna , int grelha[linha][coluna])
{
    int rand1,rand2,rand3;
    rand1=(rand() % (5 - 2 + 1)) + 2 - 1; // formula para gerar num rand entre 2 e 5
    rand2=(rand() % (5 - 2 + 1)) + 2 - 1;
    grelha[rand1][rand2]=3; // define o centro do navio
    rand3=(rand() % (4 - 1 + 1)) + 1; // formula para gerar num rand entre 1 e 4
    if(rand1==1) // ficam os 3 quadrados à esquerda do centro
    {
        grelha[rand1][rand2+1]=3;
        grelha[rand1][rand2-1]=3;
        grelha[rand1+1][rand2-1]=3;
        grelha[rand1-1][rand2-1]=3;
    }
    else if(rand3==2) // ficam os 3 quadrados abaixo do centro com o navio
    {
        grelha[rand1+1][rand2]=3;
        grelha[rand1-1][rand2]=3;
        grelha[rand1-1][rand2-1]=3;
        grelha[rand1-1][rand2+1]=3;
    }
    else if(rand3==3) // ficam os 3 quadrados à direita do centro com o navio
    {
        grelha[rand1][rand2-1]=3;
        grelha[rand1][rand2+1]=3;
        grelha[rand1+1][rand2+1]=3;
        grelha[rand1-1][rand2+1]=3;
    }
    else if(rand3==4) // ficam os 3 quadrados acima do centro com o navio
    {
        grelha[rand1-1][rand2]=3;
        grelha[rand1+1][rand2]=3;
        grelha[rand1+1][rand2-1]=3;
        grelha[rand1+1][rand2+1]=3;
    }

}

void GuardaPartida(FILE *registo)
{
    // Inicia o registo da partida no ficheiro
    // Guarda automaticamente a exata hora e data em que a partida foi comecado da seguinte maneira:
    // Vai buscar o tempo do sistema no formato Unix epoch e converte-o para um adequado à leitura humana (tudo automatico pela biblioteca time.h)
    time_t seconds;
    struct tm *timeStruct;
    seconds = time(NULL);
    timeStruct = localtime(&seconds);
    fprintf(registo,"\n\n\n\n\n\nNa partida a %d/%d/%d às %d:%d:%d o jogador efetuou as seguintes jogadas por esta ordem:\n",timeStruct->tm_mday,(timeStruct->tm_mon + 1),(timeStruct->tm_year+ 1900),timeStruct->tm_hour,timeStruct->tm_min,timeStruct->tm_sec);
}

void mostrar_batalha(int linha, int coluna, int campo[linha][coluna])
{
    printf("\n _______________");
    for (int k = 0; k < (coluna-1); k++)
    printf("________________");
    for (int i = 0; i < linha; i++)
    {
        printf("\n|");
        for (int k = 0; k < coluna; k++)
        {
            if(campo[i][k]==0 || campo[i][k]==3)
                printf("\t.\t|");
            else if(campo[i][k]==1)
                printf("\t~\t|");
            else if(campo[i][k]==2)
                printf("\t*\t|");
        }
        printf("\n|");
        for (int k = 0; k < coluna; k++)
        printf("_______________|");
    }
    printf("\n\nLegenda:\n . -> Desconhecido\n ~ -> Oceano\n * -> Navio\n");
}

int main()
{
    int grelha[6][6] = { 0 };
    int jogadas[6][6] = { 0 };
    int tentativas=0;
    int acertou=0;
    int linha=-1;
    int coluna=-1;
    char resposta[2];
    FILE *registo;
    srand(time(NULL));
    gerar_navio(6,6,grelha);
    printf("\n\nBatalha naval a comecar!");
    printf("\nEste e o estado inicial do campo de batalha:");
    mostrar_batalha(6,6,grelha);
    printf("\nO navio que esta algures na grelha tem 5 partes.");
    printf("\nVa escolhendo quadrados para disparar e tente destruir todas as partes com a informacao que descobre.");
    printf("\nQuanto menos tentativas melhor!\n");
    while (1)
    {
        while(tentativas) // Não queremos que pergunte na primeira tentativa pois já é sempre mostrado o campo antes de entrar no while
        {
            printf("\n\nDeseja ver o estado do campo de batalha?\nIntroduza \"Y\" ou \"y\" para mostrar.\nIntroduza \"N\" ou \"n\" para nao mostrar.\nSe quiser desistir e terminar o programa introduza \"0\".\n\n>>>> ");
            fflush(stdin);
            fgets(resposta,2,stdin);
            if(!(strcmp(resposta,"y")) || !(strcmp(resposta,"Y")))
            {
                printf("\nEstado do campo de batalha:");
                mostrar_batalha(6,6,grelha);
                break;
            }
            else if(!(strcmp(resposta,"n")) || !(strcmp(resposta,"N")))
                break;
            else if(!(strcmp(resposta,"0")))
            {
                printf("\nEscolheu desistir, o programa ira agora terminar!\n\n");
                registo=fopen("jogadas.txt","a");
                fprintf(registo,"\n\n// O jogador decidiu desistir depois desta jogada e por isso a partida terminou de seguida. //");
                fclose(registo);
                exit(0);
            }
            else
                printf("\n\nOpcao invalida, por favor tente novamente!");
        }
        tentativas+=1;
        while(1)
        {
            printf("\nTentativa %d:",tentativas);
            printf("\n\nDigite a linha onde esta o quadrado em que quer acertar >>>> ");
            if(scanf("%2d",&linha)==0) //salva-guarda o facto de o utilizor não introduzir um número inteiro (pode pôr um char ou decimal), além disso são ignorados todos os digitos além dos dois primeiros para impedir overflows
            {
                printf("\nO valor que inseriu nao e um numero inteiro, por favor tente novamente.\n");
                fflush(stdin);
            }
            else
            {
                fflush(stdin);
                linha-=1; // um array [6][6] vai o elemento [0][0] a [5][5] portanto retira-se 1 da escolha do utilizador de 1 a 6 para cair no sitio certo.
                printf("\nAgora digite a coluna >>>> ");
                if(scanf("%2d",&coluna)==0) //mesma razão que o anterior
                {
                    printf("\nO valor que inseriu nao e um número inteiro, por favor tente novamente.\n");
                    fflush(stdin);
                }
                else
                {
                    fflush(stdin);
                    coluna-=1; // mesma razão que o anterior
                    if (coluna<0 || coluna>5 || linha<0 || linha>5)
                        printf("\nInseriu uma coluna ou uma linha fora dos limites do campo, por favor insira outra combinacao.\n");
                    else if(jogadas[linha][coluna])
                        printf("\nJa disparou neste quadrado, por favor insira outra combinacao.\n");
                    else
                    {
                        jogadas[linha][coluna]=1;
                        printf("\nO ataque foi lancado com sucesso!");
                        if(grelha[linha][coluna]==0)
                            printf("\nNao acertou em nada a nao ser em agua...");
                        else if(grelha[linha][coluna]==3)
                            printf("\nAcertou numa parte do navio!");
                        registo=fopen("jogadas.txt","a");
                        if(registo==NULL)
                        {
                            printf("\n\nNao foi possivel inicar o ficheiro que regista as jogadas, o programa ira continuar a funcionar sem ele.");
                        }
                        if(tentativas==1) // É a primeira jogada, guarda a informacao de que é uma nova partida no ficheiro
                        {
                            GuardaPartida(registo);
                        }
                        if(grelha[linha][coluna]==3)
                        {
                            acertou+=1;
                            fprintf(registo,"\n\nJogada Nº%d: Disparou contra o quadrado na linha %d e coluna %d e acertou no navio. Partes destruídas: %d",tentativas,(linha+1),(coluna+1),acertou);
                            grelha[linha][coluna]=2;
                        }
                        else if(grelha[linha][coluna]==0)
                        {
                            fprintf(registo,"\n\nJogada Nº%d: Disparou contra o quadrado na linha %d e coluna %d e acertou no mar.",tentativas,(linha+1),(coluna+1));
                            grelha[linha][coluna]=1;
                        }
                        if (acertou==5)
                        {
                            fprintf(registo,"\n\n// O jogador destruiu a última parte do navio nesta jogada e por isso a partida terminou de seguida. //");
                            fclose(registo);
                            printf("\n\nParabens, destruiu as 5 partes do navio!\nEis o estado final do campo de batalha:");
                            mostrar_batalha(6,6,grelha);
                            printf("\nO programa ira agora terminar, prima \"ENTER\" para continuar...\n\n");
                            fflush(stdin);
                            getchar();
                            exit(0);
                        }
                        fclose(registo);
                        break;
                    }
                }
            }
        }
    }
}
