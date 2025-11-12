#include "Activo.hpp"
#include <string>
#include <vector> 

// Herencia
class ETF : public Activo {
private:
    std::string gestora;
    std::vector<std::string> principalesPosiciones; 

public:
    // Constructor de ETF
    ETF(const std::string& nombre, double precio, double retorno, double riesgo, 
        const std::string& gestora, const std::vector<std::string>& posiciones);
    
    // Destructor virtual
    virtual ~ETF(); 

    // Getters de ETF
    std::string getGestora() const;

    // Sobrescritura del método virtual para Polimorfismo
    virtual void imprimirDetalle() const override; 
};