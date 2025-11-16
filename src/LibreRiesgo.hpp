#pragma once

#include "Activo.hpp" 
#include <string>

// Hereda de Activo
class LibreRiesgo : public Activo {
public:
    // El constructor de LibreRiesgo solo necesita los datos para "Activo"
    LibreRiesgo(const std::string& nombre, double precio, double retorno, double riesgo);
    

};