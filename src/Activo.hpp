#pragma once

#include <string>
#include "HistoricoPrecios.hpp"

class Activo {
private:
    std::string nombre;
    double precio;
    double retornoEsperado;
    double riesgo;

    HistoricoPrecios* historico; 

public:
    Activo(const std::string& nombre, double precio, double retorno, double riesgo);
    
    virtual ~Activo(); 

    // Getters
    std::string getNombre() const;
    double getPrecio() const;
    HistoricoPrecios* getHistorico() const;
    double getRetornoEsperado() const;

    // Setters
    void setPrecio(double nuevoPrecio);

    // Métodos de acción
    void cargarHistorico(const std::string& nombreArchivo);
};