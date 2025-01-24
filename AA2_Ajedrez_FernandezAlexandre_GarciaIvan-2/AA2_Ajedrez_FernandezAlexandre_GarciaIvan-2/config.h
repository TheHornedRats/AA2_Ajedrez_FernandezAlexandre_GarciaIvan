#ifndef CONFIG_H
#define CONFIG_H

// Tamaño del tablero
const int HEIGHT = 9; // 8 filas del tablero + 1 para rotulos
const int WIDTH = 9;  // 8 columnas del tablero + 1 para rotulos

// Representación de colores de las piezas
const char COLOR_BLANCO = 'B'; // Blanco
const char COLOR_NEGRO = 'N';  // Negro

// Representación para casillas vacías
const char CASILLA_VACIA = '*';

// Rango de filas y columnas validas en el tablero
const  int MIN_TABLERO = 1; // Primera fila y columna (despues de los rotulos)
const  int MAX_TABLERO = 8; // Última fila y columna (tablero real)

#endif // CONFIG_H

