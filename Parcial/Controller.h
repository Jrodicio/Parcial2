/*
 * Controller.h
 *
 *  Created on: 23 jun. 2020
 *      Author: julian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Vuelos.h"
#include "LinkedList.h"
#include "Parser.h"
#include "GetValues.h"

int controller_Rodicio_leerArchivo(LinkedList* pArray, char* typeFile);

void controller_Rodicio_printVuelos(LinkedList* pArrayVuelos,LinkedList* pArrayPilotos);
void controller_Rodicio_printPilotos(LinkedList* pArrayPilotos);

int controller_Rodicio_getCantPasajeros(LinkedList* pArrayVuelos);

Piloto* controller_Rodicio_getPilotoByID(LinkedList* pArrayPilotos, int ID);
int controller_Rodicio_filtrarPilotoPorNombre(LinkedList* pArrayPilotos);

int controller_Rodicio_saveFile(char* path, LinkedList* pArrayVuelos);


#endif /* CONTROLLER_H_ */
