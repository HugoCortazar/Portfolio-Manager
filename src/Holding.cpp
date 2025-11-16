#include "Holding.hpp"
#include <iostream>

// Constructor
Holding::Holding(Activo* activo, int cantidad, double costeMedio) {
    this->activo = activo;
    this->cantidad = cantidad;
    this->costeMedio = costeMedio;
}

// Destructor
Holding::~Holding() {

}

//Getters
Activo* Holding::getActivo() const { 
    return this->activo; 
}
int Holding::getCantidad() const { 
    return this->cantidad; 
}
double Holding::getCosteMedio() const { 
    return this->costeMedio; 
}

//Métodos de actualización

void Holding::actualizarConCompra(int cantComprada, double precioCompra) {
    double costeTotalActual = this->costeMedio * this->cantidad;
    double costeNuevaCompra = precioCompra * cantComprada;
    int nuevaCantidadTotal = this->cantidad + cantComprada;

    if (nuevaCantidadTotal > 0) { 
        this->costeMedio = (costeTotalActual + costeNuevaCompra) / nuevaCantidadTotal;
    }
    this->cantidad = nuevaCantidadTotal;
    
    std::cout << "Holding actualizado (COMPRA): " << this->activo->getNombre() 
              << " | Nueva Cant: " << this->cantidad 
              << " | Nuevo Coste: " << this->costeMedio << std::endl;
}

void Holding::actualizarConVenta(int cantVendida) {
    if (cantVendida > this->cantidad) {
        std::cerr << "Advertencia: Se intento vender mas de lo que se posee." << std::endl;
        cantVendida = this->cantidad;
    }
    
    this->cantidad -= cantVendida;
    
    std::cout << "Holding actualizado (VENTA): " << this->activo->getNombre() 
              << " | Nueva Cant: " << this->cantidad << std::endl;
}