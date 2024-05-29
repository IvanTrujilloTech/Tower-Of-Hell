#include "Personaje.h"

int Personaje::getVida()
{
    return vida;
}

void Personaje::setVida(int pvida)
{
    vida = pvida;
}

int Personaje::getAtaque()
{
    return ataque;
}

void Personaje::setAtaque(int pataque)
{
    ataque = pataque;
}

string Personaje::getNombre()
{
    return nombre;
}

void Personaje::setNombre(string pnombre)
{
    nombre = pnombre;
}

int Personaje::getPosicionX()
{
    return posicionX;
}

int Personaje::getPosicionY()
{
    return posicionY;
}

void Personaje::setPosicionX(int pposicionX)
{
    posicionX = pposicionX;
}

void Personaje::setPosicionY(int pposicionY)
{
    posicionY = pposicionY;
}

void Personaje::setVelocidad(int pvelocidad)
{
    velocidad = pvelocidad;
}

int Personaje::getVelocidad()
{
    return velocidad;
}

void Personaje::getParameters()
{
    cout << "El personaje " << nombre << " tienes " << vida << " puntos de vida y tiene " << ataque << " puntos de ataque\n";
}

Personaje::Personaje()
{
}

Personaje::Personaje(int pvida, int pataque, int pvelocidad, string pnombre, int pposicionX, int pposicionY)
{
    vida = pvida;
    ataque = pataque;
    nombre = pnombre;
    posicionX = pposicionX;
    posicionY = pposicionY;
    velocidad = pvelocidad;
}
