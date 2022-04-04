#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid_proceso;

	printf(">> PID del proceso padre = %d >> Comienza ejecucion\n", getpid());
	
	pid_proceso = fork();

	while(1){
		if(pid_proceso == 0)
			printf(">>>> Este es el proceso Hijo: %d >> En Ejecucion\n", getpid());
		else
			printf(">> Este es el proceso padre: %d >> En Ejecucion\n", getpid());
		sleep(2);
	}

	return 0;

}
