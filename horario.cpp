#include "horario.h"

//Constructor y Destructor
horario::horario(string h, string f, string d) : horaInicio(h), horaFin(f), diasSemana(d) {}
horario::~horario() {}

//M�todos Get
string horario::getHoraInicio() { return horaInicio; }
string horario::getHoraFin() { return horaFin; }
string horario::getDiasSemana() { return diasSemana; }

//M�todos Set
void horario::setHoraInicio(string h) { horaInicio = h; }
void horario::setHoraFin(string h) { horaFin = h; }
void horario::setDiasSemana(string d) { diasSemana = d; }

//toString
string horario::toString() {
    stringstream s;
    s << "Horario:\n" << endl;;
    s << "Inicio:\n" << horaInicio << endl;
    s << "Fin:\n" << horaFin << endl;
    s << "D�as:\n" << diasSemana << endl;
    
    return s.str();
}
