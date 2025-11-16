#include "MedidorRiesgo.hpp"
#include <vector>
#include <iostream>
#include <cmath>

// Implementación de la función pública
double MedidorRiesgo::calcularRiesgoPortfolio(Portfolio* portfolio) {
    if (portfolio == nullptr) return 0.0;
    const auto& holdings = portfolio->getHoldings();
    if (holdings.empty()) return 0.0;

    //Calcular el valor total del portfolio
    double valorTotalPortfolio = 0.0;
    for (const Holding* holding : holdings) {
        valorTotalPortfolio += holding->getActivo()->getPrecio() * holding->getCantidad();
    }
    if (valorTotalPortfolio == 0.0) return 0.0;

    //Calcular el riesgo ponderado
    double riesgoTotalPonderado = 0.0;
    for (const Holding* holding : holdings) {
        //Calcular el peso (Weight)
        double valorHolding = holding->getActivo()->getPrecio() * holding->getCantidad();
        double peso = valorHolding / valorTotalPortfolio;

        //Calcular el riesgo (Standard Deviation) de este activo
        double riesgoActivo = calcularStdDev(holding->getActivo());

        // Añadir al total
        riesgoTotalPonderado += peso * riesgoActivo;
    }
    return riesgoTotalPonderado;
}


// Implementación de la función "ayudante" privada
double MedidorRiesgo::calcularStdDev(Activo* activo) {
    if (activo == nullptr || activo->getHistorico() == nullptr) {
        return 0.0; // No se puede calcular el riesgo sin histórico
    }
    const auto& precios = activo->getHistorico()->getPrecios();
    if (precios.size() < 2) {
        return 0.0; 
    }

    //Calcular Retornos
    std::vector<double> retornos;
    for (size_t i = 1; i < precios.size(); ++i) {
        double p_hoy = precios[i].precio;
        double p_ayer = precios[i - 1].precio;
        if (p_ayer != 0) {
            retornos.push_back((p_hoy / p_ayer) - 1.0);
        }
    }
    if (retornos.empty()) return 0.0;

    //Calcular la Media de los retornos
    double suma = 0.0;
    for (double r : retornos) { suma += r; }
    double media = suma / retornos.size();

    //Calcular la Varianza
    double sumaCuadrados = 0.0;
    for (double r : retornos) {
        sumaCuadrados += std::pow(r - media, 2);
    }
    double varianza = sumaCuadrados / (retornos.size() - 1); // Varianza muestral

    //Desviación Estándar (Riesgo)
    double stdDev = std::sqrt(varianza);
    return stdDev;
}