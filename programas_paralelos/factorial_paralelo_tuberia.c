#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

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
	int objetivo_hijo = objetivo/2;
	long int resultado = 1;
	
	int tub[2];

	pid_t pid;


	if(pipe(tub) == -1){
		fprintf(stderr, "Error en la tuberia\n");
		exit(-1);
	}

	pid = fork();

 	switch(pid){
		case -1:
			fprintf(stderr, "Error en la creacion del proceso hijo\n");
			exit(-1);
		case 0:
			while(objetivo_hijo >=1){
				resultado*=objetivo_hijo;
				objetivo_hijo--;
			}
			
			fprintf(stdout, "Resultado del hijo: %ld\n", resultado);
			write(tub[1], &resultado, sizeof(long int));

			break;
		default:	
			while(objetivo > objetivo_hijo){
				resultado*=objetivo;
				objetivo--;
			}
		fprintf(stdout, "Resultado del padre: %ld\n", resultado);
		wait(NULL);
		long int resultado_hijo;
		read(tub[0], &resultado_hijo, sizeof(long int));
		fprintf(stdout, "Resultao final : %ld\n", resultado*resultado_hijo);
		close(tub[0]);
		close(tub[1]);

	}

	return 0;
}
