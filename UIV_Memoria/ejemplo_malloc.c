#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ptr;
	int n, i;

	printf("Ingrese el tamaño del vector: ");
	scanf("%d",&n);

	ptr = (int*) malloc(n * sizeof(int));

	if(ptr == NULL){ //NULL POINTER EXCEPTION
		printf("NO se alojo la memoria..");
		exit(0);
	}
	else{
		printf("Se alojo la memoria al puntero con Malloc");

		for(i=0; i<n; i++)
			ptr[i] = i+1;

		printf("Valores del puntero:\n");
		for(i=0;i<n;i++)
			printf("%d, ", ptr[i]);
	}

	return 0;
}
