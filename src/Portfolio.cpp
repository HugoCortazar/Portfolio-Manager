#include "Portfolio.hpp"
#include <iostream>

Portfolio::Portfolio() {
    this->cantidadTotal = 0.0;
}

// DESTRUCTOR 
Portfolio::~Portfolio() {
    std::cout << "\n--- Limpiando memoria del Portfolio ---" << std::endl;
    // Recorremos el vector de holdings y borramos CADA holding
    for (Holding* holdingPtr : this->holdings) {
        std::cout << "Liberando holding: " << holdingPtr->getActivo()->getNombre() << std::endl;
        delete holdingPtr; // Esto llamará al destructor de Holding
                           // que a su vez llamará 'delete' para el Activo
    }
}

// MÉTODO AÑADIR 
void Portfolio::anadirHolding(Holding* nuevoHolding) {
    if (nuevoHolding != nullptr) {
        this->holdings.push_back(nuevoHolding);
        std::cout << "Holding añadido: " << nuevoHolding->getActivo()->getNombre() << std::endl;
    }
}

// MOSTRAR PORTFOLIO 
void Portfolio::mostrarPortfolio() const {
    std::cout << "\n--- === Contenido del Portfolio === ---" << std::endl;
    for (const Holding* holdingPtr : this->holdings) {
        // Para leer los datos del activo, primero lo obtenemos del holding
        Activo* activoPtr = holdingPtr->getActivo();

        std::cout << " - Activo: " << activoPtr->getNombre();
        std::cout << " | Cantidad: " << holdingPtr->getCantidad(); // Dato del Holding
        std::cout << " | Precio Act: " << activoPtr->getPrecio() << std::endl;
    }
    std::cout << "--- =============================== ---" << std::endl;
}