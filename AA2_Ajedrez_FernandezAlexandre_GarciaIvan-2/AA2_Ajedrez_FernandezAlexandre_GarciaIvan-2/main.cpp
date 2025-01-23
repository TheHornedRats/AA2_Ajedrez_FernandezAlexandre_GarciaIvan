#include <iostream>
#include "Rey.h"

int main() {

	Rey rey('B', 4, 4);

	std::cout << "Rey en posicion! : (" << rey.fila << "," << rey.columna << ")" << std::endl;

	if (rey.MovimientoValido(5,5))
	{
		std::cout << "Moviment valid" << std::endl;

	}
	else
	{
		std::cout << "Moviment invalid" << std::endl;

	}

	if (rey.MovimientoValido(7, 7))
	{
		std::cout << "Moviment valid" << std::endl;

	}
	else
	{
		std::cout << "Moviment invalid" << std::endl;

	}
	return 0;

}