#pragma once

#include "Activo.hpp"
#include <string>

// Hereda de Activo
class Accion : public Activo {
private:
    std::string sector;

public:
    // El constructor de Accion
    Accion(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& sector);
    
    // Getter específico
    std::string getSector() const;
};