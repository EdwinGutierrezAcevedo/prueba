#include <iostream>
#include <fstream>
#include <bitset>
#include "administrador.h"

Administrador::Administrador() {}

std::string Administrador::getContrasenaAdmin() const
{
    return contrasenaAdmin;
}



void Administrador::agregarDatos(std::string &original) {
    std::string cedula, contrasena, saldo;

    std::cout << "Ingrese su cedula: "<<std::endl;
    std::cin>>cedula;
    std::cout << "Ingrese su contrasena: "<<std::endl;
    std::cin>>contrasena;
    std::cout << "Ingrese su saldo: "<<std::endl;
    std::cin>>saldo;
    original += cedula + "|" + contrasena + "|" + saldo + "\n";
    std::cout<<"Usuario creado"<<std::endl;
}


bool Administrador::verificarContrasena(const std::string& archivo, const std::string& contraseña) {
    std::ifstream file(archivo);
    if (!file) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return false;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        if (linea == contraseña) {
            return true;
        }
    }

    return false;
}


void Administrador::menuUsuario(Usuario &usuario) {
    int opcion;
    do {
        std::cout << "\n----- MENU USUARIO -----\n";
        std::cout << "1. Consultar saldo\n";
        std::cout << "2. Retirar dinero\n";
        std::cout << "3. Salir\n";
        std::cout << "Recuerde que cada consulta o retiro de dinero tiene un costo de 1000 COP\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            // Se consulta el saldo y se verifica que sea suficiente para pagar la comisión.
            unsigned int saldoActual = usuario.getSaldo();
            if (saldoActual >= 1000) {
                usuario.setSaldo(saldoActual - 1000);
                std::cout << "Consulta exitosa. Su saldo es ahora: "
                          << usuario.getSaldo() << " COP\n";
            } else {
                std::cout << "No tiene suficiente saldo para realizar esta consulta\n";
            }
            break;
        }
        case 2: {
            // Se verifica que haya suficiente saldo para cubrir la comisión y luego se solicita la cantidad a retirar.
            unsigned int saldoActual = usuario.getSaldo();
            if (saldoActual >= 1000) {
                unsigned int cantidad;
                std::cout << "Ingrese la cantidad a retirar: ";
                std::cin >> cantidad;
                usuario.retirarDinero(cantidad);
            } else {
                std::cout << "No tiene suficiente saldo para retirar dinero\n";
            }
            break;
        }
        case 3:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);
}


