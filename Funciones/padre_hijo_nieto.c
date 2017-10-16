#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
// Padre Hijo Nieto
int main(int argc, char const *argv[])
{

	pid_t pid;	
	printf("Comenzamos\n");
	pid=fork();
	
	if(pid==0){ 
		pid=fork();
		if(pid==0){//Codigo del nieto
			fprintf(stdout, "Soy el nieto.  \n");
			fprintf(stdout, "PID: %d PPID:  %d \n", getpid(), getppid());
		}else{ //Codigo del hijo
			fprintf(stdout, "Soy el hijo.  \n");
			fprintf(stdout, "PID: %d PPID:  %d \n", getpid(), getppid());
			fprintf(stdout, "Mi hijo es:  %d\n",pid);
		 	fprintf(stdout, "Mi hijo %d termino: \n", wait(NULL));
		}
		
	}
	else{ //Codigo del padre
			fprintf(stdout, "Soy el padre.  \n");
			fprintf(stdout, "PID: %d PPID:  %d \n", getpid(), getppid());
		 	fprintf(stdout, "Mi hijo es:  %d\n", pid);
		 	fprintf(stdout, "Mi hijo %d termino: \n", wait(NULL));;
	} 

	fprintf(stdout, "PID: %d termino... \n" , getpid());

	return 0;
}