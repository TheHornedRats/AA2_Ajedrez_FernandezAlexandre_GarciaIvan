#ifndef PEON_H
#define PEON_H
#include "Piezas.h"
#include "config.h"


class Peon : public PiezaMadre {

public:
	Peon(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}
	char GetSimbolo() const override {
		return(color == 'B') ? 'P' : 'p';

	}

	bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
		//en esta logica se da por echo que los peones siempre avanzaran en linia recta, a menos que capturen pieza
		//los peones blancos siempre iran hacia arriba con lo cual sus filas decreceran siempre y para los negros al reves
		//si el peon se encuentra en su casilla inicial tambien se dara como valido un movimiento de dos casillas
		if (columna == NuevaColumna){
			if (color == 'B')
			{
				//aquesta part serveix perque en la posicio incial els peon puguin moure dues caselles
				return (NuevaFila == fila - 1 || (fila == 6 && NuevaFila == fila - 2)) &&
					tablero[NuevaFila][NuevaColumna] == nullptr; //amb això m'aseguro que només pot avançar endevant si la casella està buida
			}
			else
			{
				return (NuevaFila == fila + 1 || (fila == 2 && NuevaFila == fila + 2)) &&
					tablero[NuevaFila][NuevaColumna] == nullptr; 
			}
		}

		if (abs(NuevaColumna - columna) ==1 ) 
		{
			if (color == 'B') {
				return NuevaFila == fila - 1 &&
					tablero[NuevaFila][NuevaColumna] != nullptr &&
					tablero[NuevaFila][NuevaColumna]->color != color;

			}
			else
			{
				return NuevaFila == fila + 1 &&
					tablero[NuevaFila][NuevaColumna] != nullptr &&
					tablero[NuevaFila][NuevaColumna]->color != color;

			}

		}

		

		return false;

	}
};

#endif // !PEON_H


