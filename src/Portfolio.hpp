#pragma once

#include <vector>
#include <string>
#include "Holding.hpp" // Ahora incluimos "Holding.hpp" en vez de activo

class Portfolio {
private:
    // Ya no es un vector de Activo, sino de Holding
    std::vector<Holding*> holdings; 
    
    double cantidadTotal; // Dinero

public:
    Portfolio();
    ~Portfolio(); // El destructor ahora borrará los Holdings

    void anadirHolding(Holding* nuevoHolding);

    void mostrarPortfolio() const;
};