# Guía de Uso del Sistema Electoral

## Ejemplo de Uso Completo

### 1. Compilación y Ejecución

```bash
# Compilar el proyecto
make

# Ejecutar el sistema
./electoral_system
```

### 2. Flujo de Trabajo Demo

#### Paso 1: Cargar Datos de Ejemplo
Al iniciar, el sistema pregunta si desea cargar datos de ejemplo:
```
¿Desea cargar datos de ejemplo? (S/N): S
```

Esto cargará:
- 3 regiones (Norte, Centro, Sur)
- 4 partidos políticos
- 4 candidatos (2 masculinos, 2 femeninos)
- 6 ciudades con censos predefinidos

#### Paso 2: Listar Información (Opción 4)
Puede ver todos los datos cargados:
```
Opción: 4
1. Listar regiones
2. Listar ciudades
3. Listar partidos
4. Listar candidatos
```

#### Paso 3: Simular Votación (Opción 6)
```
Opción: 6
Iniciando simulación de primera vuelta...
Simulando votación...
Votación simulada exitosamente
```

El sistema:
- Genera participación entre 70-90% del censo
- Distribuye votos aleatoriamente entre candidatos
- Asigna aproximadamente 5% de votos en blanco

#### Paso 4: Ver Resultados (Opción 7)
```
Opción: 7
=== MOSTRAR RESULTADOS ===
1. Resultados por ciudad
2. Resultados por región
3. Resultados nacionales
```

##### Resultados por Ciudad
Muestra para cada ciudad:
- Censo electoral
- Votos emitidos
- Votos en blanco
- Votos y porcentajes por candidato

##### Resultados por Región
Agrega los votos de todas las ciudades de cada región

##### Resultados Nacionales
Muestra:
- Censo total nacional
- Total de votos emitidos
- Votos en blanco totales
- Votos y porcentajes de cada candidato
- Ganador y si requiere segunda vuelta

#### Paso 5: Reportes Estadísticos (Opción 8)
```
Opción: 8
```

Genera:
- **Votos por partido**: Suma de votos de todos los candidatos del mismo partido
- **Votos por género**: Distribución de votos según el género de los candidatos
- **Participación electoral**: Porcentaje de votantes vs censo

Ejemplo de salida:
```
--- VOTOS POR PARTIDO ---
Partido Liberal (PL): 3500000 votos (28.50%)
Partido Conservador (PC): 3200000 votos (26.00%)
Partido Verde (PV): 2800000 votos (22.80%)
Partido Social (PS): 2770000 votos (22.55%)

--- VOTOS POR GÉNERO DE CANDIDATOS ---
Masculino: 6300000 votos (51.22%)
Femenino: 5970000 votos (48.56%)

--- PARTICIPACIÓN ELECTORAL ---
Participación: 82.35%
Abstención: 17.65%
```

#### Paso 6: Segunda Vuelta (Opción 9)
Si ningún candidato obtiene más del 50%:
```
Opción: 9
¡Se requiere segunda vuelta!
¿Desea realizar la segunda vuelta? (S/N): S
```

El sistema:
1. Selecciona los dos candidatos más votados
2. Reinicia los contadores
3. Simula una nueva votación solo entre esos dos candidatos
4. Muestra resultados definitivos

#### Paso 7: Guardar Resultados (Opción 10)
```
Opción: 10
Nombre del archivo: resultados_elecciones_2024.txt
Resultados guardados en: resultados_elecciones_2024.txt
```

Genera un archivo de texto completo con:
- Resultados nacionales
- Resultados por región con detalle
- Información de todos los candidatos

#### Paso 8: Guardar Datos (Opción 3)
```
Opción: 3
Datos guardados en archivos
```

Crea archivos:
- `partidos.txt`
- `candidatos.txt`
- `regiones.txt`
- `ciudades.txt`

### 3. Funciones Avanzadas

#### Gestión de Datos (Opción 1)
Permite:
- Agregar nuevas regiones, ciudades, partidos y candidatos
- Modificar información existente
- Personalizar completamente el escenario electoral

#### Generar Censos Aleatorios (Opción 5)
```
Opción: 5
Mínimo número de votantes por ciudad: 100000
Máximo número de votantes por ciudad: 5000000
Censos aleatorios generados
```

Útil para:
- Simulaciones con diferentes tamaños de población
- Pruebas con distribuciones demográficas variadas

#### Cargar Datos desde Archivos (Opción 2)
```
Opción: 2
Partidos cargados desde archivo
Candidatos cargados desde archivo
Regiones cargadas desde archivo
Ciudades cargadas desde archivo
```

Permite:
- Reutilizar configuraciones previas
- Compartir escenarios electorales
- Realizar múltiples simulaciones con los mismos datos base

### 4. Casos de Uso

#### Caso 1: Simulación Electoral Básica
1. Cargar datos de ejemplo: S
2. Simular votación: Opción 6
3. Ver resultados nacionales: Opción 7 → 3
4. Salir: Opción 0

#### Caso 2: Análisis Completo con Reportes
1. Cargar datos de ejemplo: S
2. Simular votación: Opción 6
3. Ver resultados por ciudad: Opción 7 → 1
4. Ver resultados por región: Opción 7 → 2
5. Ver resultados nacionales: Opción 7 → 3
6. Generar reportes: Opción 8
7. Guardar resultados: Opción 10
8. Salir: Opción 0

#### Caso 3: Simulación con Segunda Vuelta
1. Cargar datos de ejemplo: S
2. Simular votación: Opción 6
3. Ver resultados nacionales: Opción 7 → 3
4. (Si <50%) Segunda vuelta: Opción 9 → S
5. Guardar resultados: Opción 10
6. Salir: Opción 0

#### Caso 4: Personalización Completa
1. No cargar datos de ejemplo: N
2. Gestión de datos: Opción 1
   - Agregar regiones
   - Agregar partidos
   - Agregar candidatos
   - Agregar ciudades con censos
3. Guardar datos: Opción 3
4. Simular votación: Opción 6
5. Ver resultados: Opción 7
6. Salir: Opción 0

### 5. Formato de Archivos

Los archivos usan el formato pipe-delimited (|) para facilitar la lectura y escritura:

**partidos.txt**: `Nombre|Sigla`
**candidatos.txt**: `Nombre|Apellido|Género|IDPartido`
**regiones.txt**: `Nombre` (uno por línea)
**ciudades.txt**: `Nombre|IDRegión|Censo`

Este formato permite:
- Fácil edición con editores de texto
- Importación/exportación a hojas de cálculo
- Procesamiento con scripts externos

### 6. Características Destacadas

- **Código Modular**: Separación clara de responsabilidades
- **Autodocumentado**: Comentarios descriptivos en todo el código
- **Manejo de Memoria**: Destructor que libera recursos correctamente
- **STL**: Uso de contenedores estándar para mejor rendimiento
- **Interfaz Amigable**: Menús intuitivos y mensajes claros
- **Persistencia**: Soporte completo de lectura/escritura de datos
- **Simulación Realista**: Participación y distribución de votos basada en rangos reales

### 7. Limitaciones y Consideraciones

- La simulación usa números aleatorios para distribuir votos
- Los resultados variarán en cada simulación
- El sistema está diseñado para propósitos educativos y demostrativos
- Para simulaciones de gran escala, considerar optimizaciones de rendimiento
