#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. MODULO 1 - GERENCIAMENTO DE USUARIOS");
    printf("\n\n\t2. MODULO 2 - GERENCIAMENTO DE AMIZADES");
    printf("\n\n\t3. SAIR");
}

void MSG_SUBMENU(int numero_modulo)
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<<<<<<",
           numero_modulo);
    printf("\n\n\t1. CADASTRAR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR");
    printf("\n\t6. SAIR");
}

void subMenuModulo1(TRedeSocial *rede, TUsuarios user)
{
    int opcao=0, index;
    do
    {
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            // codigo para opcao do menu Cadastrar
            ler(&user);
            iniciar(rede);
            cadastrar(rede, user);
            break;

        case 2:
            // codigo para opcao do menu Pesquisar
            //index = pesquisar(rede, user);
            //printf("\Numero retornado: %d", index);
            break;

        case 3:
            // codigo para opcao do menu Alterar
            ler(&user);
            alterar(rede, user, index);
            break;

        case 4:
            // codigo para opcao do menu Excluir
            //index = pesquisar(rede, user);
            //excluir(rede, index);
            break;

        case 5:
            // codigo para opcao do menu Imprimir 2
            //imprimir2(rede);
            break;

        case 6:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Saindo do MODULO... <<<<<");
            fflush(stdin);
            //system("PAUSE");
            getchar();
            break;

        default:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Digite uma opcao valida! <<<<<");
            //system("PAUSE");
            fflush(stdin);
            getchar();
        }

    }while(opcao != 6);
}
