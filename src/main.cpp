#include <iostream>
#include "Portfolio.hpp"     
#include "Accion.hpp"       
#include "LibreRiesgo.hpp"   

using namespace std;

int main() {
    Portfolio miPortfolio;

    // cargamos los csv
    Activo* ptrAccion1 = new Accion("Apple (AAPL)", 150.0, 0.1, 0.2, "Tecnología");
    ptrAccion1->cargarHistorico("AAPL.csv"); 


    Activo* ptrAccion2 = new Accion("Coca-Cola (KO)", 60.0, 0.05, 0.1, "Consumo");
    ptrAccion2->cargarHistorico("KO.csv"); 

    Activo* ptrBono = new LibreRiesgo("Bono del Estado 1 Año", 1000.0, 0.03, 0.0);

    Holding* holding1 = new Holding(ptrAccion1, 50, 145.50); 
    Holding* holding2 = new Holding(ptrAccion2, 200, 58.20); 
    Holding* holding3 = new Holding(ptrBono, 10, 998.0);     

    miPortfolio.anadirHolding(holding1);
    miPortfolio.anadirHolding(holding2);
    miPortfolio.anadirHolding(holding3);

    miPortfolio.mostrarPortfolio();

    cout << "Fin de main. El destructor de Portfolio se llamará ahora." << endl;
    return 0;
}