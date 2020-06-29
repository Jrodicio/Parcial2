/*
 * Vuelos.c
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */

#include "Vuelos.h"


Vuelo* vuelo_constructor(void)
{
	Vuelo* myVuelo = (Vuelo*) malloc(sizeof(Vuelo));

	return myVuelo;
}

Vuelo* vuelo_newParametros (char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
	Vuelo* myVuelo = vuelo_constructor();

	if (myVuelo != NULL)
	{
		set_vueloId(myVuelo,atoi(idVuelo));
		set_vueloIdAvion(myVuelo,atoi(idAvion));
		set_vueloIdPiloto(myVuelo,atoi(idPiloto));
		set_vueloFecha(myVuelo,fecha);
		set_vueloDestino(myVuelo,destino);
		set_vueloCantPasajeros(myVuelo,atoi(cantPasajeros));
		set_vueloDespegue(myVuelo,atoi(horaDespegue));
		set_vueloLlegada(myVuelo,atoi(horaLlegada));
	}

	return myVuelo;
}

int set_vueloId(Vuelo* myVuelo, int id)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->idVuelo = id;
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloIdAvion(Vuelo* myVuelo, int idAvion)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->idAvion = idAvion;
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloIdPiloto(Vuelo* myVuelo, int idPiloto)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->idPiloto = idPiloto;
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloFecha(Vuelo* myVuelo, char* fecha)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		strcpy(myVuelo->fecha,fecha);
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloDestino(Vuelo* myVuelo, char* destino)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		strcpy(myVuelo->destino,destino);
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloCantPasajeros(Vuelo* myVuelo, int cantPasajeros)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->cantPasajeros = cantPasajeros;
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloDespegue(Vuelo* myVuelo, int horaDespegue)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->horaDespegue = horaDespegue;
		auxReturn = 1;
	}
	return auxReturn;
}

int set_vueloLlegada(Vuelo* myVuelo, int horaLlegada)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		myVuelo->horaLlegada = horaLlegada;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloId(Vuelo* myVuelo, int* id)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*id = myVuelo->idVuelo;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloIdAvion(Vuelo* myVuelo, int* idAvion)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*idAvion = myVuelo->idAvion;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloIdPiloto(Vuelo* myVuelo, int* idPiloto)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*idPiloto = myVuelo->idPiloto;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloFecha(Vuelo* myVuelo, char* fecha)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		strcpy(fecha,myVuelo->fecha);
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloDestino(Vuelo* myVuelo, char* destino)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		strcpy(destino,myVuelo->destino);
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloCantPasajeros(Vuelo* myVuelo, int* cantPasajeros)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*cantPasajeros = myVuelo->cantPasajeros;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloDespegue(Vuelo* myVuelo, int* horaDespegue)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*horaDespegue = myVuelo->horaDespegue;
		auxReturn = 1;
	}
	return auxReturn;
}

int get_vueloLlegada(Vuelo* myVuelo, int* horaLlegada)
{
	int auxReturn = 0;

	if(myVuelo != NULL)
	{
		*horaLlegada = myVuelo->horaLlegada;
		auxReturn = 1;
	}
	return auxReturn;
}

void print_headerVuelo()
{
	printf("%8s | %8s | %15s | %10s | %10s | %15s | %15s | %15s\n","Vuelo", "Avion", "Piloto", "Fecha", "Destino", "Cant. pasajeros", "Hora Despegue", "Hora Llegada");
}

void print_vuelo(Vuelo* myVuelo, char* nombrePiloto, char* apellidoPiloto)
{
	int idVuelo;
	int idAvion;
	char fechaVuelo[12];
	char destino[255];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;

	get_vueloId(myVuelo,&idVuelo);
	get_vueloIdAvion(myVuelo,&idAvion);
	get_vueloFecha(myVuelo,fechaVuelo);
	get_vueloDestino(myVuelo,destino);
	get_vueloCantPasajeros(myVuelo,&cantPasajeros);
	get_vueloDespegue(myVuelo,&horaDespegue);
	get_vueloLlegada(myVuelo,&horaLlegada);

	printf("%8d | %8d | %7s %7s | %10s | %10s | %15d | %12d:00 | %12d:00\n", idVuelo,
																 	 	 	 idAvion,
																			 nombrePiloto,
																			 apellidoPiloto,
																			 fechaVuelo,
																			 destino,
																			 cantPasajeros,
																			 horaDespegue,
																			 horaLlegada);
}

int contador_pasajeros(void* eVuelo)
{
	int cantPasajeros = 0;

	Vuelo* myVuelo = (Vuelo*) eVuelo;

	get_vueloCantPasajeros(myVuelo,&cantPasajeros);

	return cantPasajeros;
}

int vuelo_destinoDistinto(void* myVuelo,char* destino)
{
	int auxReturn = 1;
	char destinoVuelo[255];
	Vuelo* vuelo;

	if (myVuelo != NULL && destino != NULL)
	{
		vuelo = (Vuelo*) myVuelo;
		get_vueloDestino(vuelo,destinoVuelo);
		if (strcmp(destinoVuelo,destino))
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}

int vuelo_destinoPortugal(void* myVuelo)
{
	return vuelo_destinoDistinto(myVuelo,"Portugal");
}

int vuelo_destinoIrlanda(void* myVuelo)
{
	return vuelo_destinoDistinto(myVuelo,"Irlanda");
}

int vuelo_duracionMenor(Vuelo* myVuelo, int duracionLimite)
{
	int auxReturn = 0;
	int horaLlegada;
	int horaDespegue;
	int duracion;

	if(myVuelo != NULL && duracionLimite>0)
	{
		get_vueloDespegue(myVuelo,&horaDespegue);
		get_vueloLlegada(myVuelo,&horaLlegada);
		duracion = horaLlegada - horaDespegue;

		if(duracion < duracionLimite)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int vuelo_filtroCortos(void* myVuelo)
{
	return vuelo_duracionMenor((Vuelo*) myVuelo,3);
}

int vuelo_verificarPilotoDistinto(Vuelo* myVuelo,  int idPiloto)
{
	int auxReturn = 1;
	int id;


	if(get_vueloIdPiloto(myVuelo,&id) && id == idPiloto)
	{
		auxReturn = 0;
	}
	return auxReturn;
}

int vuelo_verificarPilotoAlexLifeson(void* myVuelo)
{
	return vuelo_verificarPilotoDistinto((Vuelo*) myVuelo,1);
}
