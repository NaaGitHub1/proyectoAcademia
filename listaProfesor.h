#ifndef LISTAPROFESOR_H 
#define LISTAPROFESOR_H
#pragma once
#include "nodoProfesor.h"
#include "profesor.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class profesor;
class nodoProfesor;

class listaProfesor {
private:
	nodoProfesor* primero;
	nodoProfesor* actual;
public:
	listaProfesor();
	~listaProfesor();
	bool insertarPrimero(profesor*);
	bool insertarFinal(profesor*);
	bool buscarPorId(string);
	bool esVacia();
	nodoProfesor* getPrimero();
	void eliminarProfesor(string);
	void vaciarLista();
	profesor* getProfesor(string);
	string toString();
};

#endif