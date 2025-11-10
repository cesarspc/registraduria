#ifndef SISTEMAELECTORAL_H
#define SISTEMAELECTORAL_H

#include <string>
#include <list>
#include <map>
#include "Region.h"
#include "Ciudad.h"
#include "Partido.h"
#include "Candidato.h"
using namespace std;

/**
 * Clase SistemaElectoral
 * Gestiona todo el sistema de votación, incluyendo regiones, ciudades, 
 * partidos, candidatos y simulación de elecciones
 */
class SistemaElectoral {
private:
    list<Region*> regiones;
    list<Ciudad*> todasCiudades;
    list<Partido*> partidos;
    list<Candidato*> candidatos;
    bool primeraVueltaRealizada;
    bool segundaVueltaRealizada;
    
    // Contadores de IDs
    int siguienteIdRegion;
    int siguienteIdCiudad;
    int siguienteIdPartido;
    int siguienteIdCandidato;

public:
    // Constructor
    SistemaElectoral();
    
    // Destructor
    ~SistemaElectoral();
    
    // Métodos de gestión de datos
    void agregarRegion(string nombre);
    void agregarCiudad(string nombre, int idRegion, int censo);
    void agregarPartido(string nombre, string sigla);
    void agregarCandidato(string nombre, string apellido, char genero, int idPartido);
    
    // Métodos de modificación
    void modificarRegion(int id, string nuevoNombre);
    void modificarCiudad(int id, string nuevoNombre, int nuevoCenso);
    void modificarPartido(int id, string nuevoNombre, string nuevaSigla);
    void modificarCandidato(int id, string nuevoNombre, string nuevoApellido, char nuevoGenero);
    
    // Métodos de listado
    void listarRegiones() const;
    void listarCiudades() const;
    void listarPartidos() const;
    void listarCandidatos() const;
    
    // Métodos de archivo
    void cargarDatosDesdeArchivos();
    void guardarDatosEnArchivos() const;
    void guardarResultados(string archivo, bool segundaVuelta = false) const;
    
    // Métodos de simulación
    void generarCensosAleatorios(int minVotantes, int maxVotantes);
    void simularVotacion(bool segundaVuelta = false);
    void reiniciarVotacion();
    
    // Métodos de resultados
    void mostrarResultadosPorCiudad() const;
    void mostrarResultadosPorRegion() const;
    void mostrarResultadosNacionales() const;
    void generarReportesEstadisticos() const;
    
    // Segunda vuelta
    bool necesitaSegundaVuelta() const;
    void prepararSegundaVuelta();
    
    // Helpers
    Region* buscarRegion(int id) const;
    Ciudad* buscarCiudad(int id);
    Partido* buscarPartido(int id) const;
    Candidato* buscarCandidato(int id);
    int getCensoNacional() const;
    int getVotosTotalesNacionales() const;
};

#endif
