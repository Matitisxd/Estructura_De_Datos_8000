/**
 * @file Vehiculo.hpp
 * @authors Granda Carlos, Rodriguez Mathyws 
 * @brief Clase Vehiculo
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
class Vehiculo {

public:

private:

    char marca[12];
    char placaVehicular[8];
    char nombrePropietario[40];
    char fecha[11];
    Vehiculo *siguiente;
    Vehiculo *anterior;
    friend class ListaCircular;
};