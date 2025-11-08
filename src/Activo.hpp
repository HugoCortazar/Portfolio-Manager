#pragma once // Evita que este archivo se incluya múltiples veces

#include <string> // Usamos la clase string (Requisito)

// Usar 'using namespace std;' en un .hpp es mala práctica.
// Es mejor ser explícito con std::
// (En el .cpp sí puedes usarlo si quieres)

class Activo {
// Por defecto, los miembros de una clase son privados
private:
    std::string nombre;
    double precio;
    double retornoEsperado;
    double riesgo;

// Métodos públicos (la "interfaz" para usar la clase)
public:
    // Constructor: Se usa para crear un objeto de la clase
    // Usamos referencias constantes (&) para pasar el string de forma eficiente
    Activo(const std::string& nombre, double precio, double retorno, double riesgo);

    // --- Métodos "Getters" ---
    // Nos permiten leer los datos privados
    std::string getNombre() const; // 'const' significa que este método no modifica el objeto
    double getPrecio() const;
    
    // ... (Puedes añadir getters para retorno y riesgo)

    // --- Métodos "Setters" ---
    // Nos permiten modificar los datos privados
    void setPrecio(double nuevoPrecio);

    // ... (Puedes añadir otros métodos que necesites)
};