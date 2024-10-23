#include "descuento.h"

//Constructor y Destructor
descuento::descuento(int cursos, float por) : cursosMinimos(cursos), porcentajeDescuento(por) {}
descuento::~descuento() {}

//M�todos Get
int descuento::getCursos() { return cursosMinimos; }
float descuento::getPorcentaje() { return porcentajeDescuento; }

//M�todods Set
void descuento::setCursos(int m) { cursosMinimos = m; }
void descuento::setPorcentaje(float p) { porcentajeDescuento = p;; }

//M�todo para calcular descuento por cursos
float descuento::calcularDescuento(float subtotal, int cantidad) {
    if (cantidad >= cursosMinimos) {
        return subtotal * (porcentajeDescuento / 100);
    }
    return 0;
}
