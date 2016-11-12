#include "Juego.h"

Juego::Juego()
{
	turno = X;
	resultado = N;
	nivel = 5;
}

Juego::~Juego()
{
}

void Juego::jugar(Jugada& jugada)
{
	// Poner la marca en el tablero
	if (tablero.get(jugada.i, jugada.j) == N)
		if (turno == X)
		{
			tablero.set(jugada.i, jugada.j, X);
			turno = C;
		}
		else
		{
			tablero.set(jugada.i, jugada.j, C);
			turno = X;
		}

	if(tablero.gana() != N)
	{ // ver si ganó alguien o es empate
		resultado = tablero.gana();
	}
}

void Juego::jugandoCPU(Jugada& jugada)
{
	jugar(jugada);
	// Si alguien ha ganado
	if(resultado != N)
		return;
	// encontrar mejor jugada
	mejorJugada(jugada, 0, 0, nivel);
	switch(jugada.d)
	{
	case COLUMNA:
		for(int i = 0; i < 3; i++)
			if (tablero.get(i, jugada.j) == N)
			{
				jugada.i = i;
				jugar(jugada);
				break;
			}
		break;
	case FILA:
		for (int i = 0; i < 3; i++)
			if (tablero.get(jugada.i, i) == N)
			{
				jugada.j = i;
				jugar(jugada);
				break;
			}
		break;
	case DIAGONAL:
		for (int i = 0; i < 3; i++)
			if (tablero.get(i, i) == N)
			{
				jugada.j = jugada.i = i;
				jugar(jugada);
				break;
			}
		break;
	case DIAGONAL_INVERSA:
		for (int i = 2; i >= 0; i--)
			if (tablero.get(2 - i, i) == N)
			{
				jugada.i = 2 - i;
				jugada.j = i;
				jugar(jugada);
				break;
			}
		break;
	default: break;
	}
}

int Juego::mejorJugada(Jugada& jugada, int i, int j, int nivel)
{
	if (nivel < 0)
		return 0;
	int d;
	int temp = tablero.sumaColumna(i, j, C);
	d = COLUMNA;
	if(temp < tablero.sumaFila(i, j, C))
	{
		d = FILA;
		temp = tablero.sumaFila(i, j, C);
	}
	if(i == 0 && j == 0)
		if (temp < tablero.sumaDiagonal(0, 0, C))
		{
			temp = tablero.sumaDiagonal(0, 0, C);
			d = DIAGONAL;
		}
	if(i == 0 && j == 2)
		if (temp < tablero.sumaDiagonalInversa(0, 2, C))
		{
			temp = tablero.sumaDiagonalInversa(0, 2, C);
			d = DIAGONAL_INVERSA;
		}
	jugada.i = i;
	jugada.j = j;
	jugada.d = d;

	if (i == 0 && j == 2)
		return temp;

	int temp2;

	if (i < 3 && j < 3)
	{
		temp2 = mejorJugada(jugada, i + 1, j + 1, nivel - 1);
		if (temp < temp2)
		{
			if (i == 2 && j == 2)
				if (temp2 < mejorJugada(jugada, 0, 2, nivel - 1))
					return mejorJugada(jugada, 0, 2, nivel - 1);
			return temp2;
		}
		jugada.i = i;
		jugada.j = j;
		jugada.d = d;
	}
	return temp;
}

int Juego::getResultado()
{
	return resultado;
}

int Juego::get(int i, int j)
{
	return tablero.get(i, j);
}

void Juego::setNivel(int nivel)
{
	this->nivel = nivel;
}
