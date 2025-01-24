#ifndef REINA_H
#define REINA_H
#include "Piezas.h"


class Reina : public PiezaMadre {

public:
	Reina(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}


	bool MovimientoValido(int NuevaFila, int NuevaColumna) override {

		//La reina puede usar o el movimiento de la torre o la del alfil

		return ((fila== NuevaFila || columna == NuevaColumna) ||
			(abs(NuevaFila - fila) == abs(NuevaColumna - columna))) &&
			(NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);
	}
};

#endif // !REINA_H



