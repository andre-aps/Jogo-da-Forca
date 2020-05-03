#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char palavra[50];
char letra[1];
char posicao[50];
char alfabeto[26];
int erros = 6;
int acertos = 0;

void verificar(void);
void desenhar(void);
void iniciar(void);
void desenharForca(void);

main(void) {
	setlocale(LC_ALL,"");
	iniciar();
	desenhar();
		
	do {			
		verificar();
	} while(erros != 0 && acertos != strlen(palavra));
	
	if(erros == 0) {
		printf("\n\nVOCE PERDEU!\n\nPALAVRA OU FRASE: %s\n", palavra);
		desenharForca();
		system("pause");
	} else {
		printf("\n\nVOCE VENCEU!\n\n*** PARABENS ***\n");
		desenharForca();
		system("pause");
	}		
}

void verificar(void) {
	desenharForca();
	int i,contAcertos = 0, contErros = 0;
		
	for(i = 65; i <= 90; i++) {
		if(alfabeto[i] == '*') {
			alfabeto[i] = '*';
			printf("%c ", alfabeto[i]);
		} else {
			alfabeto[i] = i;
			printf("[%c] ",alfabeto[i]);
		}		
	}
	
	printf("\n\n[Espaço] SAIR\n\nTENTATIVAS: %d\n\nLETRA: ", erros);	
	
	strupr(gets(letra));
	if(*letra == ' ') {
		printf("\nVOCE SAIU!\n\nPALAVRA OU FRASE: %s", palavra);		
		exit(0);
	} else {
		system("cls");
		
		for(i = 0; i < strlen(palavra); i++) {
			if(*letra == palavra[i]) {		
				posicao[i] = *letra;
				printf("%c ", posicao[i]);
				contAcertos += 1;
			} else {
				printf("%c ", posicao[i]);
				contErros += 1;
		 	}
		}
		
		if(contErros == strlen(palavra) && alfabeto[*letra] != '*') {		
			alfabeto[*letra] = '*';
			erros -= 1;
		}
		
		if(alfabeto[*letra] != '*') {
			alfabeto[*letra] = '*';
			acertos += contAcertos;
		}

		printf("\n\n");
	}
}

void desenhar(void) {
	int i;

	for(i = 0; i < strlen(palavra); i++) {
		if(palavra[i] != ' ') {
			posicao[i] = '_';
		}
		
		printf("%c ", posicao[i]);
	}
	
	printf("\n\n");
}

void iniciar(void) {
	int i;
	printf("### JOGO DA FORCA ###\n\n");
	printf("PALAVRA OU FRASE: ");	
	strupr(gets(palavra));
	
	for(i = 0; i < strlen(palavra); i++) {
		if(palavra[i] == ' ') {
			acertos++;
		}
	}
	
	system("cls");
}

void desenharForca(void) {
	switch(erros) {
		case 6:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |\n");
			printf(" |\n");
			printf(" |\n");
			printf(" |\n");
			printf("/ \\ \n\n");
			break;
		case 5:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |\n");
			printf(" |\n");
			printf(" |\n");
			printf("/ \\ \n\n");
			break;
		case 4:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |     |\n");
			printf(" |\n");
			printf("/ \\ \n\n");
			break;
		case 3:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |     |\n");
			printf(" |    /\n");
			printf("/ \\ \n\n");
			break;
		case 2:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |     |\n");
			printf(" |    / \\ \n");
			printf("/ \\ \n\n");
			break;
		case 1:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |    \\|\n");
			printf(" |    / \\\n");
			printf("/ \\ \n\n");
			break;
		case 0:
			printf("  _____\n");
			printf(" |     |\n");
			printf(" |     O\n");
			printf(" |    \\|/\n");
			printf(" |    / \\\n");
			printf("/ \\ \n\n");
			break;
	}
		
}
