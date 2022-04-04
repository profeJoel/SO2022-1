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
	pid_t pid_hijo, pid_HIJOS[N_HIJOS];
	int i, estado;
	
	for(i=0; i<N_HIJOS; i++){
		pid_HIJOS[i] = fork();
		if(pid_HIJOS[i] == 0)
			exit(hace_algo());
	}

	//se va a esperar por cada hijo que termina la ejecucion de la funcion
	
	pid_hijo = waitpid(pid_HIJOS[0], &estado, 0);
	printf("\nProceso Padre = %d >> Proceso Hijo %d (estado = %d)", getpid(), pid_hijo, WEXITSTATUS(estado));
	
	return 0;

}
