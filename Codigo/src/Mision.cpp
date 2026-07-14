/**
 * @file Mision.cpp
 * @brief Implementacion de la clase Mision.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 */
#include "Mision.h"
#include <iostream>

static const int CAPACIDAD_INICIAL_ASIGNADOS = 2;

Mision::Mision(int id, const std::string& descripcion, const std::string& zona)
    : id(id), descripcion(descripcion), zona(zona),
      recursosAsignados(new Recurso*[CAPACIDAD_INICIAL_ASIGNADOS]),
      cantidadRecursos(0),
      capacidadRecursos(CAPACIDAD_INICIAL_ASIGNADOS) {
}

Mision::~Mision() {
    // HT02: la mision NO es duenia de los recursos (agregacion), asi que
    // libera unicamente su arreglo de punteros; los recursos los libera
    // el Controlador, evitando el doble delete.
    std::cout << "  [Memoria] Liberando misión " << id << " (" << descripcion << ")" << std::endl;
    delete[] recursosAsignados;
    recursosAsignados = nullptr;   // buena practica del curso: puntero a nullptr tras delete
}

void Mision::redimensionar() {
    // HT01: redimensionamiento manual del arreglo dinamico de punteros.
    capacidadRecursos = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[capacidadRecursos];
    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }
    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
}

void Mision::asignarRecurso(Recurso* recurso) {
    if (cantidadRecursos == capacidadRecursos) {
        redimensionar();
    }
    recursosAsignados[cantidadRecursos] = recurso;
    cantidadRecursos++;
}

bool Mision::tieneRecurso(const Recurso* recurso) const {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (recursosAsignados[i] == recurso) {
            return true;
        }
    }
    return false;
}

void Mision::ejecutar() const {
    // HU03: orden general de ejecucion. Cada recurso responde segun su tipo
    // real gracias al enlace dinamico (metodos virtuales), sin ningun
    // if/switch por tipo.
    std::cout << "\n>>> Ejecutando misión " << id << ": " << descripcion
              << " (Zona: " << zona << ")" << std::endl;
    if (cantidadRecursos == 0) {
        std::cout << "La misión no tiene recursos asignados todavía." << std::endl;
        return;
    }
    for (int i = 0; i < cantidadRecursos; i++) {
        std::cout << " - " << recursosAsignados[i]->getNombre() << ": ";
        recursosAsignados[i]->ejecutarAccion();
    }
}

void Mision::mostrarInfo() const {
    std::cout << "Misión " << id << ": " << descripcion
              << " | Zona: " << zona
              << " | Recursos asignados: " << cantidadRecursos << std::endl;
}

const std::string& Mision::getDescripcion() const {
    return descripcion;
}
