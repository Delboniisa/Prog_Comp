#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "animacao.h"

int salvarCliente(struct cliente* cliente);


	intmain(){
		
		setlocale(LC_ALL, "Portuguese");
			
			
		int i,menu1=1,menu2,menu3;
			
			
		animar();
			
		while(menu1!=ESC){
			printf("\n\n\n");
			printf("\n\t*************************************************************");
			printf("\n\t*                         NOME                              *");				
			printf("\n\t*                                                           *");
			printf("\n\t*                   #  MENU PRINCIPAL  #                    *");
			printf("\n\t*                                                           *");
			printf("\n\t*                                                           *");				
			printf("\n\t*            # DIGITE O NÚMERO DA OPÇÃO DESEJADA            *");
			printf("\n\t*                                                           *");
			printf("\n\t*            1 - CADASTRO:                                  *");
			printf("\n\t*            2 - MATCH:                                     *");				
			printf("\n\t*            3 - BUSCA:                                     *");
			printf("\n\t*          	ESC - SAIR DO PROGRAMA.                         *");
			printf("\n\t*                                                           *");                                                       
			printf("\n\t*                                                           *");				
			printf("\n\t*************************************************************");
			printf("\n\n");
			
			menu1 = getch();
			fflush(stdin);
			printf("\n");
			system("cls");
				
			}
	}
