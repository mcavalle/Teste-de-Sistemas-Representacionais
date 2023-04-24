#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


int calculoVis, calculoCin, calculoAud, calculoDig, resultado; //variáveis para cálculo das porcentagens
int i;
int confirma[4] = {0, 0, 0, 0}; //Vetor para confirmar as opções digitadas
int maior;
char maior_txt [100];
FILE * Arq;

//Função para ver valores digitados inválidos
bool valorInvalido(int opcao)
{
	if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			if (opcao == confirma[i])
			{
				printf ("\nEsse valor não é válido, digite novamente.\n");
				return true;	
			}
		}
		return false;
	}
	else
	{
		printf ("\nEsse valor não é válido, digite novamente.\n");
		return true;
	}		
}

//Função para exibir as escolhas
void escolha(char opcao, int i)
{
	do{
		printf ("\n[%c]-> ", opcao);
		fflush (stdin);
		scanf  ("%d", &resultado);
	} while (valorInvalido(resultado));
	confirma[i - 1] = resultado;
}

void confirmaZera()
{
	int i;
	for (i = 0; i < 4; i++)
		confirma[i] = 0;
}

int main(int   argc,    char * argv[]){
	setlocale(LC_ALL,"Portuguese");
	
	system("mode 70, 10");
	char nome[30], pront[9];
	printf("DIGITE SEU NOME        :   ");
	fflush(stdin); 
	gets (nome);
	printf("DIGITE SEU PRONTUÁRIO  :   ");
	fflush(stdin); 
	gets (pront);
	
	if((strcmp(nome, "MASTER") == 0 )){
	// Menu para usuários MASTER
	menu:
	system("mode 110, 20");
	system("cls");
	char opcao;
	
	printf("===========================================================================================================\n");
	printf("\t\t\t\tTESTE DOS SISTEMAS REPRESENTACIONAIS\n");
	printf("===========================================================================================================\n");
	printf("\t\t\t\t1. Cadastrar questionário\n\t\t\t\t2. Visualizar questionário\n\t\t\t\t3. Realizar teste\n\t\t\t\t4. Sobre o teste\n\t\t\t\tF. Fim\n");
	printf("===========================================================================================================\n");
	printf("\t\t\t\tEscolha -> ");
	fflush(stdin);
	scanf("%c", &opcao);

	switch(opcao){
		case '1':
			printf("1\n");
			break;
		case '2':
			printf("2\n");
			break;
		case '3':	
		
			system("cls");
			system("mode 110, 25");
			
			printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
			printf("\n\n1.Eu tomo decisões importantes baseado em: \n");
			printf("a) intuição.\n");
			printf("b) o que soa melhor.\n");
			printf("c) o que me parece melhor.\n");
			printf("d) um estudo preciso e minucioso do assunto.\n\n");
			
			escolha('a', 1);
			calculoCin += resultado;
			
			escolha('b', 2);
			calculoAud += resultado;
			
			escolha('c', 3);
			calculoCin += resultado;
			
			escolha('d', 4);
			calculoCin += resultado;
			
			system("cls");
			
			printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
			
			printf("\n\n2. Durante uma discussão eu sou mais influecidado por: \n");
			printf("a) o tom de voz da outra pessoa.\n");
			printf("b) se eu posso ou não ver o argumento da outra pessoa.\n");
			printf("c) o a lógica do argumento da outra pessoa.\n");
			printf("d) se eu entro em contato ou não com os sentimentos reais do outro.\n\n");
			
			confirmaZera();
			escolha('a', 1);
			calculoAud += resultado;
			
			escolha('b', 2);
			calculoVis += resultado;
			
			escolha('c', 3);
			calculoDig += resultado;
			
			escolha('d', 4);
			calculoCin += resultado;
			
			system("cls");
			
			printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
			
			printf("\n\n3. Eu comunico mais facilmente o que se passa comigo: \n");
			printf("a) domodo como me visto e aparento.\n");
			printf("b) pelos sentimentos que compartilho.\n");
			printf("c) pelas palavras que escolho.\n");
			printf("d) pelo tom da minha voz.\n\n");
			
			confirmaZera();
			escolha('a', 1);
			calculoVis += resultado;
			
			escolha('b', 2);
			calculoCin += resultado;
			
			escolha('c', 3);
			calculoDig += resultado;
			
			escolha('d', 4);
			calculoAud += resultado;
			
			system("cls");
			
			printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
			
			printf("\n\n4.É muito fácil para mim: \n");
			printf("a) achar o volume e a sintonia ideais num sistema de som.\n");
			printf("b) selecionar o ponto mais relevante relativo a um assunto interessante.\n");
			printf("c) escolher os móveis mais confortáveis.\n");
			printf("d) escolher as combinações de cores mais ricas e atraentes.\n\n");
			
			confirmaZera();
			escolha('a', 1);
			calculoAud += resultado;
			
			escolha('b', 2);
			calculoDig += resultado;
			
			escolha('c', 3);
			calculoCin += resultado;
			
			escolha('d', 4);
			calculoVis += resultado;
			
			system("cls");
			
			printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
			
			printf("\n\n5. Eu me percebo assim: \n");
			printf("a) se estou muito em sintonia com os sons do ambiente.\n");
			printf("b) se sou muito capaz de raciocinar com fatos e dados novos.\n");
			printf("c) eu sou muito sensível à maneira como a roupa veste o meu corpo.\n");
			printf("d) eu respondo fortemente às cores e à aprência de uma sala.\n\n");
			
			confirmaZera();
			escolha('a', 1);
			calculoAud += resultado;
			
			escolha('b', 2);
			calculoDig += resultado;
			
			escolha('c', 3);
			calculoCin += resultado;
			
			escolha('d', 4);
			calculoVis += resultado;
			
			system("cls");
			
			calculoAud *= 2;
			calculoDig *= 2;
			calculoCin *= 2;
			calculoVis += 2;
			
		Arq = fopen ("MASTER", "w"); 
				if (Arq==NULL){
					system ("cls");
					printf("\n erro ao abrir arquivo");
					getch();
					exit (EXIT_FAILURE);		
				}
				
				printf ("\n Arquivo aberto no endereço [%p]", Arq);
				
				
				fprintf ( Arq, "============================ PERFIL REPRESENTACIONAL DE MASTER ============================ "); 
				
				maior = calculoVis;
				strcpy(maior_txt, "Visual");
				
				if (maior < calculoAud)
				{
					maior = calculoAud;
					strcpy(maior_txt, "Auditivo");
				}
				else
				{
					if (maior == calculoAud)
						strcat(maior_txt, " e Auditivo");
				}
				
				if (maior < calculoDig)
				{
					maior = calculoDig;
					strcpy(maior_txt, "Digital");
				}
				else
				{
					if (maior == calculoDig)
						strcat(maior_txt, " e Digital");
				}
				
				if (maior < calculoCin)
				{
					maior = calculoCin;
					strcpy(maior_txt, "Cinestésico");
				}
				else
				{
					if (maior == calculoCin)
						strcat(maior_txt, " e Cinestésico");
				}
					
				fprintf (Arq, "\n	%.0d %% Visual  -  %.0d %% Digital -  %.0d %% Auditivo  -  %.0d %% Cinestesico", calculoVis, calculoDig, calculoAud, calculoCin);
				fprintf ( Arq, "\n========================================================================================");
				fprintf ( Arq, "\n\nAlgumas pessoas capta melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.");
				fprintf ( Arq, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais");
				fprintf ( Arq, "\nAs cinestésicas aprendem melhor por meio  das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.");
				fprintf ( Arq, "\nJá as pessoas visuais aprendem melhor quando se valendo da visão.");
				fprintf ( Arq, "\n========================================================================================");
				
				fprintf ( Arq, "\nSeu perfil é: %s", maior_txt);
				fprintf ( Arq, "\n========================================================================================");
				fclose (Arq);
				
				getch();
				goto menu;
		
				break;
		case '4':
			{
			Arq = fopen ("REFERENCIAL_TEORICO.TXT", "w"); 
				if (Arq==NULL)
				{
					system ("cls");
					printf("\nFalha ao abrir o arquivo.");
					getch();
					exit (EXIT_FAILURE);
				}
				printf ("\n Arquivo aberto [%p]", Arq);
				
	
				fprintf ( Arq, "\nREFERENCIAL TEÓRICO\n");
				fprintf ( Arq, "--------------------");
				fprintf ( Arq, "\n\nSegundo Albert Merabian, em seu livro \"Silent Messages\", o poder de influência das palavras não passa de 7%, enquanto a forma como as palavras");
				fprintf ( Arq, "\nsão ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.");
				fprintf ( Arq, "\n\nPara Merabian 55%% do impacto da comunicação é não-verbal. Corresponde à postura, gestos e contato visual da pessoa enquanto se comunica.");
				fprintf ( Arq, "\n\nO tom da voz representa 38%% do impacto da comunicação.");
				fprintf ( Arq, "\n\nPor fim, as palavras propriamente ditas detêm 7%% do impacto da comunicação.");
				fprintf ( Arq, "\n\nAssim sendo, conclui Merabian, não é o que dizemos, mas como dizemos que faz a diferença na comunicação.");
				fprintf ( Arq, "\n\nAs portas da percepção são nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos únicos pontos de contato com o mundo exterior.");
				fprintf ( Arq, "\nDa mesma forma que utilizamos os sentidos para filtrarmos as experiências, utilizamos os sentidos para estruturar nosso pensamento e nossa comunicação.");
				fprintf ( Arq, "\n\nDe acordo com a Programação Neurolinguistica existem os seguintes sistemas representacionais.");
				fprintf ( Arq, "\n\n- Auditivo");
				fprintf ( Arq, "\n- Digital");
				fprintf ( Arq, "\n- Cinestésico");
				fprintf ( Arq, "\n- Visual");
				fprintf ( Arq, "\n\nAlgumas pessoas capta melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.");
				fprintf ( Arq, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais");
				fprintf ( Arq, "\nAs cinestésicas aprendem melhor por meio  das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.");
				fprintf ( Arq, "\nJá as pessoas visuais aprendem melhor quando se valendo da visão.");
				fprintf ( Arq, "\n\nCada pessoa tem um sistema representacional predominante e adequar a comunicação ao sistema representacional dominante dela e funcamental para diálogos eficientes");
				fclose (Arq);
				system ("REFERENCIAL_TEORICO.TXT");
			}
			break;
		case 'f':
			exit(0);
			break;
		case 'F':
			exit(0);
			break;
		default:
			system("cls");
			system("mode 50, 7");
			printf("\n\n\t\tERRO AO ESCOLHER!\n\n");
			getch();
			goto menu;
	}
} else{
	system("cls");
	system("mode 110, 25");
	printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
	
	printf("\n\n1.Eu tomo decisões importantes baseado em: \n");
	printf("a) intuição.\n");
	printf("b) o que soa melhor.\n");
	printf("c) o que me parece melhor.\n");
	printf("d) um estudo preciso e minucioso do assunto.\n\n");
	
	escolha('a', 1);
	calculoCin += resultado;
	
	escolha('b', 2);
	calculoAud += resultado;
	
	escolha('c', 3);
	calculoCin += resultado;
	
	escolha('d', 4);
	calculoCin += resultado;
	
	system("cls");
	
	printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
	
	printf("\n\n2. Durante uma discussão eu sou mais influecidado por: \n");
	printf("a) o tom de voz da outra pessoa.\n");
	printf("b) se eu posso ou não ver o argumento da outra pessoa.\n");
	printf("c) o a lógica do argumento da outra pessoa.\n");
	printf("d) se eu entro em contato ou não com os sentimentos reais do outro.\n\n");
	
	confirmaZera();
	escolha('a', 1);
	calculoAud += resultado;
	
	escolha('b', 2);
	calculoVis += resultado;
	
	escolha('c', 3);
	calculoDig += resultado;
	
	escolha('d', 4);
	calculoCin += resultado;
	
	system("cls");
	
	printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
	
	printf("\n\n3. Eu comunico mais facilmente o que se passa comigo: \n");
	printf("a) domodo como me visto e aparento.\n");
	printf("b) pelos sentimentos que compartilho.\n");
	printf("c) pelas palavras que escolho.\n");
	printf("d) pelo tom da minha voz.\n\n");
	
	confirmaZera();
	escolha('a', 1);
	calculoVis += resultado;
	
	escolha('b', 2);
	calculoCin += resultado;
	
	escolha('c', 3);
	calculoDig += resultado;
	
	escolha('d', 4);
	calculoAud += resultado;
	
	system("cls");
	
	printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
	
	printf("\n\n4.É muito fácil para mim: \n");
	printf("a) achar o volume e a sintonia ideais num sistema de som.\n");
	printf("b) selecionar o ponto mais relevante relativo a um assunto interessante.\n");
	printf("c) escolher os móveis mais confortáveis.\n");
	printf("d) escolher as combinações de cores mais ricas e atraentes.\n\n");
	
	confirmaZera();
	escolha('a', 1);
	calculoAud += resultado;
	
	escolha('b', 2);
	calculoDig += resultado;
	
	escolha('c', 3);
	calculoCin += resultado;
	
	escolha('d', 4);
	calculoVis += resultado;
	
	system("cls");
	
	printf("Nas frases a seguir, pontue com:\n4 a que melhor descreve você;\n3 a próxima melhor descrição; \n2 a próxima melhor; \n1 aquela que menos descreve você.");
	
	printf("\n\n5. Eu me percebo assim: \n");
	printf("a) se estou muito em sintonia com os sons do ambiente.\n");
	printf("b) se sou muito capaz de raciocinar com fatos e dados novos.\n");
	printf("c) eu sou muito sensível à maneira como a roupa veste o meu corpo.\n");
	printf("d) eu respondo fortemente às cores e à aprência de uma sala.\n\n");
	
	confirmaZera();
	escolha('a', 1);
	calculoAud += resultado;
	
	escolha('b', 2);
	calculoDig += resultado;
	
	escolha('c', 3);
	calculoCin += resultado;
	
	escolha('d', 4);
	calculoVis += resultado;
	
	system("cls");
	
	calculoAud *= 2;
	calculoDig *= 2;
	calculoCin *= 2;
	calculoVis += 2;
	
Arq = fopen (nome, "w"); 
		if (Arq==NULL){
			system ("cls");
			printf("\n erro ao abrir arquivo");
			getch();
			exit (EXIT_FAILURE);		
		}
		
		printf ("\n Arquivo aberto no endereço [%p]", Arq);
		
		
		fprintf ( Arq, "============================ PERFIL REPRESENTACIONAL DE %c" " ============================", nome); 
		
		maior = calculoVis;
		strcpy(maior_txt, "Visual");
		
		if (maior < calculoAud)
		{
			maior = calculoAud;
			strcpy(maior_txt, "Auditivo");
		}
		else
		{
			if (maior == calculoAud)
				strcat(maior_txt, " e Auditivo");
		}
		
		if (maior < calculoDig)
		{
			maior = calculoDig;
			strcpy(maior_txt, "Digital");
		}
		else
		{
			if (maior == calculoDig)
				strcat(maior_txt, " e Digital");
		}
		
		if (maior < calculoCin)
		{
			maior = calculoCin;
			strcpy(maior_txt, "Cinestésico");
		}
		else
		{
			if (maior == calculoCin)
				strcat(maior_txt, " e Cinestésico");
		}
			
		fprintf (Arq, "\n	%.0d %% Visual  -  %.0d %% Digital -  %.0d %% Auditivo  -  %.0d %% Cinestesico", calculoVis, calculoDig, calculoAud, calculoCin);
		fprintf ( Arq, "\n========================================================================================");
		fprintf ( Arq, "\n\nAlgumas pessoas capta melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.");
		fprintf ( Arq, "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais");
		fprintf ( Arq, "\nAs cinestésicas aprendem melhor por meio  das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.");
		fprintf ( Arq, "\nJá as pessoas visuais aprendem melhor quando se valendo da visão.");
		fprintf ( Arq, "\n========================================================================================");
		
		fprintf ( Arq, "\nSeu perfil é: %s", maior_txt);
		fprintf ( Arq, "\n========================================================================================");
		fclose (Arq);
		system ("nome.txt");
}
	
	
	system("pause");
}
