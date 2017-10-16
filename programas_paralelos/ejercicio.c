#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	//Comprabacion de errores 
	
	
	int tub[2];
	int i;
	if(pipe(tub)==-1){
			fprintf(stderr, "Error en la tuberia\n");
		exit(-1);
	}
	for( i = 0; i<3; i++){
		if(fork()==0){
			pid_t pid = getpid();
			write(tub[1], &pid, sizeof(pid_t));
			return 0;
		}
	}

	for(i=0; i<3; i++){
		wait(NULL);
		pid_t hijo;
		read(tub[0], &hijo, sizeof(pid_t));
		fprintf(stdout, "El hijo %d ha acabado\n",hijo );
	}
	close(tub[0]);
	close(tub[1]);
	return 0;
}
