#include "Partido.h"

Partido::Partido(int id, string nombre, string sigla) {
    this->id = id;
    this->nombre = nombre;
    this->sigla = sigla;
}

int Partido::getId() const {
    return id;
}

string Partido::getNombre() const {
    return nombre;
}

string Partido::getSigla() const {
    return sigla;
}

void Partido::setNombre(string nombre) {
    this->nombre = nombre;
}

void Partido::setSigla(string sigla) {
    this->sigla = sigla;
}
