#include <iostream>
#include "Accion.hpp"
#include "Portfolio.hpp" 


using namespace std;

int main() {
    // 1. Creamos un objeto Portfolio 
    Portfolio miPortfolio;

    
    Activo* ptrAccion1 = new Accion("Apple (AAPL)", 150.0, 0.1, 0.2, "Tecnología");
    Activo* ptrAccion2 = new Accion("Coca-Cola (KO)", 60.0, 0.05, 0.1, "Consumo");
    
    //    Añadimos los punteros al portfolio
    miPortfolio.anadirActivo(ptrAccion1);
    miPortfolio.anadirActivo(ptrAccion2);

    miPortfolio.mostrarPortfolio();

    cout << "Fin de main. El destructor de Portfolio se llamará ahora." << endl;
    return 0;
}