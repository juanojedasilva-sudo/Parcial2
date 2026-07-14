/**
 * @file Rescatista.cpp
 * @brief Implementacion de la clase Rescatista.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 */
#include "Rescatista.h"
#include <iostream>

Rescatista::Rescatista(const std::string& nombre, const std::string& especialidad)
    : Personal(nombre, especialidad) {
}

Rescatista::~Rescatista() {
}

void Rescatista::ejecutarAccion() const {
    // HU03: salida exacta exigida por el enunciado.
    std::cout << "Buscando sobrevivientes en escombros" << std::endl;
}

void Rescatista::mostrarInfo() const {
    std::cout << "[Rescatista]  ";
    Personal::mostrarInfo();
    std::cout << std::endl;
}
