#include "Ciudad.h"

Ciudad::Ciudad(int id, string nombre, int idRegion, int censo) {
    this->id = id;
    this->nombre = nombre;
    this->idRegion = idRegion;
    this->censoElectoral = censo;
    this->votosBlancos = 0;
}

int Ciudad::getId() const {
    return id;
}

string Ciudad::getNombre() const {
    return nombre;
}

int Ciudad::getIdRegion() const {
    return idRegion;
}

int Ciudad::getCensoElectoral() const {
    return censoElectoral;
}

int Ciudad::getVotosBlancos() const {
    return votosBlancos;
}

list<Candidato*>& Ciudad::getCandidatos() {
    return candidatos;
}

void Ciudad::setNombre(string nombre) {
    this->nombre = nombre;
}

void Ciudad::setIdRegion(int idRegion) {
    this->idRegion = idRegion;
}

void Ciudad::setCensoElectoral(int censo) {
    this->censoElectoral = censo;
}

void Ciudad::agregarCandidato(Candidato* candidato) {
    candidatos.push_back(candidato);
}

void Ciudad::agregarVotoBlanco() {
    votosBlancos++;
}

void Ciudad::reiniciarVotos() {
    votosBlancos = 0;
}

int Ciudad::getTotalVotos() const {
    int total = votosBlancos;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        total += (*it)->getVotos();
    }
    return total;
}
