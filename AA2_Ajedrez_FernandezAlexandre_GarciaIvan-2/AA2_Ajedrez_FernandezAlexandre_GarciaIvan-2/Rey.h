#ifndef REY_H
#define REY_H
//incluyo el header donde esta la clase madre, para poder crear a su primogénito... EL REY
#include "Piezas.h"
#include "config.h"


//creo la clase Rey y indicop que es hija de la clase PiezaMadre

class Rey : public PiezaMadre {

public:
	//vamos construyendo la clase de la misma manera
	Rey(char color, int fila, int columna)
		//estos corchetes finales indican que el constructor nonhace nada mas que crear la clase
		:PiezaMadre(color, fila, columna) {
	}

	//ahora creamos el metodo para comprovar el movimiento valido del rey y aprovechamos que es virtual para personalizarlo para esta clase
	bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH]) override {
		//con este metodo comprovamos cuantas casillas hay en medio del movimiento deseado del Rey, si hay mas de una no es un movimiento valido

		int DiffFila = abs(NuevaFila - fila);
		int DiffColumna = abs(NuevaColumna - columna);

		//Ahora devolveremos si el movimiento del Rey ha sido valido, para que lo sea se tienen que cumplir dos condiciones
		//Primero que la diferencia entre su posicion tanto en X como Y y la nueva no sea superior a 1, ya que solo se puede mover una casilla
		//Y segundo que no termine fuera de los límites del tablero
		if (DiffFila <= 1 && DiffColumna <= 1)
		{
			if (NuevaFila >= 1 && NuevaFila < HEIGHT && NuevaColumna >= 1 && NuevaColumna < WIDTH) {
				//esto comprueba que el rey no se pueda mover encima de una casilla con una pieza amiga (de su mismo color)
				if (tablero[NuevaFila][NuevaColumna] != nullptr && tablero[NuevaFila][NuevaColumna] -> color == color)
				{
					return false;

				}
				return !EstaEnJaque(NuevaFila, NuevaColumna, tablero, color);

		}

		}
		return false;
	}
	//este metodo comprueva antes de moverse si la casilla en la que se va a ir el rey esta amenazada. Para hacerlo revisa todo el tablero y escoge el metodo de las fichas del color contrario para calcular si desde sus casillas actuales seria legal un movimiento a la casilla donde esta iendo el rey. Dicho de otra menera, revisar el Jaque
	bool EstaEnJaque(int fila, int columna, PiezaMadre* tablero[HEIGHT][WIDTH], char colorRey) {
		for (int i = 1; i < HEIGHT; i++)
		{
			for (int j = 1; j < WIDTH; j++) {
				if (tablero[i][j] != nullptr && tablero[i][j]->color != colorRey)
				{
					if (tablero[i][j]->MovimientoValido(fila, columna, tablero)) {
						return true;

				}

				}
		}

		}
		return false;

	}

};


#endif // !REY_H

