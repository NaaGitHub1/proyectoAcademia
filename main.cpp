#include <iostream>
#include "listaGrupo.h"
#include "grupo.h"
#include "horario.h"
#include "profesor.h"

using namespace std;

int main() {
    // Crear objetos Horario y Profesor para los grupos
    horario* horario1 = new horario("08:00", "10:00", "Lunes, Mi�rcoles");
    horario* horario2 = new horario("10:00", "12:00", "Martes, Jueves");
    horario* horario3 = new horario("14:00", "16:00", "Viernes");

    profesor* profesor1 = new profesor("Dr. Juan P�rez", "PROF101", "555-1234", "juanperez@uni.edu", "Doctorado en Matem�ticas");
    profesor* profesor2 = new profesor("Dr. Ana S�nchez", "PROF102", "555-5678", "anasanchez@uni.edu", "Doctorado en F�sica");

    // Crear objetos Grupo
    grupo* grupo1 = new grupo(101, 30, 25, horario1, profesor1);
    grupo* grupo2 = new grupo(102, 40, 35, horario2, profesor2);
    grupo* grupo3 = new grupo(103, 20, 15, horario3, profesor1);

    // Crear lista de grupos
    listaGrupo listaGrupos;

    // Test case: Insertar grupos en la lista
    cout << "Agregando grupos a la lista:" << endl;
    if (listaGrupos.insertarPrimero(grupo1)) {
        cout << "Grupo 101 agregado correctamente al principio." << endl;
    }
    if (listaGrupos.insertarFinal(grupo2)) {
        cout << "Grupo 102 agregado correctamente al final." << endl;
    }
    if (listaGrupos.insertarFinal(grupo3)) {
        cout << "Grupo 103 agregado correctamente al final." << endl;
    }

    // Mostrar la lista completa
    cout << "\nContenido de la lista de grupos despu�s de agregar grupos:" << endl;
    cout << listaGrupos.toString() << endl;

    // Test case: Buscar un grupo por su n�mero de grupo
    int numBuscar = 102;
    cout << "\nBuscando grupo con n�mero de grupo: " << numBuscar << endl;
    if (listaGrupos.buscarPorNumGrupo(numBuscar)) {
        cout << "Grupo encontrado." << endl;
    }
    else {
        cout << "Grupo no encontrado." << endl;
    }

    // Test case: Eliminar un grupo de la lista
    int numEliminar = 101;  // Eliminar el primer grupo
    cout << "\nEliminando grupo con n�mero de grupo: " << numEliminar << endl;
    listaGrupos.eliminarGrupo(numEliminar);

    // Mostrar la lista despu�s de la eliminaci�n
    cout << "\nContenido de la lista de grupos despu�s de eliminar el grupo 101:" << endl;
    cout << listaGrupos.toString() << endl;

    // Vaciar la lista
    cout << "\nVaciando la lista de grupos..." << endl;
    listaGrupos.vaciar();
    cout << "Lista vaciada correctamente." << endl;

    // Mostrar la lista vac�a
    cout << "\nContenido de la lista de grupos despu�s de vaciarla:" << endl;
    cout << listaGrupos.toString() << endl;

    // Liberar memoria
    delete horario1;
    delete horario2;
    delete horario3;
    delete profesor1;
    delete profesor2;
    delete grupo1;
    delete grupo2;
    delete grupo3;

    return 0;
}





