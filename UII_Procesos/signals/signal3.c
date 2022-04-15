#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){

	//int kill(pid_t pid, int signal); //Enviar una señal a otro proceso 
	//
	/*
	 * pid > 0 : corresponde al pid de un proceso
	 * pid == 0: debe enviar la signal al grupo de procesos al que pertenece el emisor
	 * pid < -1: se envie la signal a un grupo de procesos en específico
	 * pid == -1: la signal va a ser lanzada a TODOS los procesos
	 *
	 *
	 *$> kill -SIGKILL -1 // significa que se eliminan todos los procesos vigentes (sudo) 
	 *
	 */

	//retorno
	//0 -> signal se envió correctamente
	//-1 -> error en el envio
	
	int confirmacion, pid, sig;
	pid = 2788;
	sig = SIGKILL;
	
	confirmacion = kill(pid, sig);
	if(confirmacion == 0)
		printf("Se se envió la signal\n");
	else
		printf("Error al enviar\n");
	return 0;
}
