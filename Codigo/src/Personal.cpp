/**
 * @file Personal.cpp
 * @brief Implementacion de la clase intermedia Personal.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
#include "Personal.h"
#include <iostream>

Personal::Personal(const std::string& nombre, const std::string& especialidad)
    : Recurso(nombre), especialidad(especialidad) {
}

Personal::~Personal() {
}

void Personal::mostrarInfo() const {
    Recurso::mostrarInfo();
    std::cout << " | Especialidad: " << especialidad;
}
