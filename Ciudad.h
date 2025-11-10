#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
#include <list>
#include "Candidato.h"
using namespace std;

/**
 * Clase Ciudad
 * Representa una ciudad con su censo electoral y resultados de votación
 */
class Ciudad {
private:
    int id;
    string nombre;
    int idRegion;
    int censoElectoral; // Número de votantes habilitados
    int votosBlancos;
    list<Candidato*> candidatos; // Lista de candidatos

public:
    // Constructor
    Ciudad(int id = 0, string nombre = "", int idRegion = 0, int censo = 0);
    
    // Getters
    int getId() const;
    string getNombre() const;
    int getIdRegion() const;
    int getCensoElectoral() const;
    int getVotosBlancos() const;
    list<Candidato*>& getCandidatos();
    
    // Setters
    void setNombre(string nombre);
    void setIdRegion(int idRegion);
    void setCensoElectoral(int censo);
    
    // Métodos de votación
    void agregarCandidato(Candidato* candidato);
    void agregarVotoBlanco();
    void reiniciarVotos();
    int getTotalVotos() const;
};

#endif
