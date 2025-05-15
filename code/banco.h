#ifndef BANCO_H
#define BANCO_H
#include "administrador.h"

class Banco
{
    Administrador admin;
    std::string codificacion1(std::string original, const int &n);
    std::string deCodificacion1(std::string copiaOriginal,const int& n);
    std::string codificacion2(std::string original, const int &n);
    std::string deCodificacion2(std::string original,const int& n);

public:
    Banco();
    void mostrarBienvenida();
    void iniciarSesion();
    void menuUsuario(Usuario &usuario);
    void menuAdministrador();
    std::string codificar(std::string original, const int &m, const int &n);
    std::string deCodificar(std::string stringCodificado, const int &m, const int &n);
    void escribirArchivoBinario(const std::string& nombreArchivoTexto, const std::string& nombreArchivoBinario);
    void escribirArchivoBinario(const std::string& nombreArchivoTexto, const std::string& nombreArchivoBinario, const int& m, const int &n);
    std::string getContrasena() const;
    std::string leerArchivoBinario(const std::string& nombreArchivo, const int &m, const int &n);
    std::string leerArchivoBinario(const std::string& nombreArchivo);
    void escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto, const int &m, const int &n);
    void escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto);
    std::string deBinarioATexto(const std::string& contenidoBinario);
    std::string deTextoABinario(std::string &texto);
};

#endif // BANCO_H

