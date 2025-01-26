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

	//vamos a colocar a las blancas
	tablero[8][1] = new Torre('B', 8, 1);
	tablero[8][8] = new Torre('B', 8, 8);
	tablero[8][2] = new Caballo('B', 8, 2);
	tablero[8][7] = new Caballo('B', 8, 7);
	tablero[8][3] = new Alfil('B', 8, 3);
	tablero[8][6] = new Alfil('B', 8, 6);
	tablero[8][4] = new Reina('B', 8, 4);
	tablero[8][5] = new Rey('B', 8, 5);

	//turno de las negras

	tablero[1][1] = new Torre('N', 1, 1);
	tablero[1][8] = new Torre('N', 1, 8);
	tablero[1][2] = new Caballo('N', 1, 2);
	tablero[1][7] = new Caballo('N', 1, 7);
	tablero[1][3] = new Alfil('N', 1, 3);
	tablero[1][6] = new Alfil('N', 1, 6);
	tablero[1][4] = new Reina('N', 1, 4);
	tablero[1][5] = new Rey('N', 1, 5);

}

void ImprimirTablero(PiezaMadre* tablero[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			if (tablero[i][j] == nullptr)
			{
				//relleno el tablero, este simbolo * representa las casillas vacias (nulltpr)
				std::cout << "*";
			}
			else
			{
				std::cout << tablero[i][j]->GetSimbolo() << " ";

			}
	}
		std::cout << std::endl;

	}
}