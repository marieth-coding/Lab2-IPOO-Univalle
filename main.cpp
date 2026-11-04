/**
 * @file main.cpp
 * @brief Programa principal controlador para el Consultorio Médico "Vivir Sano".
 * @author Darlyn Valeria Jurado Burbano (darlyn.jurado@correounivalle.edu.co)
 * @author Santiago Andres Gomez Galvis (santiago.andres.gomez@correounivalle.edu.co)
 * @author Marieth Leguizamo Fajardo (marieth.leguizamo@correounivalle.edu.co)
 * @version 1.0
 * @date 2026-11-02
 * @license GPL-3.0
 */

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "consultorio.hpp"
#include "medico.hpp"
#include "paciente.hpp"

/**
 * @brief Comprueba si una cadena esta vacia o compuesta solo por espacios.
 * @param texto Cadena a evaluar.
 * @return true si esta vacia, false en caso contrario.
 */
bool EsTextoVacio(const std::string& texto)
{
    if (texto.empty())
    {
        return true;
    }
    for (std::size_t i = 0; i < texto.length(); ++i)
    {
        if (texto[i] != ' ' && texto[i] != '\t' && texto[i] != '\r' && texto[i] != '\n')
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Valida si un correo electronico contiene al menos un caracter '@'.
 * @param correo Cadena del correo.
 * @return true si contiene '@', false en caso contrario.
 */
bool ValidarCorreo(const std::string& correo)
{
    if (EsTextoVacio(correo))
    {
        return false;
    }
    return (correo.find('@') != std::string::npos);
}

/**
 * @brief Valida si una fecha cumple con el formato DD/MM/AAAA basico.
 * @param fecha Cadena de la fecha.
 * @return true si tiene el formato correcto, false en caso contrario.
 */
bool ValidarFormatoFecha(const std::string& fecha)
{
    if (fecha.length() != 10)
    {
        return false;
    }
    if (fecha[2] != '/' || fecha[5] != '/')
    {
        return false;
    }

    int dia = std::atoi(fecha.substr(0, 2).c_str());
    int mes = std::atoi(fecha.substr(3, 2).c_str());
    int anio = std::atoi(fecha.substr(6, 4).c_str());

    if (mes < 1 || mes > 12)
    {
        return false;
    }
    if (dia < 1 || dia > 31)
    {
        return false;
    }
    if (anio < 2024 || anio > 2100)
    {
        return false;
    }

    // Validacion de dias segun el mes
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        return false;
    }
    if (mes == 2)
    {
        bool es_bisiesto = ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));
        if (es_bisiesto && dia > 29)
        {
            return false;
        }
        if (!es_bisiesto && dia > 28)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Valida si una hora cumple con el formato HH:MM (00:00 a 23:59).
 * @param hora Cadena de la hora.
 * @return true si es valida, false en caso contrario.
 */
bool ValidarFormatoHora(const std::string& hora)
{
    if (hora.length() != 5)
    {
        return false;
    }
    if (hora[2] != ':')
    {
        return false;
    }

    int hh = std::atoi(hora.substr(0, 2).c_str());
    int mm = std::atoi(hora.substr(3, 2).c_str());

    if (hh < 0 || hh > 23)
    {
        return false;
    }
    if (mm < 0 || mm > 59)
    {
        return false;
    }

    return true;
}

/**
 * @brief Lee una cadena de la consola asegurando que no este vacia.
 * @param mensaje Mensaje de solicitud.
 * @return Cadena ingresada valida.
 */
std::string LeerTextoNoVacio(const std::string& mensaje)
{
    std::string entrada = "";
    while (true)
    {
        std::cout << mensaje;
        std::getline(std::cin, entrada);
        if (!EsTextoVacio(entrada))
        {
            return entrada;
        }
        std::cout << "Error: El texto no puede estar vacio. Intente de nuevo.\n";
    }
}

/**
 * @brief Lee y valida un correo electronico.
 * @param mensaje Mensaje de solicitud.
 * @return Correo electronico valido.
 */
std::string LeerCorreoValido(const std::string& mensaje)
{
    std::string correo = "";
    while (true)
    {
        correo = LeerTextoNoVacio(mensaje);
        if (ValidarCorreo(correo))
        {
            return correo;
        }
        std::cout << "Error: El correo debe contener el caracter '@'. Intente de nuevo.\n";
    }
}

/**
 * @brief Lee y valida la edad del paciente en el rango [0, 120].
 * @param mensaje Mensaje de solicitud.
 * @return Edad valida.
 */
int LeerEdadValida(const std::string& mensaje)
{
    int edad = 0;
    while (true)
    {
        std::cout << mensaje;
        if (std::cin >> edad)
        {
            if (edad >= 0 && edad <= 120)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return edad;
            }
            std::cout << "Error: La edad debe estar entre 0 y 120 anos.\n";
        }
        else
        {
            std::cout << "Error: Ingrese un valor numerico valido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


/**
 * @brief Carga la lista inicial de medicos predeterminados en el consultorio.
 * @param consultorio Referencia al objeto Consultorio.
 */
void CargarMedicosIniciales(Consultorio& consultorio)
{
    Medico m1("Juancho Rizzo", "657686",
               "juancho.rizzo@vivirsano.com", "Medico general Univalle");
    Medico m2("Camilo Ortaliz", "454575",
               "camilo.ortaliz@vivirsano.com", "Medico general universidad Javeriana");
    Medico m3("Anacleta Dique", "243535",
               "anacleta.dique@vivirsano.com", "Medico oncologo universidad Libre");

    consultorio.AsignarMedico(0, m1);
    consultorio.AsignarMedico(1, m2);
    consultorio.AsignarMedico(2, m3);
}

/**
 * @brief Muestra el listado de medicos registrados.
 * @param consultorio Referencia constante al consultorio.
 */
void MostrarDoctores(const Consultorio& consultorio)
{
    std::cout << "\n----------------------------------------\n";
    std::cout << "       MEDICOS DEL CONSULTORIO          \n";
    std::cout << "----------------------------------------\n";
    for (int i = 0; i < Consultorio::TOTAL_MEDICOS; ++i)
    {
        std::cout << "Doctor #" << (i + 1) << ":\n";
        std::cout << consultorio.ObtenerMedico(i).ToString() << "\n";
        std::cout << "----------------------------------------\n";
    }
}

/**
 * @brief Gestiona el flujo para pedir y agendar una cita medica.
 * @param consultorio Referencia al consultorio.
 */
void PedirCita(Consultorio& consultorio)
{
    std::cout << "\n----------------------------------------\n";
    std::cout << "         SOLICITUD DE CITA MEDICA       \n";
    std::cout << "----------------------------------------\n";

    std::string nombre = LeerTextoNoVacio("Nombre del paciente: ");
    std::string cedula = LeerTextoNoVacio("Numero de cedula: ");
    std::string correo = LeerCorreoValido("Correo electronico: ");
    std::string telefono = LeerTextoNoVacio("Telefono de contacto: ");
    int edad = LeerEdadValida("Edad del paciente (0-120): ");

    Paciente paciente(nombre, cedula, correo, telefono, edad);

    std::string fecha = "";
    while (true)
    {
        fecha = LeerTextoNoVacio("Fecha de la consulta (DD/MM/AAAA): ");
        if (ValidarFormatoFecha(fecha))
        {
            break;
        }
        std::cout << "Error: Fecha invalida o formato incorrecto (DD/MM/AAAA).\n";
    }

    std::string hora = "";
    while (true)
    {
        hora = LeerTextoNoVacio("Hora de la consulta (HH:MM): ");
        if (ValidarFormatoHora(hora))
        {
            break;
        }
        std::cout << "Error: Hora invalida o formato incorrecto (HH:MM).\n";
    }

    MostrarDoctores(consultorio);

    int seleccion = 0;
    while (true)
    {
        std::cout << "Seleccione el numero de medico (1 - " << Consultorio::TOTAL_MEDICOS << "): ";
        if (std::cin >> seleccion)
        {
            if (seleccion >= 1 && seleccion <= Consultorio::TOTAL_MEDICOS)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "Error: Opcion fuera de rango.\n";
        }
        else
        {
            std::cout << "Error: Ingrese un numero valido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int pos_medico = seleccion - 1;

    if (consultorio.AgendarCita(paciente, pos_medico, fecha, hora))
    {
        std::cout << "\n========================================\n";
        std::cout << "      !CITA CONFIRMADA EXITOSAMENTE!    \n";
        std::cout << "========================================\n";
        const std::vector<Cita>& citas = consultorio.GetCitas();
        std::cout << citas.back().ResumenReserva() << "\n";
        std::cout << "========================================\n";
    }
    else
    {
        std::cout << "\n========================================\n";
        std::cout << "Error: El medico seleccionado NO esta disponible en esa fecha y hora.\n";
        std::cout << "========================================\n";
    }
}

/**
 * @brief Punto de entrada principal.
 * @return Estado de finalizacion del programa.
 */
int main()
{
    Consultorio consultorio("Vivir Sano");
    CargarMedicosIniciales(consultorio);

    int opcion = 0;
    do
    {
        std::cout << "\n========================================\n";
        std::cout << "    CONSULTORIO MEDICO \"VIVIR SANO\"     \n";
        std::cout << "========================================\n";
        std::cout << "1. Consultar doctores\n";
        std::cout << "2. Pedir cita\n";
        std::cout << "3. Salir\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Elija una opcion: ";

        if (std::cin >> opcion)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (opcion)
            {
            case 1:
                MostrarDoctores(consultorio);
                break;
            case 2:
                PedirCita(consultorio);
                break;
            case 3:
                std::cout << "\nGracias por usar el sistema del Consultorio Vivir Sano. !Hasta luego!\n";
                break;
            default:
                std::cout << "\nError: Opcion no valida. Por favor intente de nuevo.\n";
                break;
            }
        }
        else
        {
            std::cout << "\nError: Ingrese un numero valido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (opcion != 3);

    return 0;
}
