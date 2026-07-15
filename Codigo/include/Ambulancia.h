/**
 * @file Ambulancia.h
 * @brief Recurso vehicular terrestre para transporte de pacientes (HU01, HU03).
 * @details Informacion CRC:
 *   Clase: Ambulancia (hereda de Vehiculo).
 *   Responsabilidades: redefinir la accion operativa con su comportamiento
 *     concreto ("Transportando paciente vía terrestre").
 *   Colaboradores: Vehiculo (clase base); instanciada por el Controlador.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

// Recurso vehicular terrestre para transporte de pacientes.
class Ambulancia : public Vehiculo {
public:
    Ambulancia(const std::string& nombre, const std::string& placa, int capacidad);
    ~Ambulancia();

    void ejecutarAccion() const override;   // HU03
    void mostrarInfo() const override;
};

#endif
