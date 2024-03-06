#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaçoes em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta, "w" escrever
	fprintf(file,"\n CPF: ");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //virgula e estilização
	fprintf(file, "\n NOME: ");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // "a" atualiza
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //virgula e estilização
	fprintf(file, "\n SOBRENOME: ");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //virgula e estilização
	fprintf(file, "\n CARGO: ");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,"\n ");
	fclose(file);
	
	printf("\nCadastro realizado com sucesso!\n");
	system("pause");
}

int consulta() //Função responsável por consultar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio criação de variáveis
	char cpf[40];
	char conteudo[200]; //variável de consulta do conteudo do arquivo
	//fim criação de variáveis
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //consultando o aquivo
	file = fopen(cpf, "r"); //abrindo o arquivo, "r" lê o aquivo
	
	if(file==NULL) //função caso não encontre o arquivo
	{
		printf("\n Não foi possível abrir o arquivo! Não localizado. \n\n");
	}
	else //caso encontre siga com as instruções
	{
		printf("\n Essas são as iformações do usuário:"); //estilização
		while(fgets(conteudo, 200, file) != NULL) //laço de repetição para buscar o conteudo
		{
			printf("%s", conteudo);
			printf("\n");
		}
	}
	fclose(file); //fechando o arquivo consultado
	system ("pause"); //pausa a tela após finalizar a consulta
}

int deletar() //Função responsável por deletar o usuário do sistema
{
	//início criação de variáveis
	char cpf[40];
	int resposta=0; //variável para confirmação
	//fim criação de variáveis
	
	printf(" Digite o CPF a ser deletado: "); //coletando informação do usuário
	scanf("%s", cpf);
	
	FILE *file; //buscando o arquivo
	file = fopen(cpf, "r"); //abrindo o arquivo e lendo o mesmo
	
	if(file == NULL) //função de confirmação que o usuário existe
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
		system("cls");
		return main();	
	}	
	
	printf("\n Tem certeza que deseja deletar o usuário de CPF: "); //confirmação de segurança
	printf("%s", cpf);
	
	printf("\n\n Digite 1 para sim e 2 para não: "); //coletando resposta
	scanf("%d", &resposta); //armazenando resposta
	
	switch(resposta) //função para validar a confirmação de segurança
	{
		case 1:
		resposta == 1;
		fclose(file);
		remove(cpf);
		printf("\n Usuário deletado com sucesso!\n");
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
		printf("\n Esta opção não está disponivel! Tente novamente! \n");
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
		
		printf("\t### Cartório da EBAC ###\n\n"); //Inicio do menu
		
		printf(" Escolha a opção desejada do menu:\n\n");
		
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
		
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
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;	//Fim escolhas
		}
	}
}

