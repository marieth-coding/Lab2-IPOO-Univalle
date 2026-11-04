/**
 * @file consultorio.cpp
 * @brief Implementación de los métodos de la clase Consultorio.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#include "consultorio.hpp"
#include <stdexcept>

Consultorio::Consultorio(const std::string& nombre)
    : nombre_(nombre), citas_()
{
}

const std::string& Consultorio::GetNombre() const
{
    return nombre_;
}

bool Consultorio::AsignarMedico(int posicion, const Medico& medico)
{
    if (posicion >= 0 && posicion < TOTAL_MEDICOS)
    {
        medicos_[posicion] = medico;
        return true;
    }
    return false;
}

const Medico& Consultorio::ObtenerMedico(int posicion) const
{
    if (posicion < 0 || posicion >= TOTAL_MEDICOS)
    {
        throw std::out_of_range("Posicion fuera de rango");
    }
    return medicos_[posicion];
}

bool Consultorio::EstaDisponible(int posicion, const std::string& fecha, const std::string& hora) const
{
    const Medico& medico_buscado = ObtenerMedico(posicion);

    for (std::size_t i = 0; i < citas_.size(); ++i)
    {
        if (citas_[i].GetMedico().GetCedula() == medico_buscado.GetCedula() &&
            citas_[i].GetFecha() == fecha &&
            citas_[i].GetHora() == hora)
        {
            return false;
        }
    }
    return true;
}

bool Consultorio::AgendarCita(const Paciente& paciente, int posicion,
                             const std::string& fecha, const std::string& hora)
{
    if (!EstaDisponible(posicion, fecha, hora))
    {
        return false;
    }

    Cita nueva_cita(paciente, ObtenerMedico(posicion), fecha, hora);
    citas_.push_back(nueva_cita);
    return true;
}

const std::vector<Cita>& Consultorio::GetCitas() const
{
    return citas_;
}
