#include <iostream>
#include <vector>
#include <string>
#include "GameLogic.h"
#include "Alfil.h"
#include "Caballo.h"
#include "config.h"
#include "Peon.h"
#include "Piezas.h"
#include "Reina.h"
#include "Rey.h"
#include "Tablero.h"
#include "Torre.h"

    int main() {
        // Crear el tablero como un array de punteros a PiezaMadre
        PiezaMadre* tablero[HEIGHT][WIDTH];

        // Inicializar el tablero con las piezas en sus posiciones originales
        InicializarTablero(tablero);

        // Imprimir el tablero en consola
        ImprimirTablero(tablero);

        // Pausa para evitar que la consola se cierre inmediatamente
        std::cout << "Presiona Enter para salir." << std::endl;
        std::cin.get();

        return 0;
    }

