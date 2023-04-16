#include "Lancha.h"
#include <iostream>
using namespace std;

//Constructor
Lancha::Lancha(int pVe, int pDis, int pNit, int pDado, std::string pNombre) {
	velocidad = pVe;
	distancia = pDis;
	nitro = pNit;
	dado = pDado;
	nombre = pNombre;
}

//Getters
int Lancha::getVe() {
	return velocidad;
}
int Lancha::getDis() {
	return distancia;
}
int Lancha::getNit() {
	return nitro;
}

int Lancha::getDado() {
	return dado;
}
string Lancha::getNombre() {
	return nombre;
}


//Setters
void Lancha::setVe(int pVe) {
	velocidad = pVe;
}
void Lancha::setDis(int pDis) {
	distancia = pDis;
}
void Lancha::setNit(int pNit) {
	nitro = pNit;
}

void Lancha::setDado(int pDado) {
	dado = pDado;
}
void Lancha::setName(string pNombre) {
	nombre = pNombre;
}


//Metodos propios
 //Aquí se desarrolla el código del juego.

void Lancha::tirarDado() {	
	setDado(1 + rand() % 6); cout << "\nEl jugador " << getNombre() << " ha sacado un " << getDado() << endl;
	
}
void Lancha::velocity() {
	setVe(getVe() + getDado());
	cout << "La velocidad del jugador " << getNombre() + " es: " << getVe() <<endl;
}
void Lancha::turbo() {
	int chooseTurbo;
	int numRandom = rand() % 2;
	;
	
	if (getNit() == 0)
	{
		cout << "Ya no puedes utilizar el nitro en esta ronda" <<endl;
		
	}
	else {
		cout << "Quieres utilizar el nitro en esta ronda?: [1-si] [2-no]: "; cin >> chooseTurbo;
		switch (chooseTurbo)
		{
		case 1:
			cout << "\nHas utilizado el nitro, pero viene con una condicion. Veamos si tienes suerte: " << numRandom << endl;
			setNit(0);
			if (numRandom == 1)
			{
				setVe(getVe() * 2);
				cout << "OHH!! has tenido suerte y ahora tu velocidad se vera aumentada " << getVe() << endl;

			}
			else {
				setVe(getVe() / 2);
				cout << "Que mala suerte has tenido. Ahora tu velocidad se vera disminuida " << getVe() << endl;

			}
			break;
		case 2:
			cout << "\nPuedes utilizar el nitro en la siguente ronda" << endl;
			break;
		default:
			break;
		}
	}
	
}
void Lancha::distance() {
	setDis(getDis() + getVe() * 100);
	cout << "\nLa distancia recorrida es de " << getDis() << endl;
}