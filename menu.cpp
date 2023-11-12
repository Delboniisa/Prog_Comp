#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "structs.h"
#include "animacao.h"

#define ESC 27

void cadastrarNovoPerfil(struct cadastro *cadastro);
void exibirPerfil(struct cadastro *cadastro);
void alterarCadastro(struct cadastro *cadastro);


	int main(){
		
		setlocale(LC_ALL, "Portuguese");
		
    	int opcaoMenuPrincipal = 1;
			
		int i, menu2;
			
			
		animar();
			
		while(menu1!=ESC){
			printf("\n\n\n");
			printf("\n\t*************************************************************");
			printf("\n\t*                          NOME                             *");				
			printf("\n\t*                                                           *");
			printf("\n\t*                  *  MENU PRINCIPAL  *                     *");
			printf("\n\t*                                                           *");
			printf("\n\t*                                                           *");				
			printf("\n\t*            * DIGITE O NÚMERO DA OPÇÃO DESEJADA            *");
			printf("\n\t*                                                           *");
			printf("\n\t*                     1 - CADASTRO:                         *");
			printf("\n\t*                     2 - MATCH:                            *");				
			printf("\n\t*                     3 - BUSCA:                            *");
			printf("\n\t*          	       ESC - SAIR DO PROGRAMA                   *");
			printf("\n\t*                                                           *");                                                       
			printf("\n\t*                                                           *");				
			printf("\n\t*************************************************************");
			printf("\n\n\n");
			
			opcaoMenuPrincipal = getch();
        	fflush(stdin);
        	printf("\n");
       		 system("cls");
       		 
       		switch (opcaoMenuPrincipal){
		        case 1:
		            cadastrarNovoPerfil();
		            break;
		        case 2:
		            exibirPerfil();
		            break;
		        case 3:
		            alterarCadastro();
		            break;
		        }
		}
	}
	void cadastrarNovoPerfil()
{
    	printf("\n\n\n");
		printf("\n\t*************************************************************");
		printf("\n\t*                          NOME                             *");
		printf("\n\t*                                                           *");				
		printf("\n\t*                                                           *");
		printf("\n\t*                  *  NOVO CADASTRO  *                      *");
		printf("\n\t*                                                           *");
		printf("\n\t*                      ESC-VOLTAR                           *");
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
			
		printf("\n NOME COMPLETO: ");
		gest(cadastro.nome);
		fflush(stdin);
									
		printf("\n EMAIL: ");
		gets(cadastro.email);
		fflush(stdin);
									
		printf("\n DATA DE NASCIMENTO: \n");
		printf("\n DIA: ");
		scanf("%d", &cadastro.dia);
		printf("\n MÊS: ");
		scanf("%d", &cadastro.mes);
		printf("\n ANO: ");
		scanf("%d", &cadastro.ano);
									
		printf("\n TELEFONE: \n");
		printf("\n DDD: ");
		scanf("%d", &cadastro.telefone.ddd);
		printf("\n NÚMERO: ");
		scanf("%d", &cadastro.telefone.numero);
									
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
		printf("\n\t*                      ESC-VOLTAR                           *");
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
		
		printf("\n APELIDO: ");
		gets(cadastro.descricao.apelido);
		
		printf("\n GÊNERO F/M: ");
		scanf("%c", &cadastro.descricao.genero);
		
		printf("\n SEXUALIDADE: ");
		gets(cadastro.descricao.sexualidade);
		
		printf("\n GOSTOS GERAIS: ");
		printf("\n EX: futebol, jogos, esportes, livros, e etc...");
		gets(cadastro.descricao.gosto_gerais);
		
		printf("\n DESCRIÇÃO: ");
		gets(cadastro.descricao.descricao);
}

void exibirPerfil()
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
	printf("\n TELEFONE: %d  %d", cadastro.telefone.ddd, cadastro.telefone.numero);
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
	printf("\n GÊNERO: %c", cadastro.descricao.genero);
	printf("\n SEXUALIDADE: %s", cadastro.descricao.gosto_gerais);
	printf("\n GOSTOS GERAIS: %s", cadastro.descricao.gosto_gerais);
	printf("\n DESCRIÇÃO: %s", cadastro.descricao.descricao);
}

void alterarCadastro()
{
	
	int menuAlteracao, menuAltCadastro, menuAltPerfil;
	
	printf("\n\n\n");
	printf("\n\t*************************************************************");
	printf("\n\t*                          NOME                             *");				
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*                      * ALTERAÇÂO *                        *");
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*                      1 - CADASTRO:                        *");
	printf("\n\t*                      2 - PERFIL:                          *");
	printf("\n\t*                                                           *");
	printf("\n\t*                                                           *");
	printf("\n\t*************************************************************");
	
	scanf("%d", &menuAlteracao);
	
	if(menuAlteracao== 1 || 2 || ESC){
		
		switch(menuAlteracao){
			case 1: 
			
				printf("\n\n\n");
				printf("\n\t*************************************************************");
				printf("\n\t*                          NOME                             *");				
				printf("\n\t*                                                           *");
				printf("\n\t*                                                           *");
				printf("\n\t*               * ALTERAÇÂO DE CADASTRO *                   *");
				printf("\n\t*                                                           *");
				printf("\n\t*                                                           *");
				printf("\n\t*************************************************************");
															
				sleep(3);
				system("cls");
															
				printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
				printf("\n 1 - NOME: %s", cadastro.nome);
				printf("\n 2 - EMAIL: %s", cadastro.email);
				printf("\n 3 - DATA DE NASCIMENTO: %d / %d / %d", cadastro.dia, cadastro.mes, cadastro.ano);
				printf("\n 4 - TELEFONE: %d  %d", cadastro.telefone.ddd, cadastro.telefone.numero);
				printf("\n 5 - CPF: %d", cadastro.cpf);
									
				scanf("%d", &menu3);
								
				switch(menuAltCadastro){
					case 1: printf("\n DIGITE O NOVO NOME: ");
						gets(cadastro.nome);
						fflush(stdin);
																
					case 2: printf("\n DIGITE O NOVO EMAIL: ");
						gets(cadastro.email);
						fflush(stdin);
																
					case 3: printf("\n DIGITE A NOVA DATA DE NASCIMENTO: ");
						printf("\n DIA: ");
						scanf("%d", &cadastro.dia);
						printf("\n MÊS: ");
						scanf("%d", &cadastro.mes);
						printf("\n ANO: ");
						scanf("%d", &cadastro.ano);
																
					case 4: printf("\n DIGITE O NOVO TELEFONE: ");
						printf("\n NOVO DDD: ");
						scanf("%d", &cadastro.telefone.ddd);
						printf("\n NOVO NÚMERO: ");
						scanf("%d", &cadastro.telefone.numero);
																
					case 5: printf("\n DIGITE O NOVO CPF: ");
						scanf("%d", &cadastro.cpf);	
				}
				
			case 2:
				printf("\n\n\n");
				printf("\n\t*************************************************************");
				printf("\n\t*                          NOME                             *");				
				printf("\n\t*                                                           *");
				printf("\n\t*                                                           *");
				printf("\n\t*                 * ALTERAÇÂO DE PERFIL *                   *");
				printf("\n\t*                                                           *");
				printf("\n\t*                                                           *");
				printf("\n\t*************************************************************");
															
				sleep(3);
				system("cls");
															
				printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
				printf("\n 1 - APELIDO: %s ", cadastro.descricao.apelido);
				printf("\n 2 - GENÊRO F/M: %c ", cadastro.descricao.genero);
				printf("\n 3 - SEXUALIDE: %s ", cadastro.descricao.sexualidade);
				printf("\n 4 - GOSTOS GERAIS: %s ", cadastro.descricao.gosto_gerais);
				printf("\n 5 - DESCRIÇÃO: %s ", cadastro.descricao.descricao);
				
				
				switch(menuAltPerfil){
				    case 1:
						printf("\n NOVO APELIDO: ");
						gets(cadastro.descricao.apelido);
						fflush(stdin);
					
					case 2:
						printf("\n NOVO GENÊRO F/M: ");
						gets(cadastro.descricao.genero);
						fflush(stdin);
					
					case 3:
						printf("\n NOVA SEXUALIDADE: ");
						gets(cadastro.descricao.sexualidade);
						fflush(stdin);
					
					case 4:
						printf("\n NOVO GOSTOS GERAIS: ");
						gets(cadastro.descricao.gosto_gerais);
						fflush(stdin);
					
					case 5:
						printf("\n NOVA DESCRIÇÃO: ");
						gets(cadastro.descricao.descricao);
						fflush(stdin);
					
		}
		
	}
	else{
		printf("\n NÚMERO INVÁLIDO! \n");
		
		return alterarCadastro();
	}
	
}
