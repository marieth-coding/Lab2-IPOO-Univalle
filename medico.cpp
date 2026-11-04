/**
 * @file medico.hpp
 * @brief Definición de la clase Medico para el sistema del consultorio.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#include "medico.hpp"

Medico::Medico()
    : nombre_(""), cedula_(""), correo_(""), titulo_("")
{
}

Medico::Medico(const std::string& nombre, const std::string& cedula,
               const std::string& correo, const std::string& titulo)
    : nombre_(nombre), cedula_(cedula), correo_(correo), titulo_(titulo)
{
}

const std::string& Medico::GetNombre() const
{
    return nombre_;
}

const std::string& Medico::GetCedula() const
{
    return cedula_;
}

const std::string& Medico::GetCorreo() const
{
    return correo_;
}

const std::string& Medico::GetTitulo() const
{
    return titulo_;
}

std::string Medico::ToString() const
{
    std::string resultado = "Nombre : " + nombre_ + "\n";
    resultado += "Cedula : " + cedula_ + "\n";
    resultado += "Correo : " + correo_ + "\n";
    resultado += "Titulo : " + titulo_;
    return resultado;
}
