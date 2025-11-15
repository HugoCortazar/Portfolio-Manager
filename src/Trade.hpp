#pragma once

#include <string>
#include "Activo.hpp" 

// Definimos el 'enum class' para el tipo de trade
enum class TipoTrade {
    COMPRA,
    VENTA
};

class Trade {
private:
    TipoTrade tipo;
    std::string fecha;
    Activo* activo; 
    int cantidad;
    double precio; 

public:
    // Constructor
    Trade(Activo* activo, TipoTrade tipo, int cantidad, double precio, const std::string& fecha);

    // Getters
    TipoTrade getTipo() const;
    std::string getFecha() const;
    Activo* getActivo() const;
    int getCantidad() const;
    double getPrecio() const;
};