/**
 * @file main.cpp
 * @brief Punto de entrada del SGMR: solo instancia el Controlador (HU04).
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
#include "Controlador.h"

// HU04: main minimo — solo instancia el Controlador e invoca su metodo de inicio.
// Al ser un objeto de pila, su destructor se ejecuta automaticamente al
// terminar main, liberando toda la memoria dinamica del sistema (HT02).
int main() {
    Controlador controlador;
    controlador.iniciar();
    return 0;
}
