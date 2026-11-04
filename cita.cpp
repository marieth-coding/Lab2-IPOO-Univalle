/**
 * @file cita.cpp
 * @brief Implementación de los métodos de la clase Cita.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */
#include "cita.hpp"

Cita::Cita()
    : paciente_(), medico_(), fecha_(""), hora_("")
{
}

Cita::Cita(const Paciente& paciente, const Medico& medico,
           const std::string& fecha, const std::string& hora)
    : paciente_(paciente), medico_(medico), fecha_(fecha), hora_(hora)
{
}

const Paciente& Cita::GetPaciente() const
{
    return paciente_;
}

const Medico& Cita::GetMedico() const
{
    return medico_;
}

const std::string& Cita::GetFecha() const
{
    return fecha_;
}

const std::string& Cita::GetHora() const
{
    return hora_;
}

std::string Cita::ResumenReserva() const
{
    std::string resumen = "Paciente: " + paciente_.GetNombre() + " (Cedula: " + paciente_.GetCedula() + ")\n";
    resumen += "Medico  : " + medico_.GetNombre() + "\n";
    resumen += "Fecha   : " + fecha_ + "\n";
    resumen += "Hora    : " + hora_;
    return resumen;
}
