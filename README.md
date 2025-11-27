# 📈 Gestor y Analizador de Portafolio de Inversión

Este proyecto es una aplicación de consola en C++ diseñada para simular la **gestión de una cartera de inversiones** (Portafolio). Permite a los usuarios realizar operaciones de compra y venta de activos, y lo más importante, calcular métricas financieras clave como el **Riesgo** y el **Retorno Esperado** del portafolio.

## 🛠️ Tecnologías Utilizadas

* **Lenguaje:** C++ (Estándar C++11 o superior).
* **Estructura:** Programación Orientada a Objetos (POO) con un fuerte uso de herencia y polimorfismo.

---

## ✨ Características Principales

* **Gestión de Activos:** Soporte para diferentes tipos de activos de inversión:
    * **Acciones** (`Accion.hpp`): Activos con atributos como el sector.
    * **ETFs** (`ETF.hpp`): Fondos cotizados con atributos como el índice que siguen (`index`) y el `pais`.
    * **Activos Libres de Riesgo** (`LibreRiesgo.hpp`): Representan activos con riesgo $\approx 0$.
* **Registro de Posiciones (Holdings):** La clase `Holding` gestiona la cantidad actual (`cantidad`) de un activo y recalcula automáticamente el **Coste Medio** de adquisición tras cada compra.
* **Historial de Operaciones (Trades):** Almacenamiento de todas las transacciones (`COMPRA`/`VENTA`) realizadas en un vector de `Trade*`.
* **Análisis de Portafolio:**
    * **Retorno Esperado:** Calculado como la media ponderada de los retornos esperados individuales de cada activo (`MedidorRentabilidad`).
    * **Riesgo:** Calculado como la **Desviación Estándar (StdDev) ponderada** de los retornos históricos de los activos en el portafolio (`MedidorRiesgo`).
* **Carga de Datos Históricos:** Capacidad para cargar datos de precios desde archivos **CSV** (e.g., `AAPL.csv`, `KO.csv`) utilizando la clase `HistoricoPrecios`.

---

## 🏗️ Estructura del Código

La arquitectura se basa en un modelo de POO:

### 1. Modelo de Activos (Herencia)
La clase base **`Activo`** define la interfaz principal (`nombre`, `precio`, `retornoEsperado`, `HistoricoPrecios`).
- Heredan de `Activo`: `Accion`, `ETF`, y `LibreRiesgo`.

### 2. Gestión de la Cartera (Composición)
- **`Portfolio`**: Contiene la cartera. Gestiona un vector de `Holding*` (las posiciones actuales) y un vector de `Trade*` (el historial).
- **`Holding`**: Representa una posición específica dentro del `Portfolio`, asociando un `Activo*` con una `cantidad` y `costeMedio`.

### 3. Métricas
- **`MedidorRiesgo`** y **`MedidorRentabilidad`**: Clases estáticas con funciones utilitarias para realizar los cálculos a nivel de cartera.

---

## 🚀 Cómo Compilar y Ejecutar

### 1. Compilación

Para compilar el proyecto, asegúrate de tener un compilador de C++ (como g++). Debes incluir todos los archivos de implementación (`.cpp`):

```bash
g++ -std=c++11 main.cpp Portfolio.cpp Holding.cpp Activo.cpp Accion.cpp ETF.cpp LibreRiesgo.cpp HistoricoPrecios.cpp MedidorRiesgo.cpp MedidorRentabilidad.cpp -o gestor_portafolio
