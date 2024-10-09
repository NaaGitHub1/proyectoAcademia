#include "nodoEstudiante.h"

//Constructor y Desstructor
nodoEstudiante::nodoEstudiante(estudiante* e, nodoEstudiante* s) : est(e), sig(s) {}
nodoEstudiante::~nodoEstudiante() { delete est; }

//M�todos Get
estudiante* nodoEstudiante::getEstudiante() { return est; }
nodoEstudiante* nodoEstudiante::getSiguiente() { return sig; }

//M�todos Set 
void nodoEstudiante::setEstudiante(estudiante* e) { est = e; }
void nodoEstudiante::setSiguiente(nodoEstudiante* s) { sig = s; }
