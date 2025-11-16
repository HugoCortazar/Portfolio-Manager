#include "Trade.hpp"

// Constructor
Trade::Trade(Activo* activo, TipoTrade tipo, int cantidad, double precio, const std::string& fecha) {
    this->activo = activo;
    this->tipo = tipo;
    this->cantidad = cantidad;
    this->precio = precio;
    this->fecha = fecha;
}

//Getters
TipoTrade Trade::getTipo() const {
    return this->tipo;
}
std::string Trade::getFecha() const {
    return this->fecha;
}
Activo* Trade::getActivo() const {
    return this->activo;
}
int Trade::getCantidad() const {
    return this->cantidad;
}
double Trade::getPrecio() const {
    return this->precio;
}