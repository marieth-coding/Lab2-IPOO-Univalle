/**
 * @file paciente.cpp
 * @brief Implementación de los métodos de la clase Paciente.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#include "paciente.hpp"

Paciente::Paciente()
    : nombre_(""), cedula_(""), correo_(""), telefono_(""), edad_(0)
{
}

Paciente::Paciente(const std::string& nombre, const std::string& cedula,
                   const std::string& correo, const std::string& telefono, int edad)
    : nombre_(nombre), cedula_(cedula), correo_(correo), telefono_(telefono), edad_(edad)
{
}

const std::string& Paciente::GetNombre() const
{
    return nombre_;
}

const std::string& Paciente::GetCedula() const
{
    return cedula_;
}

const std::string& Paciente::GetCorreo() const
{
    return correo_;
}

const std::string& Paciente::GetTelefono() const
{
    return telefono_;
}

int Paciente::GetEdad() const
{
    return edad_;
}
