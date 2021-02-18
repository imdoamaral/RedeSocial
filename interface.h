#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

void MSG_MENU(); // MENU PRINCIPAL
void MSG_SUBMENU(int numero_modulo); // SUBMENU MODULOS
void subMenuModulo1(TRedeSocial *rede, TUsuarios user); // GERENCIAR USUARIOS
void subMenuModulo2(TRedeSocial *rede, TUsuarios user1, TUsuarios user2); // GERENCIAR AMIZADES

#endif // INTERFACE_H_INCLUDED
