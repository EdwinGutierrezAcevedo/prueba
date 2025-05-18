#include <iostream>
#include <sstream>
#include <stdexcept>
#include "usuario.h"

// Constructor: inicializa el saldo en 0.
Usuario::Usuario() : saldo(0) {}

// Setters
void Usuario::setCedula(const std::string &ced) {
    cedula = ced;
}

void Usuario::setContrasena(const std::string &cont) {
    contrasena = cont;
}

void Usuario::setSaldo(unsigned int sal) {
    saldo = sal;
}

// Getters
std::string Usuario::getCedula() const {
    return cedula;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}

unsigned int Usuario::getSaldo() const {
    return saldo;
}

// Función para retirar dinero.
// Verifica que el saldo sea suficiente para cubrir el monto a retirar más la comisión de 1000 COP.
void Usuario::retirarDinero(unsigned int cantidad) {
    unsigned int saldoActual = getSaldo();
    if ((cantidad + 1000) <= saldoActual) {
        // Se actualiza el saldo descontando la cantidad y la comisión.
        setSaldo(saldoActual - (cantidad + 1000));
        std::cout << "Retiro exitoso." << std::endl;
    } else {
        std::cout << "Saldo insuficiente." << std::endl;
    }
}

// Función para obtener el saldo a partir de una cadena que representa el contenido del archivo,
// en el formato "cedula|contrasena|saldo". Si encuentra las credenciales correctas, actualiza los atributos
// del objeto (cedula, contrasena y saldo) y retorna el saldo en forma de cadena; en caso contrario, retorna cadena vacía.
std::string Usuario::obtenerSaldo(const std::string &datos,
                                  const std::string &contrasenaInput,
                                  const std::string &cedulaInput) {
    std::istringstream iss(datos);
    std::string linea;
    while (std::getline(iss, linea)) {
        if (linea.empty())
            continue;

        std::istringstream lineaStream(linea);
        std::string cedula_archivo, contrasena_archivo, saldo_archivo;

        // Extraemos los datos separados por '|' en la línea.
        if (std::getline(lineaStream, cedula_archivo, '|') &&
            std::getline(lineaStream, contrasena_archivo, '|') &&
            std::getline(lineaStream, saldo_archivo))
        {
            // Se verifica que la cédula y la contraseña coincidan.
            if (cedula_archivo == cedulaInput && contrasena_archivo == contrasenaInput) {
                try {
                    unsigned int saldoLeido = std::stoul(saldo_archivo);

                    // Actualizamos los atributos del objeto.
                    setCedula(cedula_archivo);
                    setContrasena(contrasena_archivo);
                    setSaldo(saldoLeido);

                    // Se devuelve el saldo en formato de cadena.
                    return saldo_archivo;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error al convertir el saldo: " << e.what() << std::endl;
                    return "";
                } catch (const std::out_of_range &e) {
                    std::cerr << "Saldo fuera de rango: " << e.what() << std::endl;
                    return "";
                }
            }
        }
    }
    // Si no se encontró al usuario o las credenciales no coinciden, se retorna cadena vacía.
    return "";
}

