#ifndef AMIZADES_H_INCLUDED
#define AMIZADES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void cadastrarAmizades(TUsuarios *user1, TUsuarios *user2, TRedeSocial *rede);
int pesquisarAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial rede);
void excluirAmizades(TUsuarios user1, TUsuarios user2, TRedeSocial *rede);
void imprimirListaAmigos(TUsuarios user, TRedeSocial rede);

#endif // AMIZADES_H_INCLUDED
