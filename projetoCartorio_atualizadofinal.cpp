#include <stdio.h> //biblioteca de comunicacao com o usuario 
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria (acentos, etc..) 
#include <locale.h> //biblioteca de alocacoes de texto por regiao (vai puxar a ortografia BR) 
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //funcao responsavel por cadastrar os usuarios no sistema 
{
	//INICIO - CRIACAO DE VARIAVEIS(STRINGS)
	char arquivo[40]; //variavel arquivo vai ser o cpf visto que cada arquivo tem um cpf 
	char cpf[40]; //tipo char para ser um caractere - colchetes[] significa que estamos criando uma string - 40 � a quantidade de caracteres 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao das variaveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando info do usuario 
	scanf("%s", cpf); //scanf com %s vai armazenar tudo dentro da string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // Criando o arquivo no banco de dados - funcao FILE vai acessar a biblioteca 
	file = fopen(arquivo, "w"); //o que � o file -fopen esta abrindo um aquivo com o nome da vari�vel (arquivo) e como estamos pedindo pra criar um arquivo novo colocamos "W" write
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo e estamos pedindo pra atualizar entao usamos o "a" 
	fprintf(file,","); //aqui colocamos uma , para que quando as infos forem compiladas estejam separadas por , 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //o que o usuario digitar vai ser salvo numa string %s na variavel 
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //salvando a variavel nome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo e estamos pedindo pra atualizar entao usamos o "a" 
	fprintf(file,","); //aqui colocamos uma , para que quando as infos forem compiladas estejam separadas por , 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //o que o usuario digitar vai ser salvo numa string %s na variavel 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo e estamos pedindo pra atualizar entao usamos o "a" 
	fprintf(file,","); //aqui colocamos uma , para que quando as infos forem compiladas estejam separadas por , 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consulta() //funcao para consultar os usuarios no sistema
{ 
	setlocale(LC_ALL, "Portuguese"); //linguagem pra conseguir ler acentos e outras coisas da lingua portuguesa
	
	char cpf[40]; //criando novamente o arquivo CPF para consulta
	char conteudo[200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf,"r");	//Estamos abrindo o arquivo CPF e pedindo para ele Ler "r" (read) 
	
	if(file == NULL) // == 2= � uma comparacao
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //*Fun�ao pra salvar o arquivo dentro -While(enquanto) -fgets(ta indo buscar) ou seja Enquanto ele estiver escrevendo na variavel (string conteudo) ate 200 valores que estao dentro do arquivo (file que � o cpf) ate ser nulo 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
}


int deletar() //funcao para deletar os usuarios no sistema
{ 
	char cpf[40]; 
	
	printf("Digite o CPF a ser deletado: ");//texto 
	scanf("%s", cpf); //string + cpf 
	
	remove(cpf);
	
	FILE *file; //entrar no campo da biblioteca e acessar os arquivos 
	file = fopen(cpf,"r"); //chamo o cara de cima - file - fopen e a funcao pra abrir a pasta e o arquivo � o cpf e r para ele ler o cpf - read 
	
	if(file == NULL)
		{ 
			printf("O usu�rio n�o se encontra no sistema!.\n"); //barra ao contrario � comando	
		}	
	else
		{
			printf("Usu�rio deletado com sucesso!\n");
		}
		
		system("pause"); //pra mensagem chegar e nao sumir de uma vez
}

int main()//fun��o principal (main) sempre vai ser a primeira a ser executada 
{
	int opcao=0; //definindo a variavel opcao (o = e a atribuicao)
	int laco=1; //variavel x para o la�o de repeti�ao
	
	for(laco=1;laco==1;)
	{

		system("cls"); //limpa a tela ap�s a sele��o 
		
		setlocale(LC_ALL, "Portuguese"); //linguagem pra conseguir ler acentos e outras coisas da lingua portuguesa
		
		printf("### Cart�rio do Cazuza ###\n\n"); //o barra n serve para dar espaco entre linhas 
		printf("Escolha a op��o desejada do menu abaixo:\n\n");
		printf("\t1 - Resgistrar nomes\n"); //barra t serve para inserir um paragrafo
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("Op��o desejada:  ");
		
		scanf("%d", &opcao); //scanf armazena tudo que o usuario digita - aqui eu to referenciando tudo qque o usuario digita na variavel opcao 
		
		system("cls"); //comando cls limpa a tela anterior 
	
		switch(opcao) //� a mesma coisa do IF - � uma escolha
		{
			case 1://se eu clicar 1 vou para: XXX
			registro(); //chamada de funcoes
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Por favor, escolha somente as op��es dispon�veis!");
			system("pause");
		}	
	}
}


