/**
 * @file paciente.hpp
 * @brief Definición de la clase Paciente para el sistema del consultorio.
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>

/**
 * @class Paciente
 * @brief Representa a un usuario que solicita una cita medica en el consultorio.
 */
class Paciente
{
private:
    std::string nombre_;   /**< Nombre completo del paciente */
    std::string cedula_;   /**< Numero de cedula de identidad */
    std::string correo_;   /**< Correo electronico de contacto */
    std::string telefono_; /**< Telefono de contacto */
    int edad_;             /**< Edad en anos cumplidos */

public:
    /**
     * @brief Constructor por defecto.
     */
    Paciente();

    /**
     * @brief Constructor parametrizado.
     * @param nombre Nombre del paciente.
     * @param cedula Numero de cedula.
     * @param correo Correo electronico.
     * @param telefono Numero telefonico.
     * @param edad Edad en anos.
     */
    Paciente(const std::string& nombre, const std::string& cedula,
             const std::string& correo, const std::string& telefono, int edad);

    /**
     * @brief Obtiene el nombre del paciente.
     * @return Referencia constante al nombre.
     */
    const std::string& GetNombre() const;

    /**
     * @brief Obtiene la cedula del paciente.
     * @return Referencia constante a la cedula.
     */
    const std::string& GetCedula() const;

    /**
     * @brief Obtiene el correo del paciente.
     * @return Referencia constante al correo.
     */
    const std::string& GetCorreo() const;

    /**
     * @brief Obtiene el telefono del paciente.
     * @return Referencia constante al telefono.
     */
    const std::string& GetTelefono() const;

    /**
     * @brief Obtiene la edad del paciente.
     * @return Edad del paciente en anos.
     */
    int GetEdad() const;
};

#endif
