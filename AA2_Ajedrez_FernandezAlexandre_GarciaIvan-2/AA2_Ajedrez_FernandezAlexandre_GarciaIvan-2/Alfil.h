#ifndef ALFIL_H
#define ALFIL_H
#include "Piezas.h"
#include "config.h"



//La clase alfil hereda de su clase madre
class Alfil : public PiezaMadre {

public:
	Alfil(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}
    //esto lo que hace es retornar B o b dependiendo del color del alfil
	char GetSimbolo() const override {
		return(color == 'B') ? 'B' : 'b';

	}
    //esta funcion revisa que el movimiento del alfil sea valido, los puntos clave son que mueva en diagonal, que no salte sobre otras piezas y que termine el movimiento en una casilla vacia o con una ficha enemiga

    bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
        int DiffFila = abs(NuevaFila - fila);
        int DiffColumna = abs(NuevaColumna - columna);

        if (DiffFila == DiffColumna) {
            int diffFila = NuevaFila - fila;
            int diffColumna = NuevaColumna - columna;

            int stepFila = (diffFila == 0) ? 0 : diffFila / abs(diffFila);
            int stepColumna = (diffColumna == 0) ? 0 : diffColumna / abs(diffColumna);


            int currentFila = fila + stepFila;
            int currentColumna = columna + stepColumna;

            while (currentFila != NuevaFila || currentColumna != NuevaColumna) {
                if (tablero[currentFila][currentColumna] != nullptr) {
                    // Hay una pieza bloqueando el camino
                    return false; 
                }
                currentFila += stepFila;
                currentColumna += stepColumna;
            }

            if (tablero[NuevaFila][NuevaColumna] == nullptr || tablero[NuevaFila][NuevaColumna]->color != color) {
                //Movimiento válido
                return true;  
            }
        }

        return false;
    }

};

#endif // !ALFIL_H


