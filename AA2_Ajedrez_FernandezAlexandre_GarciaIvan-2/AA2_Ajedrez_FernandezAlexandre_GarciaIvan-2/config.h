#ifndef CONFIG_H
#define CONFIG_H

// Tama�o del tablero
const int HEIGHT = 9; // 8 filas del tablero + 1 para rotulos
const int WIDTH = 9;  // 8 columnas del tablero + 1 para rotulos

// Representaci�n de colores de las piezas
const char COLOR_BLANCO = 'B'; // Blanco
const char COLOR_NEGRO = 'N';  // Negro

// Representaci�n para casillas vac�as
const char CASILLA_VACIA = '*';

// Rango de filas y columnas validas en el tablero
const  int MIN_TABLERO = 1; // Primera fila y columna (despues de los rotulos)
const  int MAX_TABLERO = 8; // �ltima fila y columna (tablero real)

#endif // CONFIG_H

