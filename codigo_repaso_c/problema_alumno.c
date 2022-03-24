#include<stdio.h>
#include<time.h>

typedef struct dd_mes_anho{
	int dia;
	int mes;
	int anho;
}fecha;

typedef struct persona{
	char nombre[20];
	fecha f_nac;
}alumno;

void ingreso_fecha(fecha *f){
	printf("\nIngrese el dia: ");
	scanf("%d", &f->dia);
	printf("\nIngrese el mes: ");
	scanf("%d", &f->mes);
	printf("\nIngrese el anho: ");
	scanf("%d", &f->anho);
}

void ingreso_datos_alumno(alumno *nuevo){
	printf("\nIngrese el nombre del estudiante: ");
	scanf("%s", nuevo->nombre);
	printf("\nINgresar Fecha de Nacimiento");
	ingreso_fecha(&nuevo->f_nac);
}

int calcular_edad(fecha *f){
	time_t s;
	struct tm* fecha_actual;
	s = time(NULL); //la marca de tiempo actual
	fecha_actual = localtime(&s); //transformación a formato de fecha

	int anho_actual = fecha_actual->tm_year + 1900;

	int edad = anho_actual - f->anho;
	return edad;
}

int main(){
	int cantidad_alumnos = 3, i;
	alumno listado[cantidad_alumnos];

	for(i=0; i<cantidad_alumnos;i++){
	/*	printf("\nIngrese el nombre del estudiante: ");
		scanf("%s", listado[i].nombre);
		printf("\nIngrese la fecha de Nacimiento: \n dia: ");
		scanf("%d", &listado[i].f_nac.dia);
		printf("\n mes: ");
		scanf("%d", &listado[i].f_nac.mes);
		printf("\n anho: ");
		scanf("%d", &listado[i].f_nac.anho);
		*/
		ingreso_datos_alumno(&listado[i]);
	}
	printf("Listado de Alumnos:");
	for(i=0;i<cantidad_alumnos;i++)
		printf("\nAlumno: %s (%d-%d-%d) [%d]", listado[i].nombre, listado[i].f_nac.dia, listado[i].f_nac.mes, listado[i].f_nac.anho, calcular_edad(&listado[i].f_nac));
		//printf("\n Alumno: %s", listado[i].nombre);



	return 0;
}
