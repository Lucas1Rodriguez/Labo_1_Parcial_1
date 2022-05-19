/*
 * Zonas.c
 *
 *  Created on: 16 may. 2022
 *      Author: USURIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zonas.h"
#include "Censistas.h"
#include "utn_biblioteca.h"


#define ZONA_LEN 200

//Se inicializa la bandera isEmpty
int initZonas(Zonas zonaList[],int len)
{
	int index;
	int retorno = -1;

	if(zonaList != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			zonaList[index].isEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//Cargo los censistas
//Llamo a las funciones pedir entero y texto
//Devuelvo el resultado por puntero
//Cambio el valor de la bandera a 0
int addZonas(Zonas list[], int len)
{
	int retorno=-1;
	int auxLocalidad;
	char auxCalle1[ZONA_LEN];
	char auxCalle2[ZONA_LEN];
	char auxCalle3[ZONA_LEN];
	char auxCalle4[ZONA_LEN];

	if(list!=NULL)
	{
		if(utn_getText(auxCalle1, ZONA_LEN , "Ingrese la primer calle de la zona: \n", "Error\n",3)==0)
		{
			if(utn_getText(auxCalle2,ZONA_LEN, "\nIngrese la segunda calle de la zona: \n", "Error\n",3)==0)
			{
				if(utn_getText(auxCalle3, ZONA_LEN , "\nIngrese la tercer calle de la zona: \n", "Error\n",3)==0)
				{
					if(utn_getText(auxCalle4, ZONA_LEN , "\nIngrese la cuarta calle de la zona: \n", "Error\n",3)==0)
					{
						if(utn_getNumeroInt(&auxLocalidad, "\nIngrese la localidad de la zona: \n", "Error, ingrese un numero de localidad valido\n",1, 999999, 3)==0)
						{

							list->Localidad = auxLocalidad;
							strncpy(list->calle1,auxCalle1,sizeof(list->calle1));
							strncpy(list->calle2,auxCalle2,sizeof(list->calle2));
							strncpy(list->calle3,auxCalle3,sizeof(list->calle3));
							strncpy(list->calle4,auxCalle4,sizeof(list->calle4));
							list->isEmpty = 0;
							retorno=1;
						}
					}
				}
			}
		}
	}
	return retorno;
}

//Recorro el array
//Verifico que haya espacio
//Retorno la posicion
int findEmptyPositionZonas(Zonas pZonas[], int len)
{
	int retorno=-1;
	int i;

	if(pZonas!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pZonas[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int asignarZona(Zonas pZonas[], Censistas pCensistas[], int lenZonas, int lenCensistas, int idIngresado, int localidadIngresada)
{
	int retorno=-1;

	if(pZonas!=NULL && pCensistas!=NULL && lenCensistas>0)
	{
		if(findCensistasById(pCensistas, lenCensistas, idIngresado) == idIngresado && (pCensistas->estado == ACTIVO || pCensistas->estado == LIBERADO))
		{
			if(localidadIngresada == pZonas->Localidad)
			{
				pZonas->idCensista = idIngresado;
				retorno=1;
			}
		}
	}
	return retorno;
}


int cargaDeDatos(Zonas pZonas[], Censistas pCensistas[], Censados pCensados[])
{
	int retorno=-1;
	int auxCensados;
	int auxCensadosVirtual;
	int auxCensadosAusentes;
	if(pZonas!=NULL && pCensistas!=NULL)
	{
		if(utn_getNumeroInt(&auxCensados, "\nIngrese la cantidad de censados: \n", "Error\n",1, 999999, 3)==0)
		{
			if(utn_getNumeroInt(&auxCensadosVirtual, "\nIngrese la cantidad de censados que completaron el formulario virtual: \n", "Error\n",1, 999999, 3)==0)
			{
				if(utn_getNumeroInt(&auxCensadosAusentes, "\nIngrese la cantidad de censados ausentes: \n", "Error\n",1, 999999, 3)==0)
				{
					pCensados->censados = auxCensados;
					pCensados->censadosVirtual = auxCensadosVirtual;
					pCensados->censadosAusentes = auxCensadosAusentes;
					pZonas->estado = FINALIZADO;
					pCensistas->estado = LIBERADO;
				}
			}

		}
	}

	return retorno;

}


int printZonas(Zonas pZonas[], int lenZonas, Censistas pCensistas[])
{
	int i;
    int auxZonas;
	for(i=0; i<lenZonas ;i++)
	{
        auxZonas = i;
	}

		if(pZonas->isEmpty == 0 && pZonas[auxZonas].idCensista == pCensistas[auxZonas].id)
		{
			printf("Id Censista: %d, Nombre Censista: %s, Apellido Censista: %s, Localidad: %d, Calle 1: %s, Calle 2: %s, Calle 3: %s, Calle 4: %s \n",pCensistas->id, pCensistas->nombre, pCensistas->apellido, pZonas->Localidad, pZonas->calle1, pZonas->calle2, pZonas->calle3, pZonas->calle4);
		}
		else if(pZonas->isEmpty == 0 && pZonas[auxZonas].idCensista != pCensistas[auxZonas].id)
		{
			printf("No hay un censista asignado. Localidad: %d, Calle 1: %s, Calle 2: %s, Calle 3: %s, Calle 4: %s \n", pZonas->Localidad, pZonas->calle1, pZonas->calle2, pZonas->calle3, pZonas->calle4);
		}
	return 1;
}


