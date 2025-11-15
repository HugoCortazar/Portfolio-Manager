#pragma once
#include "Activo.hpp" 

class Holding {
private:
    Activo* activo; // El puntero al activo (Apple, Coca-Cola, etc.)
    int cantidad;
    double costeMedio;

public:
    // Constructor
    Holding(Activo* activo, int cantidad, double costeMedio);

    // Destructor
    ~Holding();

    // Getters para  leer los datos
    Activo* getActivo() const;
    int getCantidad() const;
    double getCosteMedio() const;

};