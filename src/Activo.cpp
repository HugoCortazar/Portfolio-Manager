#include "Activo.hpp"

using namespace std;

// Usamos "Activo::" para indicar que esta función pertenece a la clase Activo
Activo::Activo(const std::string& nombre, double precio, double retorno, double riesgo) {

    this->nombre = nombre;
    this->precio = precio;
    this->retornoEsperado = retorno;
    this->riesgo = riesgo;
}

// Implementación de los getters
string Activo::getNombre() const {
    return this->nombre;
}

double Activo::getPrecio() const {
    return this->precio;
}

// Implementación del setter
void Activo::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) {
        this->precio = nuevoPrecio;
    }
}