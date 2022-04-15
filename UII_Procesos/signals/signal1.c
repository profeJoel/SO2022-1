#include<stdio.h>
#include<unistd.h>
#include<signal.h>


//void mi_accion(int signal)

void mi_accion(int s){
	printf(">>>>>>> Señal recibida: %d ha sido capturada con exito\n", s);
}

int main(){

	//signal(int signal, void accion(funcion, signal))
	//
	//signal(SIGALRM, SIG_IGN);//Para ignorar señales
	signal(SIGALRM, &mi_accion);
	int i = 0;
	while(1){
		printf(">> Ejecucion: %d\n", i++);
		sleep(2);
	}
	return 0;
}
