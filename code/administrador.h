#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"
class Administrador
{
    std::string contrasenaAdmin;


public:
    Administrador();
    std::string getContrasenaAdmin() const;

    void agregarDatos(std::string &original);
    bool verificarContrasena(const std::string& archivo, const std::string& contraseña);
    void menuUsuario(Usuario &usuario);
};

#endif // ADMINISTRADOR_H
