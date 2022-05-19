/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
El Estado Nacional necesita una aplicaci�n para gestionar a los censistas este 18/05/2022.
Para ello solicitan una aplicaci�n en ANSI C que permita:

1. Cargar censista: se pedir�n los datos del censista (nombre, apellido, fecha de nacimiento, edad,
direcci�n)

2. Modificar censista: se permitir�n modificar todos los datos, permiti�ndole al usuario elegir qu�
quiere modificar.

3. Dar de baja censista: se dar� de baja al censista siempre y cuando no haya sido asignado a
ninguna zona. En caso de que eso ocurra, se cambiar� al estado �INACTIVO�.

4. Cargar zona: cada zona abarca un radio de cuatro calles que delimitan su alcance y tienen una
localidad.

5. Asignar zona a censar: se asigna un censista responsable a la zona.

6. Carga de datos: al finalizar una zona se cargar� cantidad de censados in situ, cantidad de
censados que completaron el formulario virtual y cantidad ausentes. De esta forma se marcar� como
�FINALIZADO� el censo en esa zona y el censista estar� disponible para una nueva asignaci�n
(�LIBERADO�).

7. Mostrar censistas: se listar�n todos los empleados con todos sus datos.

8. Mostrar zonas: se listar�n todos los detalles de la zona, incluido el nombre y apellido del censista
responsable. Si a�n no no fue asignado un censista, deber� informarse.


NOTAS:
I. Se deber� desarrollar bibliotecas por cada entidad, las cuales contendr�n las funciones Alta, Baja,
Modificar, Listar y todas aquellas que considere necesarias.

II. Las funciones de toma y validaci�n de datos deber�n estar en una biblioteca aparte.

III. Tener en cuenta que no se puede operar sin tener datos cargados.

IV. El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y
respetar las reglas de estilo de la c�tedra.

V. La localidad se deber� manejar como un entero. Deber� existir un array de Localidades
hardcodeado.

VI. Los estados de los censistas son ACTIVO / INACTIVO / LIBERADO y los de la zona PENDIENTE
/ FINALIZADO.

VII. Se deber� contar con una funci�n de hardcodeo por cada opci�n de alta.

VIII. Direcci�n y fecha de nacimiento en censista deben ser estructuras anidadas.

IX. Modificar censista debe tener un submen� para poder elegir qu� campos modificar. Si se elige
direcci�n o fecha de nacimiento se debe hacer otro submen� para elegir qu� campo particular
cambiar de esas estructuras.
*/



#include <stdio.h>
#include <stdlib.h>
#include "Censistas.h"
#include "Zonas.h"
#include "Menu.h"
#include "utn_biblioteca.h"

#define CENSISTAS_LEN 100
#define ZONAS_LEN 100
#define CENSADOS_LEN 100

int main(void) {
	setbuf(stdout, NULL);
		Censistas censistasList[CENSISTAS_LEN];
		Zonas zonasList[ZONAS_LEN];
		Censados censadosList[CENSADOS_LEN];

		//llamo a la funcion de inicializar censistas
		initCensistas(censistasList, CENSISTAS_LEN);


		//llamo a la funcion de inicializar zonas
		initZonas(zonasList, ZONAS_LEN);

		//llamo a la funcion menu
		menuCensistas(censistasList, zonasList, censadosList, CENSISTAS_LEN, ZONAS_LEN);
	return EXIT_SUCCESS;
}
