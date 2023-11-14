#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <curses.h>
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
}

// Função para buscar e exibir todos os cadastros com um determinado CPF
void buscarCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastro;
    int encontrados = 0;

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
}

// Função para realizar o match e exibir cadastros com mesmo "sobre" e/ou "personalidade"
void matchCadastro(FILE *arquivo, const char *cpf) {
    struct Cadastro cadastroAtual;
    struct Cadastro cadastroComparar;
    int encontrados = 0;

    rewind(arquivo); // Voltar ao início do arquivo

    // Obter os dados "sobre" e "personalidade" do cadastro atual
    char sobreAtual[200];
    char personalidadeAtual[50];

    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]\n",
               cadastroAtual.cpf, cadastroAtual.primeiroNome, cadastroAtual.restoNome,
               cadastroAtual.apelido, cadastroAtual.genero, cadastroAtual.sexualidade,
               cadastroAtual.email, cadastroAtual.telefone, cadastroAtual.sobre, cadastroAtual.personalidade) != EOF) {
        if (strcmp(cadastroAtual.cpf, cpf) == 0) {
            // CPF encontrado, obter os dados "sobre" e "personalidade"
            strcpy(sobreAtual, cadastroAtual.sobre);
            strcpy(personalidadeAtual, cadastroAtual.personalidade);
            break;
        }
    }

    rewind(arquivo);
    // Percorrer o arquivo e comparar os dados "sobre" e "personalidade" com outros cadastros
    while (fscanf(arquivo, "%14[^;];%49[^;];%49[^;];%49[^;];%19[^;];%19[^;];%49[^;];%14[^;];%199[^;];%49[^\n]s",
               cadastroComparar.cpf, cadastroComparar.primeiroNome, cadastroComparar.restoNome,
               cadastroComparar.apelido, cadastroComparar.genero, cadastroComparar.sexualidade,
               cadastroComparar.email, cadastroComparar.telefone, cadastroComparar.sobre, cadastroComparar.personalidade) != EOF) {
        // Verificar se "sobre" ou "personalidade" coincidem
        if ((strcmp(sobreAtual, cadastroComparar.sobre) == 0 || strcmp(personalidadeAtual, cadastroComparar.personalidade) == 0) &&
            strcmp(cadastroAtual.cpf, cadastroComparar.cpf) != 0) {
            // Verificar se o CPF do cadastro atual é diferente do CPF fornecido pelo usuário
            if (strcmp(cpf, cadastroComparar.cpf) != 0) {
                // Cadastro com match encontrado, exibir informações
                printf("Primeiro Nome: %s\n", cadastroComparar.primeiroNome);
                printf("Apelido: %s\n", cadastroComparar.apelido);
                printf("Gênero: %s\n", cadastroComparar.genero);
                printf("Sexualidade: %s\n", cadastroComparar.sexualidade);
                printf("Telefone: %s\n", cadastroComparar.telefone);
                printf("Sobre: %s\n", cadastroComparar.sobre);
                printf("Personalidade: %s\n", cadastroComparar.personalidade);
                encontrados++;
            }
        }
    }

    // Se nenhum match for encontrado
    if (encontrados == 0) {
        printf("Nenhum match encontrado para o cadastro com CPF %s.\n", cpf);
    }

    // Aguardar a entrada do usuário antes de continuar
    aguardarEnterLimparTela();
}

// Função para aguardar a tecla Enter e limpar a tela
void aguardarEnterLimparTela() {
    printf("Pressione Enter para continuar...");
    fflush(stdout); // Limpar o buffer de saída
#ifdef _WIN32
    _getch(); // Aguardar a tecla Enter no Windows
    system("cls"); // Limpar a tela no Windows
#else
    getchar(); // Aguardar a tecla Enter no Linux/macOS
    system("clear"); // Limpar a tela no Linux/macOS
#endif
}

int main() {
    FILE *arquivo;

    // Abrir o arquivo de cadastros
    arquivo = fopen("cadastros.txt", "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de cadastros.\n");
        return 1;
    }

    int opcao;
    char cpf[15];

    do {
        // Exibir o menu
        printf("\n1 - Adicionar Cadastro\n");
        printf("2 - Buscar Cadastro\n");
        printf("3 - Editar Cadastro\n");
        printf("4 - Excluir Cadastro\n");
        printf("5 - Realizar Match\n");
        printf("0 - Sair\n");

        // Ler a opção do usuário
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executar a opção escolhida
        switch (opcao) {
            case 1:
                // Adicionar cadastro
                struct Cadastro novoCadastro;
                printf("CPF (apenas números): ");
                scanf(" %14[^\n]s", novoCadastro.cpf);
                // Verificar se o CPF já existe
                if (cpfExistente(arquivo, novoCadastro.cpf)) {
                    printf("Erro: CPF já cadastrado.\n");
                    break;
                }
                // Preencher os demais campos
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
                // Adicionar cadastro ao arquivo
                adicionarCadastro(arquivo, novoCadastro);
                break;
            case 2:
                // Buscar cadastro
                printf("Digite o CPF a ser buscado: ");
                scanf(" %14[^\n]s", cpf);
                buscarCadastro(arquivo, cpf);
                break;
            case 3:
                // Editar cadastro
                printf("Digite o CPF do cadastro a ser editado: ");
                scanf(" %14[^\n]s", cpf);
                editarCadastro(arquivo, cpf);
                break;
            case 4:
                // Excluir cadastro
                printf("Digite o CPF do cadastro a ser excluido: ");
                scanf(" %14[^\n]s", cpf);
                excluirCadastro(arquivo, cpf);
                break;
            case 5:
                // Realizar match
                printf("Digite o CPF do cadastro para realizar o match: ");
                scanf(" %14[^\n]s", cpf);
                matchCadastro(arquivo, cpf);
                break;
            case 0:
                // Sair do programa
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}

   
