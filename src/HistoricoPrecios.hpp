#pragma once

#include <string>
#include <vector>

class HistoricoPrecios {
public:
    // Un 'struct' para agrupar fecha y precio
    struct RegistroPrecio {
        std::string fecha;
        double precio;
    };

private:
    std::vector<RegistroPrecio> precios;

public:
    HistoricoPrecios();
    ~HistoricoPrecios();

    bool cargarDesdeCSV(const std::string& nombreArchivo);
    void mostrarPrecios() const;
    const std::vector<RegistroPrecio>& getPrecios() const;
};