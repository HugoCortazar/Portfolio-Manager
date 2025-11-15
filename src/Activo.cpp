#include "Activo.hpp"
#include <iostream> // Asegúrate de que está incluido

// CONSTRUCTOR: Modificar para inicializar el puntero
Activo::Activo(const std::string& nombre, double precio, double retorno, double riesgo) {
    this->nombre = nombre;
    this->precio = precio;
    this->retornoEsperado = retorno;
    this->riesgo = riesgo;
    
    this->historico = nullptr; // ¡MUY IMPORTANTE! Inicializar a 'nada'
}

// DESTRUCTOR: Modificar para borrar la memoria del histórico
Activo::~Activo() {
    std::cout << "Destruyendo Activo: " << this->nombre << std::endl;
    
    // Borramos el histórico que "poseemos"
    // 'delete' es seguro incluso si 'historico' es 'nullptr'
    delete this->historico; 
}

// --- Getters/Setters (sin cambios) ---
std::string Activo::getNombre() const { return this->nombre; }
double Activo::getPrecio() const { return this->precio; }
void Activo::setPrecio(double nuevoPrecio) { /* ... */ }

// --- NUEVOS MÉTODOS ---
void Activo::cargarHistorico(const std::string& nombreArchivo) {
    // Si ya teníamos un histórico, lo borramos antes de cargar uno nuevo
    if (this->historico != nullptr) {
        delete this->historico;
    }
    
    // Creamos el objeto (memoria dinámica)
    this->historico = new HistoricoPrecios();
    
    // Usamos el objeto para cargar el CSV
    if (this->historico->cargarDesdeCSV(nombreArchivo)) {
        std::cout << "Histórico cargado para: " << this->nombre << std::endl;
    } else {
        std::cout << "FALLO al cargar histórico para: " << this->nombre << std::endl;
    }
}

HistoricoPrecios* Activo::getHistorico() const {
    return this->historico;
}
