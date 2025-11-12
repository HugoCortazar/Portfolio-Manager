#include "ETF.hpp"
#include <iostream> // Para std::cout

// Implementación del constructor
ETF::ETF(const std::string& nombre, double precio, double retorno, double riesgo, 
         const std::string& gestora, const std::vector<std::string>& posiciones)
    : Activo(nombre, precio, retorno, riesgo) // <-- Llama al constructor del padre (Activo)
{
    this->gestora = gestora;
    this->principalesPosiciones = posiciones;
}

// Implementación del destructor
ETF::~ETF() {
    // Mensaje para ver cómo se llama (gracias al polimorfismo)
    std::cout << "Destruyendo ETF: " << this->nombre << std::endl;
}

std::string ETF::getGestora() const {
    return this->gestora;
}

// [RECOMENDADO] Implementación de la Sobrecarga Dinámica
void ETF::imprimirDetalle() const {
    // 1. Llama al método del padre (Activo) para imprimir los datos comunes
    Activo::imprimirDetalle(); 
    
    // 2. Añade la información específica de ETF
    std::cout << "  Gestora: " << this->gestora << std::endl;
    std::cout << "  Principales Posiciones:" << std::endl;
    for (const std::string& pos : principalesPosiciones) {
        std::cout << "    - " << pos << std::endl;
    }
}