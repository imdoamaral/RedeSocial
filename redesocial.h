#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;

}TData;

typedef struct usuarios
{
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData data_de_nascimento;
    int ID; // dever� ser gerado pelo programa e
            // igual ao indice do elemeto cadastrado no vetor (lista)

    int total_amigos;

}TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100]; // lista de usuarios
    int matrix[100][100]; // matriz de relacionamentos de amizades
    int indice; // indica a posicao em que o proximo elemento vai ser inserido na lista e
                // tambem informa a quantidade de usuarios cadastrados na lista

    int matrizAmigos[100][100];

    TUsuarios semAmigosEmComum[100];
    int indice2;

}TRedeSocial;

// Assinatura das fun�oes
void ler(TUsuarios *user);
void imprimir(TUsuarios user);
void inicializar(TRedeSocial *rede);
void cadastrar(TRedeSocial *rede, TUsuarios user);
void imprimir2(TRedeSocial rede);
int pesquisar(TRedeSocial rede, TUsuarios user);
void alterar(TRedeSocial *rede, TUsuarios user, int index);
void excluir (TRedeSocial *rede, int index);
void calcularAmigosEmComum(TUsuarios user1, TUsuarios user2, TRedeSocial rede);

#endif // REDESOCIAL_H_INCLUDED
