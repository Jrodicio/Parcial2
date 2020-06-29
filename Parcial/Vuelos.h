/*
 * Vuelos.h
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */

#ifndef VUELOS_H_
#define VUELOS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilotos.h"

typedef struct
{
	int idVuelo;
	int idAvion;
	int idPiloto;
	char fecha[12];
	char destino[255];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
} Vuelo;

Vuelo* vuelo_constructor(void);
Vuelo* vuelo_newParametros (char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
int set_vueloId(Vuelo* myVuelo, int id);
int set_vueloIdAvion(Vuelo* myVuelo, int idAvion);
int set_vueloIdPiloto(Vuelo* myVuelo, int idPiloto);
int set_vueloFecha(Vuelo* myVuelo, char* fecha);
int set_vueloDestino(Vuelo* myVuelo, char* destino);
int set_vueloCantPasajeros(Vuelo* myVuelo, int cantPasajeros);
int set_vueloDespegue(Vuelo* myVuelo, int horaDespegue);
int set_vueloLlegada(Vuelo* myVuelo, int horaLlegada);

int get_vueloId(Vuelo* myVuelo, int* id);
int get_vueloIdAvion(Vuelo* myVuelo, int* idAvion);
int get_vueloIdPiloto(Vuelo* myVuelo, int* idPiloto);
int get_vueloFecha(Vuelo* myVuelo, char* fecha);
int get_vueloDestino(Vuelo* myVuelo, char* destino);
int get_vueloCantPasajeros(Vuelo* myVuelo, int* cantPasajeros);
int get_vueloDespegue(Vuelo* myVuelo, int* horaDespegue);
int get_vueloLlegada(Vuelo* myVuelo, int* horaLlegada);

void print_headerVuelo();
void print_vuelo(Vuelo* myVuelo, char* nombrePiloto, char* apellidoPiloto);

int contador_pasajeros(void* eVuelo);

int vuelo_destinoDistinto(void* myVuelo,char* destino);
int vuelo_destinoPortugal(void* myVuelo);
int vuelo_destinoIrlanda(void* myVuelo);

int vuelo_duracionMenor(Vuelo* myVuelo, int duracionLimite);
int vuelo_filtroCortos(void* myVuelo);

int vuelo_verificarPilotoDistinto(Vuelo* myVuelo, int idPiloto);
int vuelo_verificarPilotoAlexLifeson(void* myVuelo);

#endif /* VUELOS_H_ */
