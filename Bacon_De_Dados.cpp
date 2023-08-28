#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaços de memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsável pelas strings

int registro () //função registro, utilizada para registrar os nomes
{
	setlocale(LC_ALL, "portuguese"); // Definindo linguagem

	char arquivo[40];
	char cpf [40];					
	char nome[40];				// Definindo variáveis 
	char sobrenome[40];
	char cargo [40];
	char decisao[]="a";
	char comparacao;
	printf ("digite o cpf a ser cadastrado: ");
	scanf("%39s", cpf);		// inserção de varável pelo usuário
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo
	fprintf(file, "cpf: ");
	fprintf(file, cpf); //salvo o valor da variável 
	fclose(file); //fecha o arquivo, para evitar bugs
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo, o "a" é para poder alterar o que contém no arquivo
	fprintf(file, ", Nome: "); //para colocar vírgula dentro do arquivo	
	printf("Digite o Nome a Ser Cadastrado: ");
	scanf("%39s", nome); //o "%39s", é para o sistema entender que é uma variavel do tipo string que não terá mais do que 39 caracteres
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
	
	system ("cls");
	printf("##Obrigado pela colaboração##\n");
	printf("##Aperte qualquer tecla para continuar trabalhando##\nDigite >sair< se quiser fechar o programa\n");
	scanf ("%s", &decisao);
	
	comparacao = strcmp(decisao, "sair");
	
	if (comparacao == 0)
	{
		exit(1);
	}
	

}

int consulta () //função consulta, utilizada para consultar os nomes já registrados. ainda é necessário otimizar essa.

{

	setlocale(LC_ALL, "portuguese"); // Definindo linguagem

	char cpf[40];				//definindo variáveis
	char conteudo[200];	
	char decisao[]="a";
	char comparacao;	
	
	printf("Digite o CPF a ser consultado: ");		
	scanf("%s", cpf); // inserção do valor da variável pelo usuário
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo
	
	if(file==NULL) //caso o arquivo não exista
	{
		printf("Não foi possível Localizar nos Registros!\n");
	}
	while(fgets(conteudo, 200, file)!=NULL) //no caso do cpf escolhido existir, a chamada de comando "fgets", junto do while, para que copiar todo o conteúdo do arquivo.
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s, ", conteudo);
		printf("\n\n");
	}
	system("pause"); //pause para que o usuário possa ver o que está na tela
	
		system ("cls");
	printf("##Obrigado pela colaboração##\n");
	printf("##Aperte qualquer tecla para continuar trabalhando##\nDigite >sair< se quiser fechar o programa\n");
	scanf ("%s", &decisao);
	
	comparacao = strcmp(decisao, "sair");
	
	if (comparacao == 0)
	{
		exit(1);
	}
}

int deletar () //chamada da função deletar, para remover cpf dos registros
{
	char cpf[40]; //utilizei variavel do tipo char, junto da tipagem string para evitar erro no caso de usarem alguma letra na hora de deletar o cpf.
	char decisao[40];
	char amendoim [] = "a";
	char comparacao;
	
	
	printf ("Digite o cpf da pessoa a ser retirada do Bancon de Dados: ");
	scanf("%s", cpf); //Registro da variável cpf
	
	FILE *file; //abertura da pasta com o mesmo numero da variável cpf
	file = fopen (cpf, "r"); 
	fclose(file);

	if(file == NULL)
	{

		printf ("o Usuário não se encontra no Sistema :(\n");
		system("pause");
		system ("cls");
		printf("##Aperte qualquer tecla para continuar trabalhando##\nDigite >sair< se quiser fechar o programa\n");
		scanf ("%s", &decisao);
	
		comparacao = strcmp(decisao, "sair");
	
		if (comparacao == 0)
		{
			exit(1);
		}
	}	
	else
		printf("o cpf: %s foi localizado em nosso Banco de dados.\n", cpf);		
	
		remove (cpf);

		printf("Removido com Sucesso!\n");
		printf("aperte qualquer botão para voltar ao menu <3\n");
		system ("pause");
		
		system ("cls");
		printf("##Obrigado pela colaboração##\n");
		printf("##Aperte qualquer tecla para continuar trabalhando##\nDigite >sair< se quiser fechar o programa\n");
		scanf ("%s", &decisao);
	
		comparacao = strcmp(decisao, "sair");		
		if (comparacao == 0)
		{
			exit(1);
		}
		
	}

int main(){ 
	char opcao;
	int ampulheta=1;
	char senha[]="a";
	int comparacao;
	
	printf("###BEM VINDO AO BACON DE DADOS###\nDigite a senha:");
	scanf("%s", senha); //variavel do tipo string para evitar erros

	comparacao = strcmp(senha, "admin"); //inserção de senha no programa, o strcmp compara a variavel senha com a palavra "admin", se ambas forem iguais retorna o valor "0" para a variavel "comparacao", dessa forma abrindo o programa.
	
	
		
	if (comparacao == 0) //exigencia para abrir o programa
	{
		
		for (ampulheta=1;ampulheta==1;) //para manter em looping o programa
		{
		
			system("cls"); //limpar a tela
			
			setlocale(LC_ALL, "portuguese"); // Definindo linguagem
			
			printf("### Bancon de Dados###\n\n");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do programa\n");
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
				case '4':
					printf("obrigado por usar o sistema <3");
					return 0; //para fechar o programa
					break;
				default:
					printf("essa opção não está disponível :/\n");
					system ("pause");
					break;
					
					
			}
		}
	}
	else
	system ("cls");
	printf("senha incorreta :(\n");
	system ("pause");
	
}
