#include "Holding.hpp"

Holding::Holding(Activo* activo, int cantidad, double costeMedio) {
    this->activo = activo;
    this->cantidad = cantidad;
    this->costeMedio = costeMedio;
}


Holding::~Holding() {
    // Cuando el Holding se destruye, destruye el Activo que "posee". Portfolio borra Holding, Holding borra Activo.
    delete this->activo;
}

Activo* Holding::getActivo() const {
    return this->activo;
}

int Holding::getCantidad() const {
    return this->cantidad;
}

double Holding::getCosteMedio() const {
    return this->costeMedio;
}
