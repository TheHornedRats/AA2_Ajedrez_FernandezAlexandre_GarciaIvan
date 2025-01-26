#ifndef PIEZA_H
#define PIEZA_H //lo llamo asi para que se entienda que es la pieza madre y la H par que se vea que es un header
//Incluyo cmath para poder usar abs() con el fin de calcular las distancias entre la casilla de una pieza y a la que se quiere mover, asi no nos preocupamos por numeros negativos
#include <cmath> 
// Inluyo string para poder usar strings, sobretodo para el nombre de las clases
#include <string> 
#include "config.h"
//Empezemos a definir las clases, pero antes una pequeña explicacion
//Una clase es como crearle una "ficha de personaje" a un objeto en concreto, podemos cojer un peon y decir de que color es, donde se encuentra, y incluso podemos usar metodos para definir las acciones que puede tomar
//Ahora definiremos una clase llamada Pieza, la madre de todas las clases. A partir de ella crearemos clases mas pequeñitas que seran las distinas piezas, cada una con sus especificaciones.

class PiezaMadre {
	//aqui estamos definiendo las caracteristicas de esta clase, podra tener color (B o N para blancas o negras)
	// y tambien un int para guardar donde esta colocada inicialmente la pieza.
public:
	char color;
	int fila, columna;
	// a esto lo llamamos construir una clase, estamos iniciando los valores de cada una de las caracteristicas de esta clase

	PiezaMadre(char color, int fila, int columna)
		: color(color), fila(fila), columna(columna) {
	}
	// ahora vamos a añadir un método, un metódo es como otorgarle una accion a este objeto
	//esto lo usaremos para poder definir como queremos que sea el movimiento de las piezas, pero como no queremos que tengan todas el mismo movimiento necesitamos que puedas "sobreescribir" el movimiento predeterminado
	//para eso tenemos que hacer que el metodo sea virtual, asi las clases derivadas de esta podran adaptar el movimiento a ellas

	// aqui declaramos un bool con el que miraremos si el movimeinto que la pieza intenta hacer es valido o no
	//esto de aqui es una sobrecarga del metodo MovimientoValido, es necesario para que tanto el Rey como el Peon puedan usar el tablero para analizar sus movimientos
	//el resto de piezas aunque no utilizen el tablero usaran este metodo para seguir validando que la casilla donde mueven no esta ocupada por una ficha amiga 
	virtual bool MovimientoValido(int NuevaFila, int NuevaColumna, PiezaMadre* tablero[HEIGHT][WIDTH])
	{
		if (NuevaFila < 0 || NuevaFila >= HEIGHT || NuevaColumna < 0 || NuevaColumna >= WIDTH)
		{
			return false;
		}
		if (tablero[NuevaFila][NuevaColumna] != nullptr && tablero[NuevaFila][NuevaColumna]->color == this->color) {
			return false;
		}
		return true;
	}
	virtual char GetSimbolo() const = 0;

	// esto de aquí he visto que se usa para evitar fugas de memoria, no se exactamente que són pero parece importante
	//Creamos el DESTRUCTOR VIRTUAL
	virtual ~PiezaMadre() {}

};
#endif //PIEZAS_H
