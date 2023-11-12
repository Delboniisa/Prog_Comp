#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Estrutura para armazenar informações do cadastro
struct Cadastro {
    char cpf[15];
    char primeiroNome[50];
    char restoNome[50];
    char apelido[50];
    char genero[20];
    char sexualidade[20];
    char email[50];
    char telefone[15];
    char sobre[200];
    char personalidade[50]; // Novo campo "Personalidade"
    // Adicione outros campos conforme necessário
};

// Função para verificar se um CPF já existe no arquivo
int cpfExistente(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;

    rewind(arquivo); // Voltar ao início do arquivo

    // Percorrer o arquivo e verificar se o CPF já existe
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
               cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
               cadastro.apelido, cadastro.genero, cadastro.sexualidade,
               cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            return 1; // CPF encontrado, retorna verdadeiro
        }
    }

    return 0; // CPF não encontrado, retorna falso
}

// Função para adicionar um novo cadastro ao arquivo
void adicionarCadastro(FILE *arquivo, struct Cadastro novoCadastro) {
    fseek(arquivo, 0, SEEK_END); // Posicionar o ponteiro no final do arquivo

    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
            novoCadastro.cpf, novoCadastro.primeiroNome, novoCadastro.restoNome,
            novoCadastro.apelido, novoCadastro.genero, novoCadastro.sexualidade,
            novoCadastro.email, novoCadastro.telefone, novoCadastro.sobre,
            novoCadastro.personalidade); // Adicionado campo "Personalidade"

    printf("Cadastro adicionado com sucesso!\n");

    // Adicionar delay de 1 segundo
    #ifdef _WIN32
    Sleep(1000);  // Em milissegundos
    #else
    sleep(1);  // Em segundos
    #endif
}

// Função para buscar e exibir todos os cadastros com um determinado CPF
void buscarCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;
    int encontrados = 0;

    // Limpar a tela antes de exibir o resultado da busca
    system("cls || clear");

    rewind(arquivo); // Voltar ao início do arquivo

    // Percorrer o arquivo e procurar pelo CPF
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
               cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
               cadastro.apelido, cadastro.genero, cadastro.sexualidade,
               cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            // Cadastro encontrado, exibir informações
            printf("CPF: %s\n", cadastro.cpf);
            printf("Primeiro Nome: %s\n", cadastro.primeiroNome);
            printf("Resto do Nome: %s\n", cadastro.restoNome);
            printf("Apelido: %s\n", cadastro.apelido);
            printf("Gênero: %s\n", cadastro.genero);
            printf("Sexualidade: %s\n", cadastro.sexualidade);
            printf("E-mail: %s\n", cadastro.email);
            printf("Telefone: %s\n", cadastro.telefone);
            printf("Sobre: %s\n", cadastro.sobre);
            printf("Personalidade: %s\n", cadastro.personalidade); // Novo campo "Personalidade"
            encontrados++;
        }
    }

    // Se o CPF não for encontrado
    if (encontrados == 0) {
        printf("Cadastro com CPF %s não encontrado.\n", cpf);
    }
}

// Função para editar os dados de um cadastro
void editarCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;

    // Abrir um arquivo temporário
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        exit(1);
    }

    rewind(arquivo); // Voltar ao início do arquivo

    // Percorrer o arquivo e copiar os dados para o arquivo temporário
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
               cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
               cadastro.apelido, cadastro.genero, cadastro.sexualidade,
               cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade) != EOF) {
        if (strcmp(cadastro.cpf, cpf) == 0) {
            // Limpar a tela antes de exibir o resultado da busca
            system("cls || clear");
            // Cadastro encontrado, permitir edição
            printf("Editando dados do cadastro com CPF %s\n", cpf);
            printf("Novo Primeiro Nome: ");
            scanf(" %49[^\n]s", cadastro.primeiroNome);
            printf("Novo Resto do Nome: ");
            scanf(" %49[^\n]s", cadastro.restoNome);
            printf("Novo Apelido: ");
            scanf(" %49[^\n]s", cadastro.apelido);
            printf("Novo Gênero: ");
            scanf(" %19[^\n]s", cadastro.genero);
            printf("Nova Sexualidade: ");
            scanf(" %19[^\n]s", cadastro.sexualidade);
            printf("Novo E-mail: ");
            scanf(" %49[^\n]s", cadastro.email);
            printf("Novo Telefone: ");
            scanf(" %14[^\n]s", cadastro.telefone);
            printf("Novo Sobre: ");
            scanf(" %199[^\n]s", cadastro.sobre);
            printf("Nova Personalidade: ");
            scanf(" %49[^\n]s", cadastro.personalidade); // Novo campo "Personalidade"
        }

        // Escrever no arquivo temporário
        fprintf(tempFile, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade); // Novo campo "Personalidade"
    }

    fclose(arquivo);  // Fechar o arquivo original
    fclose(tempFile);  // Fechar o arquivo temporário

    // Remover o arquivo original
    remove("cadastros.txt");

    // Renomear o arquivo temporário para o nome original
    rename("temp.txt", "cadastros.txt");

    printf("Cadastro editado com sucesso!\n");

    // Adicionar delay de 1 segundo
    #ifdef _WIN32
    Sleep(1000);  // Em milissegundos
    #else
    sleep(1);  // Em segundos
    #endif
}

// Função para excluir um cadastro com base no CPF
void excluirCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;

    // Abrir um arquivo temporário
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        exit(1);
    }

    rewind(arquivo); // Voltar ao início do arquivo

    // Percorrer o arquivo e copiar os dados para o arquivo temporário, exceto o cadastro a ser excluído
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
               cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
               cadastro.apelido, cadastro.genero, cadastro.sexualidade,
               cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade) != EOF) {
        if (strcmp(cadastro.cpf, cpf) != 0) {
            // Escrever no arquivo temporário
            fprintf(tempFile, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                    cadastro.cpf, cadastro.primeiroNome, cadastro.restoNome,
                    cadastro.apelido, cadastro.genero, cadastro.sexualidade,
                    cadastro.email, cadastro.telefone, cadastro.sobre, cadastro.personalidade); // Novo campo "Personalidade"
        }
    }

    fclose(arquivo);  // Fechar o arquivo original
    fclose(tempFile);  // Fechar o arquivo temporário

    // Remover o arquivo original
    remove("cadastros.txt");

    // Renomear o arquivo temporário para o nome original
    rename("temp.txt", "cadastros.txt");

    printf("Cadastro excluído com sucesso!\n");

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

    // Abrir o arquivo no modo de leitura e gravação
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
        printf("1. Criação de Cadastro\n");
        printf("2. Match\n");
        printf("3. Busca\n");
        printf("Escolha a opção (ou qualquer outra tecla para sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Criação de Cadastro
                do {
                    // Limpar a tela antes de exibir o submenu
                    system("cls || clear");

                    printf("Adicionar novo cadastro (Digite '0' para cancelar):\n");
                    printf("CPF: ");
                    scanf(" %14[^\n]s", novoCadastro.cpf);

                    // Verificar se o usuário digitou '0' para cancelar
                    if (strcmp(novoCadastro.cpf, "0") == 0) {
                        printf("Cadastro cancelado.\n");
                        break;
                    }

                    // Verificar se o CPF já existe
                    if (cpfExistente(arquivo, novoCadastro.cpf)) {
                        printf("CPF já existe. Por favor, escolha outro CPF.\n");
                        // Adicionar delay de 1 segundo
                        #ifdef _WIN32
                        Sleep(2000);  // Em milissegundos
                        #else
                        sleep(2);  // Em segundos
                        #endif
                    } else {
                        printf("Primeiro Nome: ");
                        scanf(" %49[^\n]s", novoCadastro.primeiroNome);
                        printf("Resto do Nome: ");
                        scanf(" %49[^\n]s", novoCadastro.restoNome);
                        printf("Apelido: ");
                        scanf(" %49[^\n]s", novoCadastro.apelido);
                        printf("Gênero: ");
                        scanf(" %19[^\n]s", novoCadastro.genero);
                        printf("Sexualidade: ");
                        scanf(" %19[^\n]s", novoCadastro.sexualidade);
                        printf("E-mail: ");
                        scanf(" %49[^\n]s", novoCadastro.email);
                        printf("Telefone: ");
                        scanf(" %14[^\n]s", novoCadastro.telefone);
                        printf("Sobre: ");
                        scanf(" %199[^\n]s", novoCadastro.sobre);
                        printf("Personalidade: ");
                        scanf(" %49[^\n]s", novoCadastro.personalidade); // Novo campo "Personalidade"

                        adicionarCadastro(arquivo, novoCadastro);
                        break;
                    }
                } while (1); // Loop até que um CPF único seja fornecido ou o usuário cancele

                break;

            case 2:
                // Match (pode ser implementado conforme necessário)
                printf("Opção 'Match' selecionada.\n");
                break;

            case 3:
                // Busca por CPF e exibe todos os cadastros encontrados
                do {
                    printf("\nBuscar cadastro por CPF (Digite '0' para cancelar):\n");
                    printf("CPF: ");
                    scanf(" %14[^\n]s", novoCadastro.cpf);

                    // Verificar se o usuário digitou '0' para cancelar
                    if (strcmp(novoCadastro.cpf, "0") == 0) {
                        printf("Busca cancelada.\n");
                        break;
                    }

                    buscarCadastro(arquivo, novoCadastro.cpf);

                    // Menu após a busca
                    int opcaoBusca;
                    printf("\nMenu após Busca:\n");
                    printf("1. Realizar outra busca\n");
                    printf("2. Editar cadastro\n");
                    printf("3. Excluir cadastro\n");
                    printf("4. Voltar\n");
                    printf("Escolha a opção: ");
                    scanf("%d", &opcaoBusca);

                    switch (opcaoBusca) {
                        case 1:
                            // Realizar outra busca (continua o loop)
                            break;

                        case 2:
                            // Editar cadastro
                            editarCadastro(arquivo, novoCadastro.cpf);
                            break;

                        case 3:
                            // Excluir cadastro
                            printf("\nExcluir cadastro por CPF (Digite '0' para cancelar):\n");
                            printf("CPF: ");
                            scanf(" %14[^\n]s", novoCadastro.cpf);

                            // Verificar se o usuário digitou '0' para cancelar
                            if (strcmp(novoCadastro.cpf, "0") == 0) {
                                printf("Exclusão cancelada.\n");
                                break;
                            }

                            // Verificar se o CPF existe antes de tentar excluir
                            if (cpfExistente(arquivo, novoCadastro.cpf)) {
                                excluirCadastro(arquivo, novoCadastro.cpf);
                            } else {
                                printf("Cadastro com CPF %s não encontrado.\n", novoCadastro.cpf);
                            }

                            break;

                        case 4:
                            // Voltar para o menu principal (sai do loop)
                            break;

                        default:
                            printf("Saindo do programa.\n");
                            break;
                    }
                } while (1);

                break;

            default:
                printf("Saindo do programa.\n");
        }

    } while (opcao >= 1 && opcao <= 3);

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}

