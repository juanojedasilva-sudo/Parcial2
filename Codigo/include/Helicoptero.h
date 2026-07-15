/**
 * @file Helicoptero.h
 * @brief Recurso vehicular aereo para extracciones (HU01, HU03).
 * @details Informacion CRC:
 *   Clase: Helicoptero (hereda de Vehiculo).
 *   Responsabilidades: redefinir la accion operativa con su comportamiento
 *     concreto ("Realizando extracción aérea").
 *   Colaboradores: Vehiculo (clase base); instanciado por el Controlador.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

// Recurso vehicular aereo para extracciones y sobrevuelo de zonas.
class Helicoptero : public Vehiculo {
public:
    Helicoptero(const std::string& nombre, const std::string& placa, int capacidad);
    ~Helicoptero();

    void ejecutarAccion() const override;   // HU03
    void mostrarInfo() const override;
};

#endif
