#include "nodoPeriodo.h"

//Constructor y Destructor
nodoPeriodo::nodoPeriodo(periodo* peri, nodoPeriodo* s) : p(peri), sig(s) {}
nodoPeriodo::~nodoPeriodo() { delete p; }

//M�todos Get
periodo* nodoPeriodo::getPeriodo() { return p; }
nodoPeriodo* nodoPeriodo::getSig() { return sig; }

//M�todos Set
void nodoPeriodo::setPeriodo(periodo* peri) { p = peri; }
void nodoPeriodo::setSig(nodoPeriodo* s) { sig = s; }

string nodoPeriodo::toString() {
	return p->toString();
}
