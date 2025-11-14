#pragma once

#include "Activo.hpp" 
#include <string>

// Hereda de Activo
class LibreRiesgo : public Activo {
public:
    // Constructor 
    LibreRiesgo(const std::string& nombre, double precio, double retorno, double riesgo);
    
};
