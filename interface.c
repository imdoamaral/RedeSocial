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
            system("cls");
            printf("\n\n >>>>> MSG: Cadastre um usuario: <<<<< \n\n");
            ler(&user);
            cadastrar(rede, user); // *rede aqui já é o proprio endereço '&'
            /* fflush(stdin);
            getchar(); // lê somente um caractere da tela */
            system("PAUSE"); // faz todos os procedimetnos acima
            break;

        case 2:
            // codigo para opcao do menu Pesquisar
            system("cls");
            printf("\n MSG: Digite o nome do usuario que deseja PESQUISAR: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);

            index = pesquisar(*rede, user); // o * aqui significa = "conteudo de"

            if  (index >= 0)
            {
                printf("\n\n >>>>> MSG: Usuario pesquisado encontrado: <<<<<");
                imprimir(rede->vetor[index]);
            }
            else
                printf("\n\n >>>>> MSG: Usuario pesquisado NAO esta cadastrado! <<<<<");

            printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar... <<<<<");
            fflush(stdin);
            getchar();
            //system("PAUSE");
            break;

        case 3:
            // codigo para opcao do menu Alterar
            system("cls");
            printf("\n\n MSG: Digite o nome do usuario que deseja ALTERAR: \n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);

            index  = pesquisar(*rede, user);
            printf("\n\n >>>>> MSG: Usuario pesquisado encontrado: <<<<<\n");

            if (index >= 0)
            {
                printf("\n\n >>>>> MSG: Digite os dados para alterar <<<<<\n");
                ler(&user);
                alterar(rede, user, index);
                printf("\n\n >>>>> MSG: Usuario alterado com sucesso! <<<<<\n\n");
            }
            else
                printf("\n\n >>>>> MSG: O usuario pesquisado nao esta cadastrado! <<<<<\n\n");

                printf("\n\n >>>>> MSG: Pressione uma tecla para continuar <<<<<\n\n");
                system("PAUSE");
            break;

        case 4:
            // codigo para opcao do menu Excluir
            system("cls");
            printf("\n\n MSG: Digite o nome do usuario que deseja EXCLUIR: \n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);

            index = pesquisar(*rede, user);

            if (index >= 0)
            {
                excluir(rede, index);
                printf("\n\n >>>>> MSG: Usuario excluido com sucesso! <<<<<\n\n");
            }
            else
                printf("\n\n >>>>> MSG: O usuario pesquisado nao esta cadastrado! <<<<<\n\n");

            printf("\n\n >>>>> MSG: Pressione uma tecla para continuar <<<<<\n\n");
            system("PAUSE");
            break;

        case 5:
            // codigo para opcao do menu Imprimir 2
            system("cls");
            if (rede->indice > 0)
            {
                printf("\n\n >>>>> MSG: Lista de usuarios cadastrados: <<<<<\n\n");
                imprimir2(*rede);
            }
            else
                printf("\n\n >>>>> MSG: Nao existem usuarios cadastrados! <<<<<\n\n");

            printf("\n\n >>>>> MSG: Pressione uma tecla para continuar <<<<<\n\n");
            fflush(stdin);
            getchar();
            //system("PAUSE");
            break;

        case 6:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Saindo do MODULO... <<<<<");
            fflush(stdin);
            getchar();
            //system("PAUSE");
            break;

        default:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Digite uma opcao valida! <<<<<");
            fflush(stdin);
            getchar();
            //system("PAUSE");
        }

    }while(opcao != 6);
}
