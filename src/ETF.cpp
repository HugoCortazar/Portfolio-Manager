#include "ETF.hpp"

// Implementación del constructor
ETF::ETF(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& index, const std::string& pais)
    : Activo(nombre, precio, retorno, riesgo) 
{

    this->index = index;
    this->pais = pais;
}

// Implementación de getters
std::string ETF::getIndex() const {
    return this->index;
}

std::string ETF::getPais() const {
    return this->pais;
}