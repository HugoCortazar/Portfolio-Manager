#include "Activo.hpp"
#include <iostream> 

//Constructor
Activo::Activo(const std::string& nombre, double precio, double retorno, double riesgo) {
    this->nombre = nombre;
    this->precio = precio;
    this->retornoEsperado = retorno;
    this->riesgo = riesgo;
    
    this->historico = nullptr;
}

//Destructor
Activo::~Activo() {
    std::cout << "Destruyendo Activo: " << this->nombre << std::endl;
    delete this->historico; 
}

//Getters
std::string Activo::getNombre() const { 
    return this->nombre; 
}
double Activo::getPrecio() const { 
    return this->precio; 
}
HistoricoPrecios* Activo::getHistorico() const {
    return this->historico;
}
double Activo::getRetornoEsperado() const {
    return this->retornoEsperado;
}

//Setters
void Activo::setPrecio(double nuevoPrecio) { 
    this->precio = nuevoPrecio;
}

//Métodos de acción
void Activo::cargarHistorico(const std::string& nombreArchivo) {
    // Si ya teníamos uno, lo borramos
    if (this->historico != nullptr) {
        delete this->historico;
    }
    
    // Creamos el objeto 
    this->historico = new HistoricoPrecios();
    
    // Usamos el objeto para cargar el CSV
    if (this->historico->cargarDesdeCSV(nombreArchivo)) {
        std::cout << "Histórico cargado para: " << this->nombre << std::endl;
    } else {
        std::cout << "FALLO al cargar histórico para: " << this->nombre << std::endl;
    }
}