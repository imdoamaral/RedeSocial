#ifndef EXERCICIOS_H_INCLUDED
#define EXERCICIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "amizades.h"

/*

>>>>> O CORPO/DESENVOLVIMENTO DAS FUNÇÕES SE ENCONTRA NO MÓDULO DE AMIZADES <<<<<

*/

int encontrarMaiorNumeroAmigos(TUsuarios user, TRedeSocial rede);
int retornarAmigosEmComum(int ID_01, int ID_02, TRedeSocial rede);
void registrarAmigo(TUsuarios user1, TUsuarios user2, TRedeSocial *rede);
int encontrarRelacaoIndireta();
void encontrarRelacaoIndireta2();

#endif // EXERCICIOS_H_INCLUDED
