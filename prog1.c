#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> //Para concatenar cadenas

#include "libreria.h"
int main(int argc, char* argv[]){


	int a;
	int b;

	a=4;
	b=5;


	printf("Sumar %i y %d es: %d\n",a,b,suma(a,b));
/*

	if (execl("/bin/ls","ls","-la",NULL)== -1){

		fprintf(stderr, "Error ejecutando el comando con excl:\n");

		perror("prog1.c");
	}
*/


	char comando[100];

	int i = 1;
	while( i < argc ){
		strcat(comando,argv[i]);
		strcat(comando," ");
		i++;
	}
	
	system(comando);

	return 0;
}



