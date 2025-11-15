#include "MedidorRentabilidad.hpp"
#include <vector>
#include <iostream>

//ESTA ES LA NUEVA LÓGICA DE CÁLCULO
double MedidorRentabilidad::calcularRetornoPonderado(Portfolio* portfolio) {
    
    if (portfolio == nullptr) return 0.0;
    const auto& holdings = portfolio->getHoldings();
    if (holdings.empty()) return 0.0;

    // Calcular el valor total del portfolio
    double valorTotalPortfolio = 0.0;
    for (const Holding* h : holdings) {
        valorTotalPortfolio += h->getActivo()->getPrecio() * h->getCantidad();
    }

    if (valorTotalPortfolio == 0.0) return 0.0; // Evitar división por cero

    //Calcular el retorno ponderado
    double retornoTotalPonderado = 0.0;
    for (const Holding* h : holdings) {
        //Calcular el peso
        double valorHolding = h->getActivo()->getPrecio() * h->getCantidad();
        double peso = valorHolding / valorTotalPortfolio;

        //Obtener la rentabilidad esperada
        double retornoActivo = h->getActivo()->getRetornoEsperado();

        //Añadir al total
        retornoTotalPonderado += peso * retornoActivo;
    }

    return retornoTotalPonderado;
}