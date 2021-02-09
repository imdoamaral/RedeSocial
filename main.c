/*

ANOTAÇOES - Aula 5

- Função strcmp() = usada para comparar se 2 strings sao DIFERENTES

    > retorno  0 (FALSO)      = indica que as strings sao iguais
    > retorno -1 (VERDADEIRO) = indica que as strings sao diferentes
    > retorno +1 (VERDADEIRO) = indica que as strings sao diferentes

    *A função fgets() insere um "\n" e um "\0" ao final da string

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "redesocial.h"

int main()
{
    // Declaraçao de variaveis locais
    TUsuarios user;
    TRedeSocial rede;

    // Chamada das funcoes
    ler(&user);
    iniciar(&rede);
    cadastrar(&rede, user);
    imprimir(user);
    imprimir2(rede);
    // Passagem por referencia: tudo aquilo que se vai modificar
    // Passagem por valor: todo o resto

    int index = pesquisar(rede, user);
    ler(&user);
    alterar(&rede, user, index);

    return 0;
}
