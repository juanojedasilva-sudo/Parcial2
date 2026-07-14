/**
 * @file Personal.h
 * @brief Clase intermedia abstracta para el personal humano de rescate (HU01).
 * @details Informacion CRC:
 *   Clase: Personal (hereda de Recurso).
 *   Responsabilidades: agrupar los datos comunes del personal (especialidad)
 *     y extender la presentacion de la informacion.
 *   Colaboradores: Recurso (clase base); Medico y Rescatista (derivadas).
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

// Clase intermedia abstracta para el personal humano (HU01).
class Personal : public Recurso {
protected:
    std::string especialidad;

public:
    Personal(const std::string& nombre, const std::string& especialidad);
    virtual ~Personal();

    void mostrarInfo() const override;
};

#endif
