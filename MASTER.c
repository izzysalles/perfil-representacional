#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define    MAX     5

FILE  * Arq;
char nome[100];
char prontuario[9];
char nome_arquivo[150];
char opc;
char frase  [100];
char item_1 [100];
char item_2 [100];
char item_3 [100];
char item_4 [100];
char caractere;
float calc_visual, calc_digital, calc_auditivo, calc_cinestesico;
int NroFrase, cinestesico, auditivo, visual, digital;
int i;
char chama_usuario [250];

typedef   struct
{
    int		NroFrase;
	char 	frase[100];	
	int		cinestesico;
	char 	item_1[100];
	int		auditivo;
	char 	item_2[100];
	int 	visual;
	char 	item_3[100];
	int		digital;
	char 	item_4[100];
} LAYOUT;

/* Vari�veis Globais */
char        opc;
LAYOUT    TABELA[5]={
{1, "Eu tomo decis�es importantes baseado em:", 0, "Intui��o", 0, "O que me soa melhor", 0, "O que me parece melhor", 0, "Um estudo preciso e minucioso do assunto"}, 
{2, "Durante uma discuss�o eu sou mais influenciado por:", 0, "Se eu entro em contato ou n�o com os sentimentos reais do outro", 0, "O tom da voz da outra pessoa", 0, 
    "Se eu posso ou n�o ver o argumento da outra pessoa", 0, "A l�gica do argumento da outra pessoa"}, 
{3, "Eu comunico mais facilmente o que se passa comigo:", 0, "Pelos sentimentos que compartilho", 0, "Pelo tom da minha voz", 0, "Do modo como me visto e aparento", 0, 
	"Pelas palavras que escolho"}, 
{4, "� muito f�cil para mim:", 0, "Escolher os m�veis mais confort�veis", 0, "Achar o volume e a sintonia ideais num sistema de som", 0, 
    "Escolher as combina��es de cores mais ricas e atraentes", 0, "Selecionar o ponto mais relevante relativo a um assunto interessante"}, 
{5, "Eu me percebo assim:", 0, "Eu sou muito sens�vel � maneira como a roupa veste o meu corpo", 0, "Se estou muito em sintonia com os sons dos ambientes", 0, 
    "Eu respondo fortemente �s cores e � apar�ncia de uma sala", 0, "Se sou muito capaz de raciocinar com fatos e dados novos"}, 
};

char frase [100];
char item_1[100];
char item_2[100];
char item_3[100];
char item_4[100];

FILE * arquivo;
FILE * questionario;

void geraQuestionarioTxt(void)
{
    LAYOUT registro;
    arquivo = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r"); 	
    questionario = fopen ("QUESTIONARIO_1.TXT", "w");
    fprintf (questionario, "NroFrase \t\t\t\t Frase \t\t     Cinestesico Item_1 \t\t\t\t\t\t\t Auditivo Item_2 \t\t\t\t\t\tVisual Item_3 \t\t\t\t\t\t\t Digital Item_4   \n");
    fprintf (questionario, "==============================================================================================================================================="
    				"==============================================================================================================================================="
    				"=======================================================\n");
    while ( !feof(arquivo)) //feof() detecta o final do arquivo
    {
        fread (&registro, sizeof(registro), 1, arquivo);
        fprintf (questionario, "%-8i %51s %-11i %-63s %-8i %-53s %-6i %-57s %-7i %-68s \n", registro.NroFrase, registro.frase, registro.cinestesico, registro.item_1,
		registro.auditivo, registro.item_2, registro.visual, registro.item_3, registro.digital, registro.item_4  );
    }
    fprintf (questionario, "==============================================================================================================================================="
    				"==============================================================================================================================================="
    				"=======================================================\n");
	
    fclose (arquivo);
    fclose (questionario);

    system ("QUESTIONARIO_1.TXT");
}     

void GravaTabelaNoArquivo()
{
    int resp;
    
    arquivo = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
    if ( arquivo == NULL )
    {
        printf("\n\aErro ao criar o arquivo: TESTE_SISTEMA_REPRESENTACIONAL.DAT");
        getch();
        exit(0);
    }
    
    
    resp = fwrite (&TABELA, sizeof(TABELA), 1, arquivo);
    if (resp != 1)
    {
        printf("\n\aErro ao gravar dados no arquivo: TESTE_SISTEMA_REPRESENTACIONAL.DAT");
        getch();
        exit(0);   
    }
    printf ("\n\nArquivo aberto no endere�o: [%p]", arquivo);
    fclose(arquivo);    
}

int main (int   argc,    char * argv[])
{
	setlocale (LC_ALL, "Portuguese");
	do /* Se o nome for MASTER, abrir o menu de op��es */
	{
		system ("mode  53,15");
		INICIAR: /* esta � uma label (marca��o) */
		system ("cls");
		printf ("\n==================================================");
		printf ("\n       TESTE DOS SISTEMAS REPRESENTACIONAIS        ");
		printf ("\n--------------------------------------------------");
		printf ("\n     1 - Cadastrar question�rio                   ");
		printf ("\n     2 - Visualizar question�rio                  ");
		printf ("\n     3 - Realizar teste                           ");
		printf ("\n     4 - Sobre o teste                            ");
		printf ("\n     F - Fim                                      ");
		printf ("\n==================================================");
		printf ("\n     Escolha-> ");
		fflush (stdin);/* scanf ("%c" , &opc); */
		opc = getche (); /* captura a op��o digitada pelo usu�rio */
		
	
		switch ( opc )
		{ 
			case '1' : 
			{  
			  	system ("cls");
			  	system ("mode 400,30");
                int n=0;
				system("cls");
				printf ("\n CADASTRO DEFAULT: \n\n");
				printf ("NroFrase \t\t\t\t Frase \t\t     Cinestesico Item_1 \t\t\t\t\t\t\t Auditivo Item_2 \t\t\t\t\t\tVisual Item_3 \t\t\t\t\t\t\t Digital Item_4   \n");
				printf ("==============================================================================================================================================="
                        "==============================================================================================================================================="
                        "=======================================================\n");
				for ( n=0; n<5; n++ )
                {   
                    printf ("%-8i %51s %-11i %-63s %-8i %-53s %-6i %-57s %-7i %-68s \n", TABELA[n].NroFrase, TABELA[n].frase, TABELA[n].cinestesico, TABELA[n].item_1, 
                    TABELA[n].auditivo, TABELA[n].item_2, TABELA[n].visual, TABELA[n].item_3, TABELA[n].digital, TABELA[n].item_4);
                }
                printf ("==============================================================================================================================================="
                        "==============================================================================================================================================="
                        "=======================================================\n");
                GravaTabelaNoArquivo();
              	getch(); 
			}
			break;
		
			case '2' :
			{
			    system ("cls"); 
                geraQuestionarioTxt();
            }
            break;
            
            case '3' :
            {
            	strcpy (chama_usuario, "USUARIO ");
			  	strcat (chama_usuario, argv[1]);
			  	strcat (chama_usuario, " ");
			  	strcat (chama_usuario, argv[2]);
				system (chama_usuario);		
			}	
       	    break;
        
       	    case '4' : 
       	    {
       	    	Arq = fopen ("REFERENCIAL_TEORICO.TXT", "w"); //fopen tenta abrir arquivo 
				if (Arq==NULL) /*NULL = 0000.0000*/
				{
					system ("cls");
					printf("\n Erro ao abrir arquivo");
					getch();
					exit (EXIT_FAILURE);
				}
				printf ("\n Arquivo aberto no endere�o [%p]", Arq); //endere�o do ponteiro [p]
				
					/* Gravar o cabe�alho */
				fprintf ( Arq, "\nREFERENCIAL TE�RICO");
				fprintf ( Arq, "\n--------------------");
				fprintf ( Arq, "\n\nSegundo Albert Merabian, em seu livro \"Silent Messages\", o poder de influ�ncia das palavras n�o passa de 7%, enquanto a forma como as palavras");
				fprintf ( Arq, "\ns�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.");
				fprintf ( Arq, "\n\nPara Merabian 55%% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da pessoa enquanto se comunica.");
				fprintf ( Arq, "\n\nO tom da voz representa 38%% do impacto da comunica��o.");
				fprintf ( Arq, "\n\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.");
				fprintf ( Arq, "\n\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.");
				fprintf ( Arq, "\n\nAs portas da percep��o s�o nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de contato com o mundo exterior.");
				fprintf ( Arq, "\nDa mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias, utilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o.");
				fprintf ( Arq, "\n\nDe acordo com a Programa��o Neurolinguistica existem os seguintes sistemas representacionais.");
				fprintf ( Arq, "\n\n- Auditivo");
				fprintf ( Arq, "\n- Digital");
				fprintf ( Arq, "\n- Cinest�sico");
				fprintf ( Arq, "\n- Visual");
				fprintf ( Arq, "\n\nAlgumas pessoas capta melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.");
				fprintf ( Arq, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais");
				fprintf ( Arq, "\nAs cinest�sicas aprendem melhor por meio  das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.");
				fprintf ( Arq, "\nJ� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
				fprintf ( Arq, "\n\nCada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional dominante dela e funcamental para di�logos eficientes");
				/* Fecha o arquivo */
				fclose (Arq);
				system ("REFERENCIAL_TEORICO.TXT");
			}
       	    break;
        
       	    case 'F' : 
        	case 'f' : exit(0);
        	break;
        
        	default  : printf ("\a\a\a ERROU!!!!");
    	}
    	
    	getch ();
    	goto INICIAR;
	} while(nome == "MASTER");
	
	return 0;
	
}
