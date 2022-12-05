#include <stdio.h>
#include <stdlib.h>
struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int dato;
};
struct nodo* nuevoNodo(int dato)
{
	size_t tam_nodo = sizeof(struct nodo); 
	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
	nuevo_nodo -> dato = dato;
	nuevo_nodo -> hijo_izq = NULL;
	nuevo_nodo -> hijo_der = NULL;
	return nuevo_nodo;
};
void insertarNodo(struct nodo* nd, int dato)
{
	if(dato > nd->dato){
		if(nd->hijo_der == NULL){
			nd -> hijo_der = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd ->hijo_izq == NULL){
			nd->hijo_izq = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}
int nivel = 0;
void buscar(struct nodo* nd, int num){
	nivel++;
	if(num == nd->dato){
		printf("El %d esta en el nivel %d\n", num, nivel);
	}else if(num < nd->dato && nd->hijo_izq != NULL){
		buscar(nd->hijo_izq, num);
	}else if(num > nd->dato && nd->hijo_der != NULL){
		buscar(nd->hijo_der, num);
	}else{
		printf("El numero no se encuentra\n");
	}
}

int main()
{
	int num=0;
	struct nodo* raiz=NULL;
	raiz = nuevoNodo(8);
	insertarNodo(raiz, 3);
	insertarNodo(raiz, 20);
	insertarNodo(raiz, 1);
	insertarNodo(raiz, 5);
	insertarNodo(raiz, 10);
	insertarNodo(raiz, 25);
	insertarNodo(raiz,2);
	insertarNodo(raiz,4);
	insertarNodo(raiz,9);
	insertarNodo(raiz,15);
	printf("Ingresa el numero a buscar:");
	scanf("%d", &num);
	printf("resultado de la busqueda: \n");
	buscar(raiz, num);
	printf("\n");
	return 0;
}