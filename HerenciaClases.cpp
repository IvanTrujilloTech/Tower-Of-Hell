#include "Personaje.h"
#include "EnemigoFinal.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cctype>
#include <vector>

using namespace std;

HANDLE  hConsole;
#pragma comment(lib, "winmm.lib")
int salidaX;
bool firstRead = true;
void esperar(int ms) {
	if (firstRead) {
		Sleep(ms);
	}
}


//Creacion de personajes
Personaje pocion1(1, 1, 1, "Pocion", 1,1);
Personaje pocion2(1, 1, 1, "Pocion", rand() % 11, rand() % (10 - 1));
Personaje heroe(200, 50, 65, "", 0,1);
Personaje enemigo1(100, 10, 10, "Zombie", rand() % 11, rand() % (10 - 1));
Personaje enemigo2(200, 20, 30, "Caracol mutante", rand() % 11, rand() % (10 - 1));
Personaje enemigo3(300, 30, 50, "Minotauro", rand() % 11, rand() % (10 - 1));
EnemigoFinal boss(60, 80, 200, 40, 70, "Cancerbero", 0, 0);


void intro() {
	PlaySound(TEXT("intro_music.wav"), NULL, SND_FILENAME | SND_ASYNC);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	using namespace std;
	esperar(2500);
	cout << "\t\t sdSS_SSSSSSbs    sSSs_sSSs     .S     S.     sSSs   .S_sSSs            sSSs_sSSs      sSSs         .S    S.     sSSs  S.      S.      " << endl;
	esperar(250);
	cout << "\t\t YSSS~S%SSSSSP   d%%SP~YS%%b   .SS     SS.   d%%SP  .SS~YS%%b          d%%SP~YS%%b    d%%SP        .SS    SS.   d%%SP  SS.     SS.     " << endl;
	esperar(250);
	cout << "\t\t      S%S       d%S'     `S%b  S%S     S%S  d%S'    S%S   `S%b        d%S'     `S%b  d%S'          S%S    S%S  d%S'    S%S     S%S     " << endl;
	esperar(250);
	cout << "\t\t      S%S       S%S       S%S  S%S     S%S  S%S     S%S    S%S        S%S       S%S  S%S           S%S    S%S  S%S     S%S     S%S     " << endl;
	esperar(250);
	cout << "\t\t      S&S       S&S       S&S  S%S     S%S  S&S     S%S    d*S        S&S       S&S  S&S           S%S SSSS%S  S&S     S&S     S&S     " << endl;
	esperar(250);
	cout << "\t\t      S&S       S&S       S&S  S%S     S%S  S&S_Ss  S&S   .S*S        S&S       S&S  S&S_Ss        S&S  SSS&S  S&S_Ss  S&S     S&S     " << endl;
	esperar(250);
	cout << "\t\t      S&S       S&S       S&S  S%S     S%S  S&S~SP  S&S_sdSSS         S&S       S&S  S&S~SP        S&S    S&S  S&S~SP  S&S     S&S     " << endl;
	esperar(250);
	cout << "\t\t      S&S       S&S       S&S  S%S     S%S  S&S     S&S~YSY%b         S&S       S&S  S&S           S&S    S&S  S&S     S&S     S&S     " << endl;
	esperar(250);
	cout << "\t\t      S*S       S*b       d*S  S*S     S*S  S*b     S*S   `S%b        S*b       d*S  S*b           S*S    S*S  S*b     S*b     S*b     " << endl;
	esperar(250);
	cout << "\t\t      S*S       S*S.     .S*S  S*S  .  S*S  S*S.    S*S    S%S        S*S.     .S*S  S*S           S*S    S*S  S*S.    S*S.    S*S.    " << endl;
	esperar(250);
	cout << "\t\t      S*S        SSSbs_sdSSS   S*S_sSs_S*S   SSSbs  S*S    S&S         SSSbs_sdSSS   S*S           S*S    S*S   SSSbs   SSSbs   SSSbs  " << endl;
	esperar(250);
	cout << "\t\t      S*S         YSSP~YSSY    SSS~SSS~S*S    YSSP  S*S    SSS          YSSP~YSSY    S*S           SSS    S*S    YSSP    YSSP    YSSP  " << endl;
	esperar(250);
	cout << "\t\t      SP                                            SP                               SP                   SP                           " << endl;
	esperar(250);
	cout << "\t\t      Y                                             Y                                Y                    Y                            " << endl;
	esperar(250);
	cout << "\t\t								Bienvenido a Boat Racer!\n";
	esperar(250);
	cout << "\t\t								by Ivan Trujillo\n\n ";
	esperar(2500);
	system("PAUSE");
	PlaySound(nullptr, nullptr, 0);
}

// Creo un vector bidimensional para generar la tabla
vector<vector<int>> generarNivel(int filas, int columnas) { //VECTOR EXTERIOR = FILAS | VECTOR INTERIOR = COLUMNAS
	vector<vector<int>> nivel(filas, vector<int>(columnas));

	//Generacion heroe
	heroe.setPosicionX(rand() % columnas);
	nivel[0][heroe.getPosicionX()] = 3; // limitar generacion heroe primera fila
	
	//Generacion salida
	salidaX = rand() % columnas;
	nivel[filas - 1][salidaX] = 2; // limitar generacion de salida en la ultima fila

	//Generacion enemigos
	nivel[enemigo1.getPosicionY()][enemigo1.getPosicionX()] = 4;
	nivel[enemigo2.getPosicionY()][enemigo2.getPosicionX()] = 4;
	nivel[enemigo3.getPosicionY()][enemigo3.getPosicionX()] = 4;

	//Generacion pociones
	nivel[pocion1.getPosicionY()][pocion1.getPosicionX()] = 1;
	nivel[pocion2.getPosicionY()][pocion2.getPosicionX()] = 1;

	return nivel;
}

// Función para mostrar el nivel
void mostrarNivel(const vector<vector<int>>& nivel) {
	
	for (const vector<int>& fila : nivel) {
		for (int casilla : fila) {
			switch (casilla) {
			case 0:  // Casilla vacía
				cout << "* ";
				break;
			case 1:  // Enemigo
				cout << "P ";
				break;
			case 2:  // Salida
				cout << "S ";
				break;
			case 3: //Heroes
				cout << "O ";
				break;
			case 4:
				cout << "E ";
				break;
			default:
				cout << "? ";
			}
		}
		cout << "\n";
	}
}

// Función para mover al héroe
void moverHeroe(char tecla, vector<vector<int>>& nivel) {
	// Buscar la posición del héroe en el nivel
	for (int i = 0; i < nivel.size(); ++i) {
		for (int j = 0; j < nivel[i].size(); ++j) {
			if (nivel[i][j] == 3) {
				heroe.setPosicionX(j);
				heroe.setPosicionY(i);
				break;
			}
		}
	}

	// Mover al héroe según la tecla pulsada
	switch (tecla) {
	case 9:
		cout << heroe.getVida() << "\n";
	case 72:  // Tecla arriba (arriba)
		if (heroe.getPosicionY() > 0) {
			nivel[heroe.getPosicionY()][heroe.getPosicionX()] = 0;
			nivel[heroe.getPosicionY() - 1][heroe.getPosicionX()] = 3;
			heroe.getPosicionY()-1;
		}
		break;
	case 80:  // Tecla abajo (abajo)
		if (heroe.getPosicionY() < nivel.size() - 1) {
			nivel[heroe.getPosicionY()][heroe.getPosicionX()] = 0;
			nivel[heroe.getPosicionY() + 1][heroe.getPosicionX()] = 3;
			heroe.getPosicionY() + 1;
		}
		break;
	case 75:  // Tecla izquierda (izquierda)
		if (heroe.getPosicionX() > 0) {
			nivel[heroe.getPosicionY()][heroe.getPosicionX()] = 0;
			nivel[heroe.getPosicionY()][heroe.getPosicionX() - 1] = 3;
			heroe.getPosicionX() - 1;
		}
		break;
	case 77:  // Tecla derecha (derecha)
		if (heroe.getPosicionX() < nivel[0].size() - 1) {
			nivel[heroe.getPosicionY()][heroe.getPosicionX()] = 0;
			nivel[heroe.getPosicionY()][heroe.getPosicionX() + 1] = 3;
			heroe.getPosicionX() + 1;
		}
		break;
	}
}

//Funcion para checkear si hay una pelea en esa casilla
int checkPelea() {
	if (heroe.getPosicionX() == enemigo1.getPosicionX() && heroe.getPosicionY() == enemigo1.getPosicionY()) {
		cout << "Te has topado con un " << enemigo1.getNombre() << ". Que comience la pelea!\n";
		esperar(500);
		system("CLS");
		return 1;
	}
	else if (heroe.getPosicionX() == enemigo2.getPosicionX() && heroe.getPosicionY() == enemigo2.getPosicionY()) {
		cout << "Te has topado con un " << enemigo2.getNombre() << ". Que comience la pelea!\n";
		esperar(500);
		system("CLS");
		return 2;
	}
	else if (heroe.getPosicionX() == enemigo3.getPosicionX() && heroe.getPosicionY() == enemigo3.getPosicionY()) {
		cout << "Te has topado con un " << enemigo3.getNombre() << ". Que comience la pelea!\n";
		esperar(500);
		system("CLS");
		return 3;
	}
	else if (heroe.getPosicionX() == pocion1.getPosicionX() && heroe.getPosicionY() == pocion1.getPosicionY()) {
		esperar(500);
		system("CLS");
		return 4;
	}
	else if (heroe.getPosicionX() == pocion2.getPosicionX() && heroe.getPosicionY() == pocion2.getPosicionY()) {
		esperar(500);
		system("CLS");
		return 5;
	}
	else {
		return 0;
	}
}

//Funcion para checkear si enemigo es más rapido que personaje para que ataque primero
int checkVelocidad(Personaje& enemigo, Personaje& heroe) {
	if (enemigo.getVelocidad() <= heroe.getVelocidad()) {
		cout << "Eres mas rapido que " << enemigo.getNombre() << ", tu atacas primero.\n";
		esperar(250);
		return 0;
	}
	else if (enemigo.getVelocidad() > heroe.getVelocidad()) {
		cout << "Eres mas rapido que " << enemigo.getNombre() << ", golpeas antes\n";
		esperar(250);
		return 1;
	}
}

//Funcion de las peleas en funcion de contra que enemigo te toca pelear
void pelea() {
	int turno = 0;
	if (checkPelea() == 1) {
		int ordenAtaque = checkVelocidad(enemigo1, heroe);
		while (enemigo1.getVida() > 0 && heroe.getVida() > 0) {
		if (ordenAtaque == 0){
			turno += 1;
			enemigo1.setVida(enemigo1.getVida() - heroe.getAtaque());
			cout << "----------------Turno " << turno << "----------------\n";
			if (enemigo1.getVida() < 0) {
				enemigo1.setVida(0);
			}
			cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo1.getNombre() <<
				" le queda " << enemigo1.getVida() << "Hp\n";
			if (enemigo1.getVida() <= 0) {
				PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				esperar(4000);
				cout << "Has acabado con " << enemigo1.getNombre() << "\n";
				PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			heroe.setVida(heroe.getVida() - enemigo1.getAtaque());
			if (heroe.getVida() < 0) {
				heroe.setVida(0);
			}
			cout << enemigo1.getNombre() << " te ha atacado con " << enemigo1.getAtaque() << " A " << heroe.getNombre() <<
				" te queda " << heroe.getVida() << "Hp\n";

			if (heroe.getVida() <= 0) {
				PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
				esperar(4000);
				cout << "Game Over\n";
			}
		}
		else if (ordenAtaque == 1){
			turno += 1;
			heroe.setVida(heroe.getVida() - enemigo1.getAtaque());
			if (heroe.getVida() < 0) {
				heroe.setVida(0);
			}
			cout << enemigo1.getNombre() << " te ha atacado con " << enemigo1.getAtaque() << " A " << heroe.getNombre() <<
				" te queda " << heroe.getVida() << "Hp\n";

			if (heroe.getVida() <= 0) {
				PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
				esperar(4000);
				cout << "Game Over\n";
			}
			enemigo1.setVida(enemigo1.getVida() - heroe.getAtaque());
			cout << "----------------Turno " << turno << "----------------\n";
			if (enemigo1.getVida() < 0) {
				enemigo1.setVida(0);
			}
			cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo1.getNombre() <<
				" le queda " << enemigo1.getVida() << "Hp\n";
			if (enemigo1.getVida() <= 0) {
				PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				esperar(4000);
				cout << "Has acabado con " << enemigo1.getNombre() << "\n";
				PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		else{
			cout << "Error de ordenAtaque";
		}
	}
}
	else if (checkPelea() == 2) {
		int ordenAtaque = checkVelocidad(enemigo2, heroe);
		while (enemigo2.getVida() > 0 && heroe.getVida() > 0) {
			if (ordenAtaque == 0) {
				turno += 1;
				enemigo2.setVida(enemigo2.getVida() - heroe.getAtaque());
				cout << "----------------Turno " << turno << "----------------\n";
				if (enemigo2.getVida() < 0) {
					enemigo2.setVida(0);
				}
				cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo2.getNombre() <<
					" le queda " << enemigo2.getVida() << "Hp\n";
				if (enemigo2.getVida() <= 0) {
					PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
					esperar(4000);
					cout << "Has acabado con " << enemigo2.getNombre() << "\n";
					PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				heroe.setVida(heroe.getVida() - enemigo2.getAtaque());
				if (heroe.getVida() < 0) {
					heroe.setVida(0);
				}
				cout << enemigo2.getNombre() << " te ha atacado con " << enemigo2.getAtaque() << " A " << heroe.getNombre() <<
					" te queda " << heroe.getVida() << "Hp\n";

				if (heroe.getVida() <= 0) {
					PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "Game Over\n";
				}
			}
			else if (ordenAtaque == 1) {
				turno += 1;
				heroe.setVida(heroe.getVida() - enemigo2.getAtaque());
				if (heroe.getVida() < 0) {
					heroe.setVida(0);
				}
				cout << enemigo2.getNombre() << " te ha atacado con " << enemigo2.getAtaque() << " A " << heroe.getNombre() <<
					" te queda " << heroe.getVida() << "Hp\n";

				if (heroe.getVida() <= 0) {
					PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "Game Over\n";
				}
				enemigo2.setVida(enemigo2.getVida() - heroe.getAtaque());
				cout << "----------------Turno " << turno << "----------------\n";
				if (enemigo2.getVida() < 0) {
					enemigo2.setVida(0);
				}
				cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo2.getNombre() <<
					" le queda " << enemigo2.getVida() << "Hp\n";
				if (enemigo2.getVida() <= 0) {
					PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
					esperar(4000);
					cout << "Has acabado con " << enemigo2.getNombre() << "\n";
					PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			else {
				cout << "Error de ordenAtaque";
			}
		}
	}
	else if (checkPelea() == 3) {
		int ordenAtaque = checkVelocidad(enemigo3, heroe);
		while (enemigo3.getVida() > 0 && heroe.getVida() > 0) {
			if (ordenAtaque == 0) {
				turno += 1;
				enemigo3.setVida(enemigo3.getVida() - heroe.getAtaque());
				cout << "----------------Turno " << turno << "----------------\n";
				if (enemigo3.getVida() < 0) {
					enemigo3.setVida(0);
				}
				cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo3.getNombre() <<
					" le queda " << enemigo3.getVida() << "Hp\n";
				if (enemigo3.getVida() <= 0) {
					PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
					esperar(4000);
					cout << "Has acabado con " << enemigo3.getNombre() << "\n";
					PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				heroe.setVida(heroe.getVida() - enemigo3.getAtaque());
				if (heroe.getVida() < 0) {
					heroe.setVida(0);
				}
				cout << enemigo3.getNombre() << " te ha atacado con " << enemigo3.getAtaque() << " A " << heroe.getNombre() <<
					" te queda " << heroe.getVida() << "Hp\n";

				if (heroe.getVida() <= 0) {
					PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "Game Over\n";
				}
			}
			else if (ordenAtaque == 1) {
				turno += 1;
				heroe.setVida(heroe.getVida() - enemigo3.getAtaque());
				if (heroe.getVida() < 0) {
					heroe.setVida(0);
				}
				cout << enemigo3.getNombre() << " te ha atacado con " << enemigo3.getAtaque() << " A " << heroe.getNombre() <<
					" te queda " << heroe.getVida() << "Hp\n";

				if (heroe.getVida() <= 0) {
					PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "Game Over\n";
				}
				enemigo3.setVida(enemigo3.getVida() - heroe.getAtaque());
				cout << "----------------Turno " << turno << "----------------\n";
				if (enemigo3.getVida() < 0) {
					enemigo3.setVida(0);
				}
				cout << "Has atacado con " << heroe.getAtaque() << " Al " << enemigo3.getNombre() <<
					" le queda " << enemigo3.getVida() << "Hp\n";
				if (enemigo3.getVida() <= 0) {
					PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
					esperar(4000);
					cout << "Has acabado con " << enemigo3.getNombre() << "\n";
					PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			else {
				cout << "Error de ordenAtaque";
			}
		}
	}
	else if (checkPelea() == 4) {
		cout << "Te tomas la pocion y recuperas toda tu salud\n";
		PlaySound(TEXT("potion.wav"), NULL, SND_FILENAME | SND_ASYNC);
		esperar(3000);
		heroe.setVida(200);
	}
	else if (checkPelea() == 5) {
		cout << "Te tomas la pocion y recuperas toda tu salud\n";
		PlaySound(TEXT("potion.wav"), NULL, SND_FILENAME | SND_ASYNC);
		esperar(3000);
		heroe.setVida(200);
	}
}

int main() {
	srand(time(NULL));
	bool inGame = true;
	//intro();
	system("CLS");
	string nombreHeroe;
	cout << "Introduce el nombre de tu heroe... ";
	cin >> nombreHeroe;
	heroe.setNombre(nombreHeroe);

	vector<vector<int>> nivel = generarNivel(10, 11);
	mostrarNivel(nivel);
	PlaySound(TEXT("cave.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (inGame == true) {
		char tecla = _getch();

		moverHeroe(tecla, nivel);
		system("CLS");
		mostrarNivel(nivel);
		checkPelea();
		pelea();

		if (salidaX == heroe.getPosicionX() && heroe.getPosicionY() == 9) {
			inGame = false;
			string respuestaBoss;
			system("CLS");
			cout << "Estas a punto de adentrarte en la guarida de" << boss.getNombre() << ", el guardian de las puertas del inframundo...\n";
			esperar(250);
			cout << "Estas seguro de que quieres enfrentarte a la bestia mas feroz de todos los mitos habidos y por haber?\n";
			cout << "(Y/N) ";
			cin >> respuestaBoss;
			if (respuestaBoss == "N"){
				system("CLS");
				cout << "El aventurero " << heroe.getNombre() << " resulto ser en realidad, un verdadero miedica, que se echo para atras antes de batallar contra el ser mitologico " << boss.getNombre() << "\n";
				esperar(500);
				cout << "Fin del juego... (cagon).\n";
				PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
				esperar(500);
				break;
			}
			else if (respuestaBoss == "Y"){
				int turno = 0;
				int ordenAtaque = checkVelocidad(boss, heroe);
				while (boss.getVida() > 0 && heroe.getVida() > 0) {
					if (ordenAtaque == 0) {
						turno += 1;
						boss.setVida(boss.getVida() - heroe.getAtaque());
						cout << "----------------Turno " << turno << "----------------\n";
						if (boss.getVida() < 0) {
							boss.setVida(0);
						}
						cout << "Has atacado con " << heroe.getAtaque() << " Al " << boss.getNombre() <<
							" le queda " << boss.getVida() << "Hp\n";
						if (boss.getVida() <= 0) {
							cout << "Has acabado con " << boss.getNombre() << "\n";
							PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
							esperar(500);
						}
						heroe.setVida(heroe.getVida() - boss.getAtaque());
						if (heroe.getVida() < 0) {
							heroe.setVida(0);
						}
						cout << boss.getNombre() << " te ha atacado con " << boss.getAtaque() << " A " << heroe.getNombre() <<
							" te queda " << heroe.getVida() << "Hp\n";

						if (heroe.getVida() <= 0) {
							PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
							cout << "Game Over\n";
						}
					}
					else if (ordenAtaque == 1) {
						turno += 1;
						heroe.setVida(heroe.getVida() - boss.getAtaque());
						if (heroe.getVida() < 0) {
							heroe.setVida(0);
						}
						cout << boss.getNombre() << " te ha atacado con " << boss.getAtaque() << " A " << heroe.getNombre() <<
							" te queda " << heroe.getVida() << "Hp\n";

						if (heroe.getVida() <= 0) {
							PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
							cout << "Game Over\n";
						}
						boss.setVida(boss.getVida() - heroe.getAtaque());
						cout << "----------------Turno " << turno << "----------------\n";
						if (boss.getVida() < 0) {
							boss.setVida(0);
						}
						cout << "Has atacado con " << heroe.getAtaque() << " Al " << boss.getNombre() <<
							" le queda " << boss.getVida() << "Hp\n";
						if (boss.getVida() <= 0) {
							PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
							cout << "Has acabado con " << boss.getNombre() << "\n";
						}
					}
					else {
						cout << "Error de ordenAtaque";
					}
				}
				break;
			}
			}	
	}
	return 0;
}