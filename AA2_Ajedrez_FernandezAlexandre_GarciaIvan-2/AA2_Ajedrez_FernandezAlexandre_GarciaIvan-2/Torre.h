#ifndef TORRE_H
#define TORRE_H
#include "config.h"
#include "Piezas.h"



//hereda de la clase PîezaMadre
class Torre : public PiezaMadre {
public:
	Torre(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {}

	char GetSimbolo() const override {
		return(color == 'B') ? 'R' : 'r';

	}



    //el movimento de la torre no cuenta el numero de casillas, se asegura de que solo se mueve en un eje y de que no pasa por encima de ninguna pieza
    //tambien revisa que no termine encima de ninguna casilla amiga
    bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
        if (fila == NuevaFila || columna == NuevaColumna) {
            int diffFila = NuevaFila - fila;
            int diffColumna = NuevaColumna - columna;

            int stepFila = (diffFila == 0) ? 0 : diffFila / abs(diffFila);
            int stepColumna = (diffColumna == 0) ? 0 : diffColumna / abs(diffColumna);


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

