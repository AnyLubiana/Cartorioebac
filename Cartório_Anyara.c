#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memório
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável pelas strings

int registro() //esta função cadastra os usurários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];//criação das variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final da criação das variáveis 

	printf("Digite o CPF do novo cadastro: "); //coletante informações
	scanf("%s", cpf);
		
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings	
	
	FILE *file; // cria arquivo do banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //salva a valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo. A se refere a atualizar 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo não localizado. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)

	{
		printf("\n Essas são as informações dos usuário:");
		printf("%s", conteudo);
		printf("\n\n");
		
		
	}
	
	system("pause");
	
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o cpf do cadastro que deseja deletar: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
			
	if(file == NULL)
	{
		printf("Cadastro não encontrado! Verifique o número digitado e tente novamente. \n");
		system("pause");
				
	}
	
	else
	{
		fclose(file);
		remove(cpf);
		printf("Cadastro deletado com sucesso! \n");
		system("pause");
		
	}		
	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");	//Início do Menu
		printf("Escolha a opção desejada do Menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair \n\n\n"); 
		printf("Digite a opção que deseja:"); // Fim do Menu
	
		scanf("%d", &opcao);
	
		system("cls");
		
		switch(opcao) // inicio seleção do Menu 
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
			printf("Obrigada por utilizar nosso sistema! \n");
			return 0;
			break;
						
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;			
		}
		
		
	//fim da seleção
}
} 
