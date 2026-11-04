/**
 * @file cita.hpp
 * @brief Definición de la clase Cita para el sistema del consultorio.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#ifndef CITA_HPP
#define CITA_HPP

#include <string>
#include "paciente.hpp"
#include "medico.hpp"

/**
 * @class Cita
 * @brief Representa la reserva de una consulta medica entre un paciente y un medico.
 */
class Cita
{
private:
    Paciente paciente_; /**< Paciente que solicita la cita */
    Medico medico_;     /**< Medico asignado a la cita */
    std::string fecha_; /**< Fecha de la consulta (DD/MM/AAAA) */
    std::string hora_;  /**< Hora de la consulta (HH:MM) */

public:
    /**
     * @brief Constructor por defecto.
     */
    Cita();

    /**
     * @brief Constructor parametrizado.
     * @param paciente Objeto paciente.
     * @param medico Objeto medico.
     * @param fecha Cadena con la fecha.
     * @param hora Cadena con la hora.
     */
    Cita(const Paciente& paciente, const Medico& medico,
         const std::string& fecha, const std::string& hora);

    /**
     * @brief Obtiene el paciente asignado.
     * @return Referencia constante al paciente.
     */
    const Paciente& GetPaciente() const;

    /**
     * @brief Obtiene el medico asignado.
     * @return Referencia constante al medico.
     */
    const Medico& GetMedico() const;

    /**
     * @brief Obtiene la fecha de la cita.
     * @return Referencia constante a la fecha.
     */
    const std::string& GetFecha() const;

    /**
     * @brief Obtiene la hora de la cita.
     * @return Referencia constante a la hora.
     */
    const std::string& GetHora() const;

    /**
     * @brief Genera el resumen estructurado de la reserva.
     * @return Cadena formateada con los datos de la cita.
     */
    std::string ResumenReserva() const;
};

#endif
