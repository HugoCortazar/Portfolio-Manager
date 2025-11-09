#pragma once 

#include <string> 

// Usar 'using namespace std;' en un .hpp es mala práctica.

class Activo {
// metodos privados
private:
    std::string nombre;
    double precio;
    double retornoEsperado;
    double riesgo;

// Métodos públicos 
public:

    Activo(const std::string& nombre, double precio, double retorno, double riesgo);
   
    std::string getNombre() const; 
    double getPrecio() const;
    
    void setPrecio(double nuevoPrecio);


};