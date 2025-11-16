#include "Accion.hpp"

// Implementación del constructor
Accion::Accion(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& sector)
    : Activo(nombre, precio, retorno, riesgo)
{
    this->sector = sector;
}

// Implementación de getter
std::string Accion::getSector() const {
    return this->sector;
}