/*
 * Parser.h
 *
 *  Created on: 22 jun. 2020
 *      Author: julian
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Vuelos.h"
#include "LinkedList.h"
#include <stdio.h>

int parser_vuelosFromText(FILE* pFile , LinkedList* pListVuelos);
int parser_pilotosFromText(FILE* pFile , LinkedList* pListPilotos);

#endif /* PARSER_H_ */
