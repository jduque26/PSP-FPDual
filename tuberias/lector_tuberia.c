#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//Arrancamos el lector y se queda bloqueado hasta que no arrancamos el escritor se queda esperando y al raves igual

int main(int argc, char const *argv[])
{
	int tub;

	tub = open("./TUBERIA", O_RDONLY);
	
	if (tub == -1){
		fprintf(stderr, "Erro en la creacion de la tuberia\n");
	}else{
		char mensaje[20];
		read(tub,mensaje,sizeof(mensaje));
		fprintf(stdout, "%s\n", mensaje );
	}
	return 0;
}