#include <iostream>
#include <string>
#include <vector>
#include <limits> 

#include "Portfolio.hpp"
#include "Accion.hpp"
#include "ETF.hpp"
#include "LibreRiesgo.hpp"
#include "MedidorRiesgo.hpp"
#include "Trade.hpp" 
#include "MedidorRentabilidad.hpp" 

using namespace std;

void mostrarMenu() {
    cout << "\n--- === Gestor de Portfolio === ---" << endl;
    cout << "1. Comprar Activo" << endl;
    cout << "2. Vender Activo" << endl;
    cout << "3. Mostrar Portfolio Actual" << endl;
    cout << "4. Mostrar Historial de Trades" << endl;
    cout << "5. Calcular Riesgo del Portfolio" << endl;
    cout << "6. Calcular Retorno Esperado (Media)" << endl; 
    cout << "7. Ver Histórico de Activo" << endl; 
    cout << "8. Salir" << endl;                 
    cout << "-----------------------------------" << endl;
    cout << "Elige una opción: ";
}

//Función "Ayudante" para buscar un Activo 
Activo* encontrarActivoPorNombre(const vector<Activo*>& activos, const string& nombre) {
    
    if (nombre.empty()) {
        return nullptr;
    }
    for (Activo* act : activos) {
        if (act->getNombre().find(nombre) != string::npos) {
            return act;
        }
    }
    return nullptr; 
}


int main() {

    //Inicialización de la Aplicación
    Portfolio miPortfolio;
    vector<Activo*> activosDisponibles; 

    cout << "Cargando activos del mercado..." << endl;
    
    Activo* ptrAccionAAPL = new Accion("Apple (AAPL)", 175.0, 0.15, 0.2, "Tecnología");
    ptrAccionAAPL->cargarHistorico("AAPL.csv");
    activosDisponibles.push_back(ptrAccionAAPL);
    
    Activo* ptrAccionKO = new Accion("Coca-Cola (KO)", 62.0, 0.08, 0.1, "Consumo");
    ptrAccionKO->cargarHistorico("KO.csv");
    activosDisponibles.push_back(ptrAccionKO);
    
    Activo* ptrETF_SP500 = new ETF("S&P 500 ETF (VOO)", 400.0, 0.10, 0.15, "S&P 500", "USA");
    activosDisponibles.push_back(ptrETF_SP500); 

    Activo* ptrBono = new LibreRiesgo("Bono del Estado (BONO)", 100.0, 0.04, 0.0);
    activosDisponibles.push_back(ptrBono);

    //El Bucle Principal
    int opcion = 0;
    while (true) {
        mostrarMenu();
        cin >> opcion;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        if (opcion == 1) {
            //COMPRAR
            string simbolo;
            int cantidad;
            cout << "Introduce el símbolo (ej: AAPL, KO, VOO, BONO): "; 
            getline(cin, simbolo);

            if (simbolo.empty()) {
                continue; 
            }

            Activo* activoAComprar = encontrarActivoPorNombre(activosDisponibles, simbolo);
            if (activoAComprar == nullptr) {
                cout << "Error: Activo no encontrado." << endl;
            } else {
                cout << "Introduce la cantidad: ";
                cin >> cantidad;
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                
                double precioActual = activoAComprar->getPrecio();
                Trade* nuevoTrade = new Trade(activoAComprar, TipoTrade::COMPRA, cantidad, precioActual, "2025-11-15");
                miPortfolio.procesarTrade(nuevoTrade);
                cout << "¡Compra registrada! (" << cantidad << " x " << precioActual << " USD)" << endl;
            }
        } 
        else if (opcion == 2) {
            string simbolo;
            int cantidad;
            cout << "Introduce el símbolo (ej: AAPL, KO, VOO, BONO): ";
            getline(cin, simbolo);
            
            if (simbolo.empty()) {
                continue;
            }

            Activo* activoAVender = encontrarActivoPorNombre(activosDisponibles, simbolo);
            if (activoAVender == nullptr) {
                cout << "Error: Activo no encontrado." << endl;
            } else {
                cout << "Introduce la cantidad a vender: ";
                cin >> cantidad;
                
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                
                double precioActual = activoAVender->getPrecio();
                Trade* nuevoTrade = new Trade(activoAVender, TipoTrade::VENTA, cantidad, precioActual, "2025-11-15");
                miPortfolio.procesarTrade(nuevoTrade);
                cout << "¡Venta registrada! (" << cantidad << " x " << precioActual << " USD)" << endl;
            }
        } 
        else if (opcion == 3) {
            miPortfolio.mostrarPortfolio();
        } 
        else if (opcion == 4) {
            miPortfolio.mostrarHistorialTrades();
        } 
        else if (opcion == 5) {
            double riesgo = MedidorRiesgo::calcularRiesgoPortfolio(&miPortfolio);
            cout << "\n--- === Análisis de Riesgo === ---" << endl;
            cout << "Riesgo (StdDev Ponderada): " << riesgo << endl;
        } 
        else if (opcion == 6) {
            double retorno = MedidorRentabilidad::calcularRetornoPonderado(&miPortfolio);
            cout << "\n--- === Reporte de Retorno Esperado === ---" << endl;
            cout.precision(2); 
            cout << std::fixed; 
            cout << "El Retorno Esperado (media ponderada) de tu" << endl;
            cout << "cartera actual es: " << (retorno * 100.0) << " %" << endl;
            cout.unsetf(std::ios_base::floatfield);
        } 
        else if (opcion == 7) {
            //VER HISTÓRICO
            string simbolo;
            cout << "Introduce el símbolo del activo (ej: AAPL, KO): ";
            getline(cin, simbolo);
            
            
            if (simbolo.empty()) {
                continue; 
            }

            Activo* activo = encontrarActivoPorNombre(activosDisponibles, simbolo);
            
            if (activo == nullptr) {
                cout << "Error: Activo no encontrado." << endl;
            } else if (activo->getHistorico() == nullptr) {
                cout << "Error: Este activo no tiene datos históricos cargados." << endl;
            } else {
                activo->getHistorico()->mostrarPrecios();
            }
        
        } else if (opcion == 8) { 
            
            cout << "Saliendo... ¡Gracias por usar el gestor!" << endl;
            break; 
        } else {
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    }

    //Limpieza Final
    cout << "\n--- Limpiando activos maestros ---" << endl;
    for (Activo* act : activosDisponibles) {
        delete act; 
    }
    
    cout << "Limpieza completa. Adiós." << endl;
    return 0;
}