#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}
