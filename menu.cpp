#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

#define ESC 27

struct endereco {
    char rua[50], estado[30], bairro[50], cidade[50];
    int numero, cep;
};

struct descricao {
    char genero[2], sexualidade[15], apelido[10], gosto_gerais[150], descricao[1000];
};

struct telefone {
    int ddd, numero;	
};

struct cadastro {
    int dia, mes, ano, idade;
    long int cpf; 
    char nome[75], email[75];
    struct endereco endereco;
    struct descricao descricao;
    struct telefone numero;
};

void cadastrarNovoPerfil(struct cadastro cadastro);
void exibirPerfil(struct cadastro cadastro);
void alterarCadastro(struct cadastro cadastro);


int main(){
        struct cadastro minhaStruct;		

    	int opcaoMenuPrincipal = 1;
			
		int i, menu2;
			
			

		system("cls");
		
		while(opcaoMenuPrincipal!=ESC){
			printf("\n\n\n");
			printf("\n\t*************************************************************");
			printf("\n\t*                          NOME                             *");				
			printf("\n\t*                                                           *");
			printf("\n\t*                  *  MENU PRINCIPAL  *                     *");
			printf("\n\t*                                                           *");
			printf("\n\t*                                                           *");				
			printf("\n\t*            * DIGITE O NUMERO DA OPCAO DESEJADA            *");
			printf("\n\t*                                                           *");
			printf("\n\t*                     1 - CADASTRO:                         *");
			printf("\n\t*                     2 - EXIBIR PERFIL:                    *");				
			printf("\n\t*                     3 - ALTERAR:                          *");
			printf("\n\t*          	       ESC - SAIR DO PROGRAMA                   *");
			printf("\n\t*                                                           *");                                                       
			printf("\n\t*                                                           *");				
			printf("\n\t*************************************************************");
			printf("\n\n\n");
			
			scanf("%d", &opcaoMenuPrincipal);
        	fflush(stdin);
        	printf("\n");
       		system("cls");
       		 
       		switch (opcaoMenuPrincipal){
		        case 1:
		            cadastrarNovoPerfil(minhaStruct);
		            break;
		        case 2:
		            exibirPerfil(minhaStruct);
		            break;
		        case 3:
		            alterarCadastro(minhaStruct);
		            break;
		    }
		}
	return 0;
}

	void cadastrarNovoPerfil(struct cadastro cadastro)
{
    	printf("\n\n\n");
		printf("\n\t*************************************************************");
		printf("\n\t*                          NOME                             *");
		printf("\n\t*                                                           *");				
		printf("\n\t*                                                           *");
		printf("\n\t*                  *  NOVO CADASTRO  *                      *");
		printf("\n\t*                                                           *");
		printf("\n\t*                       ESC-VOLTAR                          *");
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
			
		printf("\n NOME COMPLETO: ");
		gets(cadastro.nome);
		fflush(stdin);
									
		printf("\n EMAIL: ");
		gets(cadastro.email);
		fflush(stdin);
									
		printf("\n DATA DE NASCIMENTO: \n");
		printf("\n DIA: ");
		scanf("%d", &cadastro.dia);
		printf("\n MES: ");
		scanf("%d", &cadastro.mes);
		printf("\n ANO: ");
		scanf("%d", &cadastro.ano);
									
		printf("\n TELEFONE: \n");
		printf("\n DDD: ");
		scanf("%d", &cadastro.numero.ddd);
		printf("\n NUMERO: ");
		scanf("%d", &cadastro.numero.numero);
									
		printf("\n CPF: ");
		scanf("%d", &cadastro.cpf);
									
		system ("cls");
		
		printf("\n\n\n");
		printf("\n\t*************************************************************");
		printf("\n\t*                          NOME                             *");
		printf("\n\t*                                                           *");				
		printf("\n\t*                                                           *");
		printf("\n\t*                    *  NOVO PERFIL  *                      *");
		printf("\n\t*                                                           *");
		printf("\n\t*                        ESC-VOLTAR                         *");
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
		
		printf("\n APELIDO: ");
		gets(cadastro.descricao.apelido);
		
		printf("\n GENERO F/M: ");
		scanf("%c", &cadastro.descricao.genero);
		
		printf("\n SEXUALIDADE: ");
		gets(cadastro.descricao.sexualidade);
		
		printf("\n GOSTOS GERAIS: ");
		printf("\n EX: futebol, jogos, esportes, livros, e etc...");
		gets(cadastro.descricao.gosto_gerais);
		
		printf("\n DESCRICAO: ");
		gets(cadastro.descricao.descricao);
}

void exibirPerfil(struct cadastro cadastro)
{
    printf("\n\n\n");
	printf("\n\t*************************************************************");
	printf("\n\t*                          NOME                             *");				
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*                      * CADASTRO *                         *");
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*************************************************************");
						
	printf("\n NOME: %s", cadastro.nome);
	printf("\n EMAIL: %s", cadastro.email);
	printf("\n DATA DE NASCIMENTO: %d / %d / %d", cadastro.dia, cadastro.mes, cadastro.ano);
	printf("\n TELEFONE: %d  %d", cadastro.numero.ddd, cadastro.numero.numero);
	printf("\n CPF: %d", cadastro.cpf);		
						
	printf("\n\n\n");
	printf("\n\t*************************************************************");
	printf("\n\t*                          NOME                             *");				
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*                       * PERFIL *                          *");
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*************************************************************");
						
	printf("\n NOME: %s", cadastro.nome);
	printf("\n APELIDO: %s", cadastro.descricao.apelido);
	printf("\n GENERO: %c", cadastro.descricao.genero);
	printf("\n SEXUALIDADE: %s", cadastro.descricao.gosto_gerais);
	printf("\n GOSTOS GERAIS: %s", cadastro.descricao.gosto_gerais);
	printf("\n DESCRICAO: %s", cadastro.descricao.descricao);
}

void alterarCadastro(struct cadastro cadastro)
{
    int menuAlteracao, menuAltCadastro, menuAltPerfil, menu3;

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                      * ALTERACAO *                        *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                      1 - CADASTRO:                        *");
    printf("\n\t*                      2 - PERFIL:                          *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
  	printf("\n\t*************************************************************");
    scanf("%d", &menuAlteracao);

    if (menuAlteracao == 1 || menuAlteracao == 2 || menuAlteracao == ESC) {

        switch (menuAlteracao) {
            case 1:

                printf("\n\n\n");
                printf("\n\t*************************************************************");
                printf("\n\t*                          NOME                             *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*               * ALTERACAO DE CADASTRO *                   *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*************************************************************");

                sleep(3);
                system("cls");

                printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
                printf("\n 1 - NOME: %s", cadastro.nome);
                printf("\n 2 - EMAIL: %s", cadastro.email);
                printf("\n 3 - DATA DE NASCIMENTO: %d / %d / %d", cadastro.dia, cadastro.mes, cadastro.ano);
                printf("\n 4 - TELEFONE: %d  %d", cadastro.numero.ddd, cadastro.numero.numero);
                printf("\n 5 - CPF: %d", cadastro.cpf);

                scanf("%d", &menu3);

                switch (menuAltCadastro) {
                    case 1:
                        printf("\n DIGITE O NOVO NOME: ");
                        gets(cadastro.nome);
                        fflush(stdin);
                        break;

                    case 2:
                        printf("\n DIGITE O NOVO EMAIL: ");
                        gets(cadastro.email);
                        fflush(stdin);
                        break;

                    case 3:
                        printf("\n DIGITE A NOVA DATA DE NASCIMENTO: ");
                        printf("\n DIA: ");
                        scanf("%d", &cadastro.dia);
                        printf("\n MES: ");
                        scanf("%d", &cadastro.mes);
                        printf("\n ANO: ");
                        scanf("%d", &cadastro.ano);
                        break;

                    case 4:
                        printf("\n DIGITE O NOVO TELEFONE: ");
                        printf("\n NOVO DDD: ");
                        scanf("%d", &cadastro.numero.ddd);
                        printf("\n NOVO NUMERO: ");
                        scanf("%d", &cadastro.numero.numero);
                        break;

                    case 5:
                        printf("\n DIGITE O NOVO CPF: ");
                        scanf("%d", &cadastro.cpf);
                        break;

                    default:
                        printf("\n NUMERO INVALIDO!\n");
                        return alterarCadastro(cadastro);
                }
            break;

            case 2:
                printf("\n\n\n");
              	printf("\n\t*************************************************************");
                printf("\n\t*                          NOME                             *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*                 * ALTERACAO DE PERFIL *                   *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*************************************************************");

                sleep(3);
                system("cls");

                printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
                printf("\n 1 - APELIDO: %s ", cadastro.descricao.apelido);
                printf("\n 2 - GENERO F/M: %c ", cadastro.descricao.genero);
                printf("\n 3 - SEXUALIDADE: %s ", cadastro.descricao.sexualidade);
                printf("\n 4 - GOSTOS GERAIS: %s ", cadastro.descricao.gosto_gerais);
                printf("\n 5 - DESCRICAO: %s ", cadastro.descricao.descricao);

                scanf("%d", &menuAltPerfil);

                switch (menuAltPerfil) {
                    case 1:
                        printf("\n NOVO APELIDO: ");
                        gets(cadastro.descricao.apelido);
                        fflush(stdin);
                        break;

                    case 2:
                        printf("\n NOVO GENERO F/M: ");
                        scanf(" %c", &cadastro.descricao.genero);
                        fflush(stdin);
                        break;

                    case 3:
                        printf("\n NOVA SEXUALIDADE: ");
                        gets(cadastro.descricao.sexualidade);
                        fflush(stdin);
                        break;

                    case 4:
                        printf("\n NOVO GOSTOS GERAIS: ");
                        gets(cadastro.descricao.gosto_gerais);
                        fflush(stdin);
                        break;

                    case 5:
                        printf("\n NOVA DESCRICAO: ");
                        gets(cadastro.descricao.descricao);
                        fflush(stdin);
                        break;

                    default:
                        printf("\n NUMERO INVALIDO!\n");
                        return alterarCadastro(cadastro);
                }
            break;

            default:
                printf("\n NUMERO INVALIDO!\n");
                return alterarCadastro(cadastro);
        }
    } else {
        printf("\n NUMERO INVALIDO!\n");
        return alterarCadastro(cadastro);
    }
}
