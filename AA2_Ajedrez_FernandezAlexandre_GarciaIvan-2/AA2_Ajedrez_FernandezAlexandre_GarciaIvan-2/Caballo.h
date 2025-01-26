#ifndef CABALLO_H
#define CABALLO_H
#include "config.h"

#include "Piezas.h"



//Caballo hereda de la clase PiezaMadre
class Caballo : public PiezaMadre {
public:
	Caballo(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}

	// retorna 'N' para los blancos y 'n' para los negros
	char GetSimbolo() const override {
		return(color == 'B') ? 'N' : 'n';

	}

	//verifica que el caballo realiza un movimiento de L 
	bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
		//Con esto calculo el numero total y absoluto de las casillas que se movera el caballo
		int diffFila = abs(NuevaFila - fila);
		int diffColumna = abs(NuevaColumna - columna);
		// el caballo siempre tendra que mover dos en horizontal y 1 en vertical o al reves, esto comprueba que sea una de esas dos opciones
		bool MovimientoL = (diffFila == 2 && diffColumna == 1) || (diffFila == 1 && diffColumna == 2);
		bool DentroTablero = (NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);
		return MovimientoL && DentroTablero;

	}
	};
#endif // !TORRE_H


