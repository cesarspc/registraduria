#include <iostream>
#include <limits>
#include "SistemaElectoral.h"
using namespace std;

/**
 * Sistema de Simulación Electoral Nacional
 * Permite gestionar regiones, ciudades, partidos y candidatos
 * Simula elecciones con votos en blanco, censos aleatorios
 * Muestra resultados por ciudad, región y país
 * Soporta segunda vuelta electoral
 * Genera reportes estadísticos por partido y género
 */

void mostrarMenuPrincipal() {
    cout << "\n================================================" << endl;
    cout << "   SISTEMA DE SIMULACIÓN ELECTORAL NACIONAL" << endl;
    cout << "================================================" << endl;
    cout << "1.  Gestión de Datos" << endl;
    cout << "2.  Cargar datos desde archivos" << endl;
    cout << "3.  Guardar datos en archivos" << endl;
    cout << "4.  Listar información" << endl;
    cout << "5.  Generar censos aleatorios" << endl;
    cout << "6.  Simular votación (Primera vuelta)" << endl;
    cout << "7.  Mostrar resultados" << endl;
    cout << "8.  Generar reportes estadísticos" << endl;
    cout << "9.  Segunda vuelta electoral" << endl;
    cout << "10. Guardar resultados en archivo" << endl;
    cout << "0.  Salir" << endl;
    cout << "================================================" << endl;
    cout << "Seleccione una opción: ";
}

void menuGestionDatos(SistemaElectoral& sistema) {
    int opcion;
    do {
        cout << "\n=== GESTIÓN DE DATOS ===" << endl;
        cout << "1. Agregar región" << endl;
        cout << "2. Agregar ciudad" << endl;
        cout << "3. Agregar partido" << endl;
        cout << "4. Agregar candidato" << endl;
        cout << "5. Modificar región" << endl;
        cout << "6. Modificar ciudad" << endl;
        cout << "7. Modificar partido" << endl;
        cout << "8. Modificar candidato" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(opcion) {
            case 1: {
                string nombre;
                cout << "Nombre de la región: ";
                getline(cin, nombre);
                sistema.agregarRegion(nombre);
                break;
            }
            case 2: {
                string nombre;
                int idRegion, censo;
                sistema.listarRegiones();
                cout << "ID de la región: ";
                cin >> idRegion;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nombre de la ciudad: ";
                getline(cin, nombre);
                cout << "Censo electoral: ";
                cin >> censo;
                sistema.agregarCiudad(nombre, idRegion, censo);
                break;
            }
            case 3: {
                string nombre, sigla;
                cout << "Nombre del partido: ";
                getline(cin, nombre);
                cout << "Sigla del partido: ";
                getline(cin, sigla);
                sistema.agregarPartido(nombre, sigla);
                break;
            }
            case 4: {
                string nombre, apellido;
                char genero;
                int idPartido;
                sistema.listarPartidos();
                cout << "ID del partido: ";
                cin >> idPartido;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nombre del candidato: ";
                getline(cin, nombre);
                cout << "Apellido del candidato: ";
                getline(cin, apellido);
                cout << "Género (M/F/O): ";
                cin >> genero;
                sistema.agregarCandidato(nombre, apellido, genero, idPartido);
                break;
            }
            case 5: {
                int id;
                string nombre;
                sistema.listarRegiones();
                cout << "ID de la región a modificar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                sistema.modificarRegion(id, nombre);
                break;
            }
            case 6: {
                int id, censo;
                string nombre;
                sistema.listarCiudades();
                cout << "ID de la ciudad a modificar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                cout << "Nuevo censo: ";
                cin >> censo;
                sistema.modificarCiudad(id, nombre, censo);
                break;
            }
            case 7: {
                int id;
                string nombre, sigla;
                sistema.listarPartidos();
                cout << "ID del partido a modificar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                cout << "Nueva sigla: ";
                getline(cin, sigla);
                sistema.modificarPartido(id, nombre, sigla);
                break;
            }
            case 8: {
                int id;
                string nombre, apellido;
                char genero;
                sistema.listarCandidatos();
                cout << "ID del candidato a modificar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                cout << "Nuevo apellido: ";
                getline(cin, apellido);
                cout << "Nuevo género (M/F/O): ";
                cin >> genero;
                sistema.modificarCandidato(id, nombre, apellido, genero);
                break;
            }
            case 0:
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 0);
}

void menuListarInformacion(SistemaElectoral& sistema) {
    int opcion;
    do {
        cout << "\n=== LISTAR INFORMACIÓN ===" << endl;
        cout << "1. Listar regiones" << endl;
        cout << "2. Listar ciudades" << endl;
        cout << "3. Listar partidos" << endl;
        cout << "4. Listar candidatos" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                sistema.listarRegiones();
                break;
            case 2:
                sistema.listarCiudades();
                break;
            case 3:
                sistema.listarPartidos();
                break;
            case 4:
                sistema.listarCandidatos();
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 0);
}

void menuMostrarResultados(SistemaElectoral& sistema) {
    int opcion;
    do {
        cout << "\n=== MOSTRAR RESULTADOS ===" << endl;
        cout << "1. Resultados por ciudad" << endl;
        cout << "2. Resultados por región" << endl;
        cout << "3. Resultados nacionales" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                sistema.mostrarResultadosPorCiudad();
                break;
            case 2:
                sistema.mostrarResultadosPorRegion();
                break;
            case 3:
                sistema.mostrarResultadosNacionales();
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 0);
}

void menuSegundaVuelta(SistemaElectoral& sistema) {
    if (!sistema.necesitaSegundaVuelta()) {
        cout << "\nNo es necesaria una segunda vuelta." << endl;
        cout << "Un candidato ya obtuvo más del 50% de los votos." << endl;
        return;
    }
    
    cout << "\n¡Se requiere segunda vuelta!" << endl;
    cout << "¿Desea realizar la segunda vuelta? (S/N): ";
    char respuesta;
    cin >> respuesta;
    
    if (respuesta == 'S' || respuesta == 's') {
        sistema.prepararSegundaVuelta();
        cout << "\nSimulando segunda vuelta..." << endl;
        sistema.simularVotacion(true);
        sistema.mostrarResultadosNacionales();
        
        cout << "\n¿Desea guardar los resultados de segunda vuelta? (S/N): ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            sistema.guardarResultados("resultados_segunda_vuelta.txt", true);
        }
    }
}

void cargarDatosEjemplo(SistemaElectoral& sistema) {
    cout << "\n¿Desea cargar datos de ejemplo? (S/N): ";
    char respuesta;
    cin >> respuesta;
    
    if (respuesta == 'S' || respuesta == 's') {
        // Agregar regiones
        sistema.agregarRegion("Región Norte");
        sistema.agregarRegion("Región Centro");
        sistema.agregarRegion("Región Sur");
        
        // Agregar partidos
        sistema.agregarPartido("Partido Liberal", "PL");
        sistema.agregarPartido("Partido Conservador", "PC");
        sistema.agregarPartido("Partido Verde", "PV");
        sistema.agregarPartido("Partido Social", "PS");
        
        // Agregar candidatos
        sistema.agregarCandidato("Juan", "Pérez", 'M', 1);
        sistema.agregarCandidato("María", "González", 'F', 2);
        sistema.agregarCandidato("Carlos", "Rodríguez", 'M', 3);
        sistema.agregarCandidato("Ana", "Martínez", 'F', 4);
        
        // Agregar ciudades
        sistema.agregarCiudad("Bogotá", 1, 8000000);
        sistema.agregarCiudad("Medellín", 1, 2500000);
        sistema.agregarCiudad("Cali", 2, 2400000);
        sistema.agregarCiudad("Barranquilla", 2, 1200000);
        sistema.agregarCiudad("Cartagena", 3, 1000000);
        sistema.agregarCiudad("Bucaramanga", 3, 600000);
        
        cout << "\nDatos de ejemplo cargados exitosamente!" << endl;
    }
}

int main() {
    SistemaElectoral sistema;
    
    cout << "========================================" << endl;
    cout << " BIENVENIDO AL SISTEMA ELECTORAL" << endl;
    cout << "========================================" << endl;
    
    cargarDatosEjemplo(sistema);
    
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(opcion) {
            case 1:
                menuGestionDatos(sistema);
                break;
                
            case 2:
                sistema.cargarDatosDesdeArchivos();
                break;
                
            case 3:
                sistema.guardarDatosEnArchivos();
                break;
                
            case 4:
                menuListarInformacion(sistema);
                break;
                
            case 5: {
                int min, max;
                cout << "Mínimo número de votantes por ciudad: ";
                cin >> min;
                cout << "Máximo número de votantes por ciudad: ";
                cin >> max;
                sistema.generarCensosAleatorios(min, max);
                break;
            }
            
            case 6:
                cout << "\nIniciando simulación de primera vuelta..." << endl;
                sistema.simularVotacion(false);
                cout << "\n¡Votación completada!" << endl;
                cout << "Use la opción 7 para ver los resultados" << endl;
                break;
                
            case 7:
                menuMostrarResultados(sistema);
                break;
                
            case 8:
                sistema.generarReportesEstadisticos();
                break;
                
            case 9:
                menuSegundaVuelta(sistema);
                break;
                
            case 10: {
                string archivo;
                cout << "Nombre del archivo (ej: resultados.txt): ";
                getline(cin, archivo);
                sistema.guardarResultados(archivo, false);
                break;
            }
            
            case 0:
                cout << "\n¡Gracias por usar el Sistema Electoral!" << endl;
                cout << "Hasta pronto." << endl;
                break;
                
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 0);
    
    return 0;
}
