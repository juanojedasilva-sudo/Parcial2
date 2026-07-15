/**
 * @file Medico.h
 * @brief Personal medico para la atencion en salud (HU01, HU03).
 * @details Informacion CRC:
 *   Clase: Medico (hereda de Personal).
 *   Responsabilidades: redefinir la accion operativa con su comportamiento
 *     concreto ("Estabilizando signos vitales").
 *   Colaboradores: Personal (clase base); instanciado por el Controlador.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"

// Personal medico encargado de la atencion en salud.
class Medico : public Personal {
public:
    Medico(const std::string& nombre, const std::string& especialidad);
    ~Medico();

    void ejecutarAccion() const override;   // HU03
    void mostrarInfo() const override;
};

#endif
