#include<stdio.h>
#include <string.h>
#include "persona.h"


/*
struct person //Definimos una estructura, que contiene esos datos
{
	char nombre[100];
	char apellido[100];
	int edad;

};

typedef struct person persona; //Esto se hace para definirlo como un tipo de datos , pq antes no lo era 
*/


int main(int argc, char const *argv[])
{
	persona p1;
	strcpy(p1.nombre, "Juan");
	strcpy(p1.apellido, "Lopez");

	fecha fnac = {1960, 10 ,17};
	p1.fecha_nac = fnac;

	printf("Nombre:%s, %s\nEdad: %d\n\n ", p1.apellido, p1.nombre, obtener_edad(&p1) );


	return 0;
}
