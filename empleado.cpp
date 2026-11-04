/**
 * @file empleado.cpp
 * @brief Implementacion de los metodos de la clase Empleado.
 *
 * Laboratorio 2 (Agregacion y Composicion), Ejercicio 1: Muebles Modernos.
 * Curso 75003C, Grupo 2. Profesor: Jose Antonio Garcia Mecinas.
 *
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @date 2026-10-28 (creacion)
 * @date 2026-10-28 (ultima modificacion)
 * @version 1.0
 * @copyright Uso academico, Universidad del Valle.
 */

#include "empleado.hpp"

namespace
{
    const int ANIO_NACIMIENTO_POR_DEFECTO = 2000;
}

Empleado::Empleado()
    : nombre_(""),
      documento_(""),
      anio_nacimiento_(ANIO_NACIMIENTO_POR_DEFECTO),
      antiguedad_(0),
      horas_trabajadas_(0.0),
      valor_hora_(0.0)
{
}

Empleado::Empleado(const std::string& nombre,
                   const std::string& documento,
                   int anio_nacimiento,
                   int antiguedad,
                   double horas_trabajadas,
                   double valor_hora)
    : nombre_(nombre),
      documento_(documento),
      anio_nacimiento_(anio_nacimiento),
      antiguedad_(antiguedad),
      horas_trabajadas_(horas_trabajadas),
      valor_hora_(valor_hora)
{
}

const std::string& Empleado::GetNombre() const
{
    return nombre_;
}

const std::string& Empleado::GetDocumento() const
{
    return documento_;
}

int Empleado::GetAnioNacimiento() const
{
    return anio_nacimiento_;
}

int Empleado::GetAntiguedad() const
{
    return antiguedad_;
}

double Empleado::GetHorasTrabajadas() const
{
    return horas_trabajadas_;
}

double Empleado::GetValorHora() const
{
    return valor_hora_;
}

double Empleado::CalcularSalario() const
{
    return horas_trabajadas_ * valor_hora_;
}

int Empleado::CalcularEdad(int anio_actual) const
{
    return anio_actual - anio_nacimiento_;
}