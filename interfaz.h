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
	
	//Men� Principal
	void menuPrincipal();

	//Submen�s
	void submenuAdministracion();
	void submenuMatricula();
	void submenuInformes();
	void guardarDatos();

	//M�todos para ingresar
	void ingresarProfesor();
	void ingresarEstudiante();
	void ingresarPeriodo();
	void agregarCurso(); 
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

	//M�todos para guardar datos

};