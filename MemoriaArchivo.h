#pragma once
#include "Funciones.h"
struct Vectorusuarios
{
	jugador* usuarios; // Vector de usuarios
	int usado; // Elementos usados del vector
	int capacidad; // Capacidad del vector
}; typedef struct Vectorusuarios vectorusuarios;
void AgregarUsuario(vectorusuarios*vector);
int contarusuarios();
void cargarbuffer(vectorusuarios* vector);
void guardararchivo(vectorusuarios* vector);
vectorusuarios* crearVectorusuarios();
int crear_archivo_vacio();
void Ver_estadisticas(vectorusuarios* vector, int pos);