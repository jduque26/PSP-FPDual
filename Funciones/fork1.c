#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
// Padre Hijo Nieto
int main(int argc, char const *argv[])
{

	pid_t pid1, pid2;	
	printf("hola\n");
	pid1=fork();
	
	if(pid1==0){ //Codigo del nieto
		pid2=fork();
		if(pid2==0){
			printf("hola soy el nieto. Mi padre es: %d\n",getppid());	
		}else{ //Codigo del hijo
			printf("hola soy el hijo, mi pid es: %d\n" ,getpid());
			printf("he creado un proceso nieto cuyo pid es : %d\n",pid2);
			printf("el procesor %d termino\n", wait(NULL));
		}
		
	}
	else{ //Codigo del padre
		printf("hola soy el padre, mi pid es: %d\n",getpid());
		printf("he creado un proceso hijo cuyo pid es : %d\n",pid1);
		printf("el procesor %d termino\n", wait(NULL));
		
	} 

	return 0;
}