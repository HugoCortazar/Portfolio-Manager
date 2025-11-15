#include "LibreRiesgo.hpp"

// Solo pasamos todos los argumentos al constructor "padre" (Activo)
LibreRiesgo::LibreRiesgo(const std::string& nombre, double precio, double retorno, double riesgo)
    : Activo(nombre, precio, retorno, riesgo) 
{
    // No hay nada más que inicializar.
}