#ifndef PERSONA_H
#define PERSONA_H


#define MAX_LONG_NOMBRE 100 //Definimos el tamaño maximo son Constantes
#define MAX_LONG_APELLIDO 100

typedef struct 
{
	short int anyo;  
	short int mes;		//short int es un entero corto para que la estructura ocupe menos memoria
	short int dia;

}fecha;

typedef struct //Asi definimos directamente el tipo de dato
{
	char nombre[MAX_LONG_NOMBRE];
	char apellido[MAX_LONG_APELLIDO];
	fecha fecha_nac;
} persona;



unsigned short int obtener_edad(persona*);

#endif