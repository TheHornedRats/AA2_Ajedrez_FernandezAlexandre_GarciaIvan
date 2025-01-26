#ifndef TORRE_H
#define TORRE_H
#include "config.h"
#include "Piezas.h"
class Torre : public PiezaMadre {
public:
	Torre(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {}

	char GetSimbolo() const override {
		return(color == 'B') ? 'R' : 'r';

	}




    bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
        if (fila == NuevaFila || columna == NuevaColumna) {
            int stepFila = (NuevaFila - fila == 0) ? 0 : (NuevaFila - fila) / abs(NuevaFila - fila);
            int stepColumna = (NuevaColumna - columna == 0) ? 0 : (NuevaColumna - columna) / abs(NuevaColumna - columna);

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
#endif // !TORRE_H

