#pragma once

#include <vector>     
#include <string>
#include "Activo.hpp" 

class Portfolio {
private:
    std::vector<Activo*> activos; 
    
    double cantidadTotal; 

public:
    // Constructor
    Portfolio();
    //Liberamos memoria
    ~Portfolio();

    //Añadir un activo 
    void anadirActivo(Activo* nuevoActivo);

    //Mostrar los activos del portfolio
    void mostrarPortfolio() const;
};