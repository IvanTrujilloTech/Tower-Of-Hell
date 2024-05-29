#include "EnemigoFinal.h"

int EnemigoFinal::getSuperAtaque1()
{
    return superAtaque1;
}

void EnemigoFinal::setSuperAtaque1(int pSuperAtaque1)
{
    superAtaque1 = pSuperAtaque1;
}

int EnemigoFinal::getSuperAtaque2()
{
    return superAtaque2;
}

void EnemigoFinal::setSuperAtaque2(int pSuperAtaque2)
{
    superAtaque2 = pSuperAtaque2;
}

EnemigoFinal::EnemigoFinal()
{
}

EnemigoFinal::EnemigoFinal(int pSuperAtaque1, int pSuperAtaque2, int pvida, int pataque, int pvelocidad, string pnombre, int pposcionX, int pposicionY):Personaje(pvida, pataque, pvelocidad, pnombre, pposcionX, pposicionY)
{
    superAtaque1 = pSuperAtaque1;
    superAtaque2 = pSuperAtaque2;


}
