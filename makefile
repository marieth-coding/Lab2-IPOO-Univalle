# ==============================================================================
# Universidad del Valle - Escuela de Ingenieria de Sistemas y Computacion
# Asignatura: Introduccion a la Programacion Orientada a Objetos en C++ (75003C)
# Laboratorio 2 - Ejercicio 2: Citas medicas.
# ==============================================================================

CXX = g++
CXXFLAGS = -std=c++03 -Wall -Wextra -Werror -pedantic

.PHONY: all clean run

all: app

app: main.o consultorio.o cita.o paciente.o medico.o
	$(CXX) -o app main.o consultorio.o cita.o paciente.o medico.o

main.o: main.cpp consultorio.hpp paciente.hpp medico.hpp cita.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

consultorio.o: consultorio.cpp consultorio.hpp medico.hpp paciente.hpp cita.hpp
	$(CXX) $(CXXFLAGS) -c consultorio.cpp -o consultorio.o

cita.o: cita.cpp cita.hpp paciente.hpp medico.hpp
	$(CXX) $(CXXFLAGS) -c cita.cpp -o cita.o

paciente.o: paciente.cpp paciente.hpp
	$(CXX) $(CXXFLAGS) -c paciente.cpp -o paciente.o

medico.o: medico.cpp medico.hpp
	$(CXX) $(CXXFLAGS) -c medico.cpp -o medico.o

clean:
	rm -f app *.o

run: app
	./app