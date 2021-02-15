/*

ANOTAÇOES - Aula 5

- Função strcmp() = usada para comparar se 2 strings sao DIFERENTES

    > retorno  0 (FALSO)      = indica que as strings sao iguais
    > retorno -1 (VERDADEIRO) = indica que as strings sao diferentes
    > retorno +1 (VERDADEIRO) = indica que as strings sao diferentes

    *A função fgets() insere um "\n" e um "\0" ao final da string

- Passagem por referencia: para tudo aquilo que se vai modificar
- Passagem por valor(copia): para o que nao se pretende modificar

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "redesocial.h"
#include "interface.h"

int main()
{
    // Declaraçao de variaveis locais
    TUsuarios user;
    TRedeSocial rede;

    /*
    // Chamada da funcao
    ler(&usuario);
    imprimir(usuario);
    */

    int opcao = 0;

    do
    {
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            // Chamada de Funcao para o submenu do Modulo I
            subMenuModulo1(&rede, user);
            break;
        case 2:
            // Chamada de Funcao para o submenu do Modulo II
            // subMenuModulo2(&rede, user);
        case 3:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Saindo do programa... <<<<<");
            break;
        case 4:
            system("cls");
            printf("\n\n\n\t>>>>> MSG: Digite uma opcao valida! <<<<<");
            //system("PAUSE");
            fflush(stdin);
            getchar();
        }
    }while(opcao != 3);

    fflush(stdin);
    getchar();

    return 0;
}
