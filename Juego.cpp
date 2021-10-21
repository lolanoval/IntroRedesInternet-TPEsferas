#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
#include "MemoriaArchivo.h"
#include <iostream>
typedef enum { SALIR, INGRESAR, CREAR} OPCION;
#include <string>
#include "Funciones.h"


int main()
{
	/*int opcion, ccol, cfilas = 0;
	printf("Ingrese el modo de juego: \n Opcion 1: Solitario \n Opcion 2: Duo \n Opcion: ");
	scanf_s("%d", &opcion);
	while (opcion != 1 && opcion != 2) {
		printf("Error. Ingrese una opcion valida \n Opcion:");
		scanf_s("%d", &opcion);
	}
	if (opcion == 1)
	{
		char nombre1[20];
		Jugador jugador1{};
		Jugador jugador2{};
		jugador1.tipojuego == 0;
		jugador2.tipo == 0; //aca el jugador2 es una computadora
		LlenarNombre(jugador1, 1);
		jugador1.tipo == 1;

	printf("\n Indique la cantidad de columnas: ");
	scanf_s("%d", &ccol);
	printf("\n Indique la cantidad de filas: ");
	scanf_s("%d", &cfilas);
	int**matriz2 = CrearMatriz(ccol, cfilas);
	int ** matriz1 = LlenarMatriz(matriz2, ccol, cfilas);
	Juego(matriz1, ccol, cfilas, jugador1); //ezequiel
	}
	if (opcion == 2)
	{
		char nombre1[20], nombre2[20];
		Jugador jugador1{};
		Jugador jugador2{};
		jugador1.tipo == 1;
		jugador2.tipo == 1;
		LlenarNombre(jugador1, 1);
		LlenarNombre(jugador2, 2);
		jugador1.tipojuego == 1;
		jugador2.tipojuego == 1;

	printf("\n Indique la cantidad de columnas: ");
	scanf_s("%d", &ccol);
	printf("\n Indique la cantidad de filas: ");
	scanf_s("%d", &cfilas);
	int**matriz2 = CrearMatriz(ccol, cfilas);
	int ** matriz1 = LlenarMatriz(matriz2, ccol, cfilas);
	printf("\n Pulse enter para comenzar el juego");

	Juego(matriz1, ccol, cfilas, jugador1);
	}

}*/
	int main()
	{
		srand((time)NULL); //semilla random
		vectorusuarios* v = NULL;
		v = crearVectorusuarios(); //crea el vector que almacena a los usuarios, su cantidad ocupada y su capacidad !!
		cargarbuffer(v); //llena al vector de usuarios con el archivo 
		int  opc;  //opción del menu bienvenida
		int i = 0;  //iterador
		do {  //menu bienvenida
			printf("--------------------- MENU ---------------------");
			printf("\n1) Iniciar sesion");
			printf("\n2) Crear usuario");
			printf("\n0) Salir\n");
			printf("------------------------------------------------\n");
			scanf("%d", &opc);  //leer opción
			switch (opc)
			{
			case INGRESAR:
				printf("\nIngresar usuario: "); //pide el usuario a ingresar
				Jugador auxil; //era usuario y lo cambie por Jugador
				int pos=0;
				getchar();
				gets(auxil.nombre, 25);  //lee el usuario
				for (i = 0; i < v->usado; i++)  //bucle que recorre el vector de usuarios, frena si lo encuentra y el iterador permite ubicarlo en el vector
				{
					if (strcmp(v->usuarios[i].nombre, auxil.nombre) == 0)  //si lo encuentra frena el bucle
					pos=i;//voy guardando posicion del usuario en lista
						break;
				}
				if (i == v->usado)
					printf("El usuario no existe.\n");  //si el usuario no existe, la posición del iterador será la misma que la cantidad de usuarios en el vector
				else
				{
					printf("\nUsuario  %s, ingrese su contrasenia:", v->usuarios[i].nombre);  //lee la contraseña
					gets(auxil.contrasenia, 25);  //pide la contraseña
					if (strcmp(auxil.contrasenia, v->usuarios[i].contrasenia) == 0) //compara la contraseña ingresada con la del usuario en el vector
					{
						int opc2;  //menu de juego
						printf("\n1) Jugar");
						printf("\n2) Ver estadisticas");
						printf("\n3) Salir\n");
						scanf("%i", &opc2); //lee la opción elegida

						while (opc2 == 1 || opc2 == 2) {
							if (opc2 == 1)        //si es uno, llama a la función juego y vuelve a imprimir el menu de juego
								Juego(v, i);  //llama a la funcion juego //funcion juego, recibe el vector del usuario ingresado y su posición en el vector
							else if (opc2 == 2)    //si la opción es 3, imprime las estadísticas del jugador
								Ver_estadisticas(v, i);//Muestra las estadísticas del jugador. Recibe el vector de usuarios y su posición en el vector
							printf("\n1) Jugar");
							printf("\n2) Ver estadisticas");
							printf("\n3) Salir\n");
							scanf("%i", &opc2); //lee la opción elegida
						} //si no es uno o 3, vuelve al menu principal
					}
					else
					{
						printf("Contrasenia incorrecta.\n");  //si no coincide el la contraseña ingresada con la almacenada, no inicia sesión
					}
					break;
			case CREAR:  //agregar un usuario nuevo
				AgregarUsuario(v);  //caso contrario, la función agregarusuario lo incorpora al vector
				break;
			case SALIR:  //sale del bucle
				break;
			default:
				printf("\nOpcion invalida.");  //caso de opción incorrecta, imprime la invalidez de la misma
				break;
				}
			}
		} while (opc != SALIR);  //se repite mientras el usuario no presione la opción de salir
		guardararchivo(v);  //al finalizar se sobreescribe el archivo con la información actualizada
		free(v->usuarios);  //libera el vector dinámico de los usuarios
		free(v);  //se libera la memoria
		v = NULL;
		return 0;
	}