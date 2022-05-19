/*
 * Menu.c
 *
 *  Created on: 15 may. 2022
 *      Author: USURIO
 */

#include "Censistas.h"
#include "Zonas.h"
#include "utn_biblioteca.h"



void menuCensistas(Censistas censistasList[], Zonas zonasList[], Censados censadosList[], int lenZonas, int lenCensistas)
	{
		int option;
		int lugarLibre;
		int flagCensistas = 0;
		int flagZonas = 0;
		do{
			if (utn_getNumeroInt(&option, "\nBienvenido \n1)Cargar censista:\n2)Modificar censista:\n3)Da de baja censista:\n4)Cargar zona:\n5)Asignar zona a censar:\n6)Carga de datos:\n7)Mostrar censistas:\n8)Mostrar zona:\n9)Salir:\n", "\nError opcion Invalida",  1, 9, 5)==0)
				switch (option)
					{
						case 1:
							//Busco lugar libre
							lugarLibre = findEmptyPosition(censistasList, lenCensistas);
							//Pido y cargo los datos ingresados
							addCensistas(&censistasList[lugarLibre], lenCensistas);
							int i;
							for(i=0;i< lenCensistas ;i++)
							{
								printCensistas(&censistasList[i]);
							}
							flagCensistas=1;
							break;
						case 2:
							//Verifico que se haya cumplido la opcion 1
							if(flagCensistas==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenCensistas ;i++)
								{
									printCensistas(&censistasList[i]);
								}
								int idIngresado;
								int indexAModif;
								//Pido que ingrese un numero a buscar
								//Verifico que exista
								//Llamo a la funcion modificar e imprimo
								if (utn_getNumeroInt(&idIngresado, "Ingrese ID\n", "Error", 1, 9999, 5)==0)
								{
									indexAModif = findCensistasById(censistasList,lenCensistas,idIngresado);
									if(indexAModif >=0)
									{
										modifyCensistas(&censistasList[indexAModif]);
										printCensistas(&censistasList[indexAModif]);
									}
								}
							}
							else{
								printf("Error, no hay censistas cargados\n");
							}

							break;
						case 3:
							//Verifico que la opcion 1 se haya ingresado
							if(flagCensistas==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenCensistas ;i++)
								{
									printCensistas(&censistasList[i]);
								}
									int idingresado;
									int idDarBaja;
									//Pido que ingrese un numero a buscar
									//Verifico que exista
									//Llamo a la funcion eliminar e imprimo
									if(utn_getNumeroInt(&idingresado, "\nIngrese ID a eliminar\n", "Error", 1, 9999, 5)==0)
									{
										idDarBaja = findCensistasById(censistasList,lenCensistas,idingresado);
										if(idDarBaja>=0)
										{
											if(removeCensistas(censistasList,lenCensistas,idingresado)==1)
											{
												printf("Censista inactivo\n");
											}
											else
											{
												printf("No se pudo eliminar al censista");
											}
										}
									}
							}
							else
							{
								printf("Error, no hay censistas cargados\n");
							}

							break;
						case 4:
							//Verifico que la opcion 1 se haya ingresado
							lugarLibre = findEmptyPositionZonas(zonasList, lenZonas);
							//Pido y cargo los datos ingresados
							addZonas(&zonasList[lugarLibre], lenZonas);
							flagZonas = 1;
							break;
						case 5:
							if(flagCensistas == 1)
							{
								if(flagZonas == 1)
								{
									int idingresado;
									int auxZonaAAsignar;
									//Pido y cargo los datos ingresados
									for(int i=0;i< lenCensistas ;i++)
									{
										printCensistas(&censistasList[i]);
									}
									if(utn_getNumeroInt(&idingresado, "\nIngrese ID a asignar\n", "Error", 1, 100, 5)==0)
									{
										for(int i=0;i< lenCensistas ;i++)
										{
											printZonas(&zonasList[i], lenZonas, censistasList);
										}
										if(utn_getNumeroInt(&auxZonaAAsignar, "Ingrese la localidad de la zona a asignar: \n","Error\n", 1, 2000, 3)==0)
										{
											asignarZona(zonasList, censistasList, lenZonas, lenCensistas, idingresado, auxZonaAAsignar);
										}
									}
								}
								else
								{
									printf("Error, no hay zonas cargadas\n");
								}
							}
							else
							{
								printf("Error, no hay censistas cargados\n");
							}
							break;
						case 6:
							if(flagZonas==1)
							{
								//Pido y cargo los datos ingresados
								cargaDeDatos(zonasList, censistasList, censadosList);
							}
							else
							{
								printf("Error, no hay zonas cargadas\n");
							}
							break;
						case 7:
							if(flagCensistas==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenCensistas ;i++)
								{
									printCensistas(&censistasList[i]);
								}
							}
							else
							{
								printf("Error, no hay censistas cargados\n");
							}
							break;
						case 8:
							if(flagZonas==1)
							{
								int i;
								//Recorro el array para imprimir los datos cargados
								for(i = 0;i< lenCensistas;i++)
								{
									printZonas(&zonasList[i], lenZonas, censistasList);
								}
							}
							else
							{
								printf("Error, no hay zonas cargadas\n");
							}
							break;
						case 9:
							printf("Saliendo...");
							break;
					}
		}while (option <9);
	}


