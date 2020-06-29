/*
 * Controller.c
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */

#include "Controller.h"

int controller_Rodicio_leerArchivo(LinkedList* pArray, char* typeFile)
{
	int auxReturn = 0;
	char nombreArchivo[255];
	FILE* pFile;

	if (pArray != NULL)
	{
		inputArray(nombreArchivo,255,"Ingrese nombre o path del archivo: ");

		pFile = fopen(nombreArchivo,"r");

		if(pFile != NULL)
		{
			ll_clear(pArray);
			if (!strcmp(typeFile,"Vuelos"))
			{
				auxReturn = parser_vuelosFromText(pFile,pArray);
			}
			else if(!strcmp(typeFile,"Pilotos"))
			{
				auxReturn = parser_pilotosFromText(pFile,pArray);
			}
			fclose(pFile);
		}

	}
	return auxReturn;
}


Piloto* controller_Rodicio_getPilotoByID(LinkedList* pArrayPilotos, int ID)
{
	Piloto* ePiloto;

	int i;
	int auxID;

	if(pArrayPilotos != NULL)
	{
		for(i=0;i<ll_len(pArrayPilotos);i++)
		{

			ePiloto = (Piloto*) ll_get(pArrayPilotos,i);
			get_pilotoId(ePiloto,&auxID);

			if(auxID == ID)
			{
				break;
			}
			else
			{

				ePiloto = NULL;
			}
		}
	}

	return ePiloto;
}

void controller_Rodicio_printVuelos(LinkedList* pArrayVuelos,LinkedList* pArrayPilotos)
{
	Vuelo* myVuelo;
	Piloto* myPiloto;

	int idPiloto;
	char nombrePiloto[128];
	char apellidoPiloto[128];

	int i;

	int len = ll_len(pArrayVuelos);
	int page = 1;
	int minReg;
	int maxReg;
	int auxPage;
	int maxPage = (len+49)/50;

	if (pArrayVuelos!=NULL && pArrayPilotos != NULL)
	{
		do
		{
			system("clear");
			minReg = (page-1)*50;
			maxReg = (page*50);

			print_headerVuelo();

			for(i = minReg; i < maxReg && i < len; i++)
			{
				myVuelo = (Vuelo*) ll_get(pArrayVuelos,i);

				get_vueloIdPiloto(myVuelo,&idPiloto);

				myPiloto = controller_Rodicio_getPilotoByID(pArrayPilotos,idPiloto);


				if(myVuelo != NULL)
				{
					if(myPiloto == NULL)
					{
						myPiloto = piloto_newParametros("0","N/A","N/A");
					}

					get_pilotoNombre(myPiloto,nombrePiloto);
					get_pilotoApellido(myPiloto,apellidoPiloto);
					print_vuelo(myVuelo,nombrePiloto,apellidoPiloto);
				}
			}
			printf("Mostrando página %d/%d",page,maxPage);

			inputInt("Ingrese número de página ó '0' para salir: ",&auxPage);
			if(auxPage>maxPage || auxPage < 0)
			{
				pausa("Número de página inválida, vuelva a intentarlo.\n");
			}
			else
			{
				page = auxPage;
			}
		} while (page != 0);
	}
}

void controller_Rodicio_printPilotos(LinkedList* pArrayPilotos)
{

	Piloto* myPiloto;
	int len;
	int i;
	int page = 1;
	int minReg;
	int maxReg;
	int auxPage;
	int maxPage;

	if(pArrayPilotos != NULL)
	{
		len = ll_len(pArrayPilotos);
		maxPage = (len+49)/50;

		do
		{
			system("clear");
			minReg = (page-1)*50;
			maxReg = (page*50);
			printPilotoHeader();

			for (i=minReg; i<maxReg ; i++)
			{
				myPiloto = ll_get(pArrayPilotos,i);

				if(myPiloto != NULL)
				{
					printPiloto(myPiloto);
				}
			}
			printf("Mostrando página %d/%d",page,maxPage);

			inputInt("Ingrese número de página ó '0' para salir: ",&auxPage);
			if(auxPage>maxPage || auxPage < 0)
			{
				pausa("Número de página inválida, vuelva a intentarlo.\n");
			}
			else
			{
				page = auxPage;
			}
		} while (page != 0);
	}
}


int controller_Rodicio_getCantPasajeros(LinkedList* pArrayVuelos)
{
	int cantidadPasajeros = 0;

	if(pArrayVuelos != NULL)
	{
		cantidadPasajeros += ll_count(pArrayVuelos,contador_pasajeros);
	}

	return cantidadPasajeros;
}

int controller_Rodicio_saveFile(char* path, LinkedList* pArrayVuelos)
{
	int i;
	int len;
	FILE* vuelosFile;
	Vuelo* auxVuelo;

	int retorno = 0;

	if(path != NULL && pArrayVuelos != NULL)
	{
		len = ll_len(pArrayVuelos);
		vuelosFile = fopen(path,"w");
		if (vuelosFile != NULL)
		{
			for(i=0;i<len;i++)
			{
				auxVuelo = ll_get(pArrayVuelos,i);
				if (i == 0)
				{
					fprintf(vuelosFile, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
				}
				fprintf(vuelosFile, "%d,%d,%d,%s,%s,%d,%d,%d\n",auxVuelo->idVuelo,
																auxVuelo->idAvion,
																auxVuelo->idPiloto,
																auxVuelo->fecha,
																auxVuelo->destino,
																auxVuelo->cantPasajeros,
																auxVuelo->horaDespegue,
																auxVuelo->horaLlegada);
			}
			fclose(vuelosFile);
			retorno = 1;
		}

	}
	return retorno;
}

int controller_Rodicio_filtrarPilotoPorNombre(LinkedList* pArrayPilotos)
{
	int auxRetorno = 0;
	LinkedList* pArrayPilotosFiltrado;
	char nombre[128];

	inputArray(nombre,127,"Ingrese el nombre del piloto a filtrar: ");
	upperFirstLetters(nombre);

	pArrayPilotosFiltrado = ll_filter_parametro(pArrayPilotos,validar_nombrePiloto,nombre);

	controller_Rodicio_printPilotos(pArrayPilotosFiltrado);


	return auxRetorno;
}


