/*
 * Parser.c
 *
 *  Created on: 22 jun. 2020
 *      Author: julian
 */
#include "Parser.h"


int parser_vuelosFromText(FILE* pFile , LinkedList* pListVuelos)
{
	int auxReturn = 0;
	char idVuelo[15];
	char idAvion[15];
	char idPiloto[15];
	char fecha[12];
	char destino[255];
	char cantPasajeros[15];
	char horaDespegue[3];
	char horaLlegada[3];

	Vuelo* pVuelo;

	if(pFile != NULL && pListVuelos != NULL)
	{

		fscanf(pFile, "%*[^\n]\n");
		while (!feof(pFile))
		{

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
				pVuelo = vuelo_newParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
				ll_add(pListVuelos,pVuelo);

		}

		auxReturn = 1;
	}

    return auxReturn;
}


int parser_pilotosFromText(FILE* pFile , LinkedList* pListPilotos)
{
	int auxReturn = 0;
	char id[12];
	char nombre[128];
	char apellido[128];

	Piloto* pPiloto;

	if(pFile != NULL && pListPilotos != NULL)
	{

		fscanf(pFile, "%*[^\n]\n");
		while (!feof(pFile))
		{
				fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, apellido);
				pPiloto = piloto_newParametros(id, nombre, apellido);
				ll_add(pListPilotos,pPiloto);
		}

		auxReturn = 1;
	}

    return auxReturn;
}
