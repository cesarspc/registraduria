#include "SistemaElectoral.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

SistemaElectoral::SistemaElectoral() {
    siguienteIdRegion = 1;
    siguienteIdCiudad = 1;
    siguienteIdPartido = 1;
    siguienteIdCandidato = 1;
    primeraVueltaRealizada = false;
    segundaVueltaRealizada = false;
    srand(time(NULL));
}

SistemaElectoral::~SistemaElectoral() {
    // Liberar memoria de todas las listas
    for (auto it = regiones.begin(); it != regiones.end(); ++it) {
        delete *it;
    }
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        delete *it;
    }
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        delete *it;
    }
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        delete *it;
    }
}

void SistemaElectoral::agregarRegion(string nombre) {
    Region* region = new Region(siguienteIdRegion++, nombre);
    regiones.push_back(region);
    cout << "Región agregada: " << nombre << " (ID: " << region->getId() << ")" << endl;
}

void SistemaElectoral::agregarCiudad(string nombre, int idRegion, int censo) {
    Region* region = buscarRegion(idRegion);
    if (region == NULL) {
        cout << "Error: Región no encontrada" << endl;
        return;
    }
    
    Ciudad* ciudad = new Ciudad(siguienteIdCiudad++, nombre, idRegion, censo);
    todasCiudades.push_back(ciudad);
    region->agregarCiudad(ciudad);
    
    // Agregar referencias a todos los candidatos
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        ciudad->agregarCandidato(*it);
    }
    
    cout << "Ciudad agregada: " << nombre << " (ID: " << ciudad->getId() 
         << ", Censo: " << censo << ")" << endl;
}

void SistemaElectoral::agregarPartido(string nombre, string sigla) {
    Partido* partido = new Partido(siguienteIdPartido++, nombre, sigla);
    partidos.push_back(partido);
    cout << "Partido agregado: " << nombre << " (" << sigla << ")" << endl;
}

void SistemaElectoral::agregarCandidato(string nombre, string apellido, char genero, int idPartido) {
    Partido* partido = buscarPartido(idPartido);
    if (partido == NULL) {
        cout << "Error: Partido no encontrado" << endl;
        return;
    }
    
    Candidato* candidato = new Candidato(siguienteIdCandidato++, nombre, apellido, genero, idPartido);
    candidatos.push_back(candidato);
    
    // Agregar el candidato a todas las ciudades existentes
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        (*it)->agregarCandidato(candidato);
    }
    
    cout << "Candidato agregado: " << candidato->getNombreCompleto() 
         << " (" << partido->getSigla() << ")" << endl;
}

void SistemaElectoral::modificarRegion(int id, string nuevoNombre) {
    Region* region = buscarRegion(id);
    if (region != NULL) {
        region->setNombre(nuevoNombre);
        cout << "Región modificada exitosamente" << endl;
    } else {
        cout << "Error: Región no encontrada" << endl;
    }
}

void SistemaElectoral::modificarCiudad(int id, string nuevoNombre, int nuevoCenso) {
    Ciudad* ciudad = buscarCiudad(id);
    if (ciudad != NULL) {
        ciudad->setNombre(nuevoNombre);
        ciudad->setCensoElectoral(nuevoCenso);
        cout << "Ciudad modificada exitosamente" << endl;
    } else {
        cout << "Error: Ciudad no encontrada" << endl;
    }
}

void SistemaElectoral::modificarPartido(int id, string nuevoNombre, string nuevaSigla) {
    Partido* partido = buscarPartido(id);
    if (partido != NULL) {
        partido->setNombre(nuevoNombre);
        partido->setSigla(nuevaSigla);
        cout << "Partido modificado exitosamente" << endl;
    } else {
        cout << "Error: Partido no encontrado" << endl;
    }
}

void SistemaElectoral::modificarCandidato(int id, string nuevoNombre, string nuevoApellido, char nuevoGenero) {
    Candidato* candidato = buscarCandidato(id);
    if (candidato != NULL) {
        candidato->setNombre(nuevoNombre);
        candidato->setApellido(nuevoApellido);
        candidato->setGenero(nuevoGenero);
        cout << "Candidato modificado exitosamente" << endl;
    } else {
        cout << "Error: Candidato no encontrado" << endl;
    }
}

void SistemaElectoral::listarRegiones() const {
    cout << "\n=== REGIONES ===" << endl;
    for (auto it = regiones.begin(); it != regiones.end(); ++it) {
        cout << "ID: " << (*it)->getId() << " - " << (*it)->getNombre() 
             << " (Ciudades: " << (*it)->getCiudades().size() << ")" << endl;
    }
}

void SistemaElectoral::listarCiudades() const {
    cout << "\n=== CIUDADES ===" << endl;
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        Region* region = buscarRegion((*it)->getIdRegion());
        cout << "ID: " << (*it)->getId() << " - " << (*it)->getNombre() 
             << " (Región: " << (region ? region->getNombre() : "N/A")
             << ", Censo: " << (*it)->getCensoElectoral() << ")" << endl;
    }
}

void SistemaElectoral::listarPartidos() const {
    cout << "\n=== PARTIDOS POLÍTICOS ===" << endl;
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        cout << "ID: " << (*it)->getId() << " - " << (*it)->getNombre() 
             << " (" << (*it)->getSigla() << ")" << endl;
    }
}

void SistemaElectoral::listarCandidatos() const {
    cout << "\n=== CANDIDATOS ===" << endl;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        Partido* partido = buscarPartido((*it)->getIdPartido());
        string generoStr = ((*it)->getGenero() == 'M') ? "Masculino" : 
                          ((*it)->getGenero() == 'F') ? "Femenino" : "Otro";
        cout << "ID: " << (*it)->getId() << " - " << (*it)->getNombreCompleto()
             << " (" << (partido ? partido->getSigla() : "N/A") 
             << ", " << generoStr << ")" << endl;
    }
}

void SistemaElectoral::cargarDatosDesdeArchivos() {
    // Cargar partidos
    ifstream archivoPartidos("partidos.txt");
    if (archivoPartidos.is_open()) {
        string linea;
        while (getline(archivoPartidos, linea)) {
            if (linea.empty()) continue;
            stringstream ss(linea);
            string nombre, sigla;
            getline(ss, nombre, '|');
            getline(ss, sigla, '|');
            agregarPartido(nombre, sigla);
        }
        archivoPartidos.close();
        cout << "Partidos cargados desde archivo" << endl;
    }
    
    // Cargar candidatos
    ifstream archivoCandidatos("candidatos.txt");
    if (archivoCandidatos.is_open()) {
        string linea;
        while (getline(archivoCandidatos, linea)) {
            if (linea.empty()) continue;
            stringstream ss(linea);
            string nombre, apellido, generoStr, idPartidoStr;
            getline(ss, nombre, '|');
            getline(ss, apellido, '|');
            getline(ss, generoStr, '|');
            getline(ss, idPartidoStr, '|');
            char genero = generoStr[0];
            int idPartido = atoi(idPartidoStr.c_str());
            agregarCandidato(nombre, apellido, genero, idPartido);
        }
        archivoCandidatos.close();
        cout << "Candidatos cargados desde archivo" << endl;
    }
    
    // Cargar regiones
    ifstream archivoRegiones("regiones.txt");
    if (archivoRegiones.is_open()) {
        string linea;
        while (getline(archivoRegiones, linea)) {
            if (linea.empty()) continue;
            agregarRegion(linea);
        }
        archivoRegiones.close();
        cout << "Regiones cargadas desde archivo" << endl;
    }
    
    // Cargar ciudades
    ifstream archivoCiudades("ciudades.txt");
    if (archivoCiudades.is_open()) {
        string linea;
        while (getline(archivoCiudades, linea)) {
            if (linea.empty()) continue;
            stringstream ss(linea);
            string nombre, idRegionStr, censoStr;
            getline(ss, nombre, '|');
            getline(ss, idRegionStr, '|');
            getline(ss, censoStr, '|');
            int idRegion = atoi(idRegionStr.c_str());
            int censo = atoi(censoStr.c_str());
            agregarCiudad(nombre, idRegion, censo);
        }
        archivoCiudades.close();
        cout << "Ciudades cargadas desde archivo" << endl;
    }
}

void SistemaElectoral::guardarDatosEnArchivos() const {
    // Guardar partidos
    ofstream archivoPartidos("partidos.txt");
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        archivoPartidos << (*it)->getNombre() << "|" << (*it)->getSigla() << endl;
    }
    archivoPartidos.close();
    
    // Guardar candidatos
    ofstream archivoCandidatos("candidatos.txt");
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        archivoCandidatos << (*it)->getNombre() << "|" << (*it)->getApellido() << "|"
                         << (*it)->getGenero() << "|" << (*it)->getIdPartido() << endl;
    }
    archivoCandidatos.close();
    
    // Guardar regiones
    ofstream archivoRegiones("regiones.txt");
    for (auto it = regiones.begin(); it != regiones.end(); ++it) {
        archivoRegiones << (*it)->getNombre() << endl;
    }
    archivoRegiones.close();
    
    // Guardar ciudades
    ofstream archivoCiudades("ciudades.txt");
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        archivoCiudades << (*it)->getNombre() << "|" << (*it)->getIdRegion() << "|"
                       << (*it)->getCensoElectoral() << endl;
    }
    archivoCiudades.close();
    
    cout << "Datos guardados en archivos" << endl;
}

void SistemaElectoral::guardarResultados(string archivo, bool segundaVuelta) const {
    ofstream file(archivo.c_str());
    if (!file.is_open()) {
        cout << "Error al crear archivo de resultados" << endl;
        return;
    }
    
    file << "===========================================" << endl;
    file << "RESULTADOS ELECTORALES" << endl;
    if (segundaVuelta) {
        file << "SEGUNDA VUELTA" << endl;
    } else {
        file << "PRIMERA VUELTA" << endl;
    }
    file << "===========================================" << endl << endl;
    
    // Resultados nacionales
    file << "--- RESULTADOS NACIONALES ---" << endl;
    file << "Censo electoral total: " << getCensoNacional() << endl;
    file << "Votos emitidos: " << getVotosTotalesNacionales() << endl;
    
    int votosBlancosTotal = 0;
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        votosBlancosTotal += (*it)->getVotosBlancos();
    }
    
    file << "Votos en blanco: " << votosBlancosTotal << endl << endl;
    
    // Votos por candidato a nivel nacional
    map<int, int> votosPorCandidato;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        votosPorCandidato[(*it)->getId()] = (*it)->getVotos();
    }
    
    file << "Votos por candidato:" << endl;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        Partido* partido = buscarPartido((*it)->getIdPartido());
        double porcentaje = 0.0;
        if (getVotosTotalesNacionales() > 0) {
            porcentaje = ((*it)->getVotos() * 100.0) / getVotosTotalesNacionales();
        }
        file << "  " << (*it)->getNombreCompleto() << " (" 
             << (partido ? partido->getSigla() : "N/A") << "): " 
             << (*it)->getVotos() << " votos (" << fixed << setprecision(2) 
             << porcentaje << "%)" << endl;
    }
    
    file << endl << "--- RESULTADOS POR REGIÓN ---" << endl;
    for (auto itR = regiones.begin(); itR != regiones.end(); ++itR) {
        file << endl << "Región: " << (*itR)->getNombre() << endl;
        file << "Censo: " << (*itR)->getCensoTotal() << endl;
        file << "Votos emitidos: " << (*itR)->getVotosTotales() << endl;
        file << "Votos en blanco: " << (*itR)->getVotosBlancosTotal() << endl;
        
        // Calcular votos por candidato en la región
        map<int, int> votosRegion;
        for (auto itC = (*itR)->getCiudades().begin(); itC != (*itR)->getCiudades().end(); ++itC) {
            for (auto itCand = candidatos.begin(); itCand != candidatos.end(); ++itCand) {
                votosRegion[(*itCand)->getId()] += (*itC)->getVotosCandidato((*itCand)->getId());
            }
        }
        
        file << "Votos por candidato:" << endl;
        for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
            Partido* partido = buscarPartido((*it)->getIdPartido());
            int votos = votosRegion[(*it)->getId()];
            double porcentaje = 0.0;
            if ((*itR)->getVotosTotales() > 0) {
                porcentaje = (votos * 100.0) / (*itR)->getVotosTotales();
            }
            file << "  " << (*it)->getNombreCompleto() << " (" 
                 << (partido ? partido->getSigla() : "N/A") << "): " 
                 << votos << " votos (" << fixed << setprecision(2) 
                 << porcentaje << "%)" << endl;
        }
    }
    
    file.close();
    cout << "Resultados guardados en: " << archivo << endl;
}

void SistemaElectoral::generarCensosAleatorios(int minVotantes, int maxVotantes) {
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        int censo = minVotantes + rand() % (maxVotantes - minVotantes + 1);
        (*it)->setCensoElectoral(censo);
    }
    cout << "Censos aleatorios generados (rango: " << minVotantes 
         << " - " << maxVotantes << ")" << endl;
}

void SistemaElectoral::simularVotacion(bool segundaVuelta) {
    cout << "\nSimulando votación..." << endl;
    
    for (auto itC = todasCiudades.begin(); itC != todasCiudades.end(); ++itC) {
        int censo = (*itC)->getCensoElectoral();
        int votosEmitidos = censo * (70 + rand() % 21) / 100; // 70-90% de participación
        
        // Distribuir votos
        for (int i = 0; i < votosEmitidos; i++) {
            int decision = rand() % 100;
            
            if (decision < 5) { // 5% votos en blanco
                (*itC)->agregarVotoBlanco();
            } else {
                // Votar por un candidato aleatorio
                int numCandidatos = candidatos.size();
                if (numCandidatos > 0) {
                    int candidatoIndex = rand() % numCandidatos;
                    auto it = candidatos.begin();
                    advance(it, candidatoIndex);
                    (*itC)->agregarVotoCandidato((*it)->getId());
                    (*it)->agregarVoto();
                }
            }
        }
    }
    
    if (!segundaVuelta) {
        primeraVueltaRealizada = true;
    } else {
        segundaVueltaRealizada = true;
    }
    
    cout << "Votación simulada exitosamente" << endl;
}

void SistemaElectoral::reiniciarVotacion() {
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        (*it)->reiniciarVotos();
    }
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        (*it)->reiniciarVotos();
    }
    primeraVueltaRealizada = false;
    segundaVueltaRealizada = false;
    cout << "Votación reiniciada" << endl;
}

void SistemaElectoral::mostrarResultadosPorCiudad() const {
    if (!primeraVueltaRealizada) {
        cout << "No se ha realizado ninguna votación" << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "RESULTADOS POR CIUDAD" << endl;
    cout << "========================================" << endl;
    
    for (auto itC = todasCiudades.begin(); itC != todasCiudades.end(); ++itC) {
        cout << "\nCiudad: " << (*itC)->getNombre() << endl;
        cout << "Censo electoral: " << (*itC)->getCensoElectoral() << endl;
        cout << "Votos emitidos: " << (*itC)->getTotalVotos() << endl;
        cout << "Votos en blanco: " << (*itC)->getVotosBlancos() << endl;
        cout << "Candidatos:" << endl;
        
        for (auto itCand = candidatos.begin(); itCand != candidatos.end(); ++itCand) {
            Partido* partido = buscarPartido((*itCand)->getIdPartido());
            int votos = (*itC)->getVotosCandidato((*itCand)->getId());
            double porcentaje = 0.0;
            if ((*itC)->getTotalVotos() > 0) {
                porcentaje = (votos * 100.0) / (*itC)->getTotalVotos();
            }
            cout << "  " << (*itCand)->getNombreCompleto() << " (" 
                 << (partido ? partido->getSigla() : "N/A") << "): " 
                 << votos << " votos (" << fixed << setprecision(2) 
                 << porcentaje << "%)" << endl;
        }
    }
}

void SistemaElectoral::mostrarResultadosPorRegion() const {
    if (!primeraVueltaRealizada) {
        cout << "No se ha realizado ninguna votación" << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "RESULTADOS POR REGIÓN" << endl;
    cout << "========================================" << endl;
    
    for (auto itR = regiones.begin(); itR != regiones.end(); ++itR) {
        cout << "\nRegión: " << (*itR)->getNombre() << endl;
        cout << "Censo total: " << (*itR)->getCensoTotal() << endl;
        cout << "Votos emitidos: " << (*itR)->getVotosTotales() << endl;
        cout << "Votos en blanco: " << (*itR)->getVotosBlancosTotal() << endl;
        
        // Calcular votos por candidato en la región
        map<int, int> votosRegion;
        for (auto itC = (*itR)->getCiudades().begin(); itC != (*itR)->getCiudades().end(); ++itC) {
            for (auto itCand = candidatos.begin(); itCand != candidatos.end(); ++itCand) {
                votosRegion[(*itCand)->getId()] += (*itC)->getVotosCandidato((*itCand)->getId());
            }
        }
        
        cout << "Candidatos:" << endl;
        for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
            Partido* partido = buscarPartido((*it)->getIdPartido());
            int votos = votosRegion[(*it)->getId()];
            double porcentaje = 0.0;
            if ((*itR)->getVotosTotales() > 0) {
                porcentaje = (votos * 100.0) / (*itR)->getVotosTotales();
            }
            cout << "  " << (*it)->getNombreCompleto() << " (" 
                 << (partido ? partido->getSigla() : "N/A") << "): " 
                 << votos << " votos (" << fixed << setprecision(2) 
                 << porcentaje << "%)" << endl;
        }
    }
}

void SistemaElectoral::mostrarResultadosNacionales() const {
    if (!primeraVueltaRealizada) {
        cout << "No se ha realizado ninguna votación" << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "RESULTADOS NACIONALES" << endl;
    cout << "========================================" << endl;
    
    cout << "\nCenso electoral total: " << getCensoNacional() << endl;
    cout << "Votos emitidos: " << getVotosTotalesNacionales() << endl;
    
    int votosBlancosTotal = 0;
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        votosBlancosTotal += (*it)->getVotosBlancos();
    }
    cout << "Votos en blanco: " << votosBlancosTotal << endl << endl;
    
    cout << "Resultados por candidato:" << endl;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        Partido* partido = buscarPartido((*it)->getIdPartido());
        double porcentaje = 0.0;
        if (getVotosTotalesNacionales() > 0) {
            porcentaje = ((*it)->getVotos() * 100.0) / getVotosTotalesNacionales();
        }
        cout << "  " << (*it)->getNombreCompleto() << " (" 
             << (partido ? partido->getSigla() : "N/A") << "): " 
             << (*it)->getVotos() << " votos (" << fixed << setprecision(2) 
             << porcentaje << "%)" << endl;
    }
    
    // Determinar ganador o necesidad de segunda vuelta
    Candidato* ganador = NULL;
    int maxVotos = 0;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        if ((*it)->getVotos() > maxVotos) {
            maxVotos = (*it)->getVotos();
            ganador = *it;
        }
    }
    
    if (ganador != NULL) {
        double porcentajeGanador = (maxVotos * 100.0) / getVotosTotalesNacionales();
        cout << "\n*** GANADOR: " << ganador->getNombreCompleto();
        Partido* partido = buscarPartido(ganador->getIdPartido());
        if (partido) cout << " (" << partido->getSigla() << ")";
        cout << " con " << fixed << setprecision(2) << porcentajeGanador << "% ***" << endl;
        
        if (porcentajeGanador < 50.0 && !segundaVueltaRealizada) {
            cout << "\n¡ATENCIÓN! Ningún candidato obtuvo más del 50%" << endl;
            cout << "Se requiere segunda vuelta electoral" << endl;
        }
    }
}

void SistemaElectoral::generarReportesEstadisticos() const {
    if (!primeraVueltaRealizada) {
        cout << "No se ha realizado ninguna votación" << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "REPORTES ESTADÍSTICOS" << endl;
    cout << "========================================" << endl;
    
    // Estadísticas por partido
    cout << "\n--- VOTOS POR PARTIDO ---" << endl;
    map<int, int> votosPorPartido;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        votosPorPartido[(*it)->getIdPartido()] += (*it)->getVotos();
    }
    
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        int votos = votosPorPartido[(*it)->getId()];
        double porcentaje = 0.0;
        if (getVotosTotalesNacionales() > 0) {
            porcentaje = (votos * 100.0) / getVotosTotalesNacionales();
        }
        cout << (*it)->getNombre() << " (" << (*it)->getSigla() << "): " 
             << votos << " votos (" << fixed << setprecision(2) 
             << porcentaje << "%)" << endl;
    }
    
    // Estadísticas por género
    cout << "\n--- VOTOS POR GÉNERO DE CANDIDATOS ---" << endl;
    map<char, int> votosPorGenero;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        votosPorGenero[(*it)->getGenero()] += (*it)->getVotos();
    }
    
    for (auto it = votosPorGenero.begin(); it != votosPorGenero.end(); ++it) {
        string generoStr = (it->first == 'M') ? "Masculino" : 
                          (it->first == 'F') ? "Femenino" : "Otro";
        double porcentaje = 0.0;
        if (getVotosTotalesNacionales() > 0) {
            porcentaje = (it->second * 100.0) / getVotosTotalesNacionales();
        }
        cout << generoStr << ": " << it->second << " votos (" 
             << fixed << setprecision(2) << porcentaje << "%)" << endl;
    }
    
    // Participación electoral
    cout << "\n--- PARTICIPACIÓN ELECTORAL ---" << endl;
    double participacion = 0.0;
    if (getCensoNacional() > 0) {
        participacion = (getVotosTotalesNacionales() * 100.0) / getCensoNacional();
    }
    cout << "Participación: " << fixed << setprecision(2) << participacion << "%" << endl;
    cout << "Abstención: " << fixed << setprecision(2) << (100.0 - participacion) << "%" << endl;
}

bool SistemaElectoral::necesitaSegundaVuelta() const {
    if (!primeraVueltaRealizada || candidatos.empty()) {
        return false;
    }
    
    Candidato* ganador = NULL;
    int maxVotos = 0;
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        if ((*it)->getVotos() > maxVotos) {
            maxVotos = (*it)->getVotos();
            ganador = *it;
        }
    }
    
    if (ganador == NULL || getVotosTotalesNacionales() == 0) {
        return false;
    }
    
    double porcentaje = (maxVotos * 100.0) / getVotosTotalesNacionales();
    return porcentaje < 50.0;
}

void SistemaElectoral::prepararSegundaVuelta() {
    if (!primeraVueltaRealizada) {
        cout << "Debe realizar la primera vuelta antes" << endl;
        return;
    }
    
    // Encontrar los dos candidatos con más votos
    list<Candidato*> candidatosOrdenados = candidatos;
    candidatosOrdenados.sort([](Candidato* a, Candidato* b) {
        return a->getVotos() > b->getVotos();
    });
    
    if (candidatosOrdenados.size() < 2) {
        cout << "No hay suficientes candidatos para segunda vuelta" << endl;
        return;
    }
    
    auto it = candidatosOrdenados.begin();
    Candidato* primero = *it;
    ++it;
    Candidato* segundo = *it;
    
    cout << "\n=== SEGUNDA VUELTA ===" << endl;
    cout << "Candidatos clasificados:" << endl;
    Partido* p1 = buscarPartido(primero->getIdPartido());
    Partido* p2 = buscarPartido(segundo->getIdPartido());
    cout << "1. " << primero->getNombreCompleto() << " (" 
         << (p1 ? p1->getSigla() : "N/A") << ") - " << primero->getVotos() << " votos" << endl;
    cout << "2. " << segundo->getNombreCompleto() << " (" 
         << (p2 ? p2->getSigla() : "N/A") << ") - " << segundo->getVotos() << " votos" << endl;
    
    // Crear nueva lista con solo los dos candidatos principales
    list<Candidato*> candidatosSegundaVuelta;
    candidatosSegundaVuelta.push_back(primero);
    candidatosSegundaVuelta.push_back(segundo);
    
    // Guardar candidatos originales y reemplazar temporalmente
    list<Candidato*> candidatosOriginales = candidatos;
    candidatos = candidatosSegundaVuelta;
    
    // Reiniciar votos
    reiniciarVotacion();
    
    // Restaurar todos los candidatos pero mantener solo los dos con votos
    candidatos = candidatosOriginales;
}

Region* SistemaElectoral::buscarRegion(int id) const {
    for (auto it = regiones.begin(); it != regiones.end(); ++it) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return NULL;
}

Ciudad* SistemaElectoral::buscarCiudad(int id) {
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return NULL;
}

Partido* SistemaElectoral::buscarPartido(int id) const {
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return NULL;
}

Candidato* SistemaElectoral::buscarCandidato(int id) {
    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return NULL;
}

int SistemaElectoral::getCensoNacional() const {
    int total = 0;
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        total += (*it)->getCensoElectoral();
    }
    return total;
}

int SistemaElectoral::getVotosTotalesNacionales() const {
    int total = 0;
    for (auto it = todasCiudades.begin(); it != todasCiudades.end(); ++it) {
        total += (*it)->getTotalVotos();
    }
    return total;
}
