/**
 * @file test_memoria.cpp
 * @brief Test de HT02: comprueba cero fugas de memoria contando new/delete.
 * @author Juan Diego Ojeda Silva (cod. 2517089)
 * @mail juan.ojeda.silva@correounivalle.edu.co
 * @date 14/07/2026
 * @version 1.0
 */
// Verificacion de HT02 (cero fugas de memoria) sin depender de valgrind:
// se reemplazan los operadores globales new/delete por versiones que cuentan
// cada asignacion y liberacion, y se simulan dos sesiones completas del SGMR
// redirigiendo std::cin. La primera sesion "calienta" las asignaciones
// perezosas internas de iostreams/locale; en la segunda, cualquier new sin
// su delete correspondiente es una fuga real del SGMR.
//
// Compilar (desde Codigo/), excluyendo src/main.cpp para no duplicar main.
// IMPORTANTE: enlazar con -static en MinGW; si libstdc++ va como DLL, las
// asignaciones internas de la DLL no pasan por estos operadores reemplazados
// y el conteo queda descuadrado (se observo un falso -2 por sesion sin -static):
//   g++ -std=c++17 -Wall -static -static-libgcc -static-libstdc++ -Iinclude
//       [todos los .cpp de src/ MENOS main.cpp] tests/test_memoria.cpp
//       -o tests/test_memoria.exe

#include <cstdlib>
#include <new>
#include <iostream>
#include <sstream>
#include "Controlador.h"

static long long conteoNew = 0;
static long long conteoDelete = 0;

void* operator new(std::size_t tamanio) {
    void* puntero = std::malloc(tamanio);
    if (puntero == nullptr) {
        std::abort();
    }
    conteoNew++;
    return puntero;
}

void* operator new[](std::size_t tamanio) {
    return operator new(tamanio);
}

void operator delete(void* puntero) noexcept {
    if (puntero != nullptr) {
        conteoDelete++;
        std::free(puntero);
    }
}

void operator delete[](void* puntero) noexcept {
    operator delete(puntero);
}

void operator delete(void* puntero, std::size_t) noexcept {
    operator delete(puntero);
}

void operator delete[](void* puntero, std::size_t) noexcept {
    operator delete(puntero);
}

// Sesion completa: ver recursos, ejecutar (llena y vacia), registrar un
// helicoptero, crear mision, asignar (y duplicado), ejecutar la nueva,
// entradas invalidas y salir.
static const char* ENTRADA_SIMULADA =
    "1\n5\n1\n5\n2\n2\n2\nHalcon 2\nHK-3000\n8\n"
    "3\nRescate vertical\nFarallones de Cali\n"
    "4\n3\n8\n4\n3\n8\n5\n3\nabc\n99\n6\n";

static long long ejecutarSesion() {
    std::istringstream entrada(ENTRADA_SIMULADA);
    std::cin.clear();
    std::streambuf* bufferOriginal = std::cin.rdbuf(entrada.rdbuf());

    long long antesNew = conteoNew;
    long long antesDelete = conteoDelete;
    {
        Controlador controlador;
        controlador.iniciar();
    }
    long long netas = (conteoNew - antesNew) - (conteoDelete - antesDelete);

    std::cin.rdbuf(bufferOriginal);
    std::cin.clear();
    return netas;
}

int main() {
    // Las primeras sesiones pueden absorber (o liberar) asignaciones perezosas
    // internas de iostreams/locale que no pertenecen al SGMR; una fuga real
    // del SGMR apareceria como un saldo POSITIVO constante en TODAS las
    // sesiones. Por eso se ejecutan varias y se exige balance exacto de cero
    // en las dos ultimas (regimen estable).
    const int TOTAL_SESIONES = 4;
    long long netasPorSesion[TOTAL_SESIONES] = {};
    for (int i = 0; i < TOTAL_SESIONES; i++) {
        netasPorSesion[i] = ejecutarSesion();
    }

    std::cout << "\n[TEST MEMORIA] news totales: " << conteoNew
              << " | deletes totales: " << conteoDelete << std::endl;
    for (int i = 0; i < TOTAL_SESIONES; i++) {
        std::cout << "[TEST MEMORIA] fugas netas de la sesión " << (i + 1)
                  << ": " << netasPorSesion[i] << std::endl;
    }

    bool sinFugas = (netasPorSesion[TOTAL_SESIONES - 2] == 0)
                 && (netasPorSesion[TOTAL_SESIONES - 1] == 0);
    if (sinFugas) {
        std::cout << "[TEST MEMORIA] OK: cero fugas de memoria en régimen estable." << std::endl;
        return 0;
    }
    std::cout << "[TEST MEMORIA] FALLO: hay new sin su delete correspondiente." << std::endl;
    return 1;
}
