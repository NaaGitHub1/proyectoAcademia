#ifndef INTERFAZ_H
#define INTERFAZ_H
#pragma once
#include "academia.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class interfaz {
private:
	academia* acad;
public:
	interfaz();
	~interfaz();
	
	//Men� Principal
	void menuPrincipal();

	//Submen�s
	void submenuAdministracion();
	void submenuMatricula();
	void submenuInformes();

	//M�todos para ingresar
	void ingresarProfesor();
	void ingresarEstudiante();
	void ingresarPeriodo();
	void ingresarCurso(); 
	void ingresarGrupo();
	void asignarProfesorAGrupo();

	//M�todos de matr�cula
	void matricularEstudiante();
	void desmatricularEstudiante();

	//M�todos para mostrar
	void mostrarInformeProfesores();
	void mostrarInformeEstudiantes();
	void mostrarInformeCursosEstudiante();
	void mostrarInformeProfesorEspecifico();
	void mostrarInformePeriodos();
	void mostrarInformeGrupoEspecifico();

};

#endif