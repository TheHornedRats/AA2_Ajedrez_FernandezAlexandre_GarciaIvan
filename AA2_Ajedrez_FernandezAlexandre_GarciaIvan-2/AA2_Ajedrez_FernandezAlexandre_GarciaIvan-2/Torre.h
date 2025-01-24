#ifndef TORRE_H
#define TORRE_H
#include "Piezas.h"
#include "config.h"

class Torre : public PiezaMadre {
public:
	Torre(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {}

	bool MovimientoValido(int NuevaFila, int NuevaColumna) override {
		//Basicament el que la torre mira es si la columna o la fila segueix sent la mateixa al final del moviment
		//Despres, com totes les fitxes, comprova que segueixi dins del taulell

		return (fila == NuevaFila || columna == NuevaColumna) &&
			(NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);

	}
};
#endif // !TORRE_H

