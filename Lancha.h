#pragma once
#include <iostream>

class Lancha {
	// Declaramos nuestras variables 
private:
	int velocidad;
	int distancia;
	int nitro;
	int dado;
	std::string nombre;
	

public:

	//Constructor
	Lancha(int pVe, int pDis, int pNit, int pDado, std::string pNombre);

	//Getters
	int getVe();  //velocidad
	int getDis(); //Distancia
	int getNit(); //Nitro
	int getDado();
	std::string getNombre();
	

	//Setters
	void setVe(int pVe);
	void setDis(int pDis);
	void setNit(int pNit);
	void setDado(int pDado);
	void setName(std::string pNombre);
	


	//Metodos propios
	void tirarDado();
	void velocity();
	void turbo();
	void distance();
};