#include "interfaz.h"

//Constructor
interfaz::interfaz() {
	acad = new academia();
}

//Men� Principal
void interfaz::menuPrincipal() {
    int opcion;

    do {
        cout << "\n--- Men� Principal ---\n";
        cout << "1. Submen� Administraci�n\n";
        cout << "2. Submen� Matr�cula\n";
        cout << "3. Submen� B�squedas e Informes\n";
        cout << "4. Guardar los Datos en Archivos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion; 

        switch (opcion) { 
        case 1:
            submenuAdministracion();
            break;
        case 2:
            submenuMatricula();
            break;
        case 3:
            submenuInformes(); 
            break;
        case 4:
            guardarDatos();
            break;
        case 5:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opci�n no v�lida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 5);
}

//Submen� administraci�n
void interfaz::submenuAdministracion() {
    int opcion;

    do {
        cout << "\n--- Submen� Administraci�n General ---\n";
        cout << "(1) Ingresar Profesor\n";
        cout << "(2) Ingresar Estudiante\n";
        cout << "(3) Ingresar Bloque o Periodo\n";
        cout << "(4) Ingresar Curso\n";
        cout << "(5) Ingresar Grupo\n";
        cout << "(6) Asignar Profesor a Grupo\n";
        cout << "(0) Regresar al Men� Principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;  

        switch (opcion) { 
        case 1:
            ingresarProfesor();
            break;
        case 2:
            ingresarEstudiante();
            break;
        case 3:
            ingresarPeriodo();
            break;
        case 4:
            ingresarCurso(); 
            break;
        case 5:
            ingresarGrupo();
            break;
        case 6:
            asignarProfesorAGrupo();
            break;
        case 0:
            cout << "Regresando al men� principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opci�n inv�lida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0);
}

//Submen� matr�cula
void interfaz::submenuMatricula() {
    int opcion; 

    do {
        cout << "\n--- Submen� Matr�cula ---\n";
        cout << "(1) Matricular Estudiante\n";
        cout << "(2) Desmatricular Estudiante\n";
        cout << "(0) Regresar al men� Principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;  

        switch (opcion) {
        case 1:
            matricularEstudiante(); 
            break;
        case 2:
            desmatricularEstudiante(); 
            break;
        case 0:
            cout << "Regresando al men� principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opci�n inv�lida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0); 

}

//Submen� informes
void interfaz::submenuInformes() {
    int opcion;

    do {
        cout << "\n--- Submen� B�squedas e Informes ---\n";
        cout << "(1) Informe Profesores Registrados\n";
        cout << "(2) Informe Estudiantes Registrados\n";
        cout << "(3) Informe Cursos Matriculados por un Estudiante\n";
        cout << "(4) Informe Profesor Especifico\n";
        cout << "(5) Informe Periodos Habilitados para el A�o\n";
        cout << "(6) Informe Grupo Especifico\n";
        cout << "(0) Regresar al Men� Principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarInformeProfesores();
            break;
        case 2:
            mostrarInformeEstudiantes();
            break;
        case 3:
            mostrarInformeCursosEstudiante();
            break;
        case 4:
            mostrarInformeProfesorEspecifico();
            break;
        case 5:
            mostrarInformePeriodos();
            break;
        case 6:
            mostrarInformeGrupoEspecifico();
            break;
        case 0:
            cout << "Regresando al men� principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opci�n inv�lida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0);
}

//Guardar datos
void interfaz::guardarDatos() {

}

//M�todos de ingreso
void interfaz::ingresarProfesor() {
    string nombre, id, telefono, email, gradoAcademico;

    cout << "Ingrese el ID del profesor:\t";
    cin >> id;
    cout << endl;

    if (acad->buscarProfesor(id)) {
        cout << "Error: ya existe un profesor con ese ID.\n";
        return;
    }

    cout << "Ingrese el nombre del profesor:\t";
    cin >> nombre;
    cout << endl;
    cout << "Ingrese el telefono del profesor:\t";
    cin >> telefono;
    cout << endl;
    cout << "Ingrese el email del profesor:\t";
    cin >> email;
    cout << endl;
    cout << "Ingrese el grado academico del profesor:\t";
    cin >> gradoAcademico; 
    cout << endl;

    if (!nombre.empty() || !telefono.empty() || !email.empty() || !gradoAcademico.empty()) {
        profesor* p = new profesor(nombre, id, telefono, email, gradoAcademico);
        if (acad->agregarProfesor(p)) {
            cout << "Profesor ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
       cout << "No se pueden ingresar espacios vacios, intente nuevamente." << endl;
       submenuAdministracion();
    }
}

void interfaz::ingresarEstudiante() {
    string nombre, id, especialidad, telefono, email;

    cout << "Ingrese el ID del estudiante:\t";
    cin >> id;
    cout << endl;

    if (acad->buscarEstudiante(id)) {
        cout << "Error: ya existe un estudiante con este ID.\n";
        return;
    }

    cout << "Ingrese el nombre del estudiante:\t";
    cin >> nombre; 
    cout << endl;
    cout << "Ingrese la especialidad del estudiante:\t";
    cin >> especialidad;
    cout << endl;
    cout << "Ingrese el telefono del estudiante:\t";
    cin >> telefono;
    cout << endl;
    cout << "Ingrese el email del estudiante:\t";
    cin >> email;
    cout << endl;

    if (!nombre.empty() || !especialidad.empty() || !telefono.empty() || !email.empty()) {
        estudiante* e = new estudiante(nombre, id, especialidad, telefono, email);
        if (acad->agregarEstudiante(e)) {
            cout << "Estudiante ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
        cout << "No se pueden ingresar espacios vac�os, intente nuevamente." << endl;
        submenuAdministracion();
    }
}

void interfaz::ingresarPeriodo() {
    int numTrimestre;

    cout << "Ingrese el numero de periodo (1-4):\t";
    cin >> numTrimestre;
    cout << endl;

    if (numTrimestre < 1 || numTrimestre > 4) {
        cout << "El numero de periodo debe estar entre 1 y 4.\n";
        return;
    }

    if (acad->buscarPeriodo(numTrimestre)) {
        cout << "Ya existe un periodo con este numero.\n";
        return;
    }

    periodo* p = new periodo(numTrimestre);
    if (acad->agregarPeriodo(p)) {
        cout << "Periodo ingresado." << endl;
    }
    else {
        cout << "Error al ingresar." << endl;
    }
}

void interfaz::ingresarCurso() {
    string nombre, id;
    int horas;
    float precio;
    bool disponible;

    cout << "Ingrese el ID del curso:\t";
    cin >> id;
    cout << endl;

    if (acad->buscarCurso(id)) {
        cout << "Error: Ya existe un curso con este ID.\n";
        return;
    }

    cout << "Ingrese el nombre del curso:\t";
    cin >> nombre;
    cout << endl;
    cout << "Ingrese la cantidad de horas del curso:\t";
    cin >> horas; 
    cout << endl; 
    cout << "Ingrese el precio del curso:\t";
    cin >> precio;
    cout << endl; 
    cout << "�El curso esta disponible? (1/0):\t";
    cin >> disponible;
    cout << endl;

    if (!nombre.empty() || horas != 0 || precio != 0) {
        curso* c = new curso(nombre, id, horas, precio, disponible);
        if (acad->agregarCurso(c)) {
            cout << "Curso ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacios, intente nuevamente." << endl; 
        submenuAdministracion();
    }
}

void interfaz::ingresarGrupo() {
    string idCurso;
    int numGrupo, capacidad;
    string horarioInicio, horarioFin, diasSemana;
    profesor* prof = nullptr;

    cout << "Ingrese el ID del curso para el nuevo grupo:\t";
    cin >> idCurso; 
    cout << endl;

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no existe.\n";
        return;
    }
    curso* c = acad->getCursos()->getCurso(idCurso);

    cout << "Ingrese el numero del grupo:\t";
    cin >> numGrupo;
    cout << endl;
    cout << "Ingrese la capacidad del grupo:\t";
    cin >> capacidad;
    cout << endl;

    cout << "Informacion del horario:\n";
    cout << "Ingrese el horario de inicio:\t";
    cin >> horarioInicio;
    cout << endl;
    cout << "Ingrese el horario de fin:\t";
    cin >> horarioFin;
    cout << endl;
    cout << "Ingrese los dias de la semana del grupo:\t";
    cin >> diasSemana; 
    cout << endl; 

    if (!horarioInicio.empty() || !horarioFin.empty() || !diasSemana.empty()) {
        cout << "Datos del horario ingresados exitosamente." << endl;
    }
    horario* h = new horario(horarioInicio, horarioFin, diasSemana); 

    if (numGrupo != 0 || capacidad != 0) {
        grupo* g = new grupo(numGrupo, capacidad, 0, h, prof);
        if (c->agregarGrupo(g)) {
            cout << "Grupo ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl; 
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacios, intente de nuevo." << endl;
        submenuAdministracion();
    }
}

void interfaz::asignarProfesorAGrupo() {
    string idProfesor, idCurso;
    int numGrupo;

    cout << "Ingrese el ID para el curso del grupo correspondiente:\t";
    cin >> idCurso;
    cout << endl; 

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no esta registrado.\n";
        return;
    }
    
    cout << "Ingrese el numero de grupo deseado:\t";
    cin >> numGrupo; 
    cout << endl;

    if (numGrupo == 0) {
        cout << "El numero de grupo no es valido, intente de nuevo." << endl;
        submenuAdministracion();
    }
    grupo* g = acad->getCursos()->getCurso(idCurso)->getGrupos()->getGrupo(numGrupo);

    cout << "Ingrese el ID del profesor que desea asignar:\t";
    cin >> idProfesor;
    cout << endl; 
    if (!acad->buscarProfesor(idProfesor)) {
        cout << "Error: El profesor ingresado no esta registrado en el sistema.\n";
        return;
    }
    profesor* p = acad->getProfesores()->getProfesor(idProfesor);

    g->setProfesor(p);
    cout << "Profesor asignado correctamente al grupo con #" << numGrupo << ".\n";
}

//M�todos de matr�cula
void interfaz::matricularEstudiante() {
    string idEstudiante, idCurso;
    int numGrupo, numPeriodo;

    if (acad->listarEstudiantes().empty()) {
        cout << "Error: No hay estudiantes registrados en el sistema.\n";
        return;
    }
    if (acad->listarCursos().empty()) {
        cout << "Error: No hay cursos registrados en el sistema.\n";
        return;
    }
    if (acad->listarPeriodos().empty()) {
        cout << "Error: No hay periodos registrados en el sistema.\n";
        return;
    }

    cout << "Ingrese el ID del estudiante que desea matricular: ";
    cin >> idEstudiante; 
    if (!acad->buscarEstudiante(idEstudiante)) {
        cout << "Error: El estudiante ingresado no est� registrado en el sistema.\n";
        return;
    }

    cout << "Ingrese el ID del curso en el que desea matricular al estudiante: ";
    cin >> idCurso; 
    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso ingresado no est� registrado en el sistema.\n";
        return;
    }

    cout << "Ingrese el n�mero de periodo: ";
    cin >> numPeriodo;
    if (!acad->buscarPeriodo(numPeriodo)) {
        cout << "Error: El periodo ingresado no est� registrado en el sistema.\n";
        return;
    }

    cout << "Ingrese el n�mero de grupo en el que desea matricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no est� registrado en el curso.\n";
        return;
    }

    grupo* g = acad->getGrupos()->getGrupo(numGrupo);
    if (g->getCantidadAlumnos() >= g->getCapacidad()) {
        cout << "Error: El grupo seleccionado no tiene cupos disponibles.\n";
        return;
    }
    if (acad->matricularEstudianteEnCurso(idEstudiante, idCurso, numGrupo)) {
        cout << "Matr�cula realizada con �xito.\n";
        cout << "Factura generada:\n" << acad->generarFactura(idEstudiante, numPeriodo);
    }
    else {
        cout << "Error al matricular al estudiante.\n";
    }
}

void interfaz::desmatricularEstudiante() {
    string idEstudiante, idCurso;
    int numGrupo;

    if (acad->listarEstudiantes().empty()) {
        cout << "Error: No hay estudiantes registrados en el sistema.\n";
        return;
    }

    cout << "Ingrese el ID del estudiante que desea desmatricular: ";
    cin >> idEstudiante;
    if (!acad->buscarEstudiante(idEstudiante)) { 
        cout << "Error: El estudiante ingresado no est� registrado en el sistema.\n";
        return;
    }

    cout << "Ingrese el ID del curso del que desea desmatricular al estudiante: ";
    cin >> idCurso;
    if (!acad->buscarCurso(idCurso)) { 
        cout << "Error: El curso ingresado no est� registrado en el sistema.\n";
        return;
    }

    cout << "Ingrese el n�mero de grupo del que desea desmatricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no est� registrado en el curso.\n";
        return;
    }

    if (acad->desmatricularEstudiante(idEstudiante, idCurso, numGrupo)) {
        cout << "El estudiante ha sido desmatriculado del grupo correctamente.\n";
    }
    else {
        cout << "Error al desmatricular al estudiante.\n";
    }
}

//M�todos para mostrar
void interfaz::mostrarInformeProfesores() {
    cout << "----- Informe de Profesores Registrados -----\n";
    string informe = acad->informeProfesores(); 
    if (informe.empty()) { 
        cout << "No hay profesores registrados en el sistema.\n";
    }
    else {
        cout << "Nombre\tID\n";
        cout << informe << endl; 
    }
}

void interfaz::mostrarInformeEstudiantes() {
    cout << "----- Informe de Estudiantes Registrados -----\n";
    string informe = acad->informeEstudiantes(); 
    if (informe.empty()) { 
        cout << "No hay estudiantes registrados en el sistema.\n";
    }
    else {
        cout << "Nombre\tID\n";
        cout << informe << endl; 
    }
}

void interfaz::mostrarInformeCursosEstudiante() {
    string idEstudiante; 
    cout << "Ingrese el ID del estudiante: ";
    cin >> idEstudiante; 

    cout << "----- Informe de Cursos Matriculados por el Estudiante -----\n";
    string informe = acad->informeCursosMatriculadosEstudiante(idEstudiante); 
    if (informe == "Estudiante no encontrado.") { 
        cout << "Error: El estudiante con ID " << idEstudiante << " no est� registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
}

void interfaz::mostrarInformeProfesorEspecifico() {
    string idProfesor; 
    cout << "Ingrese el ID del profesor: ";
    cin >> idProfesor; 

    cout << "----- Informe del Profesor Espec�fico -----\n";
    string informe = acad->informeProfesorEspecifico(idProfesor); 
    if (informe == "Profesor no encontrado.") { 
        cout << "Error: El profesor con ID " << idProfesor << " no est� registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
}

void interfaz::mostrarInformePeriodos() {
    cout << "----- Informe de Periodos Habilitados para el A�o -----\n";
    string informe = acad->informePeriodos(); 
    if (informe.empty()) { 
        cout << "No hay periodos registrados en el sistema.\n";
    }
    else {
        cout << informe << endl; 
    }
}

void interfaz::mostrarInformeGrupoEspecifico() {
    string idCurso;  
    int numGrupo;

    cout << "Ingrese el ID del curso: ";
    cin >> idCurso; 

    cout << "Ingrese el n�mero de grupo: ";
    cin >> numGrupo; 
   
    cout << "----- Informe del Grupo Espec�fico -----\n";
    string informe = acad->informeGrupoEspecifico(idCurso, numGrupo); 
    if (informe == "Curso no encontrado." || informe == "Grupo no encontrado.") { 
        cout << "Error: No se encontr� el curso o grupo especificado.\n";
    }
    else {
        cout << informe << endl; 
    }
}


