#include "Tablero.h"

Tablero::Tablero()
{
	iniciar();
}


Tablero::~Tablero()
{
}

void Tablero::iniciar()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mesa[i][j] = 0;
}

int Tablero::get(int i, int j)
{
	return mesa[i][j];
}

void Tablero::set(int i, int j, int val)
{
	mesa[i][j] = val;
}


int Tablero::gana()
{
	for (int i = 0; i < 3; i++)
	{//columnas
		if (mesa[i][0] != 0 && (mesa[i][0] == mesa[i][1] && mesa[i][0] == mesa[i][2]))
		{
			if (mesa[i][0] == X)
				return X;
			else if (mesa[i][0] == C)
				return C;
		}
		else
		{// filas
			if (mesa[0][i] != 0 && (mesa[0][i] == mesa[1][i] && mesa[0][i] == mesa[2][i]))
			{
				if (mesa[0][i] == X)
					return X;
				else if (mesa[0][i] == C)
					return C;
			}
			else
			{// diagonales
				if (mesa[0][0] != 0 && (mesa[0][0] == mesa[1][1] && mesa[0][0] == mesa[2][2]))
				{
					if (mesa[0][0] == X)
						return X;
					else if (mesa[0][0] == C)
						return C;
				}
				else
				{
					if (mesa[0][2] != 0 && (mesa[0][2] == mesa[1][1] && mesa[0][2] == mesa[2][0]))
					{
						if (mesa[0][2] == X)
							return X;
						else if (mesa[0][2] == C)
							return C;
					}
				}
			}
		}
	}
	if (empate())
		return 3;
	return N;
}

bool Tablero::empate()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (mesa[i][j] == 0)
				return false;
	return true;
}

bool Tablero::Vacio()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (mesa[i][j] != 0)
				return false;
	return true;
}

int Tablero::sumaColumna(int i, int j, int marca)
{
	if (i > 2 || j > 2)
		return 0;
	if(mesa[i][j] == marca || mesa[i][j] == N)
		return 10 + sumaColumna(i + 1, j, marca);
	return sumaColumna(i + 1, j, marca);
}

int Tablero::sumaFila(int i, int j, int marca)
{
	if (i > 2 || j > 2)
		return 0;
	if (mesa[i][j] == marca || mesa[i][j] == N)
		return 10 + sumaFila(i, j + 1, marca);
	return sumaFila(i, j + 1, marca);
}

int Tablero::sumaDiagonal(int i, int j, int marca)
{
	if (i > 2 || j > 2)
		return 0;
	if (mesa[i][j] == marca || mesa[i][j] == N)
		return 10 + sumaDiagonal(i + 1, j + 1, marca);
	return sumaDiagonal(i + 1, j + 1, marca);
}

int Tablero::sumaDiagonalInversa(int i, int j, int marca)
{
	if (i > 2 || j < 0)
		return 0;
	if (mesa[i][j] == marca || mesa[i][j] == N)
		return 10 + sumaDiagonalInversa(i + 1, j - 1, marca);
	return sumaDiagonalInversa(i + 1, j - 1, marca);
}
