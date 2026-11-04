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

#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

/**
 * @class Medico
 * @brief Representa a un profesional de la salud en el consultorio.
 */
class Medico
{
private:
    std::string nombre_;  /**< Nombre completo del medico */
    std::string cedula_;  /**< Numero de documento de identidad */
    std::string correo_;  /**< Correo electronico de contacto */
    std::string titulo_;  /**< Titulo profesional y universidad */

public:
    /**
     * @brief Constructor por defecto.
     */
    Medico();

    /**
     * @brief Constructor parametrizado.
     * @param nombre Nombre del medico.
     * @param cedula Numero de cedula.
     * @param correo Correo electronico.
     * @param titulo Titulo profesional.
     */
    Medico(const std::string& nombre, const std::string& cedula,
           const std::string& correo, const std::string& titulo);

    /**
     * @brief Obtiene el nombre del medico.
     * @return Referencia constante al nombre.
     */
    const std::string& GetNombre() const;

    /**
     * @brief Obtiene la cedula del medico.
     * @return Referencia constante a la cedula.
     */
    const std::string& GetCedula() const;

    /**
     * @brief Obtiene el correo del medico.
     * @return Referencia constante al correo.
     */
    const std::string& GetCorreo() const;

    /**
     * @brief Obtiene el titulo del medico.
     * @return Referencia constante al titulo.
     */
    const std::string& GetTitulo() const;

    /**
     * @brief Genera una representacion en texto del medico.
     * @return Cadena formateada con la informacion del medico.
     */
    std::string ToString() const;
};

#endif
