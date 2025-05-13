#include <iostream>
#include <fstream>
#include <bitset>
#include "usuario.h"

//Usuario::Usuario() {}

void Usuario::setCedula(const std::string &ced) {
    cedula = ced;
}

void Usuario::setContrasena(const std::string &cont) {
    contrasena = cont;
}

void Usuario::setSaldo(double sal) {
    saldo = sal;
}

std::string Usuario::getCedula() const {
    return cedula;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}

double Usuario::getSaldo() const {
    return saldo;
}

void Usuario::consultarSaldo() const {
    std::cout << "Saldo actual: " << saldo << std::endl;
}

void Usuario::retirarDinero(double cantidad) {
    if (cantidad <= saldo) {
        saldo -= cantidad;
        std::cout << "Retiro exitoso. Saldo restante: " << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente." << std::endl;
    }
}

std::string Usuario::toString() const {
    return cedula + "|" + contrasena + "|" + std::to_string(saldo);
}
