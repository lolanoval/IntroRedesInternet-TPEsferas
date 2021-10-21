#include "Funciones.h"

#define _CRT_SECURE_NO_WARNINGS 



//LISTO
int**CrearMatriz(int cfila, int ccol)//Crea una matriz segun el gusto del usuario
{
	int** matriz = NULL;
	matriz = new int*[cfila];
	for (int j = 0; j < ccol; j++) {
			matriz[j] = new int[ccol];
	}

	return matriz;
}
//LISTO
int** LlenarMatriz(int** matriz, int ccol, int cfila)//Lleno matriz con un valor
{
	int fila, col;

	for (fila = 0; fila < cfila; fila++)
	{
		for (col = 0; col < ccol; col++)
		{
			matriz[fila][col] = 1; //se va llenando cada lugar de la matriz con 1 esfera (igual a 1)
		}
	}

	return matriz;
}

int QuedanEsferasEnFila(int** matriz, int filaelegida, int ccol)
{
	int ContadorEsferas = 0;
	for (int col = 0; col < ccol; col++)
	{
		if (matriz[filaelegida][col] == 1)
		{
			ContadorEsferas++; //cuenta 1 si hay una esfera en esa columna 
		}
	}
	return ContadorEsferas;
}

int NumeroRandomFila(int cfila)
{
	//en el main hacer un do/while con QuedanEsferasEnFila != 0
	int filaelegida = rand() % cfila;

	return filaelegida;
}

int NumeroRandomEsfera(int cantesferas)
{
	//cant de esferas se calcula en el main, deberia ser mayor o igual a 1
	//si hay una ultima fila en juego, saca todas menos 1
	int cesfera = 1 + rand() % cantesferas;
	return cesfera;
}
int CorroborarFilaElegida(int cantesferasenfila) //la cant de esferas en fila se llama con la función de dicho nombre con la fila elegida
{
	if (cantesferasenfila =! 0)
		return 1;
	else
		return 0; //si devuelve 1 la fila puede ser elegida, sino no
}


int ComprobarUltEsfera(int** matriz, int ccol, int cfila) //devuelve la cant de esferas totales
{
	int CantEsferas = 0;
	for (int fila = 0; fila < cfila; fila++)
	{
		for (int col = 0; col < ccol; col++)
		{
			if (matriz[fila][col] == 1)
				CantEsferas++;
		}
	}
	return CantEsferas;
}


void Juego(int** matriz, int ccol, int cfila, Jugador jugador1, Jugador jugador2)//saque el jugador 2 pq sin importar cual sea la opcion los dos van a tener el mismo tipo
{
	int filaelegida_r = 0, esferaselegidas_r = 0;
int filaelegida = 0, esferaselegidas = 0;
//el jugador es la computadora
if (jugador1.tipo == compu || jugador2.tipo == compu) {
	//se elige la fila random
	filaelegida_r = (1 + rand() % (cfila - 2));
	int comprobarfila_r = ElegirFila(matriz, filaelegida_r, cfila, ccol);
	if (comprobarfila_r == 0)
	{
		do
		{
			filaelegida_r = (1 + rand() % (cfila - 1));
		} while (comprobarfila_r == 0);
	}
	printf("\nLa fila elegida es: %d", filaelegida_r);


	//se elige la cantidad de esferas random
	int maxaquitar_r = QuedanEsferasEnFila(matriz, filaelegida, ccol);
	int esferaselegidas_r = (1 + rand() % (maxaquitar_r - 2));
	printf("\nLa cantidad de esferas elegidas son: %d", esferaselegidas_r);
	//se quitan las esferas de esa fila (aca como devuelve la matriz habría que ver de que se sobreescriba la matriz, no se si así esta bien)
	matriz = QuitarEsferas(matriz, filaelegida_r, esferaselegidas_r, ccol);

	}
	if (jugador1.tipo == persona  || jugador2.tipo == persona) {
		//el jugador elige la fila
		printf("\nElija fila a quitar esferas (hasta fila %d): ", cfila);
		scanf_s("%d", &filaelegida);
		int comprobarfila = ElegirFila(matriz, filaelegida, cfila, ccol);
		if (comprobarfila == 0)
		{
			do {
				printf("\nError. Elija fila a quitar esferas (hasta fila %d): ", cfila);
				scanf_s("%d", &filaelegida);
				comprobarfila = ElegirFila(matriz, filaelegida, cfila, ccol);
			} while (comprobarfila == 0);
		}
		//el jugador elige la cantidad de esferas
		int maxaquitar=QuedanEsferasEnFila(matriz,filaelegida,ccol);
		printf("\nElija cantidad de esferas a quitar (max %d): ", maxaquitar);
		int maxaquitar = QuedanEsferasEnFila(matriz, filaelegida, ccol);
		scanf_s("%d", &esferaselegidas);
		int comprobaresferas = ElegirCantidadEsferas(esferaselegidas, maxaquitar);
		if(comprobaresferas == 0)
		{
			do {
				printf("\nError. Elija cantidad de esferas a quitar (max %d): ", maxaquitar);
				scanf_s("%d", &esferaselegidas);
				comprobaresferas = ElegirCantidadEsferas(esferaselegidas, maxaquitar);
			} while (comprobaresferas == 0);
		}

		//se quitan las esferas de esta fila.
		matriz = QuitarEsferas(matriz, filaelegida, esferaselegidas, ccol);

		

	}
}


void Turno(int** matriz, int ccol, int cfila, Jugador jugador1, Jugador jugador2)
{
	int CantEsferas = ComprobarUltEsfera(matriz, ccol, cfila);
	int turno;
	do
	{
		if (turno == 1) {
			Juego(matriz, ccol, cfila, jugador1, jugador2);//juega el jugador 1
			if (ComprobarUltEsfera(matriz, ccol, cfila) == 1) {
				jugador1.partidas++;
				jugador1.victorias++;
				jugador2.partidas++;
				turno = 0;
			}
			turno = 2;
		}
		if (turno == 2) {
			Juego(matriz, ccol, cfila, jugador1, jugador2);//juega el jugador 2
			
			if (ComprobarUltEsfera(matriz, ccol, cfila) == 1) {
				if (jugador2.tipo != compu) {
					jugador2.partidas++;
					jugador2.victorias++;
					jugador1.partidas++;
				}
				else {
					jugador1.partidas++;
				}
				turno = 0;
			}
		}

	} while (turno !=0);

}
void AgregarUsuario(vectorusuarios*vector) //agrega un usuario al vector
{
	int i;
	jugador *usuarios;
	if (vector->usado == vector->capacidad) { // Redimensionar el vector
		vector->capacidad *= 2;  //nueva capacidad es el doble de la anterior


/////////////ARCHIVOS Y MEMORIA DINÁMICA
		usuarios = (jugador*)malloc((vector->capacidad)*sizeof(jugador));  //nuevo arreglo de jugadores con el doble de capacidad
		for (i = 0; i < vector->usado; i++)  //copia los datos al nuevo arreglo
			usuarios[i] = vector->usuarios[i];
		free(vector->usuarios);  //libera el vector sin espacio
		vector->usuarios = usuarios;  //iguala los vectores
	}
	printf("\nNombre de usuario a agregar: ");
	getchar();
	gets_s(vector->usuarios[vector->usado].nombre, 20);  //recibe el nombre del usuario
	printf("\nContrasenia: ");
	gets_s(vector->usuarios[vector->usado].contrasenia, 25);  //recibe la contraseña
	vector->usuarios[vector->usado].partidas = 0;  //número de partidas jugadas es cero
	vector->usuarios[vector->usado].victorias = 0;  //número de partidas ganadas es cero
	vector->usado++;  //suma uno a la cantidad de usuarios
}
int contarusuarios()  //abre el archivo y cuenta la cantidad de datos
{
	FILE*fp = NULL;
	fp = fopen("usuarios.dat", "rb");  //lo abre como lectura
	if (fp == NULL)  //si no puede abrir el archivo retorna menos uno
	{
		return -1;
	}
	fseek(fp, 0, SEEK_END);  //envía el índice al fina del archivo
	long int indice = ftell(fp);  //cantidad de bytes totales del archivo
	fclose(fp);  //cierra el archivo
	return (indice / sizeof(jugador));  //devuelve la cantidad de datos
}
void cargarbuffer(vectorusuarios*vector)  //llena el vector de usuarios 
{
	FILE*fp = NULL;
	fp = fopen("usuarios.dat", "rb");  //abre el archivo como lectura
	fread(vector->usuarios, sizeof(jugador), vector->usado, fp);  //copia los elementos del archivo al vector de usuarios
	fclose(fp);  //cierra el archivo
}
void guardararchivo(vectorusuarios* vector)  //sobreescribe el archivo
{
	FILE*fp = NULL;
	fp = fopen("usuarios.dat", "w+b");  //lo abre como escritura
	fwrite(vector->usuarios, sizeof(jugador), vector->usado, fp);  //escritura de datos
	fclose(fp);  //cerrado del archivo
}

vectorusuarios* crearVectorusuarios()  // Creación del vector que contiene al vector de usuarios, su cantidad de usados y su capacidad
{
	vectorusuarios* vusuarios = NULL;
	vusuarios = (vectorusuarios*)malloc(sizeof(vectorusuarios));  //creación con memoria dinámica
	vusuarios->usado = contarusuarios();  //cantidad ocupada es calculada por la función de contar usuarios
	if (vusuarios->usado == -1)  //de haber retornado menos uno, crea al archivo vacío 
	{
		crear_archivo_vacio();  //abre un archivo, lo crea si no existe, y lo cierra
		vusuarios->usado = 0; //como es un archivo nuevo, lo inicializa con cero usuarios
		vusuarios->capacidad = 2;  //empieza con capacidad para 2 usuarios
		vusuarios->usuarios = NULL;
		vusuarios->usuarios = (jugador*)malloc(2 * (sizeof(jugador)));  //vector de jugadores creado con capacidad para dos usuarios
		return vusuarios;  //retorna el vector
	}
	else
	{
		vusuarios->capacidad = vusuarios->usado;
		vusuarios->usuarios = NULL;
		vusuarios->usuarios = (jugador*)malloc((vusuarios->capacidad) * sizeof(jugador));  //capacidad para cuantos usuarios hayan
		return vusuarios;  //retorna el vector
	}
}
int crear_archivo_vacio() //crea un archivo vacío
{
	FILE *fp;
	fp = fopen("usuarios.dat", "w+b");  //abre para escritura y lo crea si no existe
	if (fp == NULL)
		return -1;//error al crear el archivo
	fclose(fp);  //lo cierra
	return 0;
}
void Ver_estadisticas(vectorusuarios* vector, int pos)  //imprime las estadísticas en pantalla
{//imprime las estadísticas del jugador
	printf("\n--SUS ESTADISTICAS--\n\n");
	printf("Partidas jugadas: %d\n", vector->usuarios[pos].partidas);//partidas jugadas
	printf("Victorias: %d\n\n", vector->usuarios[pos].victorias);//partidas ganadas
	printf("---------------------");
	
}
int ElegirCantidadEsferas(int cantesferas, int maxesferas) //max esferas en fila viene de quedanesferasenfila
{
	if (cantesferas > maxesferas || cantesferas == 0)
		return 0;
	else
		return cantesferas;
	//si devuelve 0, es error y el usuario debe elegir otro número de esferas
}
int ElegirFila(int** matriz, int filaelegida, int maxfilas, int ccol)
{
	int esferasenfila = QuedanEsferasEnFila(matriz, filaelegida, ccol); //modifique esto para que devuelva tmbn error si hay cero esferas en esa fila
	if (filaelegida > maxfilas || esferasenfila == 0)
		return 0;
	else
		return 1; //0 es error, 1 es todo ok
}
int TipoJugador(Jugador jugador) {
	return jugador.tipo;
}

int** QuitarEsferas(int**matriz,int filaelegida, int esferasaquitar,int ccol)
{
	int esferasquitadas = 0;
	for(int i=0; i<ccol; i++)
	{
		if (esferasquitadas != esferasaquitar && matriz[filaelegida][i] == 1) 
		{
			matriz[filaelegida][i] = 0;
			esferasquitadas++;
		}
		
	}
	return matriz; //aca cambie un poco el codigo pq solo serviria para las primeras esferas y no para las que siguen si se sacan despues
}