#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string cedula;
    std::string contrasena;
    unsigned int saldo;  // Al usar unsigned int, nos aseguramos de que el saldo siempre sea positivo.
public:
    // Constructor: inicializa el saldo en 0.
    Usuario();

    // Setters
    void setCedula(const std::string &ced);
    void setContrasena(const std::string &cont);
    void setSaldo(unsigned int sal);

    // Getters
    std::string getCedula() const;
    std::string getContrasena() const;
    unsigned int getSaldo() const;

    // Función para retirar dinero, la cual verifica que el saldo sea suficiente para
    // cubrir la cantidad solicitada más una comisión fija de 1000 COP.
    void retirarDinero(unsigned int cantidad);

    // Función que, dada una cadena de datos en el formato "cedula|contrasena|saldo",
    // busca por cédula y contraseña y, si encuentra el usuario, actualiza los atributos
    // internos (cedula, contraseña y saldo) y retorna el saldo en forma de string.
    // Si no se encuentra al usuario o las credenciales no coinciden, retorna una cadena vacía.
    std::string obtenerSaldo(const std::string &datos,
                             const std::string &contrasena,
                             const std::string &cedula);
};

#endif // USUARIO_H

