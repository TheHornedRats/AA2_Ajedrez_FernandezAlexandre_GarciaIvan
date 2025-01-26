#ifndef REINA_H
#define REINA_H
#include "Piezas.h"
#include "config.h"
#include <vector>
#include <iostream>
#include <iterator>


class Reina : public PiezaMadre {

public:
	Reina(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}

	char GetSimbolo() const override {
		return(color == 'B') ? 'Q' : 'q';

	}

	bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {

		//La reina puede usar o el movimiento de la torre o la del alfil

		return ((fila== NuevaFila || columna == NuevaColumna) ||
			(abs(NuevaFila - fila) == abs(NuevaColumna - columna))) &&
			(NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);
	}
};

#endif // !REINA_H



