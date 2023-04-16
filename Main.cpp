#include "Lancha.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include<stdlib.h>
#include <mmsystem.h>
//Mensaje de inicio del juego.
void bienvenida() {
	
	cout << "\n";
	cout << "Bienvenidos a la carrera de lanchas mas espectacular del Mediterraneo" << endl;
	cout << "Con nosotros participaran dos increibles pilotos, donde mostraran sus increibles habilidades!" << endl;
	cout << "A continuacion se los presentamos:" << endl;

}

int main() {
	
	int cuentaAtras = 5;
	int turnos = 0;
	srand(time(NULL));
	string corredor1;
	string corredor2;
	bool win = false;
	bienvenida();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	cout << "\nEl nombre del primer piloto es: "; cin >> corredor1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	cout << "El nombre del segundo piloto es: "; cin >> corredor2;
	Lancha lancha1(0, 0, 1, 0, corredor1);
	Lancha lancha2(0, 0, 1, 0, corredor2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	cout << "\nEl nombre de los pilotos son " << corredor1 + " y " << corredor2 << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "\nLa carrera comenzara en breves, asi que coloquense en sus puestos!" << endl;

	//elegirJugador(corredor1, corredor2);

	while (cuentaAtras >= 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		cout << "La carrera empieza en " << cuentaAtras << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
		Sleep(1000);
		cuentaAtras--;
	}
	while (turnos <5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		cout << "\nPresiona cualquier tecla para tirar dado : " <<endl;
		_getch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
		lancha1.tirarDado();
		lancha1.velocity();
		lancha1.turbo();
		lancha1.distance();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		cout << "\nPresiona cualquier tecla para tirar dado : " <<endl;
		_getch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		lancha2.tirarDado();
		lancha2.velocity();
		lancha2.turbo();
		lancha2.distance();
		turnos++;
	}
	if (lancha1.getDis() > lancha2.getDis() && !win)
	{
		cout << "El jugdor " <<lancha1.getNombre()<< " Ha ganado" <<endl;
		win = true;
	}
	else if (lancha1.getDis() < lancha2.getDis() && !win)
	{
		cout << "El jugdor " << lancha2.getNombre() << " Ha ganado" << endl;
		win = true;
	}
	else {
		cout<< "el jugador " <<lancha1.getNombre()<<  " y jugador " << lancha2.getNombre() << " Han empatado";
	}
	return 0;
}



