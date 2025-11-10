# Makefile para el Sistema Electoral
# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Archivos objeto
OBJS = main.o SistemaElectoral.o Region.o Ciudad.o Partido.o Candidato.o

# Ejecutable
TARGET = electoral_system

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Reglas de compilación
main.o: main.cpp SistemaElectoral.h
	$(CXX) $(CXXFLAGS) -c main.cpp

SistemaElectoral.o: SistemaElectoral.cpp SistemaElectoral.h Region.h Ciudad.h Partido.h Candidato.h
	$(CXX) $(CXXFLAGS) -c SistemaElectoral.cpp

Region.o: Region.cpp Region.h Ciudad.h
	$(CXX) $(CXXFLAGS) -c Region.cpp

Ciudad.o: Ciudad.cpp Ciudad.h Candidato.h
	$(CXX) $(CXXFLAGS) -c Ciudad.cpp

Partido.o: Partido.cpp Partido.h
	$(CXX) $(CXXFLAGS) -c Partido.cpp

Candidato.o: Candidato.cpp Candidato.h
	$(CXX) $(CXXFLAGS) -c Candidato.cpp

# Limpiar archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Recompilar todo
rebuild: clean all

.PHONY: all clean run rebuild
