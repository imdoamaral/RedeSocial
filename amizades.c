#include <stdio.h>
#include <stdlib.h>

#include "amizades.h"

void cadastrarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial *rede)
{
    int  linha, coluna, cont;
    linha = pesquisar(*rede, user1);
    coluna = pesquisar(*rede, user2);

    for(cont=0; cont<rede->indice; cont++)
    {
        rede->matrix[linha][cont] = 1;
        rede->matrix[cont][coluna] = 1;
    }
}

int pesquisarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial rede)
{
    int linha, coluna, cont;

    linha = pesquisar(rede, user1);
    coluna = pesquisar(rede, user2);

    for (cont=0; cont<rede.indice; cont++)
    {
        if ((rede.matrix[linha][cont] == 1) && (rede.matrix[cont][coluna] == 1))
        {
            return 1;
        }
    }
    return 0;
}

void excluirAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial *rede)
{
    int linha, coluna, cont;

    linha = pesquisar(*rede, user1);
    coluna = pesquisar(*rede, user2);

    for (cont=0; cont<rede->indice; cont++)
    {
        rede->matrix[linha][cont] = 0;
        rede->matrix[cont][coluna] = 0;
    }
}

void imprimirListaAmigos(TUsuarios user, TRedeSocial rede)
{
    int index, linha;

    index = pesquisar(rede, user);

    if (index >= 0)
    {
        for (linha=0; linha < rede.indice; linha++)
        {
            if (rede.matrix[linha][index] == 1)
                imprimir(rede.vetor[index]);
        }
    }
}
