/**
 * @file empresa.hpp
 * @brief Definicion de la clase Empresa para agrupar empleados y liquidar nomina.
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

#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "empleado.hpp"
#include <string>

/**
 * @brief Modela la empresa Muebles Modernos y centraliza sus 3 empleados.
 * @invariant anio_actual_ > 0
 */
class Empresa
{
public:
    /** @brief Cantidad fija de operarios en el taller segun requerimiento. */
    static const int TOTAL_EMPLEADOS = 3;

    /**
     * @brief Constructor de la empresa con nombre y anio de operacion.
     * @pre anio_actual > 0
     * @param[in] nombre Razon social del taller.
     * @param[in] anio_actual Anio de vigencia de la sesion.
     */
    Empresa(const std::string& nombre, int anio_actual);

    /**
     * @brief Consulta el nombre comercial de la empresa.
     * @return Referencia constante al nombre de la empresa.
     */
    const std::string& GetNombre() const;

    /**
     * @brief Consulta el anio actual registrado en la empresa.
     * @return Anio de referencia.
     */
    int GetAnioActual() const;

    /**
     * @brief Asigna un operario en la posicion indicada del taller.
     * @param[in] posicion Indice en el arreglo (0 <= posicion < TOTAL_EMPLEADOS).
     * @param[in] empleado Objeto Empleado a almacenar por copia interna.
     * @return true si la posicion es valida, false en caso contrario.
     */
    bool AsignarEmpleado(int posicion, const Empleado& empleado);

    /**
     * @brief Recupera la referencia al operario de una posicion dada.
     * @pre 0 <= posicion && posicion < TOTAL_EMPLEADOS
     * @param[in] posicion Indice del operario a consultar.
     * @return Referencia constante al Empleado almacenado.
     * @throws std::out_of_range si la posicion esta fuera de los limites.
     */
    const Empleado& ObtenerEmpleado(int posicion) const;

    /**
     * @brief Calcula la suma total de salarios de todos los empleados.
     * @return Nomina acumulada del periodo.
     */
    double CalcularNominaTotal() const;

    /**
     * @brief Determina el operario con mayor edad en el taller.
     * @post Si existe empate en la mayor edad, retorna el primer empleado hallado.
     * @return Referencia constante al Empleado de mayor edad.
     */
    const Empleado& ObtenerEmpleadoMayorEdad() const;

private:
    std::string nombre_;
    int anio_actual_;
    Empleado empleados_[TOTAL_EMPLEADOS];
};

#endif // EMPRESA_HPP