#include "Portfolio.hpp"
#include <iostream> 

// Constructor: Inicializa las variables
Portfolio::Portfolio() {
    this->cantidadTotal = 0.0;
    // El vector 'activos' se inicializa vacío por defecto
}


Portfolio::~Portfolio() {
    std::cout << "\n--- Limpiando memoria del Portfolio ---" << std::endl;
    // Debemos recorrer el vector y borrar CADA puntero que contiene
    for (Activo* activoPtr : this->activos) {
        std::cout << "Liberando: " << activoPtr->getNombre() << std::endl;
        delete activoPtr; //Libera la memoria
    }
    
}

// Añade un puntero a activo al vector
void Portfolio::anadirActivo(Activo* nuevoActivo) {
    if (nuevoActivo != nullptr) {
        this->activos.push_back(nuevoActivo);
        std::cout << "Activo añadido: " << nuevoActivo->getNombre() << std::endl;
    }
}

// Muestra todos los activos
// EL REEMPLAZO (CON POLIMORFISMO)
void Portfolio::mostrarPortfolio() const {
    std::cout << "\n--- === Contenido del Portfolio === ---" << std::endl;
    for (const Activo* activoPtr : this->activos) {
        
        // ¡AQUÍ OCURRE LA MAGIA!
        activoPtr->imprimirDetalle(); // <-- ¡Llamada polimórfica!

        std::cout << "-----------------------------------" << std::endl;
    }
    std::cout << "--- =============================== ---" << std::endl;
}