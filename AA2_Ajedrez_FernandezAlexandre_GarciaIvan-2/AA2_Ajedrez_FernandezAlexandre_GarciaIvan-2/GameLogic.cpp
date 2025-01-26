#include "GameLogic.h"
#include <iostream>
#include "config.h"
#include "Rey.h"

void limpiarTablero(PiezaMadre* tablero[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			if (tablero [i][j] != nullptr)
			{
				delete tablero[i][j];
				tablero[i][j] = nullptr;


			}
	}

	}
}



void Juego() {
	//esta es la funcion que contiene el juego en si, su bucle
	//empezamos por crear el tablero

	PiezaMadre* tablero[HEIGHT][WIDTH];
	InicializarTablero(tablero);

	bool JuegoEnCurso = true;
	char TurnoActual = 'B';

	while (JuegoEnCurso)
	{ //mientrras el juego este en curso... empezamos imprimiendo el tablero
		ImprimirTablero(tablero);

		//Mostramos a quien le toca
		std::cout << "Turno del jugador :" << (TurnoActual == 'B') ? "Blancas" : "Negras") << std::endl;

		//Vamos a encontrar al rey de quien le toca para comprovar si esta en jaque
		Rey* ReyActual = nullptr;
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++) {
				if (tablero [i][j] != nullptr && tablero[i][j]->GetSimbolo()==(TurnoActual == 'B' ? 'K' : 'k'))
				{
					ReyActual = dynamic_cast<Rey*>(tablero[i][j]);
				}
			
			}
			
		}
		bool enJaque = false;
		bool enJaqueMate = false;
		if (ReyActual != nullptr){
			enJaque = ReyActual->EstaEnJaque(ReyActual->fila, ReyActual->columna, tablero, TurnoActual);
			if (enJaque)
			{
				std::cout << "\n ¡Cuidado, el Rey esta en Jaque! \n" << std::endl;
				enJaqueMate = ReyActual->EstaEnJaqueMate(tablero);
			}
		}
		if (enJaqueMate)
		{
			std::cout << "\n ¡Jaque Mate! Ganan las: " << (TurnoActual == 'B' ? "Negras" : "Blancas") << std::endl;
			JuegoEnCurso = false;
			continue;

		}
		int FilaOrigen, ColumnaOrigen, FilaDestino, ColumnaDestino;
		std::cout << "Introduce fila y columna de la pieza que quieres mover (2 5):";
		std::cin >> FilaOrigen >> ColumnaOrigen;
		std::cout << "Introduce fila y columna de la casilla a la que la quieres mover";
		std::cin >> FilaDestino >> ColumnaDestino;

		if (MoverPieza(FilaOrigen, ColumnaOrigen, FilaDestino, ColumnaDestino, tablero))
		{
			TurnoActual = (TurnoActual == 'B') ? 'N' : 'B';
		}
		else {
			std::cout << "Movimiento no valido. Prueba otra vez" << std::endl;

		}
	}
	limpiarTablero(tablero);

}



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