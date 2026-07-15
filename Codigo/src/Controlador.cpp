/**
 * @file Controlador.cpp
 * @brief Implementacion de la clase Controlador (menu, registro, misiones y memoria).
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
#include "Controlador.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

static const int CAPACIDAD_INICIAL_RECURSOS = 4;
static const int CAPACIDAD_INICIAL_MISIONES = 2;

Controlador::Controlador()
    : listaRecursos(new Recurso*[CAPACIDAD_INICIAL_RECURSOS]),
      cantidadRecursos(0),
      capacidadRecursos(CAPACIDAD_INICIAL_RECURSOS),
      listaMisiones(new Mision*[CAPACIDAD_INICIAL_MISIONES]),
      cantidadMisiones(0),
      capacidadMisiones(CAPACIDAD_INICIAL_MISIONES) {
    // HU05: los datos de prueba se cargan al construirse el Controlador.
    cargarDatosPrueba();
}

Controlador::~Controlador() {
    // HT02: liberacion completa de la memoria dinamica al salir del sistema.
    std::cout << "\nLiberando la memoria dinámica del SGMR..." << std::endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        delete listaMisiones[i];
    }
    delete[] listaMisiones;
    listaMisiones = nullptr;   // buena practica del curso: puntero a nullptr tras delete
    for (int i = 0; i < cantidadRecursos; i++) {
        delete listaRecursos[i];
    }
    delete[] listaRecursos;
    listaRecursos = nullptr;
    std::cout << "Memoria liberada por completo. Hasta pronto." << std::endl;
}

void Controlador::iniciar() {
#ifdef _WIN32
    // Para que las tildes se muestren y lean bien en la consola de Windows.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::cout << "=====================================================" << std::endl;
    std::cout << "  SGMR - Sistema de Gestión de Misiones de Rescate" << std::endl;
    std::cout << "  Atención de desastres - Valle del Cauca" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "Datos de prueba precargados: " << cantidadRecursos
              << " recursos y " << cantidadMisiones << " misiones." << std::endl;

    int opcion = 0;
    do {
        mostrarMenu();
        if (!leerEnteroEnRango("Seleccione una opción: ", 1, 6, opcion)) {
            opcion = 6;   // la entrada se cerro (EOF): salida ordenada
        }
        switch (opcion) {
            case 1: verRecursos(); break;
            case 2: registrarRecurso(); break;
            case 3: crearMision(); break;
            case 4: asignarRecursoAMision(); break;
            case 5: ejecutarMision(); break;
            case 6: std::cout << "\nCerrando el sistema..." << std::endl; break;
        }
    } while (opcion != 6);
}

void Controlador::mostrarMenu() const {
    std::cout << "\n=========== MENÚ PRINCIPAL ===========" << std::endl;
    std::cout << "1. Ver recursos" << std::endl;
    std::cout << "2. Registrar recurso" << std::endl;
    std::cout << "3. Crear Misión" << std::endl;
    std::cout << "4. Asignar recurso a misión" << std::endl;
    std::cout << "5. Ejecutar misión" << std::endl;
    std::cout << "6. Salir" << std::endl;
}

void Controlador::verRecursos() const {
    std::cout << "\n--- Inventario de recursos (" << cantidadRecursos << ") ---" << std::endl;
    if (cantidadRecursos == 0) {
        std::cout << "No hay recursos registrados." << std::endl;
        return;
    }
    for (int i = 0; i < cantidadRecursos; i++) {
        std::cout << " " << (i + 1) << ") ";
        listaRecursos[i]->mostrarInfo();   // llamada polimorfica
    }
}

void Controlador::mostrarMisiones() const {
    std::cout << "\n--- Misiones (" << cantidadMisiones << ") ---" << std::endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        std::cout << " " << (i + 1) << ") ";
        listaMisiones[i]->mostrarInfo();
    }
}

void Controlador::registrarRecurso() {
    // HU01: registro de vehiculos y personal por consola.
    std::cout << "\n--- Registrar recurso ---" << std::endl;
    std::cout << "1. Ambulancia" << std::endl;
    std::cout << "2. Helicóptero" << std::endl;
    std::cout << "3. Médico" << std::endl;
    std::cout << "4. Rescatista" << std::endl;
    std::cout << "5. Volver al menú" << std::endl;

    int tipo = 0;
    if (!leerEnteroEnRango("Tipo de recurso: ", 1, 5, tipo) || tipo == 5) {
        return;
    }

    std::string nombre;
    if (!leerTexto("Nombre del recurso: ", nombre)) {
        return;
    }

    // Unico punto del sistema donde se decide el tipo concreto: la creacion.
    // Despues de este punto todo se maneja como Recurso* (HU02).
    Recurso* nuevo = nullptr;
    if (tipo == 1 || tipo == 2) {
        std::string placa;
        int capacidad = 0;
        if (!leerTexto("Placa: ", placa)) {
            return;
        }
        if (!leerEnteroEnRango("Capacidad (personas, 1-100): ", 1, 100, capacidad)) {
            return;
        }
        if (tipo == 1) {
            nuevo = new Ambulancia(nombre, placa, capacidad);
        } else {
            nuevo = new Helicoptero(nombre, placa, capacidad);
        }
    } else {
        std::string especialidad;
        if (!leerTexto("Especialidad: ", especialidad)) {
            return;
        }
        if (tipo == 3) {
            nuevo = new Medico(nombre, especialidad);
        } else {
            nuevo = new Rescatista(nombre, especialidad);
        }
    }

    agregarRecurso(nuevo);
    std::cout << "Recurso registrado exitosamente:" << std::endl << "    ";
    nuevo->mostrarInfo();
}

void Controlador::crearMision() {
    std::cout << "\n--- Crear misión ---" << std::endl;
    std::string descripcion;
    std::string zona;
    if (!leerTexto("Descripción de la emergencia: ", descripcion)) {
        return;
    }
    if (!leerTexto("Zona del desastre: ", zona)) {
        return;
    }
    Mision* nueva = new Mision(cantidadMisiones + 1, descripcion, zona);
    agregarMision(nueva);
    std::cout << "Misión creada exitosamente:" << std::endl << "    ";
    nueva->mostrarInfo();
}

void Controlador::asignarRecursoAMision() {
    // HU02: asignacion de recursos heterogeneos a una mision.
    std::cout << "\n--- Asignar recurso a misión ---" << std::endl;
    if (cantidadMisiones == 0) {
        std::cout << "No hay misiones creadas. Cree una primero (opción 3)." << std::endl;
        return;
    }
    if (cantidadRecursos == 0) {
        std::cout << "No hay recursos registrados. Registre uno primero (opción 2)." << std::endl;
        return;
    }

    mostrarMisiones();
    int numeroMision = 0;
    if (!leerEnteroEnRango("Número de la misión: ", 1, cantidadMisiones, numeroMision)) {
        return;
    }
    Mision* mision = listaMisiones[numeroMision - 1];

    verRecursos();
    int numeroRecurso = 0;
    if (!leerEnteroEnRango("Número del recurso a asignar: ", 1, cantidadRecursos, numeroRecurso)) {
        return;
    }
    Recurso* recurso = listaRecursos[numeroRecurso - 1];

    if (mision->tieneRecurso(recurso)) {
        std::cout << "Ese recurso ya está asignado a esta misión." << std::endl;
        return;
    }
    mision->asignarRecurso(recurso);
    std::cout << "Recurso \"" << recurso->getNombre() << "\" asignado a la misión \""
              << mision->getDescripcion() << "\"." << std::endl;
}

void Controlador::ejecutarMision() {
    std::cout << "\n--- Ejecutar misión ---" << std::endl;
    if (cantidadMisiones == 0) {
        std::cout << "No hay misiones creadas." << std::endl;
        return;
    }
    mostrarMisiones();
    int numeroMision = 0;
    if (!leerEnteroEnRango("Número de la misión a ejecutar: ", 1, cantidadMisiones, numeroMision)) {
        return;
    }
    listaMisiones[numeroMision - 1]->ejecutar();
}

void Controlador::agregarRecurso(Recurso* recurso) {
    // HT01: si el arreglo se llena, se redimensiona manualmente al doble.
    if (cantidadRecursos == capacidadRecursos) {
        capacidadRecursos = capacidadRecursos * 2;
        Recurso** nuevoArreglo = new Recurso*[capacidadRecursos];
        for (int i = 0; i < cantidadRecursos; i++) {
            nuevoArreglo[i] = listaRecursos[i];
        }
        delete[] listaRecursos;
        listaRecursos = nuevoArreglo;
    }
    listaRecursos[cantidadRecursos] = recurso;
    cantidadRecursos++;
}

void Controlador::agregarMision(Mision* mision) {
    // HT01: mismo esquema de redimensionamiento manual que el inventario.
    if (cantidadMisiones == capacidadMisiones) {
        capacidadMisiones = capacidadMisiones * 2;
        Mision** nuevoArreglo = new Mision*[capacidadMisiones];
        for (int i = 0; i < cantidadMisiones; i++) {
            nuevoArreglo[i] = listaMisiones[i];
        }
        delete[] listaMisiones;
        listaMisiones = nuevoArreglo;
    }
    listaMisiones[cantidadMisiones] = mision;
    cantidadMisiones++;
}

void Controlador::cargarDatosPrueba() {
    // HU05: metodo oculto que instancia dinamicamente los datos quemados
    // (2 misiones, 2 ambulancias, 1 helicoptero, 2 medicos y 2 rescatistas).
    Mision* mision1 = new Mision(1, "Deslizamiento de tierra", "La Cumbre - zona rural");
    Mision* mision2 = new Mision(2, "Inundación por ola invernal", "Juanchito - oriente de Cali");
    agregarMision(mision1);
    agregarMision(mision2);

    Recurso* ambulancia1 = new Ambulancia("Ambulancia Cruz Roja 1", "ABC-123", 3);
    Recurso* ambulancia2 = new Ambulancia("Ambulancia Básica 2", "DEF-456", 2);
    Recurso* helicoptero1 = new Helicoptero("Halcón 1", "HK-2050", 6);
    Recurso* medico1 = new Medico("Laura Gómez", "Medicina de urgencias");
    Recurso* medico2 = new Medico("Carlos Ruiz", "Traumatología");
    Recurso* rescatista1 = new Rescatista("Andrés Parra", "Rescate en escombros");
    Recurso* rescatista2 = new Rescatista("Sofía Mejía", "Rescate acuático");
    agregarRecurso(ambulancia1);
    agregarRecurso(ambulancia2);
    agregarRecurso(helicoptero1);
    agregarRecurso(medico1);
    agregarRecurso(medico2);
    agregarRecurso(rescatista1);
    agregarRecurso(rescatista2);

    // La mision 1 queda con 4 recursos heterogeneos asignados para poder
    // Ejecutar (opcion 5) de inmediato; asignar 4 ademas fuerza el
    // redimensionamiento manual del arreglo interno de la mision (HT01).
    mision1->asignarRecurso(ambulancia1);
    mision1->asignarRecurso(helicoptero1);
    mision1->asignarRecurso(medico1);
    mision1->asignarRecurso(rescatista1);
}

bool Controlador::leerEnteroEnRango(const std::string& mensaje, int minimo, int maximo, int& valorLeido) {
    std::string linea;
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\n(La entrada se cerró; saliendo del programa)" << std::endl;
            return false;
        }
        // Recorta espacios y retornos de carro al inicio y al final.
        size_t inicio = linea.find_first_not_of(" \t\r");
        size_t fin = linea.find_last_not_of(" \t\r");
        if (inicio == std::string::npos) {
            std::cout << "Opción inválida. Intente de nuevo." << std::endl;
            continue;
        }
        linea = linea.substr(inicio, fin - inicio + 1);

        // Solo digitos y maximo 9 caracteres (evita desbordar el int).
        bool valido = linea.size() <= 9;
        int resultado = 0;
        for (size_t i = 0; i < linea.size() && valido; i++) {
            if (linea[i] < '0' || linea[i] > '9') {
                valido = false;
            } else {
                resultado = resultado * 10 + (linea[i] - '0');
            }
        }
        if (valido && resultado >= minimo && resultado <= maximo) {
            valorLeido = resultado;
            return true;
        }
        std::cout << "Opción inválida. Intente de nuevo." << std::endl;
    }
}

bool Controlador::leerTexto(const std::string& mensaje, std::string& destino) {
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, destino)) {
            std::cout << "\n(La entrada se cerró; saliendo del programa)" << std::endl;
            return false;
        }
        // Recorta espacios, tabulaciones y el retorno de carro final (CRLF),
        // igual que leerEnteroEnRango: un texto de solo espacios NO es valido.
        size_t inicio = destino.find_first_not_of(" \t\r");
        size_t fin = destino.find_last_not_of(" \t\r");
        if (inicio != std::string::npos) {
            destino = destino.substr(inicio, fin - inicio + 1);
            return true;
        }
        std::cout << "El texto no puede estar vacío." << std::endl;
    }
}
