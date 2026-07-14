/**
 * @file Ambulancia.cpp
 * @brief Implementacion de la clase Ambulancia.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 */
#include "Ambulancia.h"
#include <iostream>

Ambulancia::Ambulancia(const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(nombre, placa, capacidad) {
}

Ambulancia::~Ambulancia() {
}

void Ambulancia::ejecutarAccion() const {
    // HU03: salida exacta exigida por el enunciado.
    std::cout << "Transportando paciente vía terrestre" << std::endl;
}

void Ambulancia::mostrarInfo() const {
    std::cout << "[Ambulancia]  ";
    Vehiculo::mostrarInfo();
    std::cout << std::endl;
}
