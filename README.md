# Sistema de Simulación Electoral Nacional

Sistema completo en C++ para simular elecciones nacionales con gestión de regiones, ciudades, partidos políticos y candidatos.

## Características

### Estructuras de Datos
- **Listas enlazadas (list)**: Gestión dinámica de regiones, ciudades, partidos y candidatos
- **Multilistas**: Ciudades asociadas a regiones mediante referencias múltiples
- **Mapas (map)**: Agregación eficiente de votos por partido y género

### Funcionalidades Principales

1. **Gestión de Datos**
   - Crear, modificar y listar regiones
   - Crear, modificar y listar ciudades con censos
   - Crear, modificar y listar partidos políticos
   - Crear, modificar y listar candidatos (con género)

2. **Persistencia de Datos**
   - Lectura desde archivos .txt (partidos.txt, candidatos.txt, regiones.txt, ciudades.txt)
   - Escritura de datos en archivos .txt
   - Exportación de resultados a archivos de texto

3. **Sistema Electoral**
   - Generación de censos aleatorios por ciudad
   - Simulación de votación con participación realista (70-90%)
   - Soporte para votos en blanco (aproximadamente 5%)
   - Modificación de datos antes de realizar la votación

4. **Resultados y Reportes**
   - Visualización de resultados por ciudad
   - Visualización de resultados por región
   - Visualización de resultados nacionales
   - Reportes estadísticos por partido político
   - Reportes estadísticos por género de candidatos
   - Análisis de participación electoral

5. **Segunda Vuelta Electoral**
   - Detección automática cuando ningún candidato supera el 50%
   - Selección de los dos candidatos más votados
   - Simulación de segunda vuelta
   - Resultados de segunda vuelta

## Arquitectura del Sistema

### Clases Principales

```
Candidato.h/cpp    - Representación de candidatos (nombre, género, partido, votos)
Partido.h/cpp      - Representación de partidos políticos (nombre, sigla)
Ciudad.h/cpp       - Gestión de ciudades (censo, votos, lista de candidatos)
Region.h/cpp       - Gestión de regiones (lista de ciudades)
SistemaElectoral.h/cpp - Controlador principal del sistema electoral
main.cpp           - Interfaz de usuario y menú principal
```

### Diseño Modular
- Código autodocumentado con comentarios descriptivos
- Separación de interfaces (.h) e implementación (.cpp)
- Principio de responsabilidad única en cada clase
- Encapsulamiento de datos con getters y setters

## Compilación y Ejecución

### Requisitos
- Compilador C++ con soporte para C++11 o superior (g++, clang++)
- Make (opcional, para usar Makefile)

### Compilación con Makefile
```bash
make              # Compilar el proyecto
make run          # Compilar y ejecutar
make clean        # Limpiar archivos compilados
make rebuild      # Limpiar y recompilar
```

### Compilación manual
```bash
g++ -std=c++11 -Wall -Wextra -c Candidato.cpp
g++ -std=c++11 -Wall -Wextra -c Partido.cpp
g++ -std=c++11 -Wall -Wextra -c Ciudad.cpp
g++ -std=c++11 -Wall -Wextra -c Region.cpp
g++ -std=c++11 -Wall -Wextra -c SistemaElectoral.cpp
g++ -std=c++11 -Wall -Wextra -c main.cpp
g++ -std=c++11 -o electoral_system main.o SistemaElectoral.o Region.o Ciudad.o Partido.o Candidato.o
```

### Ejecución
```bash
./electoral_system
```

## Uso del Sistema

### Flujo de Trabajo Típico

1. **Inicio**: El sistema ofrece cargar datos de ejemplo
2. **Gestión**: Agregar/modificar regiones, ciudades, partidos y candidatos
3. **Preparación**: Generar censos aleatorios o establecer manualmente
4. **Votación**: Simular la primera vuelta electoral
5. **Resultados**: Ver resultados por ciudad, región o a nivel nacional
6. **Reportes**: Generar estadísticas por partido y género
7. **Segunda Vuelta**: Si es necesario, realizar segunda vuelta
8. **Persistencia**: Guardar datos y resultados en archivos

### Formato de Archivos de Entrada

**partidos.txt**
```
Nombre del Partido|SIGLA
Partido Liberal|PL
Partido Conservador|PC
```

**candidatos.txt**
```
Nombre|Apellido|Género|IDPartido
Juan|Pérez|M|1
María|González|F|2
```

**regiones.txt**
```
Nombre de la Región
Región Norte
Región Centro
```

**ciudades.txt**
```
Nombre|IDRegión|Censo
Bogotá|1|8000000
Medellín|1|2500000
```

## Ejemplo de Uso

```
1. Seleccionar opción 1 (Gestión de Datos) para agregar datos
2. Seleccionar opción 5 para generar censos aleatorios
3. Seleccionar opción 6 para simular la votación
4. Seleccionar opción 7 para ver resultados
5. Seleccionar opción 8 para reportes estadísticos
6. Si es necesario, seleccionar opción 9 para segunda vuelta
7. Seleccionar opción 10 para guardar resultados
```

## Características Técnicas

- **Gestión automática de memoria**: Uso de punteros con liberación en destructor
- **STL**: Uso intensivo de contenedores estándar (list, map)
- **Generación aleatoria**: Uso de srand/rand para censos y simulación de votos
- **Entrada/Salida robusta**: Manejo de archivos con validación
- **Formato de salida**: Resultados con porcentajes y formato tabular

## Autor

Sistema desarrollado para simular procesos electorales con fines educativos y de análisis.

## Licencia

Proyecto educativo - Uso libre para fines académicos
