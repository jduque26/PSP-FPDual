#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

	pid_t pid1, pid2;	
	printf("hola\n");
	pid1=fork();
	
	if(pid1==0){ //Codigo del hijo
		sleep(1); //Para la ejecucion durante 1 seg
		printf("hola soy el hijo. Mi padre es: %d\n",getppid());
	}
	else{
		pid2=fork(); //Codigo del padre 
		if(pid2 == 0){ //COdifo para el segundo hijo
			sleep(1); //Para la ejecucion durante 1 seg
			printf("hola soy el 2º hijo. Mi padre es: %d\n",getppid());
		}else{
			printf("hola soy el padre, mi pid es: %d\n",getpid());
			printf("he creado un proceso hijo cuyo pid es : %d\n",pid1);
			printf("he creado un proceso hijo cuyo pid es : %d\n",pid2);
			
			printf("el procesor %d termino\n", wait(NULL));
			printf("el procesor %d termino\n", wait(NULL));
		}
	} 

	return 0;
}