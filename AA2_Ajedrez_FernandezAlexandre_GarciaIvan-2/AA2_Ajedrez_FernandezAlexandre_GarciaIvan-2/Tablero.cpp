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
	for (int j = 0; j < WIDTH; j++)
	{
		//Los peones negros
		tablero[1][j] = new Peon('N', 1, j);
		// y los blancos
		tablero[6][j] = new Peon('B', 6, j);
	}

	//vamos a colocar a las blancas
	tablero[7][0] = new Torre('B', 7, 0);
	tablero[7][7] = new Torre('B', 7, 7);
	tablero[7][1] = new Caballo('B', 7, 1);
	tablero[7][6] = new Caballo('B', 7, 6);
	tablero[7][2] = new Alfil('B', 7, 2);
	tablero[7][5] = new Alfil('B', 7, 5);
	tablero[7][3] = new Reina('B', 7, 3);
	tablero[7][4] = new Rey('B', 7, 4);

	//turno de las negras

	tablero[0][0] = new Torre('N', 0, 0);
	tablero[0][7] = new Torre('N', 0, 7);
	tablero[0][1] = new Caballo('N', 0, 1);
	tablero[0][6] = new Caballo('N', 0, 6);
	tablero[0][2] = new Alfil('N', 0, 2);
	tablero[0][5] = new Alfil('N', 0, 5);
	tablero[0][3] = new Reina('N', 0, 3);
	tablero[0][4] = new Rey('N', 0, 4);

}

void ImprimirTablero(PiezaMadre* tablero[HEIGHT][WIDTH]) {
	//imprime las columnas de la A a la H
	std::cout << "  ";
	for (int j = 0; j < WIDTH; j++)
	{
		std::cout << (j+1) << " ";
	}
	std::cout << std::endl;

	
	
	for (int i = 0; i < HEIGHT; i++)
	{
		std::cout << (HEIGHT - i) << " ";

		for (int j = 0; j < WIDTH; j++) {
			if (tablero[i][j] == nullptr)
			{
				//relleno el tablero, este simbolo * representa las casillas vacias (nulltpr)
				std::cout << "* ";
			}
			else
			{
				std::cout << tablero[i][j]->GetSimbolo() << " ";

			}
	}
		std::cout << std::endl;

	}
	std::cout << std::endl;
}