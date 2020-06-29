#include "Parser.h"
#include "Controller.h"
#include "Menu.h"

/* Menú
 *		1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.
 *		2) Imprimir vuelos: Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto (no el número)
 *		3) Cantidad de pasajeros: Cantidad de pasajeros totales
 *		4) Cantidad de pasajeros a Irlanda: cantidad de pasajeros a irlanda.
 *		5) Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los datos de los vuelos cuya duración sea inferior a 3 horas.
 *		6) Listar vuelos a Portugal: Generar un listado que solo incluya los vuelos con destino a Portugal.
 *		7) Filtrar a Alex Lifeson: Necesitamos un listado de vuelos que no incluya al chofer Alex Lifeson
 * */

int main()
{
	char* menu[128] = {	"Cargar archivo vuelos",
						"Cargar archivo pilotos",
						"Imprimir vuelos",
						"Cantidad de pasajeros",
						"Cantidad de pasajeros a Irlanda",
						"Filtrar vuelos cortos (<3hs)",
						"Listar vuelos a Portugal",
						"Filtrar a Alex Lifeson (quitar sus vuelos)",
						"Filtrar pilotos por nombre",
						"Salir"
	};

	int opcionIngresada;
	int retornoFuncion;
	/*Listas generales*/
	LinkedList* listaVuelos = ll_newLinkedList();
	LinkedList* listaPilotos = ll_newLinkedList();

	/*Listas filtradas*/
	LinkedList* listaVuelosFiltrada;

	piloto_hardcodeo(listaPilotos);


	do
	{
		system("clear");
		printf("-=Menú Principal=-");
		opcionIngresada = inputMenuOption(menu);
		system("clear");
		if(opcionIngresada != 1 && opcionIngresada != 2 && opcionIngresada != 10 && ll_isEmpty(listaVuelos))
		{
			pausa("Debe cargar un archivo de vuelos antes de dar realizar cualquier otra acción. ");
			continue;
		}
		switch(opcionIngresada)
		{
			case 1:
				printf("-=Carga archivo vuelos=-");
				if (controller_Rodicio_leerArchivo(listaVuelos,"Vuelos"))
				{
					printf("Archivo cargado con exito!");
				}
				else
				{
					printf("El archivo no existe o no tiene permisos para acceder al mismo.");
				}
				break;

			case 2:
				printf("-=Carga archivo pilotos=-");
				if (controller_Rodicio_leerArchivo(listaPilotos,"Pilotos"))
				{
					printf("Archivo cargado con exito!");
				}
				else
				{
					printf("El archivo no existe o no tiene permisos para acceder al mismo.");
				}
				break;

			case 3:

				controller_Rodicio_printVuelos(listaVuelos,listaPilotos);

				break;

			case 4:
				retornoFuncion = controller_Rodicio_getCantPasajeros(listaVuelos);
				if(retornoFuncion < 0)
				{
					printf("No se pudo contabilizar la cantidad de pasajeros.");
				}
				else
				{
					printf("Pasajeros totales: %d",retornoFuncion);
				}

				break;

			case 5:

				listaVuelosFiltrada = ll_filter_parametro(listaVuelos,vuelo_destinoDistinto,"Irlanda");

				retornoFuncion = controller_Rodicio_getCantPasajeros(listaVuelosFiltrada);
				if(retornoFuncion < 0)
				{
					printf("No se pudo contabilizar la cantidad de pasajeros con destino 'Irlanda'.");
				}
				else
				{
					printf("Pasajeros con destino 'Irlanda': %d",retornoFuncion);
				}
				break;

			case 6:
				printf("\n-=Vuelos cortos=-\n");
				listaVuelosFiltrada = ll_filter(listaVuelos,vuelo_filtroCortos);
				if(controller_Rodicio_saveFile("VuelosCortos.csv",listaVuelosFiltrada))
				{
					printf("\nSe generó el archivo 'VuelosCortos.csv' correctamente.");
				}
				break;

			case 7:
				printf("\n-=Vuelos a Portugal=-\n");
				listaVuelosFiltrada = ll_filter(listaVuelos,vuelo_destinoPortugal);
				controller_Rodicio_printVuelos(listaVuelosFiltrada,listaPilotos);
				break;

			case 8:
				listaVuelosFiltrada = ll_filter(listaVuelos,vuelo_verificarPilotoAlexLifeson);
				if(ll_isEmpty(listaVuelosFiltrada))
				{
					printf("No hay vuelos sin Alex Lifeson.");
				}
				else
				{
					controller_Rodicio_printVuelos(listaVuelosFiltrada,listaPilotos);
				}
				break;

			case 9:
				printf("-=Filtrar por nombre piloto=-");
				controller_Rodicio_filtrarPilotoPorNombre(listaPilotos);
				break;

			case 10:
				printf("\nADIOS!");
				break;

			default:
				printf("\nOpción inválida!");
				break;
		}
	pausa("");
	}while (opcionIngresada != 10);

	system("clear");
	return 0;
}
