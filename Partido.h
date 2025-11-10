#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
using namespace std;

/**
 * Clase Partido
 * Representa un partido político
 */
class Partido {
private:
    int id;
    string nombre;
    string sigla;
    
public:
    // Constructor
    Partido(int id = 0, string nombre = "", string sigla = "");
    
    // Getters
    int getId() const;
    string getNombre() const;
    string getSigla() const;
    
    // Setters
    void setNombre(string nombre);
    void setSigla(string sigla);
};

#endif
