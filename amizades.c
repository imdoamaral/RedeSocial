#include <stdio.h>
#include <stdlib.h>

#include "amizades.h"

void cadastrarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial *rede)
{
    int i, j, coluna;

    i = pesquisar(*rede, user1);
    j = pesquisar(*rede, user2);

    if(i>=0 && j>=0)
    {
        for(coluna=0; coluna<rede->indice; coluna++)
        {
            rede->matrix[i][coluna] = 1;
            rede->matrix[coluna][j] = 1;
        }
        printf("\n\n >>>>> MSG: Amizade cadastrada! <<<<< \n\n");

    }else
        printf("\n\n >>>>> MSG: Os usuarios pesquisados nao estao cadastrados! <<<<<\n\n");

}

int pesquisarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial rede)
{
    int linha, i, j,  coluna;

    i = pesquisar(rede, user1);
    j = pesquisar(rede, user2);

    if(i>=0 && j>=0)
    {
        for (coluna=0; coluna<rede.indice; coluna++)
        {
            if ((rede.matrix[coluna][i] == 1) || (rede.matrix[j][coluna] == 1))
            {
                return 1;
            }
        }
    }

    return 0;
}

void excluirAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial *rede)
{
    int i, j, coluna;

    i = pesquisar(*rede, user1);
    j = pesquisar(*rede, user2);

    if (i >= 0 && j >=0)
    {
        for (coluna=0; coluna<rede->indice; coluna++)
        {
            rede->matrix[i][coluna] = 0;
            rede->matrix[coluna][j] = 0;
        }
        printf("\n\n >>>>> MSG: Amizade excluida com sucesso! <<<<<\n\n");
    }
    else
        printf("\n\n >>>>> MSG: Amizade nao encontrada! <<<<<\n\n");


}

void imprimirListaAmigos(TUsuarios user, TRedeSocial rede)
{
    int i, linha;

    i = pesquisar(rede, user);

    for (linha=0; linha < rede.indice; linha++)
    {
        if (rede.matrix[i][linha] == 1 || rede.matrix[i][linha] == 1)
            imprimir(rede.vetor[linha]);
    }

}
