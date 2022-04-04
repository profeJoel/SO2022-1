#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define N_HIJOS 10

int hace_algo(){
	int r;
	srand(getpid());
	r = (rand() % 256);
	printf("----> HIJO: pid = %d, Random = %d\n", getpid(), r);
	//sleep(1);
	return r;
}

int main(){
	pid_t pid_hijo;
	int i, estado;
	
	for(i=0; i<N_HIJOS; i++){
		pid_hijo = fork();
		if(pid_hijo == 0)
			exit(hace_algo());
	}

	//se va a esperar por cada hijo que termina la ejecucion de la funcion
	for(i=0;i<N_HIJOS; i++){
		pid_hijo = wait(&estado);
		printf("\nProceso Padre = %d >> Proceso Hijo %d (estado = %d)", getpid(), pid_hijo, WEXITSTATUS(estado));
	}
	return 0;

}
