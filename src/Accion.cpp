#include "Accion.hpp"


// parámetros al constructor (Activo)
Accion::Accion(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& sector)
    : Activo(nombre, precio, retorno, riesgo) 
{

    this->sector = sector;
}

std::string Accion::getSector() const {
    return this->sector;
}