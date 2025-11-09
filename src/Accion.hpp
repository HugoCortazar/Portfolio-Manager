#pragma once

#include "Activo.hpp" 
#include <string>


class Accion : public Activo {
private:
    std::string sector; 

public:
    // El constructor de Accion necesita los datos para sí mismo Y para Activo
    Accion(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& sector);
    
    // Un getter para la nueva propiedad
    std::string getSector() const;
};