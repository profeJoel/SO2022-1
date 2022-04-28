#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 5

int dato_publico = 0;

void *dice_hola(void *t){
	long hilo_id = (long) t;
	
	dato_publico++;
	printf("HILO %ld (%ld)[%d]: está en ejecucion - dato_publico = %d...\n", hilo_id, pthread_self(), getpid(), dato_publico);
	pthread_exit(NULL);
}

int main(){
	pthread_t hilo[N];
	int confirmacion;
	long i;

	for(i=0; i<N;i++){
		printf("MAIN: %d Crea un hilo...\n", getpid());
		printf("MAIN: id del hilo = %ld\n", i);
		printf("MAIN: dato_public = %d\n", dato_publico);
		confirmacion = pthread_create(&hilo[i],NULL, dice_hola, (void *) i) ;
		if(confirmacion > 0){
			printf("Error al crear el hilo %d\n", confirmacion);
			exit(-1);
		}
	}
	
	for(i=0; i<N; i++){
		confirmacion = pthread_join(hilo[i], NULL);
		if(confirmacion >= 0){
			printf("ERROR al recibir el hilo: %d\n", confirmacion);
			exit(-1);
		}
	}

	return 0;
}
