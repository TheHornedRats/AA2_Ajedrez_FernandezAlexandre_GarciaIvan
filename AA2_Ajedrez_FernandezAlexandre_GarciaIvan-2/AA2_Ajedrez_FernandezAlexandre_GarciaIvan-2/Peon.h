#ifndef PEON_H
#define PEON_H
#include "Piezas.h"


class Peon : public PiezaMadre {

public:
	Peon(char color, int fila, int columna)
		: PiezaMadre(color, fila, columna) {
	}


	bool MovimientoValido(int NuevaFila, int NuevaColumna) override {
		//en esta logica se da por echo que los peones siempre avanzaran en linia recta, a menos que capturen pieza
		//los peones blancos siempre iran hacia arriba con lo cual sus filas decreceran siempre y para los negros al reves
		//si el peon se encuentra en su casilla inicial tambien se dara como valido un movimiento de dos casillas
		if (columna == NuevaColumna){
			if (color == 'B')
			{
				return (NuevaFila == fila - 1 || (fila == 6 && NuevaFila == fila - 2)) &&
					(NuevaFila >= 0 && NuevaFila < 8);
			}
		}
		if (abs(NuevaColumna - columna) ==1 ) 
		{
			if (color == 'B') { return NuevaFila == fila - 1; }
			else
			{
				return NuevaFila == fila + 1;

			}

		}

		

		return false;

	}
};

#endif // !PEON_H


