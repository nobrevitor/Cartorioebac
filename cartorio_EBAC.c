#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�oes em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta, "w" escrever
	fprintf(file,"\n CPF: ");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //virgula e estiliza��o
	fprintf(file, "\n NOME: ");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // "a" atualiza
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //virgula e estiliza��o
	fprintf(file, "\n SOBRENOME: ");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //virgula e estiliza��o
	fprintf(file, "\n CARGO: ");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,"\n ");
	fclose(file);
	
	printf("\nCadastro realizado com sucesso!\n");
	system("pause");
}

int consulta() //Fun��o respons�vel por consultar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria��o de vari�veis
	char cpf[40];
	char conteudo[200]; //vari�vel de consulta do conteudo do arquivo
	//fim cria��o de vari�veis
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //consultando o aquivo
	file = fopen(cpf, "r"); //abrindo o arquivo, "r" l� o aquivo
	
	if(file==NULL) //fun��o caso n�o encontre o arquivo
	{
		printf("\n N�o foi poss�vel abrir o arquivo! N�o localizado. \n\n");
	}
	else //caso encontre siga com as instru��es
	{
		printf("\n Essas s�o as iforma��es do usu�rio:"); //estiliza��o
		while(fgets(conteudo, 200, file) != NULL) //la�o de repeti��o para buscar o conteudo
		{
			printf("%s", conteudo);
			printf("\n");
		}
	}
	fclose(file); //fechando o arquivo consultado
	system ("pause"); //pausa a tela ap�s finalizar a consulta
}

int deletar() //Fun��o respons�vel por deletar o usu�rio do sistema
{
	//in�cio cria��o de vari�veis
	char cpf[40];
	int resposta=0; //vari�vel para confirma��o
	//fim cria��o de vari�veis
	
	printf(" Digite o CPF a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	FILE *file; //buscando o arquivo
	file = fopen(cpf, "r"); //abrindo o arquivo e lendo o mesmo
	
	if(file == NULL) //fun��o de confirma��o que o usu�rio existe
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
		system("cls");
		return main();	
	}	
	
	printf("\n Tem certeza que deseja deletar o usu�rio de CPF: "); //confirma��o de seguran�a
	printf("%s", cpf);
	
	printf("\n\n Digite 1 para sim e 2 para n�o: "); //coletando resposta
	scanf("%d", &resposta); //armazenando resposta
	
	switch(resposta) //fun��o para validar a confirma��o de seguran�a
	{
		case 1:
		resposta == 1;
		fclose(file);
		remove(cpf);
		printf("\n Usu�rio deletado com sucesso!\n");
		system("pause");
		break;
			
		case 2:
		resposta == 2;
		fclose(file);
		printf("\n Retorne ao menu! \n");
		system("pause");
		system("cls");
		break;
		
		default:
		printf("\n Esta op��o n�o est� disponivel! Tente novamente! \n");
		system("pause");
		system("cls");
		return deletar();
		break;	
	}
	
}

int main()
{
	int opcao=0; //Definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\t### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		
		printf(" Escolha a op��o desejada do menu:\n\n");
		
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuario
		
		system("cls");
		
		switch(opcao) //Inicio 
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;	//Fim escolhas
		}
	}
}

