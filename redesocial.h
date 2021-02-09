#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>

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
    int ID; // deverá ser gerado pelo programa e
            // igual ao indice do elemeto cadastrado no vetor (lista)
}TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100]; // lista de usuarios
    int matrix[100][100]; // matriz de relacionamentos de amizades
    int indice; // indica a posicao em que o proximo elemento vai ser inserido na lista e
                // tambem informa a quantidade de usuarios cadastrados na lista

}TRedeSocial;

// Assinatura das funçoes
void ler(TUsuarios *user);
void imprimir(TUsuarios user);
void iniciar(TRedeSocial *rede);
void cadastrar(TRedeSocial *rede, TUsuarios user);
void imprimir2(TRedeSocial rede);

#endif // REDESOCIAL_H_INCLUDED
