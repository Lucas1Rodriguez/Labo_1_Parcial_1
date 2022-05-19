/*
 * Zonas.h
 *
 *  Created on: 16 may. 2022
 *      Author: USURIO
 */
#include "Censistas.h"
#ifndef ZONAS_H_
#define ZONAS_H_
#define PENDIENTE 1
#define FINALIZADO 2


struct
{
	char calle1[200];
	char calle2[200];
	char calle3[200];
	char calle4[200];
	int Localidad;
	int estado;
	int idCensista;
	int isEmpty;
}typedef Zonas;


int initZonas(Zonas zonaList[],int len);
int addZonas(Zonas list[], int len);
int findEmptyPositionZonas(Zonas pZonas[], int len);
int asignarZona(Zonas pZonas[], Censistas pCensistas[], int lenZonas, int lenCensistas, int idIngresado, int localidadIngresada);
int cargaDeDatos(Zonas pZonas[], Censistas pCensistas[], Censados pCensados[]);
int printZonas(Zonas pZonas[], int lenZonas, Censistas pCensistas[]);



#endif /* ZONAS_H_ */
