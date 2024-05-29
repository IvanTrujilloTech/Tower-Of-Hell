#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje
{
private:
	int superAtaque1;
	int superAtaque2;

//Metodos
public:
	int getSuperAtaque1();
	void setSuperAtaque1(int superAtaque1);
	int getSuperAtaque2();
	void setSuperAtaque2(int superAtaque2);
	

	//Constructores
	EnemigoFinal();
	EnemigoFinal(int pSuperAtaque1, int pSuperAtaque2, int pvida, int pataque, int pvelocidad, string pnombre, int pposicionX, int pposicionY);

};

