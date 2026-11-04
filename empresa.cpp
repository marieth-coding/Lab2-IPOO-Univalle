/**
 * @file empresa.cpp
 * @brief Implementacion de metodos de agregacion y nomina en Empresa.
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

#include "empresa.hpp"
#include <stdexcept>

Empresa::Empresa(const std::string& nombre, int anio_actual)
    : nombre_(nombre),
      anio_actual_(anio_actual)
{
}

const std::string& Empresa::GetNombre() const
{
    return nombre_;
}

int Empresa::GetAnioActual() const
{
    return anio_actual_;
}

bool Empresa::AsignarEmpleado(int posicion, const Empleado& empleado)
{
    if (posicion < 0 || posicion >= TOTAL_EMPLEADOS)
    {
        return false;
    }
    empleados_[posicion] = empleado;
    return true;
}

const Empleado& Empresa::ObtenerEmpleado(int posicion) const
{
    if (posicion < 0 || posicion >= TOTAL_EMPLEADOS)
    {
        throw std::out_of_range("Posicion de empleado fuera de rango.");
    }
    return empleados_[posicion];
}

double Empresa::CalcularNominaTotal() const
{
    double total_nomina = 0.0;
    for (int i = 0; i < TOTAL_EMPLEADOS; ++i)
    {
        total_nomina += empleados_[i].CalcularSalario();
    }
    return total_nomina;
}

const Empleado& Empresa::ObtenerEmpleadoMayorEdad() const
{
    int posicion_mayor = 0;
    int mayor_edad = empleados_[0].CalcularEdad(anio_actual_);

    for (int i = 1; i < TOTAL_EMPLEADOS; ++i)
    {
        int edad_actual = empleados_[i].CalcularEdad(anio_actual_);
        if (edad_actual > mayor_edad)
        {
            mayor_edad = edad_actual;
            posicion_mayor = i;
        }
    }
    return empleados_[posicion_mayor];
}