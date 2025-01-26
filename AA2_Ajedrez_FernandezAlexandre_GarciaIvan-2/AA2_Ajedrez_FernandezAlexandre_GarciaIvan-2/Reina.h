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

		int DiffFila = abs(NuevaFila - fila);
		int DiffColumna = abs(NuevaColumna - columna);

			
        // La Reina se mueve en línea recta (como una Torre) o en diagonal (como un Alfil)
        if (DiffFila == DiffColumna || fila == NuevaFila || columna == NuevaColumna) {
            // Determinar la dirección del movimiento
            int stepFila = (NuevaFila - fila == 0) ? 0 : (NuevaFila - fila) / abs(NuevaFila - fila);
            int stepColumna = (NuevaColumna - columna == 0) ? 0 : (NuevaColumna - columna) / abs(NuevaColumna - columna);

            int currentFila = fila + stepFila;
            int currentColumna = columna + stepColumna;

            // Verificar cada casilla en el camino hacia el destino
            while (currentFila != NuevaFila || currentColumna != NuevaColumna) {
                if (tablero[currentFila][currentColumna] != nullptr) {
                    return false; // Hay una pieza bloqueando el camino
                }
                currentFila += stepFila;
                currentColumna += stepColumna;
            }

            // Verificar la casilla destino
            if (tablero[NuevaFila][NuevaColumna] == nullptr || tablero[NuevaFila][NuevaColumna]->color != color) {
                return true; // Movimiento válido si la casilla está vacía o tiene una pieza enemiga
            }
        }

        return false; // Movimiento inválido
    }
};

#endif // !REINA_H



