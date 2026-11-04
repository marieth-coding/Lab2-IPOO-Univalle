/**
 * @file empleado.hpp
 * @brief Definicion de la clase Empleado para la gestion de operarios del taller.
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

#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

/**
 * @brief Modela un operario en el taller Muebles Modernos.
 * @invariant anio_nacimiento_ > 0 && antiguedad_ >= 0
 * @invariant horas_trabajadas_ >= 0.0 && valor_hora_ >= 0.0
 */
class Empleado
{
public:
    /**
     * @brief Constructor por defecto.
     * @details Requerido por C++03 para permitir la instanciacion del arreglo
     *          estatico de empleados dentro de la clase Empresa.
     */
    Empleado();

    /**
     * @brief Constructor parametrizado con datos completos del empleado.
     * @pre anio_nacimiento > 0 && antiguedad >= 0
     * @pre horas_trabajadas >= 0.0 && valor_hora >= 0.0
     * @param[in] nombre Nombre completo del operario.
     * @param[in] documento Documento de identidad del operario.
     * @param[in] anio_nacimiento Anio calendario de nacimiento.
     * @param[in] antiguedad Anios de vinculacion laboral en el taller.
     * @param[in] horas_trabajadas Horas laboradas en el periodo.
     * @param[in] valor_hora Tarifa pactada por hora trabajada.
     */
    Empleado(const std::string& nombre,
             const std::string& documento,
             int anio_nacimiento,
             int antiguedad,
             double horas_trabajadas,
             double valor_hora);

    /**
     * @brief Obtiene el nombre completo del empleado.
     * @return Referencia constante a la cadena con el nombre.
     */
    const std::string& GetNombre() const;

    /**
     * @brief Obtiene el numero de documento del empleado.
     * @return Referencia constante a la cadena con el documento.
     */
    const std::string& GetDocumento() const;

    /**
     * @brief Obtiene el anio de nacimiento registrado.
     * @return Entero con el anio de nacimiento.
     */
    int GetAnioNacimiento() const;

    /**
     * @brief Obtiene la antiguedad del trabajador en anios.
     * @return Cantidad de anios vinculado a la empresa.
     */
    int GetAntiguedad() const;

    /**
     * @brief Obtiene las horas trabajadas en el periodo liquidado.
     * @return Horas laboradas.
     */
    double GetHorasTrabajadas() const;

    /**
     * @brief Obtiene la tarifa monetaria por hora laborada.
     * @return Valor fijado por hora.
     */
    double GetValorHora() const;

    /**
     * @brief Liquida el salario multiplicando horas por valor de la hora.
     * @return Salario bruto a pagar en el periodo.
     */
    double CalcularSalario() const;

    /**
     * @brief Calcula la edad alcanzada respecto a un anio dado.
     * @pre anio_actual >= anio_nacimiento_
     * @param[in] anio_actual Anio de referencia para el computo.
     * @return Edad calculada en anios.
     */
    int CalcularEdad(int anio_actual) const;

private:
    std::string nombre_;
    std::string documento_;
    int anio_nacimiento_;
    int antiguedad_;
    double horas_trabajadas_;
    double valor_hora_;
};

#endif // EMPLEADO_HPP