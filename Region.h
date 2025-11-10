#ifndef REGION_H
#define REGION_H

#include <string>
#include <list>
#include "Ciudad.h"
using namespace std;

/**
 * Clase Region
 * Representa una región geográfica que contiene múltiples ciudades
 */
class Region {
private:
    int id;
    string nombre;
    list<Ciudad*> ciudades; // Lista de ciudades en la región

public:
    // Constructor
    Region(int id = 0, string nombre = "");
    
    // Getters
    int getId() const;
    string getNombre() const;
    list<Ciudad*>& getCiudades();
    
    // Setters
    void setNombre(string nombre);
    
    // Métodos de gestión
    void agregarCiudad(Ciudad* ciudad);
    int getCensoTotal() const;
    int getVotosTotales() const;
    int getVotosBlancosTotal() const;
};

#endif
