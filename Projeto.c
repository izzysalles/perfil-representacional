/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Variáveis globais */

FILE  * Arq;
char nome [100];
char prontuario [9];
char nome_arquivo [150];
char opc;
char frase  [100]; 
char item_1 [100];
char item_2 [100];
char item_3 [100];
char item_4 [100];
char caractere;
char chama_usuario [250];
char chama_master [250];
float calc_visual, calc_digital, calc_auditivo, calc_cinestesico;
int NroFrase, cinestesico, auditivo, visual, digital;

/* Corpo do programa */
int main()
{
	setlocale (LC_ALL, "Portuguese");
	system ("mode  60,18");
	memset (nome,          '\0', 100 ); 
	memset (prontuario,    '\0', 9   );
	memset (nome_arquivo,  '\0', 150 );
	printf ("DIGITE SEU NOME        : "); fflush(stdin); gets (nome);
	printf ("DIGITE O SEU PRONTUÁRIO: "); fflush (stdin); gets (prontuario);
	strcat (nome_arquivo, "RESULTADO_"); 	/* Monta o nome do arquivo que será gerado*/
	strcat (nome_arquivo, nome);
	strcat (nome_arquivo, "_" );
	strcat (nome_arquivo, prontuario);
	strcat (nome_arquivo, ".TXT");
	Arq = fopen ( nome_arquivo, "w" ); /* fopen abre o arquivo, no caso, para gravação *//* Abre o arquivo para gerar o relatório */
	
	if ( Arq == NULL) /* Testar se a abertura do arquivo foi bem sucedida*/
	{
		printf ("Erro ao abrir: RESULTADO.TXT");
		getch ();
		exit (EXIT_FAILURE); 	
	} 
	
	fclose (Arq);
	
	strcpy (chama_usuario, "USUARIO ");
  	strcat (chama_usuario, nome_arquivo);
  	strcat (chama_usuario, " ");
  	strcat (chama_usuario, nome);
  	
  	strcpy (chama_master, "MASTER ");
  	strcat (chama_master, nome_arquivo);
  	strcat (chama_master, " ");
  	strcat (chama_master, nome);
	
	// printf("o nome é: %s", nome);
	
	if (  (  strcmp ( nome,  "MASTER"   ) == 0 ) )
        {
        	system (chama_master);
		}
    else
    {
      	system (chama_usuario);
    }        
    
	getch();
    return 0;
}
