#ifndef TABLERO_H
#define TABLERO_H
#include "Piezas.h"
#include "config.h"
#include <iostream>

//con esto inicializaremos el tablero con cada pieza en su posicion original

void InicializarTablero(PiezaMadre* tablero[HEIGHT][WIDTH]);

// y con este lo imprimiremos por pantalla
void ImprimirTablero(PiezaMadre* tablero[HEIGHT][WIDTH]);


#endif // !TABLERO_H
