#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "Piezas.h"
#include "config.h"

bool MoverPieza(int FilaOrigen, int ColumnaOrigen, int FilaDestino, int ColumnaDestino, PiezaMadre* tablero[HEIGHT][WIDTH]);

#endif // !GAMELOGIC_H

