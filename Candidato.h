#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
using namespace std;

/**
 * Clase Candidato
 * Representa un candidato político con sus atributos básicos
 */
class Candidato {
private:
    int id;
    string nombre;
    string apellido;
    char genero; // 'M' masculino, 'F' femenino, 'O' otro
    int idPartido;
    int votos;

public:
    // Constructor
    Candidato(int id = 0, string nombre = "", string apellido = "", 
              char genero = 'M', int idPartido = 0);
    
    // Getters
    int getId() const;
    string getNombre() const;
    string getApellido() const;
    string getNombreCompleto() const;
    char getGenero() const;
    int getIdPartido() const;
    int getVotos() const;
    
    // Setters
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setGenero(char genero);
    void setIdPartido(int idPartido);
    void agregarVoto();
    void reiniciarVotos();
};

#endif
