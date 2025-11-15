#include "HistoricoPrecios.hpp"
#include <iostream> 
#include <fstream>
#include <sstream>  
#include <stdexcept> 

// Constructor
HistoricoPrecios::HistoricoPrecios() {
    // El constructor puede estar vacío
}

// Destructor
HistoricoPrecios::~HistoricoPrecios() {
    std::cout << "Destruyendo Histórico (" << this->precios.size() << " registros)" << std::endl;
}

// Método para cargar el CSV
bool HistoricoPrecios::cargarDesdeCSV(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el fichero: " << nombreArchivo << std::endl;
        return false;
    }

    std::string linea;
    std::getline(archivo, linea); // Descartar cabecera

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string fechaStr, precioStr;

        std::getline(ss, fechaStr, ',');
        std::getline(ss, precioStr, ',');

        try {
            double precio = std::stod(precioStr);
            this->precios.push_back({fechaStr, precio});

        } catch (const std::invalid_argument& e) {
            std::cerr << "Advertencia: Línea mal formada en CSV: '" << linea << "'" << std::endl;
        }
    }

    archivo.close();
    return true;
}

// Método para mostrar precios
void HistoricoPrecios::mostrarPrecios() const {
    std::cout << "\n--- Histórico de Precios Cargado ---" << std::endl;
    for (const auto& registro : this->precios) {
        std::cout << "  Fecha: " << registro.fecha << ", Precio: " << registro.precio << std::endl;
    }
}

// "Getter" para la lista de precios
const std::vector<HistoricoPrecios::RegistroPrecio>& HistoricoPrecios::getPrecios() const {
    return this->precios;
}