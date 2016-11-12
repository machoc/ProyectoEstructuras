#pragma once
#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
public:
	Tablero();
	~Tablero();

	int get(int, int);
	void set(int, int, int);
	int gana();
	bool empate();
	bool Vacio();
	// Funciones recursivas para la suma de puntos en la mesa
	int sumaColumna(int, int, int);
	int sumaFila(int, int, int);
	int sumaDiagonal(int, int, int);
	int sumaDiagonalInversa(int, int, int);
	void iniciar();// todo en 0
private:
	int mesa[3][3];
};

enum MyEnum
{
	C = -1,
	N = 0,
	X = 1 /// C = circulos N = nada (vacio) X = X
};

#endif
