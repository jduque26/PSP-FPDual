#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	
	// int tuberia[1] entrada
	//int tuberia[0] salida

	int tuberia[2];
	if (pipe(tuberia) == -1){
		fprintf(stderr, "Error en pipe\n");
		exit(-1);
	}

	pid_t pid;
	pid = fork();

	switch(pid){
		case -1:
			fprintf(stderr, "Error en fork\n");
			exit(-1);
		case 0:
			write(tuberia[1], "Hola padre!", 11*sizeof(char)); //11 porque hola padre! son 11
			break;
		default:
			wait(NULL);
			char buffer[20];
			read (tuberia[0],buffer, 11*sizeof(char)); //*sizeof cuanto ocupa en memoria un char en este caso un byte
			fprintf(stdout, "%s\n", buffer);
			close(tuberia[0]);
			close(tuberia[1]);

	}

	return 0;

}