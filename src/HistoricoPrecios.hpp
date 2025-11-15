#pragma once

#include <string>
#include <vector>

class HistoricoPrecios {
public:
    // Un 'struct' es como una 'clase' pero pública por defecto.
    // Lo usamos para agrupar datos simples.
    struct RegistroPrecio {
        std::string fecha;
        double precio;
    };

private:
    std::vector<RegistroPrecio> precios;

public:
    // Constructor
    HistoricoPrecios();
    ~HistoricoPrecios();

    // El método principal para leer el fichero
    // Devuelve 'true' si lo consigue, 'false' si falla
    bool cargarDesdeCSV(const std::string& nombreArchivo);

    // Un método simple para ver si funcionó
    void mostrarPrecios() const;
    
};
