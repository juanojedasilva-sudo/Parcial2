/**
 * @file Controlador.h
 * @brief Clase controladora que orquesta todo el flujo del SGMR (HU04).
 * @details Informacion CRC:
 *   Clase: Controlador.
 *   Responsabilidades: desplegar el menu interactivo, registrar recursos
 *     (HU01), crear misiones, delegar asignacion y ejecucion (HU02, HU03),
 *     cargar los datos de prueba (HU05) y administrar TODA la memoria
 *     dinamica del sistema (composicion, HT01/HT02).
 *   Colaboradores: Recurso y sus derivadas, Mision; main.cpp solo lo instancia.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @date 14/07/2026
 * @version 1.0
 * Curso: Fundamentos de Programacion Orientada a Objetos - Grupo 80, Universidad del Valle.
 */
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include "Recurso.h"
#include "Mision.h"

// Clase controladora del SGMR (HU04): unica clase instanciada desde main.cpp.
// Es la duenia de toda la memoria dinamica del sistema: el inventario general
// de recursos y las misiones (composicion).
class Controlador {
private:
    // Inventario general de recursos (HT01: arreglo dinamico de punteros).
    Recurso** listaRecursos;
    int cantidadRecursos;
    int capacidadRecursos;

    // Misiones de emergencia creadas.
    Mision** listaMisiones;
    int cantidadMisiones;
    int capacidadMisiones;

    // ---- Opciones del menu ----
    void verRecursos() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMision();

    // ---- Utilidades internas ----
    void mostrarMenu() const;
    void mostrarMisiones() const;
    void agregarRecurso(Recurso* recurso);
    void agregarMision(Mision* mision);
    void cargarDatosPrueba();   // HU05: datos quemados (metodo oculto)

    // Lectura validada por consola. Devuelven false si la entrada se cierra
    // (EOF), para que el programa pueda salir de forma ordenada y sin bucles.
    bool leerEnteroEnRango(const std::string& mensaje, int minimo, int maximo, int& valorLeido);
    bool leerTexto(const std::string& mensaje, std::string& destino);

public:
    Controlador();
    ~Controlador();   // HT02: libera recursos, misiones y ambos arreglos

    // No copiable: el Controlador es el unico dueno de la memoria del
    // sistema; copiarlo duplicaria los punteros y causaria doble delete
    // (HT02). Tambien fuerza el paso por referencia o puntero (HT03).
    Controlador(const Controlador&) = delete;
    Controlador& operator=(const Controlador&) = delete;

    void iniciar();   // despliega el ciclo del menu principal (HU04)
};

#endif
