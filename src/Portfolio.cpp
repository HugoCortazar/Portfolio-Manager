#include "Portfolio.hpp"
#include <iostream>

// Constructor
Portfolio::Portfolio() {
    this->cantidadTotal = 0.0;
}

//DESTRUCTOR
Portfolio::~Portfolio() {
    std::cout << "\n--- Limpiando memoria del Portfolio ---" << std::endl;
    
    //Borrar todos los Trades
    std::cout << "--- Limpiando historial de trades ---" << std::endl;
    for (Trade* tradePtr : this->historialTrades) {
        std::cout << "Liberando trade (" << tradePtr->getActivo()->getNombre() << ")" << std::endl;
        delete tradePtr; // Borra el objeto Trade
    }

    //Borrar todos los Holdings
    std::cout << "--- Limpiando holdings ---" << std::endl;
    for (Holding* holdingPtr : this->holdings) {
        std::cout << "Liberando holding: " << holdingPtr->getActivo()->getNombre() << std::endl;
        delete holdingPtr; 
    }
}

// Muestra el contenido actual del portfolio
void Portfolio::mostrarPortfolio() const {
    std::cout << "\n--- === Contenido del Portfolio === ---" << std::endl;
    for (const Holding* holdingPtr : this->holdings) {
        Activo* activoPtr = holdingPtr->getActivo();
        std::cout << " - Activo: " << activoPtr->getNombre();
        std::cout << " | Cantidad: " << holdingPtr->getCantidad();
        std::cout << " | Precio Act: " << activoPtr->getPrecio() << std::endl;
    }
    std::cout << "--- =============================== ---" << std::endl;
}

// Muestra el historial de todas las transacciones
void Portfolio::mostrarHistorialTrades() const {
    std::cout << "\n--- === Historial de Transacciones === ---" << std::endl;
    for (const Trade* tradePtr : this->historialTrades) {
        std::string tipoStr = (tradePtr->getTipo() == TipoTrade::COMPRA) ? "COMPRA" : "VENTA";
        
        std::cout << " - " << tradePtr->getFecha();
        std::cout << " | " << tipoStr;
        std::cout << " | " << tradePtr->getActivo()->getNombre();
        std::cout << " | " << tradePtr->getCantidad() << " x " << tradePtr->getPrecio() << " USD" << std::endl;
    }
    std::cout << "--- ================================== ---" << std::endl;
}

// "Getter" para que los Medidores puedan leer los holdings
const std::vector<Holding*>& Portfolio::getHoldings() const {
    return this->holdings;
}

// Método "ayudante" privado para buscar un holding existente
Holding* Portfolio::encontrarHolding(Activo* activo) {
    for (Holding* h : this->holdings) {
        if (h->getActivo() == activo) {
            return h; // Encontrado
        }
    }
    return nullptr; // No encontrado
}

//Procesa una compra o venta
void Portfolio::procesarTrade(Trade* nuevoTrade) {
    if (nuevoTrade == nullptr) return;

    this->historialTrades.push_back(nuevoTrade);
    Activo* activoDelTrade = nuevoTrade->getActivo();
    Holding* holdingExistente = encontrarHolding(activoDelTrade);

    if (nuevoTrade->getTipo() == TipoTrade::COMPRA) {
        if (holdingExistente == nullptr) {
            //Primera compra de este activo
            std::cout << "Creando nuevo holding para: " << activoDelTrade->getNombre() << std::endl;
            Holding* nuevoHolding = new Holding(
                activoDelTrade,
                nuevoTrade->getCantidad(),
                nuevoTrade->getPrecio()
            );
            this->holdings.push_back(nuevoHolding);
        } else {
            //Comprando más de un activo que ya tenemos
            holdingExistente->actualizarConCompra(
                nuevoTrade->getCantidad(),
                nuevoTrade->getPrecio()
            );
        }
    } 
    else if (nuevoTrade->getTipo() == TipoTrade::VENTA) {
        if (holdingExistente == nullptr) {
            std::cerr << "Error: Intento de VENTA de un activo no poseído: " 
                      << activoDelTrade->getNombre() << std::endl;
        } else {
            //Venta de un activo que poseemos
            holdingExistente->actualizarConVenta(nuevoTrade->getCantidad());
            
            if (holdingExistente->getCantidad() == 0) {
                std::cout << "Cantidad de " << activoDelTrade->getNombre() << " es 0. Eliminando holding." << std::endl;
                for (size_t i = 0; i < this->holdings.size(); ++i) {
                    if (this->holdings[i] == holdingExistente) {
                        this->holdings.erase(this->holdings.begin() + i); 
                        delete holdingExistente; // Borra el holding (no el activo)
                        break; 
                    }
                }
            }
        }
    }
}