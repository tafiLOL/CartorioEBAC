#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de strings


int registro() //fun��o responsavel de cadastrar os usuarios no sistema
{
	char arquivo[40]; // criando todas as variaveis pro cadastro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf ("%s", cpf); //Vai armazenar o valor da string dentro da variavel CPF
	
	strcpy(arquivo, cpf); //vai copiar o valor da string cpf e armazenar na string arquivo
	
	FILE* file;
		file = fopen(arquivo, "w"); //vai abrir a pasta e criar o arquivo
		fprintf(file,cpf);
		fclose(file);
	
		file = fopen(arquivo, "a"); // atualizando o arquivo ja existente
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o sobrenome:");
	scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o cargo:");
	scanf("%s", cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nenhum arquivo correpondente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas s�o as informa��es do usu�rio:\n \t");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
    
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado no sistema!\n");
		system("pause");
	}
	
	else
	{
		if(remove(cpf) ==0);
		{
			printf("Usu�rio deletado com sucesso!\n\n");
			system("pause");
		}
		
	}	
}


int main()
{ 
	int opcao=0; // variavel op��o para armazenar a escolha no menu
	int menu=1;
	
	for(menu=1;menu=1;) // o LOOP sendo criado para sempre voltar para o MENU
    {
		system("cls"); //vai limpar a tela para retomar do come�o

    	setlocale(LC_ALL,"Portuguese_Brazil.1252");
	
		printf ("--- Cart�rio da EBAC ---\n\n");
		printf ("ESCOLHA A OP��O DESEJADA DO MENU: \n\n");
    	printf ("\t1 - Registrar nomes\n\n");
    	printf ("\t2 - Consultar nomes\n\n");
    	printf ("\t3 - Deletar nomes\n\n\n");
    	printf("Digite sua op��o:");
    
    	scanf ("%d", &opcao); // escaneia oque foi digitado e atribui � variavel op��o
    
    	system ("cls"); //limpa a tela para ir para as fun�oes
    
    	switch(opcao)
    	{
    		case 1: // chamada das fun�oes usando o CASE
    			registro();
    			break;
    		
    		case 2:
    			consultar();
    			break; // break para finalizar sempre
    			
    		case 3:
    			deletar();
				break;
				
			default: // default no CASE � como se fosse um NULL
				printf("op��o inexistente, tente novamente!\n");
				system("pause");
    			break;
    	}
       	
    }
}
