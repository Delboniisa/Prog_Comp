#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#undef sleep


#define ESC 27

struct endereco {
    char rua[50], estado[30], bairro[50], cidade[50];
    int numero, cep[11];
};

struct descricao {
    char genero, sexualidade[15], apelido[10], gosto_gerais[150], descricao[1000];
};

struct telefone {
    int ddd, numero;
};

struct cadastro {
    long int cpf;
    char nome[75], email[75], dataNascimento[12];
    struct endereco endereco;
    struct descricao descricao;
    struct telefone numero;
    int dia, mes, ano;
};

// Colocar os prototipos das funcoes!!
int diferencaAbsoluta(int ano1, int ano2);
void cadastrarNovoPerfil(struct cadastro *cadastro);
void exibirPerfil(FILE *arquivo);
void alterarCadastro(FILE *arquivo, struct cadastro *cadastro);
void matchCadastro(FILE *arquivo, const struct cadastro *cadastro);
void aguardarEnterLimparTela();
void salvarCadastro(FILE *arquivo, struct cadastro novoCadastro);
void animar();
int buscarPerfilPorCPF(const struct cadastro *usuarioAtual, struct cadastro *perfilEncontrado, FILE *arquivo);

int main() {
    struct cadastro minhaStruct;

    FILE *arquivo; 
    arquivo = fopen("cadastros.txt", "a+"); // Modo "a+" para leitura e escrita, criando se nao existir

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcaoMenuPrincipal = 1;
	
	animar();
	
    while (opcaoMenuPrincipal != ESC) {
        printf("\n\n\n");
        printf("\n\t*************************************************************");
        printf("\n\t*                         CINDER                            *");
        printf("\n\t*                                                           *");
        printf("\n\t*                  *  MENU PRINCIPAL  *                     *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*            * DIGITE O NUMERO DA OPCAO DESEJADA            *");
        printf("\n\t*                                                           *");
        printf("\n\t*                     1 - CADASTRO:                         *");
        printf("\n\t*                     2 - EXIBIR PERFIL:                    *");
        printf("\n\t*                     3 - ALTERAR:                          *");
        printf("\n\t*                     4 - MATCH:                            *");
        printf("\n\t*                                                           *");
        printf("\n\t*************************************************************");
        printf("\n\n\n");

        scanf("%d", &opcaoMenuPrincipal);
        fflush(stdin);
        printf("\n");
        system("cls");
        
		
	        switch (opcaoMenuPrincipal) {
	            case 1:
	                cadastrarNovoPerfil(&minhaStruct); 
	                salvarCadastro(arquivo, minhaStruct);
	                break;
	            case 2:
	                exibirPerfil(arquivo);
	                break;
	            case 3:
	                alterarCadastro(arquivo, &minhaStruct);
	                break;
	            case 4:
	                matchCadastro(arquivo, &minhaStruct);
	                break;
	        }
	    
    }

    fclose(arquivo); // Para fecharmos o arquivo apos a utilizacao

    return 0;
}
void cadastrarNovoPerfil(struct cadastro *cadastro) {
	
	
    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                   *  NOVO CADASTRO  *                     *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    printf("\n NOME COMPLETO: ");
    fgets(cadastro->nome, sizeof(cadastro->nome), stdin);
    cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';
    fflush(stdin);

    printf("\n EMAIL: ");
    fgets(cadastro->email, sizeof(cadastro->email), stdin);
    cadastro->email[strcspn(cadastro->email, "\n")] = '\0';
    fflush(stdin);


    printf("\n DATA DE NASCIMENTO: \n ");
    printf("\n DIA: ");
    scanf("%d", &cadastro->dia);
    fflush(stdin);

    printf("\n MES: ");
    scanf("%d", &cadastro->mes);
    fflush(stdin);

    printf("\n ANO: ");
    scanf("%d", &cadastro->ano);
    fflush(stdin);

    printf("\n TELEFONE: \n");
    printf("\n DDD: ");
    scanf("%d", &cadastro->numero.ddd);
    fflush(stdin);

    printf("\n NUMERO: ");
    scanf("%d", &cadastro->numero.numero);
    fflush(stdin);

    printf("\n CPF: ");
    scanf("%ld", &cadastro->cpf);
    fflush(stdin);

    system("cls");

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                    *  NOVO PERFIL  *                      *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    fflush(stdin);

    printf("\n APELIDO: ");
    fgets(cadastro->descricao.apelido, sizeof(cadastro->descricao.apelido), stdin);
    cadastro->descricao.apelido[strcspn(cadastro->descricao.apelido, "\n")] = '\0';
    fflush(stdin);

    printf("\n GENERO F/M: ");
    scanf(" %c", &cadastro->descricao.genero);
    fflush(stdin);

    printf("\n SEXUALIDADE: ");
    fgets(cadastro->descricao.sexualidade, sizeof(cadastro->descricao.sexualidade), stdin);
    cadastro->descricao.sexualidade[strcspn(cadastro->descricao.sexualidade, "\n")] = '\0';
    fflush(stdin);

    printf("\n GOSTOS GERAIS: ");
    printf("\n EX: futebol, jogos, esportes, livros, e etc...\n");
    fgets(cadastro->descricao.gosto_gerais, sizeof(cadastro->descricao.gosto_gerais), stdin);
    cadastro->descricao.gosto_gerais[strcspn(cadastro->descricao.gosto_gerais, "\n")] = '\0';
    fflush(stdin);

    printf("\n DESCRICAO: ");
    fgets(cadastro->descricao.descricao, sizeof(cadastro->descricao.descricao), stdin);
    cadastro->descricao.descricao[strcspn(cadastro->descricao.descricao, "\n")] = '\0';
    fflush(stdin);

}

// Funcao para exibir o perfil
void exibirPerfil(FILE *arquivo) {
    long int cpf;
    
    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*          * DIGITE O CPF PARA ENCONTRAR O PERFIL *         *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");
    printf("\n \n");
    scanf("%ld", &cpf);

    struct cadastro perfilEncontrado;

    rewind(arquivo);

    while (fread(&perfilEncontrado, sizeof(struct cadastro), 1, arquivo) == 1) {
    	
        if (perfilEncontrado.cpf == cpf) {
        	
	printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                 * CADASTRO ENCONTRADO *                   *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");
    
    // Para exibir informacoees do cadastro
    
	printf("\n NOME: %s", perfilEncontrado.nome);
    printf("\n EMAIL: %s", perfilEncontrado.email);
	printf("\n DATA DE NASCIMENTO: %d / %d / %d", perfilEncontrado.dia, perfilEncontrado.mes, perfilEncontrado.ano);
	printf("\n TELEFONE: %d  %d", perfilEncontrado.numero.ddd, perfilEncontrado.numero.numero);
    printf("\n CPF: %ld", perfilEncontrado.cpf);

	Sleep(10);

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                  * PERFIL ENCONTRADO *                    *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    // Para exibir informações do perfil
    
    printf("\n APELIDO: %s", perfilEncontrado.descricao.apelido);
    printf("\n GENERO: %c", perfilEncontrado.descricao.genero);
    printf("\n SEXUALIDADE: %s", perfilEncontrado.descricao.sexualidade);
	printf("\n GOSTOS GERAIS: %s", perfilEncontrado.descricao.gosto_gerais);
    printf("\n DESCRICAO: %s", perfilEncontrado.descricao.descricao);

        return;  
        }
    }

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                * PERFIL NAO ENCONTRADO *                  *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");
}

void alterarCadastro(FILE *arquivo, struct cadastro *cadastro) {
    int menuAlteracao, menuAltCadastro, menuAltPerfil, menu3;

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
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
    printf("\n \n ");
    scanf(" %d", &menuAlteracao);
    
    system("cls");

    if (menuAlteracao == 1 || menuAlteracao == 2 || menuAlteracao == ESC) {
        switch (menuAlteracao) {
            case 1:
                printf("\n\n\n");
                printf("\n\t*************************************************************");
                printf("\n\t*                        CINDER                             *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*               * ALTERACAO DE CADASTRO *                   *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*************************************************************");

            	Sleep(2);
                system("cls");

                printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
                printf("\n 1 - NOME: %s", cadastro->nome);
                printf("\n 2 - EMAIL: %s", cadastro->email);
                printf("\n 3 - DATA DE NASCIMENTO: %d / %d / %d", cadastro->dia, cadastro->mes, cadastro->ano);
                printf("\n 4 - TELEFONE: %d  %d", cadastro->numero.ddd, cadastro->numero.numero);
                printf("\n 5 - CPF: %ld", cadastro->cpf);
				
				printf("\n \n");
                scanf("%d", &menuAltCadastro);
                

                switch (menuAltCadastro) {
                    case 1:
                        printf("\n DIGITE O NOVO NOME: ");
                        fgets(cadastro->nome, sizeof(cadastro->nome), stdin);
                        cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';
                        break;

                    case 2:
                        printf("\n DIGITE O NOVO EMAIL: ");
                        fgets(cadastro->email, sizeof(cadastro->email), stdin);
                        cadastro->email[strcspn(cadastro->email, "\n")] = '\0';
                        break;

                    case 3:
                        printf("\n DIGITE A NOVA DATA DE NASCIMENTO: ");
                        printf("\n DIA: ");
                        scanf("%d", &cadastro->dia);
                        printf("\n MES: ");
                        scanf("%d", &cadastro->mes);
                        printf("\n ANO: ");
                        scanf("%d", &cadastro->ano);
                        break;

                    case 4:
                        printf("\n DIGITE O NOVO TELEFONE: ");
                        printf("\n NOVO DDD: ");
                        scanf("%d", &cadastro->numero.ddd);
                        printf("\n NOVO NUMERO: ");
                        scanf("%d", &cadastro->numero.numero);
                        break;

                    case 5:
                        printf("\n DIGITE O NOVO CPF: ");
                        scanf("%ld", &cadastro->cpf);
                        break;

                    default:
                        printf("\n NUMERO INVALIDO!\n");
                        return alterarCadastro(arquivo, cadastro);
                }
                break;

            case 2:
                printf("\n\n\n");
                printf("\n\t*************************************************************");
                printf("\n\t*                         CINDER                            *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*                 * ALTERACAO DE PERFIL *                   *");
                printf("\n\t*                                                           *");
                printf("\n\t*                                                           *");
                printf("\n\t*************************************************************");

                Sleep(2);
                system("cls");

                printf("\n QUAL DOS ITENS DESEJA ALTERAR: ");
                printf("\n 1 - APELIDO: %s ", cadastro->descricao.apelido);
                printf("\n 2 - GENERO F/M: %c ", cadastro->descricao.genero);
                printf("\n 3 - SEXUALIDADE: %s ", cadastro->descricao.sexualidade);
                printf("\n 4 - GOSTOS GERAIS: %s ", cadastro->descricao.gosto_gerais);
                printf("\n 5 - DESCRICAO: %s ", cadastro->descricao.descricao);
				
				printf("\n \n");
                scanf("%d", &menuAltPerfil);

                switch (menuAltPerfil) {
                    case 1:
                        printf("\n NOVO APELIDO: ");
                        fgets(cadastro->descricao.apelido, sizeof(cadastro->descricao.apelido), stdin);
                        cadastro->descricao.apelido[strcspn(cadastro->descricao.apelido, "\n")] = '\0';
                        break;

                    case 2:
                        printf("\n NOVO GENERO F/M: ");
                        scanf(" %c", &cadastro->descricao.genero);
                        fflush(stdin);
                        break;

                    case 3:
                        printf("\n NOVA SEXUALIDADE: ");
                        fgets(cadastro->descricao.sexualidade, sizeof(cadastro->descricao.sexualidade), stdin);
                        cadastro->descricao.sexualidade[strcspn(cadastro->descricao.sexualidade, "\n")] = '\0';
                        break;

                    case 4:
                        printf("\n NOVOS GOSTOS GERAIS: ");
                        printf("\n EX: futebol, jogos, esportes, livros, e etc...\n");
                        fgets(cadastro->descricao.gosto_gerais, sizeof(cadastro->descricao.gosto_gerais), stdin);
                        cadastro->descricao.gosto_gerais[strcspn(cadastro->descricao.gosto_gerais, "\n")] = '\0';
                        break;

                    case 5:
                        printf("\n NOVA DESCRICAO: ");
                        fgets(cadastro->descricao.descricao, sizeof(cadastro->descricao.descricao), stdin);
                        cadastro->descricao.descricao[strcspn(cadastro->descricao.descricao, "\n")] = '\0';
                        break;

                    default:
                        printf("\n NUMERO INVALIDO!\n");
                        return alterarCadastro(arquivo, cadastro);
                }
                break;
			
            case ESC:
                return;
        }

        printf("\n\n\n");
        printf("\n\t*************************************************************");
        printf("\n\t*                         CINDER                            *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*                 * CADASTRO ALTERADO! *                    *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*************************************************************");

        Sleep(2);
        system("cls");

        printf("\n\n\n");
        printf("\n\t*************************************************************");
        printf("\n\t*                          CINDER                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*                  *  DESEJA ALTERAR MAIS? *                *");
        printf("\n\t*                                                           *");
        printf("\n\t*                        1 - SIM                            *");
        printf("\n\t*                        2 - NAO                            *");
        printf("\n\t*                                                           *");
        printf("\n\t*************************************************************\n\n");
        printf("\n \n");
		scanf(" %d", &menu3);
        getchar();
        
        if (menu3 == 2) {
            return;
        } else {
            return alterarCadastro(arquivo,cadastro);
        }
    } else {
        printf("\n NUMERO INVALIDO!\n");
        return alterarCadastro(arquivo,cadastro);
    }
}

void matchCadastro(FILE *arquivo, const struct cadastro *usuarioAtual) {
    rewind(arquivo);
	 
	printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                         CINDER                            *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                   * MATCH DE PERFIS *                     *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");
	 
    struct cadastro perfilExistente;

    while (fread(&perfilExistente, sizeof(struct cadastro), 1, arquivo) == 1) {
        
        exibirPerfil(arquivo);

        int escolha;
        printf("\n\n Escolha uma opcao:\n");
        printf("1 - Match\n");
        printf("2 - Proximo perfil\n");
        scanf("%d", &escolha);

        if (escolha == 1) {
        	
        printf("\n\n\n");
	    printf("\n\t*************************************************************");
	    printf("\n\t*                         CINDER                            *");
	    printf("\n\t*                                                           *");
	    printf("\n\t*                                                           *");
	    printf("\n\t*                   * VOCÊ DEU MATCH! *                     *");
	    printf("\n\t*                                                           *");
	    printf("\n\t*                                                           *");
	    printf("\n\t*************************************************************");

	    Sleep(2);
	    system("cls");
	    
        } else if (escolha == 2) {
            printf("Proximo perfil.\n");
        } else {
            printf("Opcao invalida. Proximo perfil.\n");
        }

    
    }
}

void salvarCadastro(FILE *arquivo, struct cadastro novoCadastro) {
    fseek(arquivo, 0, SEEK_END); 
    fwrite(&novoCadastro, sizeof(struct cadastro), 1, arquivo); 
    fclose(arquivo);
}

int buscarPerfilPorCPF(const struct cadastro *usuarioAtual, struct cadastro *perfilEncontrado, FILE *arquivo) {
    rewind(arquivo);

    while (fread(perfilEncontrado, sizeof(struct cadastro), 1, arquivo) == 1) {
        if (perfilEncontrado->cpf == usuarioAtual->cpf) {
            return 1;  //se encontrar
        }
    }

    return 0;  //se não encontrar
}

void animar(){

	int i;
	
	for(i=0; i<1; i++){
	
	 	printf("\n \n \n \n");
		printf("\n                          ###*  ####               ####*  *###              ###*   *####        ");
		printf("\n                      @################@       @######@#######@#@@       @#@####@@@#######@      ");
		printf("\n                      @###############@@       @@###############@@       @################@      ");
		printf("\n                        @######@@####@           @############@@           @@#########@#@@       ");
		printf("\n                         @#########@              #@#########@              @@######@@@@         ");
		printf("\n                            @@###@                   @@##@@                    @@##@@            ");
		printf("\n                              @@                       @@                        @@            \n");
		
		Sleep(1000);
		system("cls");
		
		printf("\n \n \n \n");
		printf("\n                        ###   ####              ###*  ####                ###  *###         \n");
		printf("                     @################@       @################@       @@      @@       @@       \n");
		printf("                     @###############@@       @###############@@       @@               @@       \n");
		printf("                       @######@@####@           @######@@####@          @              @@        \n");
		printf("                        @#########@              @#########@             #@          @@          \n");
		printf("                            @@###@                   @@###@                 @@,     @        	 \n");
		printf("                             @@                       @@                       @@@               \n");
		 
		Sleep(1000);
		system("cls");
		
		printf("\n \n \n \n");
		printf("\n                       *###   *####               ###  *###                  ###  *###         \n");
		printf("                     @################@       @@      @@       @@       @@      @@       @@      \n");
		printf("                     @###############@@       @@               @@       @@               @@      \n");
		printf("                       @######@@####@          @              @@         @              @@       \n");
		printf("                         @#########@             #@          @@           #@          @@         \n");
		printf("                            @@###@                 @@,     @                @@,      @           \n");
		printf("                              @@                      @@@                       @@@              \n");
	
		Sleep(1000);
		system("cls");
		
		printf("\n \n \n \n");
		printf("\n                       ###  *###                  ###  *###                ###*  ####        \n");
		printf("                    @@      @@       @@       @@      @@       @@       @@      @@       @@      \n");
		printf("                    @@               @@       @@               @@       @@               @@      \n");
		printf("                     @              @@         @              @@         @              @@       \n");
		printf("                      #@          @@            #@          @@             #@          @@        \n");
		printf("                        @@,      @                @@,      @                 @@,     @           \n");
		printf("                            @@@                       @@@                       @@@              \n");
		
		Sleep(1000);
		system("cls");
		 
		printf("\n \n \n \n");
		printf("\n                      *###*  ####               ####  *###*                ####  *###*        \n");
		printf("                     @################@       @@      @@       @@       @@      @@       @@      \n");
		printf("                     @###############@@       @@               @@       @@               @@      \n");
		printf("                       @######@@####@          @              @@         @              @@       \n");
		printf("                         @#########@             #@          @@           #@          @@         \n");
		printf("                            @@###@                 @@,     @                @@,      @           \n");
		printf("                              @@                      @@@                       @@@              \n");
	
		Sleep(1000);
		system("cls");
		
		printf("\n \n \n \n");
		printf("\n                      *###*  ####               *###*  ####               ####  *###*        \n");
		printf("                     @################@       @################@       @@      @@       @@       \n");
		printf("                     @###############@@       @###############@@       @@               @@       \n");
		printf("                       @######@@####@           @######@@####@          @              @@        \n");
		printf("                        @#########@              @#########@             #@          @@          \n");
		printf("                           @@###@                   @@###@                 @@,      @        	 \n");
		printf("                              @@                       @@                      @@@               \n");
		
		Sleep(1000);
		system("cls");
	}
}
