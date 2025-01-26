#include "GameLogic.h"
#include <iostream>
#include "config.h"
#include "Rey.h"
#include "Peon.h"
#include "Reina.h"

void limpiarTablero(PiezaMadre* tablero[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (tablero[i][j] != nullptr) {
                delete tablero[i][j];
                tablero[i][j] = nullptr;
            }
        }
    }
}

void Juego() {
    // Inicializar el tablero
    PiezaMadre* tablero[HEIGHT][WIDTH];
    InicializarTablero(tablero);

    bool JuegoEnCurso = true;
    char TurnoActual = 'B'; // Blancas comienzan

    while (JuegoEnCurso) {
        // Imprimir el tablero
        ImprimirTablero(tablero);

        // Mostrar de quién es el turno
        std::cout << "Turno del jugador: " << ((TurnoActual == 'B') ? "Blancas" : "Negras") << std::endl;

        // Buscar al rey del turno actual
        Rey* ReyActual = nullptr;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (tablero[i][j] != nullptr && tablero[i][j]->GetSimbolo() == (TurnoActual == 'B' ? 'K' : 'k')) {
                    ReyActual = dynamic_cast<Rey*>(tablero[i][j]);
                }
            }
        }

        // Verificar Jaque y Jaque Mate
        bool enJaque = false;
        bool enJaqueMate = false;
        if (ReyActual != nullptr) {
            enJaque = ReyActual->EstaEnJaque(ReyActual->fila, ReyActual->columna, tablero, TurnoActual);
            if (enJaque) {
                std::cout << "\n ¡Cuidado, el Rey está en Jaque! \n" << std::endl;
                enJaqueMate = ReyActual->EstaEnJaqueMate(tablero);
            }
        }

        if (enJaqueMate) {
            std::cout << "\n ¡Jaque Mate! Ganan las " << (TurnoActual == 'B' ? "Negras" : "Blancas") << "!\n";
            JuegoEnCurso = false;
            continue;
        }

        int FilaOrigen, ColumnaOrigen, FilaDestino, ColumnaDestino;
        std::cout << "Introduce fila y columna de la pieza que quieres mover (ejemplo: 2 5): ";
        std::cin >> FilaOrigen >> ColumnaOrigen;
        std::cout << "Introduce fila y columna de destino (ejemplo: 3 5): ";
        std::cin >> FilaDestino >> ColumnaDestino;

        // Ajustar índices para el array
        FilaOrigen -= 1;
        ColumnaOrigen -= 1;
        FilaDestino -= 1;
        ColumnaDestino -= 1;

        // Validar límites del tablero
        if (FilaOrigen < 0 || FilaOrigen >= HEIGHT || ColumnaOrigen < 0 || ColumnaOrigen >= WIDTH ||
            FilaDestino < 0 || FilaDestino >= HEIGHT || ColumnaDestino < 0 || ColumnaDestino >= WIDTH) {
            std::cout << "Movimiento fuera del tablero, vuelve a intentarlo.\n";
            continue;
        }

        // Validar el movimiento
        if (MoverPieza(FilaOrigen, ColumnaOrigen, FilaDestino, ColumnaDestino, tablero, TurnoActual)) {
            TurnoActual = (TurnoActual == 'B') ? 'N' : 'B'; // Cambiar turno
        }
        else {
            std::cout << "Movimiento no válido. Intenta de nuevo.\n";
        }
    }

    // Limpiar el tablero al final del juego
    limpiarTablero(tablero);
}

bool MoverPieza(int FilaOrigen, int ColumnaOrigen, int FilaDestino, int ColumnaDestino, PiezaMadre* tablero[HEIGHT][WIDTH], char TurnoActual) {
    if (tablero[FilaOrigen][ColumnaOrigen] == nullptr) {
        std::cout << "No hay ninguna pieza que puedas mover en esta casilla.\n";
        return false;
    }

    PiezaMadre* pieza = tablero[FilaOrigen][ColumnaOrigen];

    if (pieza->color != TurnoActual) {
        std::cout << "No puedes mover las piezas del oponente.\n";
        return false;
    }

    if (!pieza->MovimientoValido(FilaDestino, ColumnaDestino, tablero)) {
        std::cout << "Este movimiento no es válido para esta pieza.\n";
        return false;
    }

    // Captura de piezas enemigas
    if (tablero[FilaDestino][ColumnaDestino] != nullptr) {
        delete tablero[FilaDestino][ColumnaDestino];
        tablero[FilaDestino][ColumnaDestino] = nullptr;
        std::cout << "Pieza capturada.\n";
    }

    // Mover la pieza
    tablero[FilaDestino][ColumnaDestino] = pieza;
    tablero[FilaOrigen][ColumnaOrigen] = nullptr;

    // Actualizar la posición de la pieza
    pieza->fila = FilaDestino;
    pieza->columna = ColumnaDestino;

    // Promoción de peón a reina
    if (dynamic_cast<Peon*>(pieza) != nullptr) { // Si es un Peón
        if ((pieza->color == 'B' && FilaDestino == HEIGHT - 1) || (pieza->color == 'N' && FilaDestino == 0)) {
            // Promoción directa sin borrar la instancia
            pieza = new Reina(pieza->color, FilaDestino, ColumnaDestino);
            tablero[FilaDestino][ColumnaDestino] = pieza; // Asignar la Reina al tablero
            std::cout << "¡Un peón ha sido promovido a Reina de color "
                << ((pieza->color == 'B') ? "Blanco" : "Negro") << "!\n";
        }
    }


    return true;
}
