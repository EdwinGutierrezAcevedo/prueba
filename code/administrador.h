#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"
class Administrador
{
    std::string contrasena;

    Usuario usuario;


public:
    Administrador();
    std::string getContrasena() const;

    void agregarDatos(std::string &original);
};

#endif // ADMINISTRADOR_H

