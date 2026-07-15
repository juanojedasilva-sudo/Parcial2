/**
 * @file Mision.h
 * @brief Mision de emergencia que agrupa recursos heterogeneos (HU02, HU03).
 * @details Informacion CRC:
 *   Clase: Mision.
 *   Responsabilidades: almacenar punteros a recursos heterogeneos bajo la
 *     clase base Recurso en un arreglo dinamico manual (HT01), redimensionarlo,
 *     y ejecutar la orden operativa recorriendolos polimorficamente (HU03).
 *   Colaboradores: Recurso (agregacion, no es duenia); Controlador (la crea).
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef MISION_H
#define MISION_H

#include "Recurso.h"

// Mision de emergencia: agrupa recursos heterogeneos bajo la clase base (HU02).
// NO es duenia de los recursos (agregacion): solo guarda punteros; la memoria
// de cada recurso la administra el Controlador.
class Mision {
private:
    int id;
    std::string descripcion;
    std::string zona;

    // Arreglo dinamico de punteros a la clase base (HT01).
    Recurso** recursosAsignados;
    int cantidadRecursos;
    int capacidadRecursos;

    // Duplica la capacidad del arreglo copiando los punteros (HT01).
    void redimensionar();

public:
    Mision(int id, const std::string& descripcion, const std::string& zona);
    ~Mision();   // libera SOLO el arreglo de punteros (HT02)

    // No copiable: una copia superficial duplicaria el puntero al arreglo y
    // provocaria doble delete (HT02); ademas obliga a pasar toda Mision por
    // referencia o puntero (HT03). El compilador rechaza cualquier copia.
    Mision(const Mision&) = delete;
    Mision& operator=(const Mision&) = delete;

    void asignarRecurso(Recurso* recurso);              // HU02
    bool tieneRecurso(const Recurso* recurso) const;
    void ejecutar() const;                              // HU03: recorrido polimorfico
    void mostrarInfo() const;

    const std::string& getDescripcion() const;
};

#endif
