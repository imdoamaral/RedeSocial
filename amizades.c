#include <stdio.h>
#include <stdlib.h>

#include "amizades.h"
#include "exercicios.h"

void cadastrarAmizades(TUsuarios *user1, TUsuarios *user2, TRedeSocial *rede)
{
    int i, j, coluna;

    i = pesquisar(*rede, *user1);
    j = pesquisar(*rede, *user2);

    if (i>=0 && j>=0)
    {
        for(coluna=0; coluna<rede->indice; coluna++)
        {
            rede->matrix[i][coluna] = 1;
            rede->matrix[coluna][j] = 1;
        }
        printf("\n\n >>>>> MSG: Amizade cadastrada! <<<<< \n\n");

        rede->vetor[i].total_amigos = +1;
        rede->vetor[j].total_amigos = +1;

    }else
        printf("\n\n >>>>> MSG: Os usuarios pesquisados nao estao cadastrados! <<<<<\n\n");
}

int pesquisarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial rede)
{
    int i, j, coluna;

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
        if (rede.matrix[i][linha] == 1 || rede.matrix[i][linha] == 1) // REVISAR
            imprimir(rede.vetor[linha]);
    }
}

// 7. Exercícios para desenvolvimento de funções

// 7. a)
int encontrarMaiorNumeroAmigos(TUsuarios user, TRedeSocial rede)
{
    int i, maior;

    if (rede.indice >= 0)
    {
        maior = rede.vetor[0].total_amigos;

        for(i=1; i < rede.indice; i++)
        {
            if ((rede.vetor[i].total_amigos) > maior)
            {
                maior = rede.vetor[i].ID;
            }
        }
        return maior;
    }
    else
        return -1;
}

// 7. b)
int retornarAmigosEmComum(int ID_01, int ID_02, TRedeSocial rede)
{
    int coluna, cont;

    for(coluna=0; coluna<rede.indice; coluna++)
    {
        if (rede.matrix[ID_01][coluna] == 1 && rede.matrix[ID_02][coluna] == 1)
        {
            cont++;
        }
    }
    return cont;
}

// 7. c) - Está dentro do módulo redesocial.c

// 7. d)

void registrarAmigo(TUsuarios user1, TUsuarios user2, TRedeSocial *rede)
{
    int valor = pesquisarAmizades(user1, user2, *rede);

    if (valor == 0) // Se nao houver amigos em comum ENTAO
    {
        rede->semAmigosEmComum[rede->indice2] = user1;
        rede->indice2++;
        rede->semAmigosEmComum[rede->indice2] = user2;
        rede->indice2++;
    }
}

// 7. e
