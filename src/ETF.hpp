#pragma once

#include "Activo.hpp" 
#include <string>

class ETF : public Activo {
private:
    std::string index; 
    std::string pais;  

public:
    // Constructor
    ETF(const std::string& nombre, double precio, double retorno, double riesgo, const std::string& index, const std::string& pais);
    
    // Getters
    std::string getIndex() const;
    std::string getPais() const;
};