#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ptr;
	int n, i;

	ptr = (int *) malloc(sizeof(int));
	printf("sizeof(ptr): %ld", sizeof(ptr));
	printf("sizeof(ptr): %ld", sizeof(ptr)/sizeof(int));
	do{

		printf("\nIngrese un valor: (-1 para salir)\n");
		scanf("%d", &n);
		if(n>=0)
			//ptr = (int *) malloc(sizeof(int));
			ptr = realloc(ptr, sizeof(int));
		
		if(ptr == NULL){ //NULL POINTER EXCEPTION
			printf("NO se alojo la memoria..");
			exit(0);
		}
		else{
			printf("Se alojo la memoria al puntero con Malloc");
			ptr[sizeof(ptr)/sizeof(int)-1] = n;
			printf("Valores del puntero:\n");
			for(i=0;i<sizeof(ptr)/sizeof(int);i++)
				printf("%d, ", ptr[i]);
		}
	}while(n>0);

	return 0;
}
