#include <stdlib.h>
#include <stdio.h>

//vou salvar como biblioteca, para passar as informações como ponteiro ao menu principal

struct cadastro{
	int dia, mes, ano, idade;
	long int cpf; 
	char nome[75], email[75];
	struct endereco endereco;
	struct descricao descricao;
	struct numero numero;
};

struct telefone{
	int ddd, numero;	
};

struct endereco{
	char rua[50], estado[30], bairro[50], cidade[50];
	int numero, cep;
};

struct descricao{
	char genero[2], sexualidade[15], apelido[10], gosto_gerais[150], descricao[1000];
};