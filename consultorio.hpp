/**
 * @file consultorio.hpp
 * @brief Definición de la clase Consultorio para la gestión de médicos y citas.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP

#include <string>
#include <vector>
#include "medico.hpp"
#include "paciente.hpp"
#include "cita.hpp"

/**
 * @class Consultorio
 * @brief Gestiona los medicos del establecimiento y la agenda general de citas.
 */
class Consultorio
{
public:
    static const int TOTAL_MEDICOS = 3; /**< Numero fijo de medicos en el consultorio */

private:
    std::string nombre_;              /**< Nombre del consultorio */
    Medico medicos_[TOTAL_MEDICOS];   /**< Arreglo fijo de medicos */
    std::vector<Cita> citas_;         /**< Agenda de citas registradas */

public:
    /**
     * @brief Constructor parametrizado.
     * @param nombre Nombre del consultorio.
     */
    explicit Consultorio(const std::string& nombre);

    /**
     * @brief Obtiene el nombre del consultorio.
     * @return Referencia constante al nombre.
     */
    const std::string& GetNombre() const;

    /**
     * @brief Asigna un medico en una posicion especifica.
     * @param posicion Indice del arreglo (0 a 2).
     * @param medico Objeto medico a asignar.
     * @return true si la asignacion fue exitosa, false en caso contrario.
     */
    bool AsignarMedico(int posicion, const Medico& medico);

    /**
     * @brief Obtiene la referencia del medico en la posicion indicada.
     * @param posicion Indice del medico (0 a 2).
     * @return Referencia constante al medico.
     * @throw std::out_of_range Si la posicion esta fuera del rango valido.
     */
    const Medico& ObtenerMedico(int posicion) const;

    /**
     * @brief Verifica si un medico esta libre en una fecha y hora especificas.
     * @param posicion Indice del medico.
     * @param fecha Fecha de la consulta.
     * @param hora Hora de la consulta.
     * @return true si esta disponible, false si ya posee una cita agendada.
     */
    bool EstaDisponible(int posicion, const std::string& fecha, const std::string& hora) const;

    /**
     * @brief Agenda una nueva cita si el medico esta disponible.
     * @param paciente Datos del paciente.
     * @param posicion Indice del medico seleccionado.
     * @param fecha Fecha de la cita.
     * @param hora Hora de la cita.
     * @return true si la cita fue agendada exitosamente, false en caso contrario.
     */
    bool AgendarCita(const Paciente& paciente, int posicion,
                     const std::string& fecha, const std::string& hora);

    /**
     * @brief Obtiene el listado completo de citas agendadas.
     * @return Referencia constante al vector de citas.
     */
    const std::vector<Cita>& GetCitas() const;
};

#endif
