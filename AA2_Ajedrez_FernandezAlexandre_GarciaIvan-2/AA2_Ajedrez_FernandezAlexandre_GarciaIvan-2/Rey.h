#ifndef REY_H
#define REY_H
//incluyo el header donde esta la clase madre, para poder crear a su primogénito... EL REY
#include "Piezas.h"
//creo la clase Rey y indicop que es hija de la clase PiezaMadre

class Rey : public PiezaMadre{

public:
	//vamos construyendo la clase de la misma manera
	Rey(char color, int fila, int columna)
		//estos corchetes finales indican que el constructor nonhace nada mas que crear la clase
		:PiezaMadre(color, fila, columna) {}

	//ahora creamos el metodo para comprovar el movimiento valido del rey y aprovechamos que es virtual para personalizarlo para esta clase
	bool MovimientoValido(int NuevaFila, int NuevaColumna) override {
		//con este metodo comprovamos cuantas casillas hay en medio del movimiento deseado del Rey, si hay mas de una no es un movimiento valido

		int DiffFila = abs(NuevaFila - fila);
		int DiffC
#endif // !REY_H

