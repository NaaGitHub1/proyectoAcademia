#include "nodoProfesor.h"

//Constructor y Destructor
nodoProfesor::nodoProfesor(profesor* p, nodoProfesor* s) : prof(p), sig(s) {}
nodoProfesor::~nodoProfesor() { delete prof; }

//M�todos Get
profesor* nodoProfesor::getProfesor() { return prof; }
nodoProfesor* nodoProfesor::getSiguiente() { return sig; }

//M�todos Set
void nodoProfesor::setProfesor(profesor* p) { prof = p; }
void nodoProfesor::setSiguiente(nodoProfesor* s) { sig = s; }
