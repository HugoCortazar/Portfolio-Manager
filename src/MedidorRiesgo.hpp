#pragma once

#include "Portfolio.hpp" 
#include "Activo.hpp"    

class MedidorRiesgo {
private:
    // Función "ayudante" privada
    static double calcularStdDev(Activo* activo);

public:
    // Función pública estática
    static double calcularRiesgoPortfolio(Portfolio* portfolio);
};