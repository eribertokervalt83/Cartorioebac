#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
int registro() //Função responsável por cadastrar usuários
{ 
    //início criação das variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário 
    scanf("%s", cpf); // //armazenando a escolha do usuário, %s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por criar os valores da string
    
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo , "w" significa escrever
    fprintf(file,cpf); // salva o valor da variável
    fclose(file); // fecha o arquivo
    
    
    file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, " , "); //insere a vírgula entre os arquivos
	fclose(file); //fecha a edição do arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Imprime na tela o campo para inserção de nome
	scanf("%s",nome); //armazenando a escolha do usuário
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, "NOME:"); //insere a especificação do dado
	fclose(file); //fecha a edição do arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file,nome); //abre o campo para inserção do nome
	fclose(file); //fecha a edição do arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, " , "); //insere a vírgula entre os arquivos
	fclose(file); //fecha a edição do arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Imprime na tela o campo para inserção de sobrenome
	scanf("%s",sobrenome); //armazenando a escolha do usuário
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, "SOBRENOME:"); //insere a especificação do dado
	fclose(file); //fecha a edição do arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file,sobrenome); //abre o campo para inserção do sobrenome
	fclose(file); //fecha a edição do arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, " , "); //insere a vírgula entre os arquivos
	fclose(file); //fecha a edição do arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Imprime na tela o campo para inserção do cargo
	scanf("%s",cargo); //armazenando a escolha do usuário
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file, "CARGO:"); //insere a especificação do dado
	fclose(file); //fecha a edição do arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para edição
	fprintf(file,cargo);//abre o campo para inserção do cargo
	fclose(file); //fecha a edição do arquivo
	
	system("pause"); //Responsável por fazer o código esperar para ir para outra tela
	
		
}

int consulta() //Função responsável por consultar usuários
{
	#include <locale.h> //biblioteca de alocações de texto por região
	
    char cpf[40]; //armazenando o CPF
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file; 
    file = fopen(cpf,"r");
    
    if(file == NULL) //Comando caso o digite CPF inválido
    {
    	printf("Não foi possível abrir o arquivo, não locoliazad0!.\n "); //mensagem de resposta na tela
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
	    printf("\nEssas são as informaçõaes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");	
	}	 
}

int deletar() //Função responsável por deletar usuários
{
    char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause"); 
	}
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	   system("cls");
		
	   setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	
     	printf("### cartório da ebac ###\n\n"); //início do menu
    	printf("escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registar nomes\n");
    	printf("\t2 - Consultar nomes\n ");
    	printf("\t3 - Deletar nomes\n\n"); 
    	printf("\t4 - Sair do sistema\n\n");
    	printf("opção: ");//Fim do menu
	
    	scanf("%d",  &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //Responsável por limpar a tela
    	
    	switch(opcao)
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
	    	printf("Obrigado por usar o sistema!\n");
	    	return 0;
	    	break;
	    		
	    	default:
	    	printf("Essa opção não está disponível!\n");
    	    system("pause");
    	    break;
		}
   	}		
}