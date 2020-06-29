/*
 * Pilotos.h
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */

#ifndef PILOTOS_H_
#define PILOTOS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[128];
	char apellido[128];
} Piloto;

Piloto* piloto_constructor(void);
Piloto* piloto_newParametros(char* id, char* nombre, char* apellido);

int piloto_hardcodeo(LinkedList* pArrayPilotos);
int set_pilotoId(Piloto* myPiloto, int id);
int set_pilotoNombre(Piloto* myPiloto, char* nombre);
int set_pilotoApellido(Piloto* myPiloto, char* apellido);

int get_pilotoId(Piloto* myPiloto, int* id);
int get_pilotoNombre(Piloto* myPiloto, char* nombre);
int get_pilotoApellido(Piloto* myPiloto, char* apellido);

void printPilotoHeader();
void printPiloto(Piloto* myPiloto);

int validar_nombrePiloto(void* pPiloto, char* nombre);

#endif /* PILOTOS_H_ */
