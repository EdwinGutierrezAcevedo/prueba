#ifndef BANCO_H
#define BANCO_H
#include "administrador.h"
#include "usuario.h"

class Banco
{
    Administrador admin;
    Usuario usuario;
    std::string codificacion1(std::string original, const int &n);
    std::string deCodificacion1(std::string copiaOriginal,const int& n);
    std::string codificacion2(std::string original, const int &n);
    std::string deCodificacion2(std::string original,const int& n);

public:
    Banco();
    void mostrarBienvenida();
    void actualizarSaldoEnTexto(std::string &texto, const Usuario &usuario);
    std::string iniciarSesion(std::string texto, const int &m, const int &n);
    //void menuUsuario(Usuario &usuario);
    void menuAdministrador(std::string &texto);
    std::string codificar(std::string original, const int &m, const int &n);
    std::string deCodificar(std::string stringCodificado, const int &m, const int &n);
    void escribirArchivoBinario(const std::string& nombreArchivoTexto, const std::string& nombreArchivoBinario);
    void escribirArchivoBinario(const std::string& nombreArchivoTexto, const std::string& nombreArchivoBinario, const int& m, const int &n);
    std::string getContrasena() const;
    std::string leerArchivoBinario(const std::string& nombreArchivo, const int &m, const int &n);//toma un archivo binario codificado y retorna su contenido en texto
    std::string leerArchivoBinario(const std::string& nombreArchivo); //toma un archivo binario sin codificar y retorna su contenido en texto
    void escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto, const int &m, const int &n);
    void escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto);
    std::string deBinarioATexto(const std::string& contenidoBinario);
    void rescribirArchivoBinario(std::string contenido, const std::string& nombreArchivoBinario);
    void rescribirArchivoBinario( std::string contenido,const std::string& nombreArchivoBinario,const int& m, const int& n);
    std::string deTextoABinario(std::string &texto);
};

#endif // BANCO_H

