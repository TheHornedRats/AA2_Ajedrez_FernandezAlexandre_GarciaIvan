#ifndef ALFIL_H
#define ALFIL_H
#include "Piezas.h"
#include "config.h"

class Alfil : public PiezaMadre {

public:
	Alfil(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}


	bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
		//Aquest moviment restringeix el moviment del alfil en diagonal pero sense fixarse en el total de caselles que es mou

		return(abs(NuevaFila - fila) == abs(NuevaColumna - columna)) &&
			(NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);
	}
};

#endif // !ALFIL_H


