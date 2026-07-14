/**
 * @file Vehiculo.cpp
 * @brief Implementacion de la clase intermedia Vehiculo.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 */
#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const std::string& nombre, const std::string& placa, int capacidad)
    : Recurso(nombre), placa(placa), capacidad(capacidad) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::mostrarInfo() const {
    Recurso::mostrarInfo();
    std::cout << " | Placa: " << placa << " | Capacidad: " << capacidad << " personas";
}
