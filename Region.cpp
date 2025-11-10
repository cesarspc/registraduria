#include "Region.h"

Region::Region(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

int Region::getId() const {
    return id;
}

string Region::getNombre() const {
    return nombre;
}

list<Ciudad*>& Region::getCiudades() {
    return ciudades;
}

void Region::setNombre(string nombre) {
    this->nombre = nombre;
}

void Region::agregarCiudad(Ciudad* ciudad) {
    ciudades.push_back(ciudad);
}

int Region::getCensoTotal() const {
    int total = 0;
    for (auto it = ciudades.begin(); it != ciudades.end(); ++it) {
        total += (*it)->getCensoElectoral();
    }
    return total;
}

int Region::getVotosTotales() const {
    int total = 0;
    for (auto it = ciudades.begin(); it != ciudades.end(); ++it) {
        total += (*it)->getTotalVotos();
    }
    return total;
}

int Region::getVotosBlancosTotal() const {
    int total = 0;
    for (auto it = ciudades.begin(); it != ciudades.end(); ++it) {
        total += (*it)->getVotosBlancos();
    }
    return total;
}
