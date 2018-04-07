#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
/*Comentario
Generar un programa que me permita guardar los datos de los clientes
de un banco,nombre,documento y el tipo de transacciones a realizar. Se
requiere conocer el tiempo total de la atencion las personas en la cola,los
tiempos estimados para cada transaccion son los sgtes:
Retiro 4min
Deposito 2min
Consulta 3.5min
Actualizacion 5min
Pagos 2min
Elaborado por:Fernando Lopez Mejia, Leyder Londoño*/
struct Cliente{
	char id[10];
	char nombre[20];
	char tipo_trans[15];
	float tiempo;
};
struct Nodo{
	Cliente c;
	Nodo *siguiente;
};
void cargar_cliente(Cliente);
void insertar_cola(Nodo *&frente,Nodo *&fin,Cliente &c);
bool colaVacia(Nodo *frente);
void mostrar_cola(Nodo *&frente);

int main() {
	Cliente c;
	cargar_cliente(c);
	return 0;
}

void cargar_cliente(Cliente c){
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	int num;
	printf("\n Digite cuantos usuarios desea ingresar \n");
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		printf("\n Ingrese el nombre : ");
		scanf("%s",c.nombre);
		printf("\n Ingrese el documento : ");
		scanf("%s",c.id);
		int opc=0;
		printf("\n|-----------------------------------------|");
		printf("\n|             MENU DE COLAS               |");
		printf("\n|-----------------------------------------|");
		printf("\n|  SELECCIONE EL TIPO DE TRANSACCION QUE  |");
		printf("\n|                DESEA                    |");
		printf("\n|------------------|----------------------|");
		printf("\n|                  |                      |");
		printf("\n| 1. RETIRO        | 2. DEPOSITO          |");
		printf("\n|                  |                      |");
		printf("\n| 3. CONSULTA      | 4. ACTUALIZACION     |");
		printf("\n|                  |                      |");
		printf("\n| 5. PAGOS         | 6. SALIR             |");
		printf("\n|------------------|----------------------|");
		printf("\n|-----------------------------------------|");
		
		printf("\n\nOPCION :");
		scanf("%i",&opc);
		switch(opc) {
		case 1:
			system("cls");
			strcpy(c.tipo_trans,"Retiro");
			c.tiempo=4;
			break;
		case 2:
			system("cls");
			strcpy(c.tipo_trans,"Deposito");
			c.tiempo=2;
			break;
		case 3:
			system("cls");
			strcpy(c.tipo_trans,"Consulta");
			c.tiempo=3.5;
			break;
		case 4:
			system("cls");
			strcpy(c.tipo_trans,"Actualizacion");
			c.tiempo=5;
			break;
		case 5:
			system("cls");	
			strcpy(c.tipo_trans,"Pagos");
			c.tiempo=2;
			break;
		case 6:
			system("cls");
			printf("\n\t\tGRACIAS POR ELEGIR LA MEJOR OPCION \n"); 
			exit(6);
		default:
			system("cls");
			printf("\n\t\tHA INGRESADO UN DATO INVALIDO \n");
			break;
		}
		insertar_cola(frente,fin,c);
		mostrar_cola(frente);
	}
}
	
void insertar_cola(Nodo *&frente,Nodo *&fin,Cliente &c){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo ->c = c;
	nuevo_nodo -> siguiente=NULL;
	if(colaVacia(frente)){
		frente=nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	printf("El dato se agrego correctamente a la Cola\n");
}
bool colaVacia(Nodo *frente){
	return (frente==NULL)?true : false;
}
void mostrar_cola(Nodo *&frente){
	Nodo *aux;
	aux = frente;
	float acum=0;
	while(aux != NULL){
		printf("\n\t\t[%s] ",aux->c.nombre);
		printf("\n\t\t[%s] ",aux->c.id);
		printf("\n\t\t[%s] ",aux->c.tipo_trans);
		printf("\n\t\t[%.1f] ",aux->c.tiempo);
		acum=acum+aux->c.tiempo;
		aux=aux->siguiente;
	}
	printf("\n");
	printf("El tiempo total es %d \n",acum);
}

