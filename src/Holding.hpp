#pragma once
#include "Activo.hpp"

class Holding {
private:
    Activo* activo; 
    int cantidad;
    double costeMedio;

public:
    Holding(Activo* activo, int cantidad, double costeMedio);
    ~Holding();

    Activo* getActivo() const;
    int getCantidad() const;
    double getCosteMedio() const;

    void actualizarConCompra(int cantComprada, double precioCompra);
    void actualizarConVenta(int cantVendida);
};