#pragma once 
#include <string> 

class Activo {
// ¡CAMBIADO A PROTECTED!
// para que las clases hijas (Accion, ETF) puedan ver las variables
protected:
    std::string nombre;
    double precio;
    double retornoEsperado;
    double riesgo;

public:
    Activo(const std::string& nombre, double precio, double retorno, double riesgo);
    
    // Getters
    std::string getNombre() const; 
    double getPrecio() const;
    
    // Setter
    void setPrecio(double nuevoPrecio);

    // --- ¡MOVIDOS AQUÍ DENTRO DE 'public:'! ---
    // Destructor virtual (OBLIGATORIO para polimorfismo)
    virtual ~Activo(); 
    
    // Método virtual para Sobrecarga Dinámica
    virtual void imprimirDetalle() const;
};