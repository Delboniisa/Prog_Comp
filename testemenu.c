#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ESC 27

struct endereco {
    char rua[50], estado[30], bairro[50], cidade[50];
    int numero, cep;
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

// Protótipo das funções
int diferencaAbsoluta(int a, int b);
void cadastrarNovoPerfil(struct cadastro *cadastro);
void exibirPerfil(const struct cadastro *cadastro);
void alterarCadastro(struct cadastro *cadastro);
void matchCadastro(FILE *arquivo, const struct cadastro *cadastro);
void aguardarEnterLimparTela();
void salvarCadastro(FILE *arquivo, struct cadastro novoCadastro);

int main() {
    struct cadastro minhaStruct;

    FILE *arquivo;
    arquivo = fopen("cadastros.txt", "a+"); // Modo "a+" para leitura e escrita, criando se não existir

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcaoMenuPrincipal = 1;

    while (opcaoMenuPrincipal != ESC) {
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
        printf("\n\t*                     4 - MATCH:                            *");
        printf("\n\t*          	       ESC - SAIR DO PROGRAMA                   *");
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
                exibirPerfil(&minhaStruct);
                break;
            case 3:
                alterarCadastro(&minhaStruct);
                break;
            case 4:
                matchCadastro(arquivo, &minhaStruct);
                break;
        }
    }

    fclose(arquivo); // Fechar o arquivo após a utilização

    return 0;
}
void cadastrarNovoPerfil(struct cadastro *cadastro) {
    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                  *  NOVO CADASTRO  *                      *");
    printf("\n\t*                                                           *");
    printf("\n\t*                       ESC-VOLTAR                          *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    printf("\n NOME COMPLETO: ");
    fgets(cadastro->nome, sizeof(cadastro->nome), stdin);
    cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';

    printf("\n EMAIL: ");
    fgets(cadastro->email, sizeof(cadastro->email), stdin);
    cadastro->email[strcspn(cadastro->email, "\n")] = '\0';

    printf("\n DATA DE NASCIMENTO: \n\n ");
    printf("\n DIA: ");
    scanf("%d", &cadastro->dia);
    printf("\n MES: ");
    scanf("%d", &cadastro->mes);
    printf("\n ANO: ");
    scanf("%d", &cadastro->ano);
    fflush(stdin);

    printf("\n TELEFONE: \n");
    printf("\n DDD: ");
    scanf("%d", &cadastro->numero.ddd);
    printf("\n NUMERO: ");
    scanf("%d", &cadastro->numero.numero);
    fflush(stdin);

    printf("\n CPF: ");
    scanf("%ld", &cadastro->cpf);

    system("cls");

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                    *  NOVO PERFIL  *                      *");
    printf("\n\t*                                                           *");
    printf("\n\t*                        ESC-VOLTAR                         *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    fflush(stdin);

    printf("\n APELIDO: ");
    fgets(cadastro->descricao.apelido, sizeof(cadastro->descricao.apelido), stdin);
    cadastro->descricao.apelido[strcspn(cadastro->descricao.apelido, "\n")] = '\0';

    printf("\n GENERO F/M: ");
    scanf(" %c", &cadastro->descricao.genero);
    fflush(stdin);

    printf("\n SEXUALIDADE: ");
    fgets(cadastro->descricao.sexualidade, sizeof(cadastro->descricao.sexualidade), stdin);
    cadastro->descricao.sexualidade[strcspn(cadastro->descricao.sexualidade, "\n")] = '\0';

    printf("\n GOSTOS GERAIS: ");
    printf("\n EX: futebol, jogos, esportes, livros, e etc...\n");
    fgets(cadastro->descricao.gosto_gerais, sizeof(cadastro->descricao.gosto_gerais), stdin);
    cadastro->descricao.gosto_gerais[strcspn(cadastro->descricao.gosto_gerais, "\n")] = '\0';

    printf("\n DESCRICAO: ");
    fgets(cadastro->descricao.descricao, sizeof(cadastro->descricao.descricao), stdin);
    cadastro->descricao.descricao[strcspn(cadastro->descricao.descricao, "\n")] = '\0';
}

// Função para exibir o perfil
void exibirPerfil(const struct cadastro *cadastro) {
    printf("\n NOME: %s", cadastro->nome);
    printf("\n EMAIL: %s", cadastro->email);
    printf("\n DATA DE NASCIMENTO: %d / %d / %d", cadastro->dia, cadastro->mes, cadastro->ano);
    printf("\n TELEFONE: %d  %d", cadastro->numero.ddd, cadastro->numero.numero);
    printf("\n CPF: %ld", cadastro->cpf);

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                       * PERFIL *                          *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    printf("\n APELIDO: %s", cadastro->descricao.apelido);
    printf("\n GENERO: %c", cadastro->descricao.genero);
    printf("\n SEXUALIDADE: %s", cadastro->descricao.sexualidade);
    printf("\n GOSTOS GERAIS: %s", cadastro->descricao.gosto_gerais);
    printf("\n DESCRICAO: %s", cadastro->descricao.descricao);
}

void alterarCadastro(struct cadastro *cadastro) {
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
                printf("\n 1 - NOME: %s", cadastro->nome);
                printf("\n 2 - EMAIL: %s", cadastro->email);
                printf("\n 3 - DATA DE NASCIMENTO: %d / %d / %d", cadastro->dia, cadastro->mes, cadastro->ano);
                printf("\n 4 - TELEFONE: %d  %d", cadastro->numero.ddd, cadastro->numero.numero);
                printf("\n 5 - CPF: %ld", cadastro->cpf);

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
                printf("\n 1 - APELIDO: %s ", cadastro->descricao.apelido);
                printf("\n 2 - GENERO F/M: %c ", cadastro->descricao.genero);
                printf("\n 3 - SEXUALIDADE: %s ", cadastro->descricao.sexualidade);
                printf("\n 4 - GOSTOS GERAIS: %s ", cadastro->descricao.gosto_gerais);
                printf("\n 5 - DESCRICAO: %s ", cadastro->descricao.descricao);

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
                        return alterarCadastro(cadastro);
                }
                break;

            case ESC:
                return;
        }

        printf("\n\n\n");
        printf("\n\t*************************************************************");
        printf("\n\t*                          NOME                             *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*                 * CADASTRO ALTERADO! *                    *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*************************************************************");

        sleep(2);
        system("cls");

        printf("\n\n\n");
        printf("\n\t*************************************************************");
        printf("\n\t*                          NOME                             *");
        printf("\n\t*                                                           *");
        printf("\n\t*                                                           *");
        printf("\n\t*                  *  DESEJA ALTERAR MAIS? *                *");
        printf("\n\t*                                                           *");
        printf("\n\t*                        1 - SIM                            *");
        printf("\n\t*                        2 - NAO                            *");
        printf("\n\t*                                                           *");
        printf("\n\t*************************************************************");
        scanf("%d", &menu3);
        if (menu3 == 2) {
            return;
        } else {
            return alterarCadastro(cadastro);
        }
    } else {
        printf("\n NUMERO INVALIDO!\n");
        return alterarCadastro(cadastro);
    }
}

// Função para verificar se dois perfis são compatíveis
int verificarCompatibilidade(const struct cadastro *perfil1, const struct cadastro *perfil2) {
    // Critério 1: Interesses Gerais (comparando gosto_gerais)
    int interessesCompativeis = strcmp(perfil1->descricao.gosto_gerais, perfil2->descricao.gosto_gerais) == 0;

    // Critério 2: Idade (comparando a diferença de idade)
    int diferencaIdade = diferencaAbsoluta(perfil1->ano, perfil2->ano);
    int idadeCompativel = diferencaIdade <= 5;  // Exemplo: considerando compatível se a diferença for menor ou igual a 5 anos

    // Critério 3: Localização (comparando estado e cidade)
    int localizacaoCompativel = strcmp(perfil1->endereco.estado, perfil2->endereco.estado) == 0 &&
                                strcmp(perfil1->endereco.cidade, perfil2->endereco.cidade) == 0;

    // Avaliação geral de compatibilidade
    return interessesCompativeis && idadeCompativel && localizacaoCompativel;
}

// Função para realizar o match de perfis
void matchCadastro(FILE *arquivo, const struct cadastro *cadastro) {
    struct cadastro perfilAtual;

    rewind(arquivo);

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*                   * MATCH DE PERFIS *                     *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    int perfilCompativelEncontrado = 0;

    while (fread(&perfilAtual, sizeof(struct cadastro), 1, arquivo) == 1) {
        if (perfilAtual.cpf != cadastro->cpf) {
            if (verificarCompatibilidade(cadastro, &perfilAtual)) {
                perfilCompativelEncontrado = 1;
                printf("\n\n PERFIL COMPATÍVEL ENCONTRADO!");
                exibirPerfil(perfilAtual);
            }
        }
    }

    if (!perfilCompativelEncontrado) {
        printf("\n\n Nenhum perfil compatível encontrado.");
    }

    fclose(arquivo);

    printf("\n\n\n");
    printf("\n\t*************************************************************");
    printf("\n\t*                          NOME                             *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*              * MATCH DE PERFIS CONCLUÍDO! *               *");
    printf("\n\t*                                                           *");
    printf("\n\t*                                                           *");
    printf("\n\t*************************************************************");

    sleep(2);
    system("cls");
}

void salvarCadastro(FILE *arquivo, const struct cadastro cadastro) {
    // Implemente a lógica para salvar o cadastro no arquivo aqui
}
