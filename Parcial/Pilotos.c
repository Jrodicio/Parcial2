/*
 * Pilotos.c
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */
#include "Pilotos.h"


Piloto* piloto_constructor(void)
{
	Piloto* myPiloto = (Piloto*) malloc(sizeof(Piloto));

	return myPiloto;
}

Piloto* piloto_newParametros(char* id, char* nombre, char* apellido)
{
	Piloto* myPiloto = piloto_constructor();

	if(myPiloto != NULL)
	{
		set_pilotoId(myPiloto,atoi(id));
		set_pilotoNombre(myPiloto,nombre);
		set_pilotoApellido(myPiloto,apellido);
	}

	return myPiloto;
}

int piloto_hardcodeo(LinkedList* pArrayPilotos)
{
	int auxReturn = 0;
	Piloto* myPilot ;

	if(pArrayPilotos != NULL)
	{
		ll_clear(pArrayPilotos);
		myPilot = piloto_newParametros("1","Alex", "Lifeson");
		ll_add(pArrayPilotos,myPilot);

		myPilot = piloto_newParametros("2","Richard", "Bach");
		ll_add(pArrayPilotos,myPilot);

		myPilot = piloto_newParametros("3","John", "Kerry");
		ll_add(pArrayPilotos,myPilot);

		myPilot = piloto_newParametros("4","Erwin", "Rommel");
		ll_add(pArrayPilotos,myPilot);

		myPilot = piloto_newParametros("5","Stephen", "Coonts");
		ll_add(pArrayPilotos,myPilot);

		auxReturn = 1;
	}
	return auxReturn;
}


int set_pilotoId(Piloto* myPiloto, int id)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		myPiloto->id = id;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_pilotoId(Piloto* myPiloto, int* id)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		*id = myPiloto->id;
		auxReturn = 1;
	}
	return auxReturn;
}


int set_pilotoNombre(Piloto* myPiloto, char* nombre)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		strcpy(myPiloto->nombre,nombre);
		auxReturn = 1;
	}
	return auxReturn;
}

int get_pilotoNombre(Piloto* myPiloto, char* nombre)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		strcpy(nombre,myPiloto->nombre);
		auxReturn = 1;
	}
	return auxReturn;
}

int set_pilotoApellido(Piloto* myPiloto, char* apellido)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		strcpy(myPiloto->apellido,apellido);
		auxReturn = 1;
	}
	return auxReturn;
}

int get_pilotoApellido(Piloto* myPiloto, char* apellido)
{
	int auxReturn = 0;

	if(myPiloto != NULL)
	{
		strcpy(apellido,myPiloto->apellido);
		auxReturn = 1;
	}
	return auxReturn;
}

void printPilotoHeader()
{
	printf("%4s| %7s | %3s\n","ID","Nombre","Apellido");
}

void printPiloto(Piloto* myPiloto)
{
	int idPiloto;
	char nombre[128];
	char apellido[128];

	get_pilotoId(myPiloto,&idPiloto);
	get_pilotoNombre(myPiloto,nombre);
	get_pilotoApellido(myPiloto,apellido);

	printf("%4d| %7s | %3s\n",idPiloto,nombre,apellido);
}

int validar_nombrePiloto(void* pPiloto, char* nombre)
{
	int auxReturn = 1;
	Piloto* myPiloto;
	char nombrePiloto[128];

	if(pPiloto != NULL)
	{
		myPiloto = (Piloto*) pPiloto;
		get_pilotoNombre(myPiloto,nombrePiloto);

		if(strcmp(nombrePiloto,nombre))
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}
