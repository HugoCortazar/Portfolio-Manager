#include "Activo.hpp" // ¡Muy importante incluir tu propia cabecera!

// Aquí implementamos el constructor
// Usamos "Activo::" para indicar que esta función pertenece a la clase Activo
Activo::Activo(const std::string& nombre, double precio, double retorno, double riesgo) {
    // 'this->' se usa para diferenciar el miembro de la clase (this->nombre)
    // del parámetro de la función (nombre)
    this->nombre = nombre;
    this->precio = precio;
    this->retornoEsperado = retorno;
    this->riesgo = riesgo;
}

// Implementación de los getters
std::string Activo::getNombre() const {
    return this->nombre;
}

double Activo::getPrecio() const {
    return this->precio;
}

// Implementación del setter
void Activo::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) { // Buena idea añadir validaciones
        this->precio = nuevoPrecio;
    }
}