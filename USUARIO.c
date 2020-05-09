#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

FILE  * Arq;
char opc;
char frase  [100];
char item_1 [100];
char item_2 [100];
char item_3 [100];
char item_4 [100];
char caractere;
int calc_visual, calc_digital, calc_auditivo, calc_cinestesico;
int NroFrase, cinestesico, auditivo, visual, digital;
int i;
int aux;
int record[4] = {0, 0, 0, 0};
int maior;
char maior_txt [100];

bool OpcaoInvalida(int opcao)
{
	if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			if (opcao == record[i])
			{
				printf ("\nValor inválido, digite novamente!");
				return true;	
			}
		}
		return false;
	}
	else
	{
		printf ("\nValor inválido, digite novamente!");
		return true;
	}		
}

void PrintaOpcao(char opcao, int i)
{
	do
	{
		printf ("\n[%c]-> ", opcao);
		fflush (stdin);
		scanf  ("%d", &aux);
	} while (OpcaoInvalida(aux)); // ENQUANTO FOR INVALIDO
	record[i - 1] = aux; // adiciona o aux ao final da straux
}

void ResetaRecord()
{
	int i;
	for (i = 0; i < 4; i++)
		record[i] = 0;
}

int main (int   argc,    char * argv[])
{
	calc_visual = 0;
	calc_digital = 0;
	calc_auditivo = 0;
	calc_cinestesico = 0;
	setlocale (LC_ALL, "Portuguese");
	system ("mode  73,25");
	printf ("Nas frases a seguir pontue com: ");
	printf ("\n4 a que melhor descreve você;");
	printf ("\n3 a próxima melhor descrição;");
	printf ("\n2 a próxima melhor;");
	printf ("\n1 aquela que menos descreve você.");
	
	printf ("\n\n1. Eu tomo decisões importantes baseado em: \n");
	printf ("a) intuição.\n");
	printf ("b) o que me soa melhor.\n");
	printf ("c) o que me parece melhor.\n");
	printf ("d) um estudo preciso e minucioso do assunto.\n\n");

	ResetaRecord();
	PrintaOpcao('a', 1); // chama a função PrintaOpcao e manda a opcao A
	calc_cinestesico += aux;
	
	PrintaOpcao('b', 2); // chama a função PrintaOpcao e manda a opcao B
	calc_auditivo += aux;
	
	PrintaOpcao('c', 3); // chama a função PrintaOpcao e manda a opcao C
	calc_visual += aux;
	
	PrintaOpcao('d', 4); // chama a função PrintaOpcao e manda a opcao D
	calc_digital += aux;
	
	system ("cls");

	printf ("\n2. Durante uma discussão eu sou mais influenciado por: \n");
	printf ("a) o tom da voz da outra pessoa.\n");
	printf ("b) se eu posso ou não ver o argumento da outra pessoa.\n");
	printf ("c) a lógica do argumento da outra pessoa.\n");
	printf ("d) se eu entro em contato ou não com os sentimentos reais do outro.\n\n");
	
	ResetaRecord();
	PrintaOpcao('a', 1); // chama a função PrintaOpcao e manda a opcao A
	calc_auditivo += aux;
	
	PrintaOpcao('b', 2); // chama a função PrintaOpcao e manda a opcao B
	calc_visual += aux;
	
	PrintaOpcao('c', 3); // chama a função PrintaOpcao e manda a opcao C
	calc_digital += aux;
	
	PrintaOpcao('d', 4); // chama a função PrintaOpcao e manda a opcao D
	calc_cinestesico += aux;
	
	system ("cls");

	printf ("\n3. Eu comunico mais facilmente o que se passa comigo: \n");
	printf ("a) do modo como me visto e aparento\n");
	printf ("b) pelos sentimentos que compartilho.\n");
	printf ("c) pelas palavras que escolho.\n");
	printf ("d) pelo tom da minha voz.\n\n");
	
	ResetaRecord();
	PrintaOpcao('a', 1); // chama a função PrintaOpcao e manda a opcao A
	calc_visual += aux;
	
	PrintaOpcao('b', 2); // chama a função PrintaOpcao e manda a opcao B
	calc_cinestesico += aux;
	
	PrintaOpcao('c', 3); // chama a função PrintaOpcao e manda a opcao C
	calc_digital += aux;
	
	PrintaOpcao('d', 4); // chama a função PrintaOpcao e manda a opcao D
	calc_auditivo += aux;
	
	system ("cls");
	
	printf ("\n4. É muito fácil para mim: \n");
	printf ("a) achar o volume e a sintonia ideais num sistema de som.\n");
	printf ("b) selecionar o ponto mais relevante relativo a um assunto interessante.\n");
	printf ("c) escolher os móveis mais confortáveis.\n");
	printf ("d) escolher as combinações de cores mais ricas e atraentes.\n\n");

	ResetaRecord();
	PrintaOpcao('a', 1); // chama a função PrintaOpcao e manda a opcao A
	calc_auditivo += aux;
	
	PrintaOpcao('b', 2); // chama a função PrintaOpcao e manda a opcao B
	calc_digital += aux;
	
	PrintaOpcao('c', 3); // chama a função PrintaOpcao e manda a opcao C
	calc_cinestesico += aux;
	
	PrintaOpcao('d', 4); // chama a função PrintaOpcao e manda a opcao D
	calc_visual += aux;
	
	system ("cls");
	
	printf ("\n5. Eu me percebo assim: \n");
	printf ("a) se estou muito em sintonia com os sons dos ambientes.\n");
	printf ("b) se sou muito capaz de raciocinar com fatos e dados novos.\n");
	printf ("c) eu sou muito sensível à maneira como a roupa veste o meu corpo.\n");
	printf ("d) eu respondo fortemente às cores e à aparência de uma sala.\n\n");
	
	ResetaRecord();
	PrintaOpcao('a', 1); // chama a função PrintaOpcao e manda a opcao A
	calc_auditivo += aux;
	
	PrintaOpcao('b', 2); // chama a função PrintaOpcao e manda a opcao B
	calc_digital += aux;
	
	PrintaOpcao('c', 3); // chama a função PrintaOpcao e manda a opcao C
	calc_cinestesico += aux;
	
	PrintaOpcao('d', 4); // chama a função PrintaOpcao e manda a opcao D
	calc_visual += aux;
	
	system ("cls");
	
	calc_visual *= 2;
	calc_auditivo *= 2;
	calc_digital *= 2;
	calc_cinestesico *= 2;
	
	Arq = fopen (argv[1], "w"); //fopen tenta abrir arquivo ///= 'a' adiciona
		if (Arq==NULL) /*NULL = 0000.0000*/
		{
			system ("cls");
			printf("\n erro ao abrir arquivo");
			getch();
			exit (EXIT_FAILURE);
			
		}
		printf ("\n Arquivo aberto no endereço [%p]", Arq); //endereço do ponteiro [p]
		
			/* Gravar o cabeçalho */
		
		fprintf ( Arq, "============================ PERFIL REPRESENTACIONAL DE %s" " ============================", argv[2]); 
		
		maior = calc_visual;
		strcpy(maior_txt, "Visual");
		
		if (maior < calc_auditivo)
		{
			maior = calc_auditivo;
			strcpy(maior_txt, "Auditivo");
		}
		else
		{
			if (maior == calc_auditivo)
				strcat(maior_txt, " e Auditivo");
		}
		
		if (maior < calc_digital)
		{
			maior = calc_digital;
			strcpy(maior_txt, "Digital");
		}
		else
		{
			if (maior == calc_digital)
				strcat(maior_txt, " e Digital");
		}
		
		if (maior < calc_cinestesico)
		{
			maior = calc_cinestesico;
			strcpy(maior_txt, "Cinestésico");
		}
		else
		{
			if (maior == calc_cinestesico)
				strcat(maior_txt, " e Cinestésico");
		}
			
		fprintf (Arq, "\n	%.0d %% Visual  -  %.0d %% Digital -  %.0d %% Auditivo  -  %.0d %% Cinestesico", calc_visual, calc_digital, calc_auditivo, calc_cinestesico);
		fprintf ( Arq, "\n========================================================================================");
		fprintf ( Arq, "\n\nAlgumas pessoas capta melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.");
		fprintf ( Arq, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais");
		fprintf ( Arq, "\nAs cinestésicas aprendem melhor por meio  das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.");
		fprintf ( Arq, "\nJá as pessoas visuais aprendem melhor quando se valendo da visão.");
		fprintf ( Arq, "\n========================================================================================");
		
		fprintf ( Arq, "\nSeu perfil é: %s", maior_txt);
		fprintf ( Arq, "\n========================================================================================");
		fclose (Arq);
		system (argv[1]);
		
	return 0;
}
