#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaços de memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsável pelas strings

int registro ()
{
	setlocale(LC_ALL, "portuguese"); // Definindo linguagem

	char arquivo[40];
	char cpf [40];					
	char nome[40];				// Definindo variáveis 
	char sobrenome[40];
	char cargo [40];
	
	printf ("digite o cpf a ser cadastrado: ");
	scanf("%39s", cpf);		// inserção de varável pelo usuário
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo
	fprintf(file, "cpf: ");
	fprintf(file, cpf); //salvo o valor da variável 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Nome: "); //para colocar vírgula dentro do arquivo	
	printf("Digite o Nome a Ser Cadastrado: ");
	scanf("%39s", nome);
	fprintf(file, nome);
	fclose(file);
	
	fopen(arquivo, "a");
	printf("digite o sobrenome: ");
	scanf("%s", sobrenome);
	fprintf(file," %s", sobrenome);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file, ", Cargo:");
	printf("Digite o Cargo a Ser Cadastrado: ");
	scanf("%39s",cargo);
	fprintf(file,cargo);
	fclose(file);			//fechar o arquivo
	
	system("pause"); //para manter a mensagem na tela, pausando o programa
}

int consulta ()

{

	setlocale(LC_ALL, "portuguese"); // Definindo linguagem

	char cpf[40];				//definindo variáveis
	char conteudo[200];		
	
	printf("Digite o CPF a ser consultado: ");		
	scanf("%s", cpf); // inserção do valor da variável pelo usuário
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo
	
	if(file==NULL) //caso o arquivo não exista
	{
		printf("Não foi possível Localizar nos Registros!\n");
	}
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s, ", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar ()
{
	char cpf[40];
	char decisao[40];
	printf ("Digite o cpf da pessoa a ser retirada do Bancon de Dados: ");
	scanf("%s", cpf); //Registro da variável cpf
	
	FILE *file; //abertura da pasta com o mesmo numero da variável cpf
	file = fopen (cpf, "r"); 
	fclose(file);

	if(file == NULL)
	{

		printf ("o Usuário não se encontra no Sistema :(\n");
		system("pause");
	}	
	else
		printf("o cpf: %s foi localizado em nosso Banco de dados.\n", cpf);		
	
		remove (cpf);

		printf("Removido com Sucesso!\n");
		printf("aperte qualquer botão para voltar ao menu <3\n");
		system ("pause");
		
	}





int main(){ 
	char opcao;
	int ampulheta=1;
	for (ampulheta=1;ampulheta=1;)
	{
	
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "portuguese"); // Definindo linguagem
		
		printf("### Bancon de Dados###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opção: ");	
		
		scanf("%s", &opcao); // %s define que é para o comando scanf preencher o valor de uma variável do tipo string e o "& + opcao" é para indicar a variavel a ser preenchida, no caso a variavel opcao
	
		system("cls");
		
		switch(opcao) //inicio da seleção do menu
		{
				
			case '1':
				registro();
				break;
			case '2':
				consulta();
				break;
			case '3':
				deletar();
				break;
			default:
				printf("essa opção não está disponível :/\n");
				system ("pause");
				break;
				
				
		}
	}
}
