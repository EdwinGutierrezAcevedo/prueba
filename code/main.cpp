#include <iostream>
#include <fstream>
#include <bitset>
#include "banco.h"

int main() {
    Banco banco;
    int n,m;
    std::cout<<"Ingrese el modo de codidficado: "<<std::endl;
    std::cin>>m;
    std::cout<<"Introduzca la semilla: "<<std::endl;
    std::cin>>n;
    std::string texto;
    std::string textoUser;
    //banco.escribirArchivoBinario("sudo.txt", "sudo_binario.bin",m,n); //toma un txt normal y crea un binario codificado
    texto=banco.leerArchivoBinario("archivo_binario_usuario.bin",m,n); //toma un binario, lo codifica y retorna un texto
    //banco.escribirArchivoBinario("archivo_usuario.txt", "archivo_binario_usuario.bin",m,n); //toma un txt normal y crea un binario codificado
    textoUser=banco.leerArchivoBinario("sudo_binario.bin",m,n); //toma un binario, lo codifica y retorna un texto
    texto=banco.iniciarSesion(texto,textoUser,m,n);

    banco.rescribirArchivoBinario(texto,"archivo_binario_usuario.bin",m,n);//toma un texto normal y lo codifica a binario
    return 0;
}
