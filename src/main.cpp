#include <iostream>
#include <string>
#include "Activo.hpp" // 1. ¡Incluye tu nueva clase!

using namespace std;

int main() {
    // 2. Crea un objeto (una "instancia") de tu clase
    //    Esto llama al constructor que definiste
    Activo miActivo("Acción de Apple (AAPL)", 150.50, 0.15, 0.25);

    // 3. Usa los métodos de la clase
    //    (Requisito: Lectura/escritura por pantalla)
    cout << "--- Información del Activo ---" << endl;
    cout << "Nombre: " << miActivo.getNombre() << endl;
    cout << "Precio: " << miActivo.getPrecio() << " USD" << endl;

    // 4. Modifica el objeto usando un setter
    miActivo.setPrecio(152.75);
    cout << "Precio actualizado: " << miActivo.getPrecio() << " USD" << endl;

    return 0; // Indica que el programa terminó correctamente
}