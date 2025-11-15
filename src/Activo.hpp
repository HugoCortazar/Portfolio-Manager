#pragma once

#include <string>
#include "HistoricoPrecios.hpp" // 1. ¡INCLUIR LA NUEVA CLASE!

class Activo {
private:
    std::string nombre;
    double precio;
    double retornoEsperado;
    double riesgo;
    
    // 2. AÑADIR: Cada Activo "posee" su histórico
    HistoricoPrecios* historico; 

public:
    Activo(const std::string& nombre, double precio, double retorno, double riesgo);
    virtual ~Activo(); // (Ya deberías tenerlo)

    std::string getNombre() const;
    double getPrecio() const;
    void setPrecio(double nuevoPrecio);

    // 3. AÑADIR: Métodos para gestionar el histórico
    void cargarHistorico(const std::string& nombreArchivo);
    HistoricoPrecios* getHistorico() const;
};