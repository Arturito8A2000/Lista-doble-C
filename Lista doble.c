#include <stdio.h>
#include <stdlib.h>

typedef struct Molde{
	int dato;
	struct Molde* siguiente;
	struct Molde* atras;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

int MenuAnadir();
int MenuPrincipal();
void insertarNodoInicio();
void insertarNodoDespues();
void insertarNodoFinal();
int longitud();
void buscarNodo();
void buscarNodoPos();
void eliminarNodo();
void eliminarNodoPos();
void desplegarLista();

int main(){
	int out, outSub;
	do{
        out=MenuPrincipal();
		switch(out){
			case 1:
				if(primero==NULL)
                    printf("\n\n LA LISTA ESTA VACIA \n\n");
				else
                    printf("\n\n LA LISTA NO ESTA VACIA \n\n");
				break;
            case 2:{
				printf("\n\n DESPLEGAR LISTA DE NODOS \n\n");
				desplegarLista();}
				break;
			case 3: outSub=MenuAnadir();
                    switch(outSub){
                        case 1: insertarNodoInicio(); break;
                        case 2: insertarNodoDespues(); break;
                        case 3: insertarNodoFinal(); break;
                        default: printf("Opcion incorrecta\n");
                    }
                    break;
            case 4:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				eliminarNodo();
				break;
            case 5:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				eliminarNodoPos();
				break;
            case 6:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodo();
				break;
			case 7:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodoPos();
				break;
			case 0:
				printf("\n\n Adios!!...\n");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n"); break;
		}
	}
	while(out != 0);
return 0;
}

int MenuPrincipal(){
    int opcionMenu;
	do{
		printf("\n|     ° LISTA DOBLEMENTE LIGADA °     |");
		printf("\n|-------------------------------------|");
		printf("\n| 1) Indicar si la lista esta vacia   |");
		printf("\n| 2) Desplegar lista                  |");
		printf("\n| 3) Insertar nodo                    |");
		printf("\n| 4) Eliminar nodo por valor          |");
		printf("\n| 5) Eliminar nodo en posicion        |");
		printf("\n| 6) Buscar valor en lista            |");
		printf("\n| 7) Buscar posicion en lista         |");
		printf("\n| 0) Salir                            |");
		printf("\n|-------------------------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf(" %d", &opcionMenu);
    }
    while(opcionMenu < 0 && opcionMenu > 6);
return opcionMenu;
}

int MenuAnadir(){
    int opcion;
    do{
        printf("\nElija una de las siguientes opciones: \n");
        printf("\b 1) Anadir al inicio\n");
        printf("\b 2) Anadir despues de posicion\n");
        printf("\b 3) Anadir al final\n");
        printf("::: ");
        scanf(" %d",&opcion);
    }
    while(opcion < 0 && opcion > 3);
    return opcion;
}

void insertarNodoInicio(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
	    primero->atras=nuevo;
	    nuevo->siguiente=primero;
	    nuevo->atras = NULL;
	    primero=nuevo;
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void insertarNodoDespues(){
    int x, i, a=longitud();
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	//nodo *aux=primero;
	printf("\n Ingrese la posición (se asigna despues de la posicion ingresada)\n:: NOTA: Conteo realizado desde 1: ");
	scanf("%d", &x);
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
	    if(x>=a){
            ultimo->siguiente = nuevo;
            nuevo->siguiente = NULL;
            nuevo->atras = ultimo;
            ultimo = nuevo;
        }else{
            nodo *aux=primero;
            for(i=0; i<x-1; i++)
                aux=aux->siguiente;

            nuevo->siguiente=aux->siguiente;
            (aux->siguiente)->atras=nuevo;
            aux->siguiente=nuevo;
            nuevo->atras=aux;

        }
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void insertarNodoFinal(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void buscarNodo(){
    int posicion=1;
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado en posicion %d\n\n", nodoBuscado, posicion);
				encontrado = 1;
			}
            posicion++;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void buscarNodoPos(){
    int x, i, a=longitud();
    printf("Da la posicion del numero a buscar (Conteo a partir de 1): ");
    scanf(" %d", &x);
    if(primero==NULL)
        printf("La lista esta vacia\n\n");
    else{
        if(x>0 && x<=a){
            nodo *aux=primero;
            for(i=0; i<x-1; i++)
                aux=aux->siguiente;
            printf("\n\nEl valor del nodo con la posicion %d es: %d\n", x, aux->dato);
        }else{
        printf("Nodo no encontrado");
        }
    }
}

void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->dato == nodoBuscado){

				if(actual==primero && actual->siguiente==NULL)
                    primero=NULL;
				else if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");

				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void eliminarNodoPos(){
    int x, i, a=longitud();
    printf("Da la posicion del nodo a eliminar (Conteo a partir de 1): ");
    scanf(" %d", &x);
    nodo *aux=primero;
    if(primero==NULL)
        printf("La lista esta vacia\n\n");
    else{
        if(x==1 && primero->siguiente==NULL)
            primero=NULL;
        else{
            if(x==1){
                (aux->siguiente)->atras=NULL;
                primero=aux->siguiente;
                aux->siguiente=NULL;
                free(aux);
            }else{
                if(x>1 && x<a){
                    for(i=0; i<x-1; i++)
                        aux=aux->siguiente;
                    (aux->atras)->siguiente=aux->siguiente;
                    (aux->siguiente)->atras=aux->atras;
                    free(aux);
                }else{
                    if(x==a){
                        for(i=0; i<x-1; i++)
                            aux=aux->siguiente;
                        ultimo=aux->atras;
                        ultimo->siguiente=NULL;
                        aux->atras=NULL;
                        free(aux);
                    }else{
                        if(x>a)
                            printf("::ERROR: Posicion ingresada supera la cantidad de elementos");
                    }
                }
            }
        }
    }
}


void desplegarLista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

int longitud(){
    int longitud=0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			actual = actual->siguiente;
			longitud++;
		}
	}
return longitud;
}
