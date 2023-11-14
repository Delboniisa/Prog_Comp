#include <stdio.h>
#include <string.h>


struct Usuario {
    char nome[50];
    char email[100];
    char dataNascimento[12];
    char telefone[20];
    char cpf[15];
    char apelido[30];
    char genero[20];
    char sexualidade[20];
    char gostosGerais[100];
    char descricao[200];
    char vazio[10];
};

// Função para adicionar um novo usuário ao arquivo
void cadastrarUsuario(FILE *arquivo) {
  arquivo = fopen("usuarios.txt", "a+");
  struct Usuario novoUsuario;

    printf("\n\n");
    fgets(novoUsuario.vazio, 10, stdin);
    printf("Nome: ");
    fgets(novoUsuario.nome, 50, stdin);
    fflush(stdin);
    printf("Email: ");
    fgets( novoUsuario.email, 100, stdin);
    fflush(stdin);
    printf("Data de Nascimento (DD/MM/YYYY): ");
    fgets(novoUsuario.dataNascimento, 12, stdin);
    fflush(stdin);
    printf("Telefone: ");
    fgets(novoUsuario.telefone, 20, stdin);
    fflush(stdin);
    printf("CPF: ");
    fgets(novoUsuario.cpf, 15, stdin);
    fflush(stdin);
    printf("Apelido: ");
    fgets(novoUsuario.apelido, 30, stdin);
    fflush(stdin);
    printf("Genero: ");
    fgets(novoUsuario.genero, 20, stdin);
    fflush(stdin);
    printf("Sexualidade: ");
    fgets(novoUsuario.sexualidade, 20, stdin);
    fflush(stdin);
    printf("Gostos gerais: ");
    fgets(novoUsuario.gostosGerais, 100, stdin);
    fflush(stdin);
    printf("Descrição: ");
    fgets(novoUsuario.descricao, 200, stdin);
    fflush(stdin);

    fprintf(arquivo, "Nome: %s\n", novoUsuario.nome);
    fprintf(arquivo, "Email: %s\n", novoUsuario.email);
    fprintf(arquivo, "Data de Nascimento: %s\n", novoUsuario.dataNascimento);
    fprintf(arquivo, "Telefone: %s\n", novoUsuario.telefone);
    fprintf(arquivo, "CPF: %s\n", novoUsuario.cpf);
    fprintf(arquivo, "Apelido: %s\n", novoUsuario.apelido);
    fprintf(arquivo, "Genero: %s\n", novoUsuario.genero);
    fprintf(arquivo, "Sexualidade: %s\n", novoUsuario.sexualidade);
    fprintf(arquivo, "Gostos gerais: %s\n", novoUsuario.gostosGerais);
    fprintf(arquivo, "Descrição: %s\n", novoUsuario.descricao);

    fprintf(arquivo, "\n"); 
    printf("Usuário cadastrado com sucesso!\n");

  fclose(arquivo);
   
}

// Função para listar todos os usuários do arquivo
void listarUsuarios(const char *usuarios) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Nome: ") != NULL) {
          printf("%s", linha + 6);
            }
    
    }

    fclose(arquivo);
}

void match(const char *usuarios) {


}

int main() {
    FILE *arquivo = fopen("usuarios.txt", "a+");
    int escolha;
    char nome[50];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        printf("\n1. Cadastrar usuário\n2. Listar usuários\n3. Remover usuário\n4. Sair\nEscolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarUsuario(arquivo);
                break;
            case 2:
                printf("Usuários cadastrados:\n");
                listarUsuarios(arquivo);
                break;
            case 3:
                printf("Nome do usuário a ser removido: ");
                scanf("%s", nome);
                printf("Usuário removido com sucesso!\n");
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    fclose(arquivo);

    return 0;
}
