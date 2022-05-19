/*
 * Censistas.c
 *
 *  Created on: 15 may. 2022
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censistas.h"
#include "utn_biblioteca.h"

#define NOMBRE_Y_APELLIDO_LEN 200
#define DIRECCION_LEN 200


static int getId(void);
static int getFieldToModify(int* selectedField);

//Se inicializa la bandera isEmpty
int initCensistas(Censistas censistasList[],int len)
{
	int index;
	int retorno = -1;
	if(censistasList != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			censistasList[index].isEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//Cargo los censistas
//Llamo a las funciones pedir entero y texto
//Devuelvo el resultado por puntero
//Cambio el valor de la bandera a 0
int addCensistas(Censistas list[], int len)
{
	int retorno=-1;
	int auxEdad;
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxTipoVivienda;
	int auxNumeroCalle;
	char auxNombre[NOMBRE_Y_APELLIDO_LEN];
	char auxApellido[NOMBRE_Y_APELLIDO_LEN];
	char auxCalle[DIRECCION_LEN];
	char auxPiso[DIRECCION_LEN];
	char auxDepartamento[DIRECCION_LEN];
	if(list!=NULL)
	{
		if(utn_getText(auxNombre, NOMBRE_Y_APELLIDO_LEN , "Ingrese el nombre del censista: \n", "Error\n",3)==0)
		{
			if(utn_getText(auxApellido,NOMBRE_Y_APELLIDO_LEN, "\nIngrese el apellido del censista: \n", "Error\n",3)==0)
			{
				if(utn_getNumeroInt(&auxDia, "\nIngrese el dia de nacimiento del censista: \n", "Error\n",1, 31, 3)==0)
				{
					if(utn_getNumeroInt(&auxMes, "\nIngrese el mes de nacimiento del censista: \n", "Error\n",1, 12, 3)==0)
					{
						if(utn_getNumeroInt(&auxAnio, "\nIngrese el año de nacimiento del censista: \n", "Error, ingrese un año valido\n",1, 2022, 3)==0)
						{
							if(utn_getNumeroInt(&auxEdad, "\nIngrese la edad del censista: \n", "Error\n",1, 150, 3)==0)
							{
								if(utn_getText(auxCalle, DIRECCION_LEN , "\nIngrese la calle del censista: \n", "Error\n",3)==0)
								{
									if(utn_getNumeroInt(&auxNumeroCalle, "\nIngrese numero de calle del censista: \n", "Error\n",1, 9999, 3)==0)
									{
										if(utn_getNumeroInt(&auxTipoVivienda, "\nIngrese tipo de vivienda del censista: \n1)Edificio \n2)Casa\n", "Error\n",1, 2, 3)==0)
										{
											if(utn_getText(auxPiso, DIRECCION_LEN , "\nIngrese el piso del censista: \n", "Error\n",3)==0)
											{
												if(utn_getText(auxDepartamento, DIRECCION_LEN , "\nIngrese el departamento del censista: \n", "Error\n",3)==0)
												{
													list->edad = auxEdad;
													list->id = getId();
													list->fechaNacimiento.dia= auxDia;
													list->fechaNacimiento.mes= auxMes;
													list->fechaNacimiento.anio= auxAnio;
													list->direccion.numeroDeCalle = auxNumeroCalle;
													list->direccion.tipoDeVivienda = auxTipoVivienda;
													strncpy(list->nombre,auxNombre,sizeof(list->nombre));
													strncpy(list->apellido,auxApellido,sizeof(list->apellido));
													strncpy(list->direccion.calle,auxCalle,sizeof(list->direccion.calle));
													strncpy(list->direccion.piso,auxPiso,sizeof(list->direccion.piso));
													strncpy(list->direccion.departamento,auxDepartamento,sizeof(list->direccion.departamento));
													list->estado = ACTIVO;
													list->isEmpty = 0;
													retorno=1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

static int getId(void)
{
	static int contador=0;
	contador++;//Es global : Mantiene su valor
	return contador;
}

//Recorro el array
//Verifico que haya espacio
//Retorno la posicion
int findEmptyPosition(Censistas pCensista[], int len)
{
	int retorno=-1;
	int i;
	if(pCensista!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pCensista[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistas(Censistas pCensistas[])
{
	int status=-1;
	int idAModificar;
	int auxFechaNacimiento;
	int auxDireccion;
	Censistas auxCensistas;
	if(pCensistas !=NULL)
	{
		if(getFieldToModify(&idAModificar)==1)
		{
			status=0;
			switch (idAModificar)
			{
			case 1:
				if(utn_getText(auxCensistas.nombre,NOMBRE_Y_APELLIDO_LEN , "Ingrese nuevo nombre: \n", "Error\n", 3)==0)
				{
					strncpy(pCensistas->nombre, auxCensistas.nombre, NOMBRE_Y_APELLIDO_LEN);
				}
				break;
			case 2:
				if(utn_getText(auxCensistas.apellido,NOMBRE_Y_APELLIDO_LEN , "Ingrese nuevo apellido: \n", "Error\n", 3)==0)
				{
					strncpy(pCensistas->apellido, auxCensistas.apellido, NOMBRE_Y_APELLIDO_LEN);
				}
				break;
			case 3:
				if(utn_getNumeroInt(&auxCensistas.edad, "Ingrese nueva edad: \n","Error\n", 1, 150, 3)==0)
				{
					pCensistas->edad = auxCensistas.edad;
				}
				break;
			case 4:
				if(utn_getNumeroInt(&auxFechaNacimiento, "Ingrese que campo quiere modificar: \n1)Dia \n2)Mes \n3)Año \n","Error\n", 1, 3, 3)==0)
				{
					switch(auxFechaNacimiento)
					{
						case 1:
							if(utn_getNumeroInt(&auxCensistas.fechaNacimiento.dia, "Ingrese nuevo dia de nacimiento\n","Error\n", 1, 31, 3)==0)
							{
								pCensistas->fechaNacimiento.dia = auxCensistas.fechaNacimiento.dia;
							}
							break;
						case 2:
							if(utn_getNumeroInt(&auxCensistas.fechaNacimiento.mes, "Ingrese nuevo mes de nacimiento\n","Error\n", 1, 12, 3)==0)
							{
								pCensistas->fechaNacimiento.mes = auxCensistas.fechaNacimiento.mes;
							}
							break;
						case 3:
							if(utn_getNumeroInt(&auxCensistas.fechaNacimiento.anio, "Ingrese nuevo año de nacimiento\n","Error\n", 1, 2022, 3)==0)
							{
								pCensistas->fechaNacimiento.anio = auxCensistas.fechaNacimiento.anio;
							}
							break;
					}
				}
				break;
			case 5:
				if(utn_getNumeroInt(&auxDireccion, "Ingrese que campo quiere modificar: \n1)Calle \n2)Numero de la calle \n3)Tipo de vivienda \n4)Piso \n5)Departamento \n","Error\n", 1, 5, 3)==0)
				{
					switch(auxDireccion)
					{
						case 1:
							if(utn_getText(auxCensistas.direccion.calle,NOMBRE_Y_APELLIDO_LEN , "Ingrese nueva calle: \n", "Error\n", 3)==0)
							{
								strncpy(pCensistas->direccion.calle, auxCensistas.direccion.calle, DIRECCION_LEN);
							}
							break;
						case 2:
							if(utn_getNumeroInt(&auxCensistas.direccion.numeroDeCalle, "Ingrese nuevo numero de calle\n","Error\n", 1, 9999, 3)==0)
							{
								pCensistas->direccion.numeroDeCalle = auxCensistas.direccion.numeroDeCalle;
							}
							break;
						case 3:
							if(utn_getNumeroInt(&auxCensistas.direccion.tipoDeVivienda, "Ingrese nuevo tipo de vivienda: 1) Edificio 2) Casa\n","Error\n", 1, 2, 3)==0)
							{
								pCensistas->direccion.tipoDeVivienda = auxCensistas.direccion.tipoDeVivienda;
							}
							break;
						case 4:
							if(utn_getText(auxCensistas.direccion.piso,NOMBRE_Y_APELLIDO_LEN , "Ingrese nuevo piso: \n", "Error\n", 3)==0)
							{
								strncpy(pCensistas->direccion.piso, auxCensistas.direccion.piso, DIRECCION_LEN);
							}
							break;
						case 5:
							if(utn_getText(auxCensistas.direccion.departamento,NOMBRE_Y_APELLIDO_LEN , "Ingrese nuevo departamento: \n", "Error\n", 3)==0)
							{
								strncpy(pCensistas->direccion.departamento, auxCensistas.direccion.departamento, DIRECCION_LEN);
							}
							break;
					}
				}
				break;
			}
			status = 1;
		}
	}
	return status;
}

//Funcion privada del archivo
//Llamo a la funcion pedir int
//Retorno por puntero el valor ingresado para la funcion modificar
static int getFieldToModify(int* selectedField)
{
	int status=-1;
	int auxSelectItem;

	{
		status =1;
	if(utn_getNumeroInt(&auxSelectItem, "\nElegi la opcion:\n 1-Nombre\n 2-Apellido\n 3-Edad\n 4-Fecha de nacimiento\n 5-Direccion\n", "Error, elegi un campo valido",1 , 5, 3)==0)
		*selectedField= auxSelectItem;
	}
	return status;
}

//Imprimo las posiciones que tengan la bandera isEmpty iniciada
int printCensistas(Censistas pCensistas[])
{
	if(pCensistas->isEmpty == 0)
	{
		printf("Id: %d, Nombre: %s, Apellido: %s, Edad: %d, Dia: %d, Mes: %d, Año: %d, Calle: %s, Numero de calle: %d, Tipo de vivienda: %d, Piso: %s, Departamento: %s\n",pCensistas->id, pCensistas->nombre, pCensistas->apellido, pCensistas->edad, pCensistas->fechaNacimiento.dia, pCensistas->fechaNacimiento.mes, pCensistas->fechaNacimiento.anio,pCensistas->direccion.calle,pCensistas->direccion.numeroDeCalle,pCensistas->direccion.tipoDeVivienda,pCensistas->direccion.piso,pCensistas->direccion.departamento);
	}
	return 1;
}

//Recorro el array
//Verifico que exista el id
//Retorno la posicion
int findCensistasById(Censistas pCensistas[], int len, int idBuscado)
{
	int status=-1;
	int i;

	if(pCensistas!=NULL && len>0 && idBuscado>=0)
	{
		for(i=0; i<len ; i++)
		{
			if(pCensistas[i].id==idBuscado && pCensistas[i].isEmpty == 0)
			{
				status = i;
				break;
			}
		}
	}
	return status;
}

//Para eliminar a los censistas
//Cambio el estado del id recibido a INACTIVO
int removeCensistas(Censistas censistasList[], int len, int idBuscado)
{
	int status = -1;
	if(censistasList != NULL)
	{
		for(int i;i<len;i++)
		{
			if(censistasList[i].id == idBuscado)
			{
				status = 1;
				censistasList[i].estado = INACTIVO;
			}
		}
	}
	return status;
}
