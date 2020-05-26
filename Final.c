#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Se define una estructura llamada 'cliente', la cual se utilizara para 
contener los datos de cada uno de los clientes
*/

typedef struct{
/*
La estructura cliente contiene dos variables, un entero (id) y un 
character en forma de arreglo (a) que corresponden a la identificación 
y rol del cliente respectivamente
*/
	int id;
	char a[20];
} cliente;

/*
Se crea una estructura llamada 'product', la cual se utilizara para
contener los datos de cada producto registrado por los clientes
*/
typedef struct{
/*
La estructura cliente contiene tres variables, un entero (id) y dos flotantes (c, p)
que corresponden a la identificación, cantidad del producto y precio
*/
	int id;
	float c, p;

} product;



/*
Se inicia el codigo principal
*/
int main(){
	int i, o; // La variable 'i' se utilizara como un contador en un bucle. y la variable o que contendra la cantidad de clientes a atender
	float pri; // Se crea el flotante pri para guardar el precio final con descuento

	printf("Ingrese el numero total de clientes a atender:\n");
	scanf("%d", &o ); // Se le preguntara al usuario la cantidad de clientes que se atenderan. Este dato se guardara en la variable 'o'
        	
	cliente * cl = malloc( o * sizeof(cliente) ); //Se crea un arreglo dinamico del tamaño de o donde se guardaran temporalmente los datos de cada cliente

	for(i = 0; i<o; i++){
		product * pr = malloc( sizeof(product) ); // Se crea un arreglo dinamico para contener temporalmente los datos del producto
		printf("Ingrese la identificacion y el rol del cliente\n[Porfavor ingresar 'Estudiante' o 'Profesor' como esta escrito solamente]:\n");
		scanf("%d", &cl[i].id ); // Se le pregunta al usuario los datos del cliente y se guardados en las variable correspondientes
		scanf("%s", &cl[i].a ); 

		printf("Ingrese el codigo del producto, la cantidad de unidades & su precio:\n");
		scanf("%d", &pr[0].id ); // Se le pregunta al usuario los datos del producto y se guardan en las variables correcpondientes
		scanf("%f", &pr[0].c );
		scanf("%f", &pr[0].p );

		if( strcmp(cl[i].a, "Estudiante") == 0 ){ // Se inicia una condicion, si el cliente tiene el rol de 'Estudiante'

			pri = (pr[0].p * pr[0].c) * 0.4; // Se calcula el descuento 
			printf("El %s con cedula # %d, debe pagar $ %.2f por el producto # %d\n", cl[i].a, cl[i].id, pri, pr[0].id);
				// Se imprime el mensaje del descuento del cliente para el producto
			pri = 0; // Se reinicia el precio final para evitar errores

		}
		else if( strcmp(cl[i].a, "Profesor") == 0 ){ // Si el cliente tiene el rol de 'Profesor'

			pri = (pr[0].p * pr[0].c) * 0.2; // Se calcula el descuento
			printf("El %s con cedula # %d, debe pagar $ %.2f por el producto # %d\n", cl[i].a, cl[i].id, pri, pr[0].id); 
				// Se imprime el mensaje del descuento del cliente para el producto
			pri = 0; // Se reinicia el precio final para evitar errores
			
		}
		
		free(pr); // Se borran los datos del arreglo del producto para evitar errores
	};
	free(cl); // Se borran los datos del arreglo del cliente
	return 0;
}