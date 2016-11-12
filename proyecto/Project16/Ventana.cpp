#include "Ventana.h"

Ventana::Ventana()
{
	iniciaSprites();
	modo = -1;
	Tablero();
}

Ventana::~Ventana()
{
}

void Ventana::iniciaSprites()
{
	fondoMenu.loadFromFile("imagenesJuego\\imagenInicial.jpg");
	jugar.loadFromFile("imagenesJuego\\botonJugar.png");
	salir.loadFromFile("imagenesJuego\\botonSalir.png");

	unJugadorTextura.loadFromFile("imagenesJuego\\botonUnJugador.png");
	multiJugador.loadFromFile("imagenesJuego\\botonMultijugador.png");

	modoFacil.loadFromFile("imagenesJuego\\botonFacil.png");
	modoNormal.loadFromFile("imagenesJuego\\botonNormal.png");
	modoDificil.loadFromFile("imagenesJuego\\botonDificil.png");
	regresar.loadFromFile("imagenesJuego\\botonRegresar.png");

	tableroJuego.loadFromFile("imagenesJuego\\base.png");
	circulo.loadFromFile("imagenesJuego\\circuloJuego.png");
	equis.loadFromFile("imagenesJuego\\equisJuego.png");

	fondoMenuSprite.setTexture(fondoMenu);
	jugarSprite.setTexture(jugar);
	salirSprite.setTexture(salir);

	unJugadorSprite.setTexture(unJugadorTextura);
	multijugadorSprite.setTexture(multiJugador);
	regresarSprite.setTexture(regresar);

	modoFacilSprite.setTexture(modoFacil);
	modoNormalSprite.setTexture(modoNormal);
	modoDificilSprite.setTexture(modoDificil);

	equisSprite.setTexture(equis);
	circuloSprite.setTexture(circulo);
}

void Ventana::iniciaElMenu()
{
	menu.create(sf::VideoMode(400, 500), "TIC TAC TOE");
	fondoMenuSprite.setPosition(0, 0);
	jugarSprite.setPosition(86.5, 186);
	salirSprite.setPosition(86.5, 314);

	while (menu.isOpen())
	{
		while (menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				menu.close();
				return;
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (jugarSprite.getGlobalBounds().contains(menu.mapPixelToCoords(sf::Mouse::getPosition(menu))))
					{
						menu.close();
						iniciaModo();
						return;
					}


					if (salirSprite.getGlobalBounds().contains(menu.mapPixelToCoords(sf::Mouse::getPosition(menu))))
					{
						menu.close();
						return;
					}
				}
			}
		}
		menu.clear();
		menu.draw(fondoMenuSprite);
		menu.draw(jugarSprite);
		menu.draw(salirSprite);
		menu.display();
	}
}

void Ventana::iniciaModo()
{
	modoMenu.create(sf::VideoMode(400, 500), "TIC TAC TOE");
	unJugadorSprite.setPosition(86.5, 58);
	multijugadorSprite.setPosition(86.5, 186);
	regresarSprite.setPosition(86.5, 314);

	while (modoMenu.isOpen())
	{
		while (modoMenu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				modoMenu.close();
				return;
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if (unJugadorSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(modoMenu))))
				{
					modoMenu.close();
					Dificultad();
					return;
				}


				if (multijugadorSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(modoMenu))))
				{
					modoMenu.close();
					dosJugadores();
					return;
				}

				if (regresarSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(modoMenu))))
				{
					modoMenu.close();
					iniciaElMenu();
					return;
				}
			}
		}
		modoMenu.clear();
		modoMenu.draw(unJugadorSprite);
		modoMenu.draw(multijugadorSprite);
		modoMenu.draw(regresarSprite);
		modoMenu.display();
	}
}

void Ventana::Dificultad()
{
	juegoVentana.create(sf::VideoMode(400, 500), "UN JUGADOR");

	modoFacilSprite.setPosition(86.5, 58);
	modoNormalSprite.setPosition(86.5, 186);
	modoDificilSprite.setPosition(86.5, 314);
	regresarSprite.setPosition(86.5, 378);


	while (juegoVentana.isOpen())
	{
		while (juegoVentana.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				juegoVentana.close();
				return;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (modoFacilSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
				{
					juegoVentana.close();
					juego.setNivel(1);
					unJugador();
					return;
				}


				if (modoNormalSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
				{
					juegoVentana.close();
					juego.setNivel(3);
					unJugador();
					return;
				}

				if (modoDificilSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
				{
					juegoVentana.close();
					juego.setNivel(5);
					unJugador();
					return;
				}

				if (regresarSprite.getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
				{
					juegoVentana.close();
					iniciaModo();
					return;
				}
			}
		}

		juegoVentana.clear();


		juegoVentana.draw(modoFacilSprite);
		juegoVentana.draw(modoNormalSprite);
		juegoVentana.draw(modoDificilSprite);
		juegoVentana.draw(regresarSprite);


		juegoVentana.display();
	}
}

void Ventana::dosJugadores()
{
	juegoVentana.create(sf::VideoMode(300, 300), "TIC TAC TOE");
	float x = 0, y = 0;
	for(int i = 0, j; i < 3; i++)
	{
		for(j = 0, x = 0; j < 3; j++)
		{
			tableroJuegoSprite[i][j].setTexture(tableroJuego);
			tableroJuegoSprite[i][j].setPosition(x, y);
			x += 100;
		}
		y += 100;
	}
	while (juegoVentana.isOpen())
	{
		while (juegoVentana.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				juegoVentana.close();
				return;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0, j; i < 3; i++)
					for (j = 0; j < 3; j++)
						if (tableroJuegoSprite[i][j].getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
						{
							Jugada jugada;
							jugada.i = i;
							jugada.j = j;
							juego.jugar(jugada);
							if (juego.getResultado() != N)
							{
								juegoVentana.close();
								return;
							}
							if (juego.get(i, j) == X)
								tableroJuegoSprite[i][j].setTexture(equis);
							else
								tableroJuegoSprite[i][j].setTexture(circulo);
						}
			}
		}

		juegoVentana.clear();

		for (int i = 0, j; i < 3; i++)
			for (j = 0; j < 3; j++)
				juegoVentana.draw(tableroJuegoSprite[i][j]);

		juegoVentana.display();
	}
}

void Ventana::unJugador()
{
	juegoVentana.create(sf::VideoMode(300, 300), "TIC TAC TOE");
	float x = 0, y = 0;
	for (int i = 0, j; i < 3; i++)
	{
		for (j = 0, x = 0; j < 3; j++)
		{
			tableroJuegoSprite[i][j].setTexture(tableroJuego);
			tableroJuegoSprite[i][j].setPosition(x, y);
			x += 100;
		}
		y += 100;
	}
	while (juegoVentana.isOpen())
	{
		while (juegoVentana.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				juegoVentana.close();
				return;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0, j; i < 3; i++)
					for (j = 0; j < 3; j++)
						if (tableroJuegoSprite[i][j].getGlobalBounds().contains(modoMenu.mapPixelToCoords(sf::Mouse::getPosition(juegoVentana))))
						{
							Jugada jugada;
							jugada.i = i;
							jugada.j = j;
							juego.jugandoCPU(jugada);
							if (juego.getResultado() != N)
							{
								juegoVentana.close();
								return;
							}
						}
			}
		}

		juegoVentana.clear();

		for (int i = 0, j; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (juego.get(i, j) == X)
					tableroJuegoSprite[i][j].setTexture(equis);
				else if(juego.get(i, j) == C)
					tableroJuegoSprite[i][j].setTexture(circulo);

		for (int i = 0, j; i < 3; i++)
			for (j = 0; j < 3; j++)
				juegoVentana.draw(tableroJuegoSprite[i][j]);

		juegoVentana.display();
	}
}
