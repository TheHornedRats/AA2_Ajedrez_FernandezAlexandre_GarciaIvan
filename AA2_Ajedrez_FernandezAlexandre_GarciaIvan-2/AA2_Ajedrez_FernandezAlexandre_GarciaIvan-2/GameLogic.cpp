#include "GameLogic.h"
#include <iostream>>
#include "config.h"

bool MoverPieza(int FilaOrigen, int ColumnaOrigen, int FilaDestino, int ColumnaDestino, PiezaMadre* tablero[HEIGHT][WIDTH]) {
	//este es el metodo para mover las piezas, lo primero que hara es comprovar que en la casilla que selecciones haya una pieza que puedas mover.
	if (tablero[FilaOrigen][ColumnaOrigen] == nullptr)
	{
		std::cout << "No hay ninguna pieza que puedas mover en esta casilla. \n";
		return false;
	}
//ahora vamos a reconocer que pieza es la que se va a mover

	PiezaMadre* pieza = tablero[FilaOrigen][ColumnaOrigen];

	//y ahora comprovamos si la pieza seleccionada se pude mover a la casilla escogida
	if (!pieza->MovimientoValido(FilaDestino, ColumnaDestino, tablero))
	{
		std::cout << "Este movimiento no es valido para esta pieza. \n";
		return false;
	}

//Ahora comprovaremos si en la casilla hay una pieza (no hace falta comprovar si es aliada porque eso ya lo hace MovimientoValido

	if (tablero[FilaDestino][ColumnaDestino] != nullptr) 
	{ //si hay una ficha vamos a liberar la memoria convirtiendolo en nullptr
		delete tablero[FilaDestino][ColumnaDestino];
		tablero[FilaDestino][ColumnaDestino] = nullptr;
		std::cout << "Pieza capturada. \n";


	}
	//una vez liberada la memoria vamos a mover nuestra pieza ahi
	tablero[FilaDestino][ColumnaDestino] = pieza;
	
	//una vez nos movemos liberamos la memoria de la casilla donde estabamos
	tablero[FilaOrigen][ColumnaOrigen] = nullptr;
	//ahora actualizaremos la posicion de nuestra pieza en su clase
	pieza->fila = FilaDestino;
	pieza->columna = ColumnaDestino;

	return true;


}