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
El Estado Nacional necesita una aplicación para gestionar a los censistas este 18/05/2022.
Para ello solicitan una aplicación en ANSI C que permita:

1. Cargar censista: se pedirán los datos del censista (nombre, apellido, fecha de nacimiento, edad,
dirección)

2. Modificar censista: se permitirán modificar todos los datos, permitiéndole al usuario elegir qué
quiere modificar.

3. Dar de baja censista: se dará de baja al censista siempre y cuando no haya sido asignado a
ninguna zona. En caso de que eso ocurra, se cambiará al estado “INACTIVO”.

4. Cargar zona: cada zona abarca un radio de cuatro calles que delimitan su alcance y tienen una
localidad.

5. Asignar zona a censar: se asigna un censista responsable a la zona.

6. Carga de datos: al finalizar una zona se cargará cantidad de censados in situ, cantidad de
censados que completaron el formulario virtual y cantidad ausentes. De esta forma se marcará como
“FINALIZADO” el censo en esa zona y el censista estará disponible para una nueva asignación
(“LIBERADO”).

7. Mostrar censistas: se listarán todos los empleados con todos sus datos.

8. Mostrar zonas: se listarán todos los detalles de la zona, incluido el nombre y apellido del censista
responsable. Si aún no no fue asignado un censista, deberá informarse.


NOTAS:
I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las funciones Alta, Baja,
Modificar, Listar y todas aquellas que considere necesarias.

II. Las funciones de toma y validación de datos deberán estar en una biblioteca aparte.

III. Tener en cuenta que no se puede operar sin tener datos cargados.

IV. El código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.

V. La localidad se deberá manejar como un entero. Deberá existir un array de Localidades
hardcodeado.

VI. Los estados de los censistas son ACTIVO / INACTIVO / LIBERADO y los de la zona PENDIENTE
/ FINALIZADO.

VII. Se deberá contar con una función de hardcodeo por cada opción de alta.

VIII. Dirección y fecha de nacimiento en censista deben ser estructuras anidadas.

IX. Modificar censista debe tener un submenú para poder elegir qué campos modificar. Si se elige
dirección o fecha de nacimiento se debe hacer otro submenú para elegir qué campo particular
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
