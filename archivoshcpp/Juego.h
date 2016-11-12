#pragma once
#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

typedef struct MyStruct
{
	int i, j, d;
} Jugada;

class Juego
{
public:
	Juego();
	~Juego();
	void jugar(Jugada&);
	void jugandoCPU(Jugada&);
	int mejorJugada(Jugada&, int, int, int);
	int getResultado();
	int get(int, int);
	void setNivel(int nivel);
private:
	Tablero tablero;
	int turno;
	int resultado;
	// maxima cantidad de veces que la recursion continua
	int nivel;
};

enum ENUM
{
	COLUMNA = 1,
	FILA = 2,
	DIAGONAL = 3,
	DIAGONAL_INVERSA = 4
};

#endif
