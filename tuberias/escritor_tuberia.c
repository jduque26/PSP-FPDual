#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int tub;

	tub = open("./TUBERIA", O_WRONLY);
	
	if (tub == -1){
		fprintf(stderr, "Erro en la creacion de la tuberia\n");
	}else{
		char mensaje[20];
		strcpy(mensaje, "HOla mundo!!!!");
		write(tub, mensaje, sizeof(mensaje));
	}
	return 0;
}