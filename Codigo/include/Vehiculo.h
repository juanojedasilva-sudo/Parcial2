/**
 * @file Vehiculo.h
 * @brief Clase intermedia abstracta para los recursos vehiculares (HU01).
 * @details Informacion CRC:
 *   Clase: Vehiculo (hereda de Recurso).
 *   Responsabilidades: agrupar los datos comunes de los vehiculos de rescate
 *     (placa y capacidad de personas) y extender la presentacion de la info.
 *   Colaboradores: Recurso (clase base); Ambulancia y Helicoptero (derivadas).
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"

// Clase intermedia abstracta para los recursos vehiculares (HU01).
class Vehiculo : public Recurso {
protected:
    std::string placa;
    int capacidad;   // numero de personas que puede transportar

public:
    Vehiculo(const std::string& nombre, const std::string& placa, int capacidad);
    virtual ~Vehiculo();

    void mostrarInfo() const override;
};

#endif
