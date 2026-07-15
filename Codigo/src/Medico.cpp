/**
 * @file Medico.cpp
 * @brief Implementacion de la clase Medico.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
#include "Medico.h"
#include <iostream>

Medico::Medico(const std::string& nombre, const std::string& especialidad)
    : Personal(nombre, especialidad) {
}

Medico::~Medico() {
}

void Medico::ejecutarAccion() const {
    // HU03: salida exacta exigida por el enunciado.
    std::cout << "Estabilizando signos vitales" << std::endl;
}

void Medico::mostrarInfo() const {
    std::cout << "[Médico]      ";
    Personal::mostrarInfo();
    std::cout << std::endl;
}
