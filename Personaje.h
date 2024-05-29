#pragma once
#include <iostream>

using namespace std;
class Personaje
{
//Atributos basicos
private:
	int vida;
	int ataque;
	string nombre;
	int posicionX;
	int posicionY;
	int velocidad;

//Metodos
public:
	int getVida();
	void setVida(int pvida);
	int getAtaque();
	void setAtaque(int pataque);
	string getNombre();
	void setNombre(string pnombre);
	int getPosicionX();
	int getPosicionY();
	void setPosicionX(int pposicionX);
	void setPosicionY(int pposicionY);
	void setVelocidad(int pvelocidad);
	int getVelocidad();

	//Funciones
	void getParameters();
	//Constructor
	Personaje();
	Personaje(int pvida, int pataque, int velocidad, string pnombre, int posicionX, int posicionY);
};

