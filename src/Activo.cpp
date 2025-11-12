#include "Activo.hpp"
#include <iostream> // Necesario para std::cout

using namespace std;

// --- 1. CONSTRUCTOR ---
Activo::Activo(const std::string& nombre, double precio, double retorno, double riesgo) {
    this->nombre = nombre;
    this->precio = precio;
    this->retornoEsperado = retorno;
    this->riesgo = riesgo;
}

// --- 2. GETTERS Y SETTERS ---
string Activo::getNombre() const {
    return this->nombre;
}

double Activo::getPrecio() const {
    return this->precio;
}

void Activo::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) {
        this->precio = nuevoPrecio;
    }
}

// --- 3. IMPLEMENTACIONES VIRTUALES (SOLO UNA VEZ) ---

Activo::~Activo() {
    // Destructor virtual necesario para polimorfismo
    // Mensaje para depurar:
    std::cout << "Destruyendo Activo: " << this->nombre << std::endl;
}

void Activo::imprimirDetalle() const {
    // Implementación base
    std::cout << "  Nombre: " << this->nombre << " | Precio: " << this->precio << std::endl;
}