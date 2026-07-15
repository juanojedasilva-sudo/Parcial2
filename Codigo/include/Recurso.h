/**
 * @file Recurso.h
 * @brief Clase base abstracta de todo recurso del SGMR (HU02).
 * @details Informacion CRC:
 *   Clase: Recurso.
 *   Responsabilidades: representar de forma generica un recurso de rescate
 *     (nombre), declarar la accion operativa polimorfica (HU03) y mostrar
 *     su informacion.
 *   Colaboradores: Mision y Controlador lo referencian mediante punteros.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef RECURSO_H
#define RECURSO_H

#include <string>

// Clase base abstracta de todo recurso del SGMR (vehiculos y personal).
// Permite tratar recursos heterogeneos bajo un mismo concepto (HU02).
class Recurso {
protected:
    std::string nombre;

public:
    Recurso(const std::string& nombre);
    virtual ~Recurso();   // virtual: garantiza la destruccion correcta via punteros a la base (HT02)

    // Accion operativa que cada recurso concreto redefine (HU03, polimorfismo).
    virtual void ejecutarAccion() const = 0;

    // Muestra la informacion del recurso; las subclases la extienden.
    virtual void mostrarInfo() const;

    const std::string& getNombre() const;
};

#endif
