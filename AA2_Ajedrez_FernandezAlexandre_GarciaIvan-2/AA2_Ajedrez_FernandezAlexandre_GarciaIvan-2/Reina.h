#ifndef REINA_H
#define REINA_H

#include "Piezas.h"
#include "config.h"

//esta clase hereda de PiezaMadre
class Reina : public PiezaMadre {
public:
    Reina(char color, int fila, int columna)
        : PiezaMadre(color, fila, columna) {
    }
    //devuelve Q para las blancas y q para las negras
    char GetSimbolo() const override {
        return (color == 'B') ? 'Q' : 'q';
    }

    bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
        int DiffFila = abs(NuevaFila - fila);
        int DiffColumna = abs(NuevaColumna - columna);

        // Verificar límites del tablero
        if (NuevaFila < 0 || NuevaFila >= HEIGHT || NuevaColumna < 0 || NuevaColumna >= WIDTH) {
            return false;
        }

        // el movimiento de la reina es el movimiento del alfil o el de la torre
        if (DiffFila == DiffColumna || fila == NuevaFila || columna == NuevaColumna) {
            int stepFila = (NuevaFila - fila == 0) ? 0 : (NuevaFila - fila) / abs(NuevaFila - fila);
            int stepColumna = (NuevaColumna - columna == 0) ? 0 : (NuevaColumna - columna) / abs(NuevaColumna - columna);

            int currentFila = fila + stepFila;
            int currentColumna = columna + stepColumna;

            // Verificar todas las casillas en el camino
            while (currentFila != NuevaFila || currentColumna != NuevaColumna) {
                if (currentFila < 0 || currentFila >= HEIGHT || currentColumna < 0 || currentColumna >= WIDTH) {
                    // Fuera de los límites
                    return false; 
                }
                if (tablero[currentFila][currentColumna] != nullptr) {
                    // Hay una pieza bloqueando el camino
                    return false; 
                }
                currentFila += stepFila;
                currentColumna += stepColumna;
            }

            // Verificar la casilla destino
            if (tablero[NuevaFila][NuevaColumna] == nullptr || tablero[NuevaFila][NuevaColumna]->color != color) {
                return true;
            }
        }

        return false;
    }
};

#endif // REINA_H
