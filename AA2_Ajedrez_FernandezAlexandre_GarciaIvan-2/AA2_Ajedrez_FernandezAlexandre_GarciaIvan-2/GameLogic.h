#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "Piezas.h"
#include "config.h"
#include "Tablero.h"

bool MoverPieza(int FilaOrigen, int ColumnaOrigen, int FilaDestino, int ColumnaDestino, PiezaMadre* tablero[HEIGHT][WIDTH]);

void Juego();

#endif // !GAMELOGIC_H

