#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Estrutura para armazenar informa��es do cadastro
struct Cadastro {
    char cpf[15];
    char primeiroNome[50];
    char restoNome[50];
    char apelido[50];
    char genero[20];
    char sexualidade[20];
    char email[50];
    char redesSociais[50];
    char telefone[15];
    char sobre[200];
    char identidadeGenero[50];
    // Adicione outros campos conforme necess�rio
};

// Fun��o para verificar se um CPF j� existe no arquivo
int cpfExistente(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;

    rewind(arquivo); // Voltar ao in�cio do arquivo

    // Percorrer o arquivo e verificar se o CPF j� existe
    while (fscanf(arquivo, "%14[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%49[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
                   cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                   cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                   cadastro.email, cadastro.redesSociais,
                   cadastro.telefone, cadastro.sobre, cadastro.identidadeGenero) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            // CPF encontrado, retorna verdadeiro
            return 1;
        }
    }

    // CPF n�o encontrado, retorna falso
    return 0;
}

// Fun��o para adicionar um novo cadastro ao arquivo
void adicionarCadastro(FILE *arquivo, struct Cadastro novoCadastro) {
    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
            novoCadastro.cpf, novoCadastro.primeiroNome, novoCadastro.restoNome,
            novoCadastro.apelido, novoCadastro.genero, novoCadastro.sexualidade,
            novoCadastro.email, novoCadastro.redesSociais,
            novoCadastro.telefone, novoCadastro.sobre, novoCadastro.identidadeGenero);

    printf("Cadastro adicionado com sucesso!\n");

    // Adicionar delay de 1 segundo
    #ifdef _WIN32
    Sleep(1000);  // Em milissegundos
    #else
    sleep(1);  // Em segundos
    #endif
}

// Fun��o para buscar e exibir todos os cadastros com um determinado CPF
void buscarCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;
    int encontrados = 0;

    // Limpar a tela antes de exibir o resultado da busca
    system("cls || clear");

    rewind(arquivo); // Voltar ao in�cio do arquivo

    // Percorrer o arquivo e procurar pelo CPF
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
                   cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                   cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                   cadastro.email, cadastro.redesSociais,
                   cadastro.telefone, cadastro.sobre, cadastro.identidadeGenero) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            // Cadastro encontrado, exibir informa��es
            printf("CPF: %s\n", cadastro.cpf);
            printf("Primeiro Nome: %s\n", cadastro.primeiroNome);
            printf("Resto do Nome: %s\n", cadastro.restoNome);
            printf("Apelido: %s\n", cadastro.apelido);
            printf("G�nero: %s\n", cadastro.genero);
            printf("Sexualidade: %s\n", cadastro.sexualidade);
            printf("E-mail: %s\n", cadastro.email);
            printf("Redes Sociais: %s\n", cadastro.redesSociais);
            printf("Telefone: %s\n", cadastro.telefone);
            printf("Sobre: %s\n", cadastro.sobre);
            printf("Identidade de G�nero: %s\n", cadastro.identidadeGenero);
            printf("\n");
            encontrados++;
        }
    }

    // Se o CPF n�o for encontrado
    if (encontrados == 0) {
        printf("Cadastro com CPF %s n�o encontrado.\n", cpf);
    }
}

// Fun��o para editar os dados de um cadastro
void editarCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;

    // Abrir um arquivo tempor�rio
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo tempor�rio.\n");
        exit(1);
    }

    rewind(arquivo); // Voltar ao in�cio do arquivo

    // Percorrer o arquivo e copiar os dados para o arquivo tempor�rio
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
                   cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                   cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                   cadastro.email, cadastro.redesSociais,
                   cadastro.telefone, cadastro.sobre, cadastro.identidadeGenero) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            // Cadastro encontrado, permitir edi��o
            printf("Editando dados do cadastro com CPF %s\n", cpf);
            printf("Novo Primeiro Nome: ");
            scanf(" %49[^\n]s", cadastro.primeiroNome);
            printf("Novo Resto do Nome: ");
            scanf(" %49[^\n]s", cadastro.restoNome);
            printf("Novo Apelido: ");
            scanf(" %49[^\n]s", cadastro.apelido);
            printf("Novo G�nero: ");
            scanf(" %19[^\n]s", cadastro.genero);
            printf("Nova Sexualidade: ");
            scanf(" %19[^\n]s", cadastro.sexualidade);
            printf("Novo E-mail: ");
            scanf(" %49[^\n]s", cadastro.email);
            printf("Novas Redes Sociais: ");
            scanf(" %49[^\n]s", cadastro.redesSociais);
            printf("Novo Telefone: ");
            scanf(" %14[^\n]s", cadastro.telefone);
            printf("Novo Sobre: ");
            scanf(" %199[^\n]s", cadastro.sobre);
            printf("Nova Identidade de G�nero: ");
            scanf(" %49[^\n]s", cadastro.identidadeGenero);
        }

        // Escrever no arquivo tempor�rio
        fprintf(tempFile, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                cadastro.email, cadastro.redesSociais,
                cadastro.telefone, cadastro.sobre, cadastro.identidadeGenero);
    }

    fclose(arquivo);  // Fechar o arquivo original
    fclose(tempFile);  // Fechar o arquivo tempor�rio

    // Remover o arquivo original
    remove("cadastros.txt");

    // Renomear o arquivo tempor�rio para o nome original
    rename("temp.txt", "cadastros.txt");

    printf("Cadastro editado com sucesso!\n");

    // Adicionar delay de 1 segundo
    #ifdef _WIN32
    Sleep(1000);  // Em milissegundos
    #else
    sleep(1);  // Em segundos
    #endif
}

int main() {
    FILE *arquivo;
    struct Cadastro novoCadastro;

    // Abrir o arquivo no modo de leitura e grava��o
    arquivo = fopen("cadastros.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcao;
    do {
        // Limpar a tela antes de exibir o menu principal
        system("cls || clear");

        // Exibir menu principal
        printf("Menu:\n");
        printf("1. Cria��o de Cadastro\n");
        printf("2. Match\n");
        printf("3. Busca\n");
        printf("Escolha a op��o (ou qualquer outra tecla para sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cria��o de Cadastro
                do {
                    // Limpar a tela antes de exibir o submenu
                    system("cls || clear");

                    printf("Adicionar novo cadastro (Digite '0' para cancelar):\n");
                    printf("CPF: ");
                    scanf(" %14[^\n]s", novoCadastro.cpf);

                    // Verificar se o usu�rio digitou '0' para cancelar
                    if (strcmp(novoCadastro.cpf, "0") == 0) {
                        printf("Cadastro cancelado.\n");
                        break;
                    }

                    // Verificar se o CPF j� existe
                    if (cpfExistente(arquivo, novoCadastro.cpf)) {
                        printf("CPF j� existe. Por favor, escolha outro CPF.\n");
                    } else {
                        printf("Primeiro Nome: ");
                        scanf(" %49[^\n]s", novoCadastro.primeiroNome);
                        printf("Resto do Nome: ");
                        scanf(" %49[^\n]s", novoCadastro.restoNome);
                        printf("Apelido: ");
                        scanf(" %49[^\n]s", novoCadastro.apelido);
                        printf("G�nero: ");
                        scanf(" %19[^\n]s", novoCadastro.genero);
                        printf("Sexualidade: ");
                        scanf(" %19[^\n]s", novoCadastro.sexualidade);
                        printf("E-mail: ");
                        scanf(" %49[^\n]s", novoCadastro.email);
                        printf("Redes Sociais: ");
                        scanf(" %49[^\n]s", novoCadastro.redesSociais);
                        printf("Telefone: ");
                        scanf(" %14[^\n]s", novoCadastro.telefone);
                        printf("Sobre: ");
                        scanf(" %199[^\n]s", novoCadastro.sobre);
                        printf("Identidade de G�nero: ");
                        scanf(" %49[^\n]s", novoCadastro.identidadeGenero);

                        adicionarCadastro(arquivo, novoCadastro);
                        break;
                    }
                } while (1); // Loop at� que um CPF �nico seja fornecido ou o usu�rio cancele

                break;

            case 2:
                // Match (pode ser implementado conforme necess�rio)
                printf("Op��o 'Match' selecionada.\n");
                break;

            case 3:
                // Busca por CPF e exibe todos os cadastros encontrados
                printf("Buscar cadastro por CPF (Digite '0' para cancelar):\n");
                printf("CPF: ");
                scanf(" %14[^\n]s", novoCadastro.cpf);

                // Verificar se o usu�rio digitou '0' para cancelar
                if (strcmp(novoCadastro.cpf, "0") == 0) {
                    printf("Busca cancelada.\n");
                    break;
                }

                buscarCadastro(arquivo, novoCadastro.cpf);

                // Menu ap�s a busca
                int opcaoBusca;
                do {
                    printf("Menu ap�s Busca:\n");
                    printf("1. Realizar outra busca\n");
                    printf("2. Editar cadastro\n");
                    printf("3. Voltar\n");
                    printf("Escolha a op��o: ");
                    scanf("%d", &opcaoBusca);

                    switch (opcaoBusca) {
                        case 1:
                            // Realizar outra busca
                            printf("Buscar cadastro por CPF (Digite '0' para cancelar):\n");
                            printf("CPF: ");
                            scanf(" %14[^\n]s", novoCadastro.cpf);

                            // Verificar se o usu�rio digitou '0' para cancelar
                            if (strcmp(novoCadastro.cpf, "0") == 0) {
                                printf("Busca cancelada.\n");
                                break;
                            }

                            buscarCadastro(arquivo, novoCadastro.cpf);
                            break;

                        case 2:
                            // Editar cadastro
                            editarCadastro(arquivo, novoCadastro.cpf);
                            break;

                        case 3:
                            // Voltar para o menu principal
                            break;

                        default:
                            printf("Op��o inv�lida. Tente novamente.\n");
                    }
                } while (opcaoBusca != 3);

                break;

            default:
                printf("Saindo do programa.\n");
        }

    } while (opcao >= 1 && opcao <= 3);

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}
