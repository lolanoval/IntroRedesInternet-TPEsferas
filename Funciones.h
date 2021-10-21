#pragma once

#include <iostream>
#include <stdio.h>
#include "stdlib.h"

typedef enum{compu =0, persona=1}tipo;
struct Jugador
{
	char nombre[20];
	char contrasenia[20];
	tipo tipo; //0:compu - 1:persona
	int tipojuego; //0:solitario 1:duo
	int victorias; 
	int partidas;

};
typedef struct Jugador jugador;
struct Vectorusuarios
{
	jugador* usuarios; // Vector de usuarios
	int usado; // Elementos usados del vector
	int capacidad; // Capacidad del vector
}; typedef struct Vectorusuarios vectorusuarios;

int** CrearMatriz(int ccol, int cfila);
int** LlenarMatriz(int** matriz, int ccol, int cfila);
int QuedanEsferasEnFila(int** matriz, int filaelegida, int ccol);
int NumeroRandomFila(int cfila);
int NumeroRandomEsfera(int cantesferas);
int CorroborarFilaElegida(int cantesferasenfila);
int ElegirFila(int** matriz, int filaelegida, int maxfilas, int ccol); //compruba si la fila elegida está dentro del rango
int ElegirCantidadEsferas(int cantesferas, int maxesferas); //max esferas viene de quedanesferasenfila
int ComprobarUltEsfera(int** matriz, int ccol, int cfila); //comprueba si el jugador le deja la última esfera al siguiente
void Turno(int** matriz, int ccol, int cfila, Jugador jugador1, Jugador jugador2); 
void Juego(int** matriz, int ccol, int cfila, Jugador jugador1, Jugador jugador2); 
int** QuitarEsferas(int** matriz, int filaelegida, int esferasaquitar, int ccol);

/// ARCHIVOS Y MEMORIA DINAMICA
void AgregarUsuario(vectorusuarios*vector);
int contarusuarios();
void cargarbuffer(vectorusuarios* vector);
void guardararchivo(vectorusuarios* vector);
vectorusuarios* crearVectorusuarios();
int crear_archivo_vacio();
void Ver_estadisticas(vectorusuarios* vector, int pos);