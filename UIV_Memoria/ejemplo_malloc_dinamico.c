#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ptr, *p;
	int n, i, ultimo = 0;

	do{
		if(ultimo == 0){
			printf("Dar espacio por primera vez...\n");
			//con esta instruccion se asigna la primera posicion
			// ptr = NULL; // antes de la instruccion
			// ptr = []; // despues de la instruccion
			ptr = (int *) malloc((ultimo+1) * sizeof(int));
			if(ptr == NULL){
				printf("No se alojo memoria\n");
				exit(0);
			}
		}
		else{
			printf("Dar espacio por las otras veces...\n");
			//con esta instruccion se asina una nueva posicion sumado a la tamaño del puntero anterior
			// ptr = [...]; // antes de la instruccion
			// ptr = [...]+[]; // despues de la instruccion
			ptr = (int *) realloc(ptr,(ultimo+1) * sizeof(int));
			if(ptr == NULL){
				printf("No Se alojo memoria\n");
				exit(0);
			}
		}

		printf("sizeof(ptr): %ld bytes\n", (ultimo + 1) *sizeof(ptr));
		printf("sizeof(ptr): %d posiciones\n", ultimo+1);
		
		printf("\nIngrese un valor: (-1 para salir)\n");
		scanf("%d", &n);
		
		if(ptr == NULL){ //NULL POINTER EXCEPTION
			printf("NO se alojo la memoria..\n");
			exit(0);
		}
		else{
			printf("Se alojo la memoria al puntero con Malloc");
			ptr[ultimo] = n;
			printf("\nValores del puntero:\n");
			for(i=0;i<ultimo+1;i++)	
				printf("ptr[%d] = %d\n", i, ptr[i]);
			printf("\n");
		}
		ultimo++;
	}while(n>=0);

	return 0;
}
