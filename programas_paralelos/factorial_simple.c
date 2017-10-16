#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//Comprabacion de errores 
	if (argc != 2)
	{
		fprintf(stderr, "Error en el uso de propgrama\n");
		fprintf(stderr, "Uso:\n\t %s numero\n\n", argv[0]);
		exit(-1);
	}
	//Cambiar pasar el primere paramentro  a numero == atoi
	int objetivo = atoi(argv[1]);
	long int resultado = 1;

	while(objetivo >=1){
		resultado*=objetivo;
		objetivo--;
	}
	//ld para imprimer un lon gint

	fprintf(stdout, "El factorial del numero %s es %ld\n\n", argv[1], resultado);


	return 0;
}
