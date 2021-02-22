#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "redesocial.h"

void ler(TUsuarios *user)
{
    printf("\nDigite o nome do usuario: ");
    fflush(stdin); // faz a limpeza do ponto (buffer) de entrada de dados (teclado)
    fgets(user->nome, 100, stdin);  // stdin = entrada padrao
                                    // console de comanda onde o usuario digita as informaçoes

    printf("\nDigite o email do usuario: ");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\nDigite o login do usuario: ");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\nDigite a senha do usuario: ");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf("\nData de nascimento:\n");
    printf("\nDigite o dia: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.dia);

    printf("\nDigite o mes: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.mes);

    printf("\nDigite o ano: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.ano);

    printf("\n");
}

void imprimir(TUsuarios user)
{
    printf("\n##### CHAMADA DA FUNCAO IMPRIMIR #####\n");

    printf("\nNome do usuario: ");
    printf("\n%s", user.nome);

    printf("\nEmail do usuario: ");
    printf("\n%s", user.email);

    printf("\nLogin do usuario: ");
    printf("\n%s", user.login);

    printf("\nSenha do usuario: ");
    printf("\n%s", user.senha);

    printf("\nData de nascimento:\n");
    printf("\n\tDia: ");
    printf("%d", user.data_de_nascimento.dia);

    printf("\n\tMes: ");
    printf("%d", user.data_de_nascimento.mes);

    printf("\n\tAno: ");
    printf("%d", user.data_de_nascimento.ano);

    printf("\n\nID: ");
    printf("%d", user.ID);

    user.total_amigos = 0;

    printf("\n");
}

void inicializar(TRedeSocial *rede)
{
    rede->indice = 0;

    rede->indice2 = 0;

    int linha, coluna;

    for(linha=0; linha < rede->indice; linha++)
    {
        for(coluna=0; coluna < rede->indice; coluna++)
            rede->matrix[linha][coluna] = 0;
    }
}

void cadastrar(TRedeSocial *rede, TUsuarios user)
{
    if (rede->indice < 100)
    {
        user.ID = rede->indice;
        rede->vetor[rede->indice] = user;
        rede->indice++;
    }
}

void imprimir2(TRedeSocial rede)
{
    int i;

    for (i=0; i < rede.indice; i++)
    {
        imprimir(rede.vetor[i]);
    }
}

int pesquisar(TRedeSocial rede, TUsuarios user)
{
    // Se encontrar o usuario = retorna o INDICE
    // Se NAO encontrar = retorna -1

    int i;

    for (i=0; i < rede.indice; i++)
    {
        if (strcmp(rede.vetor[i].nome, user.nome) == 0)
            return i;
    }
    return -1;
}

void alterar(TRedeSocial *rede, TUsuarios user, int index)
{
    rede->vetor[index]=user;
}

void excluir (TRedeSocial *rede, int index)
{
        rede->vetor[index].ID = -1;
        int coluna;

        /* Zerando todas as amizades do ponto de vista do usuario 'index'
        for (coluna=0; coluna < rede->indice ; coluna++)
        {
            if(rede->matrix[index][coluna] == 1)
                rede->matrix[index][coluna] = 0;
        }
        // Zerando as amizades do ponto de vista dos OUTROS USUARIOS
        // que possuem amizade com o usuario 'i'
        for (linha=0; linha < rede->indice; linha ++)
            if (rede->matrix[linha][index] == 1)
                rede->matrix[linha][index] = 0;
        */

        for (coluna=0; coluna < rede->indice ; coluna++)
        {
            if(rede->matrix[index][coluna] == 1)
                rede->matrix[index][coluna] = 0; // do ponto de vista: i
                rede->matrix[coluna][index] = 0; // do ponto de vista: col
        }
}

// 7. c)
void calcularAmigosEmComum(TUsuarios user1, TUsuarios user2, TRedeSocial rede)
{
    int i, j, linha, coluna;

    i = pesquisar(rede, user1);
    j = pesquisar(rede, user2);

    int index = retornarAmigosEmComum(i, j, rede);

    for(linha=0; linha < rede.indice; linha++)
    {
        for(coluna=0; coluna < rede.indice; coluna++)
            rede.matrizAmigos[linha][coluna] = index;
    }
}
