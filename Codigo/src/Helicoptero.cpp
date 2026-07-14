/**
 * @file Helicoptero.cpp
 * @brief Implementacion de la clase Helicoptero.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 */
#include "Helicoptero.h"
#include <iostream>

Helicoptero::Helicoptero(const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(nombre, placa, capacidad) {
}

Helicoptero::~Helicoptero() {
}

void Helicoptero::ejecutarAccion() const {
    // HU03: salida exacta exigida por el enunciado.
    std::cout << "Realizando extracción aérea" << std::endl;
}

void Helicoptero::mostrarInfo() const {
    std::cout << "[Helicóptero] ";
    Vehiculo::mostrarInfo();
    std::cout << std::endl;
}
