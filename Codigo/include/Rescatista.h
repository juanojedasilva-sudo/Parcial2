/**
 * @file Rescatista.h
 * @brief Personal de rescate para busqueda de sobrevivientes (HU01, HU03).
 * @details Informacion CRC:
 *   Clase: Rescatista (hereda de Personal).
 *   Responsabilidades: redefinir la accion operativa con su comportamiento
 *     concreto ("Buscando sobrevivientes en escombros").
 *   Colaboradores: Personal (clase base); instanciado por el Controlador.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"

// Personal de rescate encargado de la busqueda de sobrevivientes.
class Rescatista : public Personal {
public:
    Rescatista(const std::string& nombre, const std::string& especialidad);
    ~Rescatista();

    void ejecutarAccion() const override;   // HU03
    void mostrarInfo() const override;
};

#endif
