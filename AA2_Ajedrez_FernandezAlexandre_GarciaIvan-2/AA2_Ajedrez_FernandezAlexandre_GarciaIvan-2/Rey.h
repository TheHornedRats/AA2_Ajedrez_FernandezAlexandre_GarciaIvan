#ifndef REY_H
#define REY_H
//incluyo el header donde esta la clase madre, para poder crear a su primogénito... EL REY
#include "Piezas.h"
//creo la clase Rey y indicop que es hija de la clase PiezaMadre

class Rey : public PiezaMadre {

public:
	//vamos construyendo la clase de la misma manera
	Rey(char color, int fila, int columna)
		//estos corchetes finales indican que el constructor nonhace nada mas que crear la clase
		:PiezaMadre(color, fila, columna) {
	}

	//ahora creamos el metodo para comprovar el movimiento valido del rey y aprovechamos que es virtual para personalizarlo para esta clase
	bool MovimientoValido(int NuevaFila, int NuevaColumna) override {
		//con este metodo comprovamos cuantas casillas hay en medio del movimiento deseado del Rey, si hay mas de una no es un movimiento valido

		int DiffFila = abs(NuevaFila - fila);
		int DiffColumna = abs(NuevaColumna - columna);

		//Ahora devolveremos si el movimiento del Rey ha sido valido, para que lo sea se tienen que cumplir dos condiciones
		//Primero que la diferencia entre su posicion tanto en X como Y y la nueva no sea superior a 1, ya que solo se puede mover una casilla
		//Y segundo que no termine fuera de los límites del tablero
		return (DiffFila <= 1 && DiffColumna <= 1) &&
			(NuevaFila >= 0 && NuevaFila < 8) &&
			(NuevaColumna >= 0 && NuevaColumna < 8);
	}
};

#endif // !REY_H

