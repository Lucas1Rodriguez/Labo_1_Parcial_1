/*
 * Cencistas.h
 *
 *  Created on: 15 may. 2022
 *      Author: USURIO
 */

#ifndef CENSISTAS_H_
#define CENSISTAS_H_

#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

struct
{
	int dia;
	int mes;
	int anio;
}typedef FechaDeNacimiento;

struct
{
	char calle[200];
	int numeroDeCalle;
	int tipoDeVivienda;
	char piso[200];
	char departamento[200];
}typedef Direccion;

struct
{
	char nombre[200];
	char apellido[200];
	int edad;
	FechaDeNacimiento fechaNacimiento;
	Direccion direccion;
	int estado;
	int id;
	int isEmpty;
}typedef Censistas;

struct
{
	int censados;
	int censadosVirtual;
	int censadosAusentes;
}typedef Censados;

int initCensistas(Censistas censistasList[],int len);
int addCensistas(Censistas list[], int len);
int findEmptyPosition(Censistas pCensista[], int len);
int modifyCensistas(Censistas pCensistas[]);
int printCensistas(Censistas pCensistas[]);
int findCensistasById(Censistas pCensistas[], int len, int idBuscado);
int removeCensistas(Censistas censistasList[], int len, int idBuscado);

#endif /* CENSISTAS_H_ */
