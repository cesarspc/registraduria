#include "Candidato.h"

Candidato::Candidato(int id, string nombre, string apellido, char genero, int idPartido) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->idPartido = idPartido;
    this->votos = 0;
}

int Candidato::getId() const {
    return id;
}

string Candidato::getNombre() const {
    return nombre;
}

string Candidato::getApellido() const {
    return apellido;
}

string Candidato::getNombreCompleto() const {
    return nombre + " " + apellido;
}

char Candidato::getGenero() const {
    return genero;
}

int Candidato::getIdPartido() const {
    return idPartido;
}

int Candidato::getVotos() const {
    return votos;
}

void Candidato::setNombre(string nombre) {
    this->nombre = nombre;
}

void Candidato::setApellido(string apellido) {
    this->apellido = apellido;
}

void Candidato::setGenero(char genero) {
    this->genero = genero;
}

void Candidato::setIdPartido(int idPartido) {
    this->idPartido = idPartido;
}

void Candidato::agregarVoto() {
    votos++;
}

void Candidato::reiniciarVotos() {
    votos = 0;
}
