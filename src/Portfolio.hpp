#pragma once

#include <vector>
#include <string>
#include "Holding.hpp"
#include "Trade.hpp" 

class Portfolio {
private:
    std::vector<Holding*> holdings; 
    std::vector<Trade*> historialTrades; 
    double cantidadTotal;

    // Método "ayudante" privado
    Holding* encontrarHolding(Activo* activo); 

public:
    Portfolio();
    ~Portfolio(); 
    
    // Método principal para operar
    void procesarTrade(Trade* nuevoTrade);

    // Métodos para mostrar información
    void mostrarPortfolio() const;
    void mostrarHistorialTrades() const; 
    
    // Getter para los medidores
    const std::vector<Holding*>& getHoldings() const;
};