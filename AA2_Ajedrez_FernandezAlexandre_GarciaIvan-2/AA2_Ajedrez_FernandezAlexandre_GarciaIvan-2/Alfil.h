#ifndef ALFIL_H
#define ALFIL_H
#include "Piezas.h"
#include "config.h"

class Alfil : public PiezaMadre {

public:
	Alfil(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}

	char GetSimbolo() const override {
		return(color == 'B') ? 'B' : 'b';

	}

    bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
        int DiffFila = abs(NuevaFila - fila);
        int DiffColumna = abs(NuevaColumna - columna);

        if (DiffFila == DiffColumna) {
            int stepFila = (NuevaFila - fila) / abs(NuevaFila - fila);
            int stepColumna = (NuevaColumna - columna) / abs(NuevaColumna - columna);

            int currentFila = fila + stepFila;
            int currentColumna = columna + stepColumna;

            while (currentFila != NuevaFila || currentColumna != NuevaColumna) {
                if (tablero[currentFila][currentColumna] != nullptr) {
                    return false; // Hay una pieza bloqueando el camino
                }
                currentFila += stepFila;
                currentColumna += stepColumna;
            }

            if (tablero[NuevaFila][NuevaColumna] == nullptr || tablero[NuevaFila][NuevaColumna]->color != color) {
                return true; // Movimiento válido
            }
        }

        return false;
    }

};

#endif // !ALFIL_H


