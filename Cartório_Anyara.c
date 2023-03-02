#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�rio
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //esta fun��o cadastra os usur�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];//cria��o das vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final da cria��o das vari�veis 

	printf("Digite o CPF do novo cadastro: "); //coletante informa��es
	scanf("%s", cpf);
		
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings	
	
	FILE *file; // cria arquivo do banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //salva a valor da vari�vel
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
		printf("Arquivo n�o localizado. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)

	{
		printf("\n Essas s�o as informa��es dos usu�rio:");
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
		printf("Cadastro n�o encontrado! Verifique o n�mero digitado e tente novamente. \n");
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
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");	//In�cio do Menu
		printf("Escolha a op��o desejada do Menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair \n\n\n"); 
		printf("Digite a op��o que deseja:"); // Fim do Menu
	
		scanf("%d", &opcao);
	
		system("cls");
		
		switch(opcao) // inicio sele��o do Menu 
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;			
		}
		
		
	//fim da sele��o
}
} 
