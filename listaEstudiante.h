#ifndef LISTAESTUDIANTE_H 
#define LISTAESTUDIANTE_H
#pragma once
#include "nodoEstudiante.h"
#include "estudiante.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class estudiante;
class nodoEstudiante;

class listaEstudiante {
private:
	nodoEstudiante* primero;
	nodoEstudiante* actual;
public:
	listaEstudiante();
	~listaEstudiante();
	bool insertarPrimero(estudiante*);
	bool insertarFinal(estudiante*);
	bool buscarPorId(string);
	bool esVacia();
	void eliminarEstudiante(string);
	nodoEstudiante* getPrimero();
	void vaciarLista();
	estudiante* getEstudiante(string);
	string toString();
};

#endif