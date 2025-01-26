#include "Tablero.h"
#include "config.h"
#include "Peon.h"
#include "Caballo.h"
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"



void InicializarTablero(PiezaMadre* tablero[HEIGHT][WIDTH]) {
	//primero llenaremos todas las casillas con nullptr para marcarlas como vacias
	//despues recorreremos el tablero añadiendo cada ficha a la casilla donde deberia
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			tablero[i][j] = nullptr;
		}
	}

	//primero colocare los peones 
	for (int j = 1; j < 8; j++)
	{
		//Los peones negros
		tablero[2][j] = new Peon('N', 2, j);
		// y los blancos
		tablero[7][j] = new Peon('B', 7, j);
	}

}