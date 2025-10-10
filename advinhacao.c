#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define PRIMEIRO_TENTATIVA 1
#define VINTE_TENTATIVAS 20
#define QUINZE_TENTATIVAS 15
#define SEIS_TENTATIVAS 6
#define PONTOSS 1000

int main(){
	setlocale(LC_ALL, "Portuguese");

	// Jogo da advinhaçãoo. primeiramente, interface de entrada onde o usuario irá escolher a dificuldade de jogo
	printf("\n\n");
	printf("           P  /_\\  P                                \n");
	printf("          /_\\_|_|_/_\\                              \n");
	printf("      n_n | ||. .|| | n_n         Bem-vindo ao       \n");
	printf("      |_|_|nnnn nnnn|_|_|     Jogo de Advinhação!    \n");
	printf("     |\" \"   |  |_|  |\" \" |                       \n");
	printf("     |_____| ' _ ' |_____|                           \n");
	printf("           \\__|_|__/                                \n");
	printf("\n\n");
	
	int chute;
	double pontos = PONTOSS;
	srand(time(0));
	int numerosecreto = rand() % 100;
	int acertou = 0;
	int nivel;
	int totalDeTentativas;

	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil (2) Medio (3) Dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
														switch(nivel){
															case 1:
																totalDeTentativas = VINTE_TENTATIVAS;
																break;
															case 2:
																totalDeTentativas = QUINZE_TENTATIVAS;
																break;
															default: 
																totalDeTentativas = SEIS_TENTATIVAS;
																break;
														}

	for(int i = PRIMEIRO_TENTATIVA; i <= totalDeTentativas; i++){
		printf("\n-> Tentativa %d de %d\n\n", i, totalDeTentativas);
		printf("Chute um número: ");
		scanf("%d", &chute);
		
		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos\n");
			continue;
			i--;
		}
		
		printf("Seu %dº chute foi %d\n", i, chute);
		
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
		
		acertou = chute == numerosecreto;
		int maior = chute > numerosecreto;
		
		if(acertou) {	
			break;
		}
		else {
			if(maior){
				printf("Seu chute foi maior que o numero secreto!\n\n");
			} 
			else{
				printf("Seu chute foi menor que o numero secreto!\n\n");
			}
		}
	}

	printf("\n");
	if(acertou){
		printf ( "              OOOOOOOOOOO                    \n");
        printf ( "          OOOOOOOOOOOOOOOOOOO                \n");
        printf ( "       OOOOOO  OOOOOOOOO  OOOOOO             \n");
        printf ( "     OOOOOO      OOOOO      OOOOOO           \n");
        printf ( "   OOOOOOOO  #   OOOOO  #   OOOOOOOO         \n");
        printf ( "  OOOOOOOOOO    OOOOOOO    OOOOOOOOOO        \n");
        printf ( " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf ( " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf ( " OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO       \n");
        printf ( "  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO        \n");
        printf ( "   OOOO  OOOOOOOOOOOOOOOOOOOOO  OOOO         \n");
        printf ( "     OOOOO  OOOOOOOOOOOOOOOO   OOOO          \n");
        printf ( "       OOOOOO  OOOOOOOOOO   OOOOOO           \n");
        printf ( "          OOOOOO         OOOOOO              \n");
        printf ( "              OOOOOOOOOOOO                   \n");
		
		printf("\nParabens! Voce acertou!\n\n");	
		printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);	
	}
	else{
		printf("          \\|/ ____ \\|/         \n");
		printf("           @~/ ,. \\~@           \n");
		printf("          /_( \\__/ )_\\         \n");
		printf("             \\__U_/             \n");
		printf("\nVoce perdeu! Tente novamente!\n\n");
	}	

	printf("Obrigado por jogar!\n");
	system("pause");
	return 0;
}