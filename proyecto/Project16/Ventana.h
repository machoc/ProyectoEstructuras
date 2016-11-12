#pragma once
#ifndef VENTANA_H
#define VENTANA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Juego.h"

class Ventana
{
public:
	Ventana();
	~Ventana();

	void iniciaSprites(); // carga las texturas que tendran cada boton de meu
	void iniciaElMenu(); //inicializa el menu principal ya sea para jugar o para salir
	void iniciaModo(); // inicializa el menu de modo en donde se escoge el modo
	void Dificultad();// se cambia el modo de juego para de essa forma abrir el juego
	void dosJugadores();
	void unJugador();
	/*bool manejaTurno(bool); // asigna al jugador segun el turno
	int ganador(); // revisa ganador
	void juegaMaquina();// 0 dificil , 1 facil
	void dibujar(); // dibuja el lo que sera el tablero segun la matriz, que en este caso seria de 3x3
	void Tablero(); // pone 0 en todo
	void Resultado(int); //se obtiene el resultado final del juego
	bool empate();//se verifica a ver si en el juego hay empate*/
private:
	//se selecciona cuales seran ventanas y tambien cuales seran las texturas y cargarlas en sprite
	sf::RenderWindow menu, juegoVentana, modoMenu, juegoMultijugador;
	sf::Texture fondoMenu, jugar, salir, unJugadorTextura, multiJugador, modoFacil, modoNormal, modoDificil, regresar, circulo, equis, tableroJuego;
	sf::Sprite fondoMenuSprite, jugarSprite, salirSprite, unJugadorSprite, multijugadorSprite, modoFacilSprite, modoNormalSprite, modoDificilSprite, regresarSprite, circuloSprite, equisSprite, tableroJuegoSprite[3][3];
	sf::Event event;
	Juego juego;
	int modo;
};
#endif