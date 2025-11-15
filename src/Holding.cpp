#include "Holding.hpp"

// El constructor  asigna los valores
Holding::Holding(Activo* activo, int cantidad, double costeMedio) {
    this->activo = activo;
    this->cantidad = cantidad;
    this->costeMedio = costeMedio;
}

// El Holding es "dueño" del Activo
Holding::~Holding() {
    // Cuando el Holding se destruye, destruye el Activo que "posee".
    // Portfolio borra Holding, Holding borra Activo.
    delete this->activo;
}

// --- Getters ---
Activo* Holding::getActivo() const {
    return this->activo;
}

int Holding::getCantidad() const {
    return this->cantidad;
}

double Holding::getCosteMedio() const {
    return this->costeMedio;
}
