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
    banco.escribirArchivoBinario("archivotexto.txt", "archivobinario.bin");
    banco.mostrarBienvenida();
    banco.iniciarSesion();
    banco.escribirArchivoTexto("archivobinario.bin","archivotexto.txt");
    return 0;

}
