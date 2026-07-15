/**
 * @file Recurso.cpp
 * @brief Implementacion de la clase base Recurso.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
#include "Recurso.h"
#include <iostream>

Recurso::Recurso(const std::string& nombre) : nombre(nombre) {
}

Recurso::~Recurso() {
    // Mensaje de evidencia para HT02: se ve la liberacion de cada recurso.
    std::cout << "  [Memoria] Liberando recurso: " << nombre << std::endl;
}

void Recurso::mostrarInfo() const {
    std::cout << "Nombre: " << nombre;
}

const std::string& Recurso::getNombre() const {
    return nombre;
}
