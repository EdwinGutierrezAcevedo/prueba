#include <iostream>
#include <fstream>
#include <bitset>
#include "administrador.h"

Administrador::Administrador() {}

std::string Administrador::getContrasena() const
{
    return contrasena;
}



void Administrador::agregarDatos(std::string &original) {
    std::string cedula, contrasena, saldo;

    std::cout << "Ingrese su cédula: ";
    std::getline(std::cin, cedula);
    std::cout << "Ingrese su contraseña: ";
    std::getline(std::cin, contrasena);
    std::cout << "Ingrese su saldo: ";
    std::getline(std::cin, saldo);

    original += "\n" + cedula + "|" + contrasena + "|" + saldo;
}
