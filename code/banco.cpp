#include <iostream>
#include <fstream>
#include <bitset>
#include "banco.h"

Banco::Banco() {}

void Banco::mostrarBienvenida() {
    std::cout << "******************************************" << std::endl;
    std::cout << "* Bienvenido al Banco UDEA               *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "Por favor, seleccione una opción:" << std::endl;
    std::cout << "1. Entrar como Administrador" << std::endl;
    std::cout << "2. Entrar como Usuario" << std::endl;
    //std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}
void Banco::iniciarSesion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(); // Limpiar el buffer de entrada

    if (opcion == 1) {
        menuAdministrador();
    } else if (opcion == 2) {
        std::string cedula, contrasena;
        std::cout << "Ingrese su cédula: ";
        std::getline(std::cin, cedula);
        std::cout << "Ingrese su contraseña: ";
        std::getline(std::cin, contrasena);
        /*
        Usuario* usuario = admin.buscarUsuario(cedula);
        if (usuario && usuario->getContrasena() == contrasena) {
            menuUsuario(*usuario);
        } else {
            std::cout << "Cédula o contraseña incorrecta." << std::endl;
        }*/
    } else {
        std::cout << "Opción no válida." << std::endl;
    }
    //std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}

void Banco::menuUsuario(Usuario &usuario) {
    int opcion;
    do {
        std::cout << "1. Consultar saldo" << std::endl;
        std::cout << "2. Retirar dinero" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            usuario.consultarSaldo();
            break;
        case 2: {
            double cantidad;
            std::cout << "Ingrese la cantidad a retirar: ";
            std::cin >> cantidad;
            usuario.retirarDinero(cantidad);
            break;
        }
        case 3:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
        }
    } while (opcion != 3);
    //std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}


void Banco::menuAdministrador() {
    int opcion;
    do {
        std::cout << "1. Crear usuario" << std::endl;
        std::cout << "2. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string cedula, contrasena;
            double saldo;
            std::cout << "Ingrese la cédula: ";
            std::getline(std::cin, cedula);
            std::cout << "Ingrese la contraseña: ";
            std::getline(std::cin, contrasena);
            std::cout << "Ingrese el saldo inicial: ";
            std::cin >> saldo;
            //admin.agregarDatos();
            break;
        }
        case 2:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
        }
    } while (opcion != 2);
    std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}

std::string Banco::codificacion1(std::string original,const int &n){
    std::string copiaOriginal;
    int bloques=original.size()/n,ceros,unos,aux1,aux0,cont;
    for (int i=0;i<bloques;i++){ceros=0;unos=0;cont=1;
        for (int j=i*n;j<(i+1)*n;j++){
            original[j]=='0'?ceros++:unos++;
            if(aux0==aux1||i==0){original[j]=='0'?copiaOriginal+='1':copiaOriginal+='0';}
            else if(aux0>aux1&&cont%2==0){original[j]=='0'?copiaOriginal+='1':copiaOriginal+='0';}
            else if(aux1>aux0&&cont%3==0){original[j]=='0'?copiaOriginal+='1':copiaOriginal+='0';}
            else{copiaOriginal+=original[j];}
            cont++;
        }
        aux0=ceros,aux1=unos;
    }
    return copiaOriginal;
}

std::string Banco::deCodificacion1(std::string copiaOriginal, const int &n){
    std::string original;
    int bloques=copiaOriginal.size()/n,ceros,unos,aux1,aux0,cont;
    for (int i=0;i<bloques;i++){ceros=0;unos=0;cont=1;
        for (int j=i*n;j<(i+1)*n;j++){
            if(i==0){copiaOriginal[j]=='0'?original+='1':original+='0';}
            else if(aux0==aux1){copiaOriginal[j]=='0'?original+='1':original+='0';}
            else if(aux0>aux1&&cont%2==0){copiaOriginal[j]=='0'?original+='1':original+='0';}
            else if(aux1>aux0&&cont%3==0){copiaOriginal[j]=='0'?original+='1':original+='0';}
            else{original+=copiaOriginal[j];}
            original[j]=='0'?ceros++:unos++;
            cont++;
        }
        aux0=ceros,aux1=unos;
    }
    return original;
}

std::string Banco::codificacion2(std::string original,const int& n){
    std::string copiaOriginal;
    copiaOriginal=original;
    int bloques=original.size()/n;
    for (int i=0;i<bloques;i++){
        for (int j=i*n;j<(i+1)*n;j++){
            (j==i*n&&j+1!=(i+1)*n)?copiaOriginal[j]=original[(i+1)*n-1]:copiaOriginal[j]=original[(j-1)];
        }
    }
    return copiaOriginal;
}

std::string Banco::deCodificacion2(std::string original, const int &n){
    std::string copiaOriginal;
    copiaOriginal=original;
    int bloques=original.size()/n;
    for (int i=0;i<bloques;i++){
        for (int j=i*n;j<(i+1)*n;j++){
            (j==i*n&&j+1!=(i+1)*n)?original[(i+1)*n-1]=copiaOriginal[j]:original[(j-1)]=copiaOriginal[j];
        }
    }
    return original;
}

std::string Banco::codificar(std::string original,const int& m, const int& n){
    std::string stringCifrado;
    if(m==2){stringCifrado=codificacion2(original,n);}
    if(m==1){stringCifrado=codificacion1(original,n);}
    return stringCifrado;
}

std::string Banco::deCodificar(std::string stringCodificado,const int& m,const int&n){
    std::string stringDecodificado;
    if(m==2){stringDecodificado=deCodificacion2(stringCodificado,n);}
    if(m==1){stringDecodificado=deCodificacion1(stringCodificado,n);}
    return stringDecodificado;
}

std::string Banco::deTextoABinario(std::string& texto){ //toma un string y devuelve su representacion en binario
    std::string stringBits;
    for (char caracter : texto) {
        std::bitset<8> bits(caracter);
        stringBits += bits.to_string();
    }
    return stringBits;
}

std::string Banco::deBinarioATexto(const std::string& binario) { //toma un string en binario y devuelve su representacion en texto
    std::string texto;
    char caracter = 0;
    int bitCount = 0;

    for (char bit : binario) {
        caracter = (caracter << 1) | (bit - '0'); // Desplazar el carácter y añadir el nuevo bit
        bitCount++;
        if (bitCount == 8) {
            texto += caracter; // Añadir el carácter al texto
            //std::cout<<"caracter Despues "<<caracter<<std::endl;
            caracter = 0; // Reiniciar el carácter
            bitCount = 0; // Reiniciar el contador de bits
        }
    }

    return texto;
}

void Banco::escribirArchivoBinario(const std::string& nombreArchivoTexto,const std::string& nombreArchivoBinario){ //abre un archivo de texto, lo decodifica y crea un archivo binario con su contenido
    // Abrir el archivo de texto en modo lectura
    std::ifstream archivo_texto(nombreArchivoTexto);
    if (!archivo_texto.is_open()) {std::cerr << "No se pudo abrir el archivo de texto." << std::endl;
        return;
    }

    // Crear el archivo binario en modo escritura
    std::ofstream archivo_binario(nombreArchivoBinario, std::ios::binary);
    if (!archivo_binario.is_open()) {std::cerr << "No se pudo crear el archivo binario." << std::endl;
        return;
    }

    // Leer el contenido del archivo de texto en un string
    std::string contenidoTexto;
    char caracter;
    while (archivo_texto.get(caracter)) {
        contenidoTexto += caracter;
    }
    archivo_texto.close();

    // Convertir el contenido del texto a binario
    std::string stringBits = deTextoABinario(contenidoTexto);

    //Escribir archivo
    if (archivo_binario.is_open()) {
        archivo_binario.write(stringBits.c_str(), stringBits.size());
    }

    // Cerrar los archivos
    archivo_texto.close();
    archivo_binario.close();

    std::cout << "El archivo de texto "<<nombreArchivoTexto<< " ha sido convertido a binario y se guardo en el archivo binario " <<nombreArchivoBinario<< std::endl;
    std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}

void Banco::escribirArchivoBinario(const std::string& nombreArchivoTexto,const std::string& nombreArchivoBinario,const int& m,const int& n){ //abre un archivo de texto, lo decodifica y crea un archivo binario con su contenido
    // Abrir el archivo de texto en modo lectura
    std::ifstream archivo_texto(nombreArchivoTexto);
    if (!archivo_texto.is_open()) {std::cerr << "No se pudo abrir el archivo de texto." << std::endl;
        return;
    }

    // Crear el archivo binario en modo escritura
    std::ofstream archivo_binario(nombreArchivoBinario, std::ios::binary);
    if (!archivo_binario.is_open()) {std::cerr << "No se pudo crear el archivo binario." << std::endl;
        return;
    }

    // Leer el contenido del archivo de texto en un string
    std::string contenidoTexto;
    char caracter;
    while (archivo_texto.get(caracter)) {
        contenidoTexto += caracter;
    }
    archivo_texto.close();

    // Convertir el contenido del texto a binario
    std::string stringBits = deTextoABinario(contenidoTexto);

    //decodificar contenido
    std::string stringBitsCodificado=deCodificar(stringBits,m,n); //el archivo ya esta codificado, se necesita decodificar

    //Escribir archivo
    if (archivo_binario.is_open()) {
        archivo_binario.write(stringBitsCodificado.c_str(), stringBitsCodificado.size());
    }

    // Cerrar los archivos
    archivo_texto.close();
    archivo_binario.close();

    std::cout << "El archivo de texto "<<nombreArchivoTexto<< " ha sido convertido a binario y se guardo en el archivo binario " <<nombreArchivoBinario<< std::endl;
    std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
}

std::string Banco::leerArchivoBinario(const std::string& nombreArchivo) { //toma un archivo binario y retorna su contenido en texto
    std::ifstream inFile(nombreArchivo, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return "";
    }

    std::string contenido;
    char caracter;
    while (inFile.get(caracter)) {
        contenido += caracter;
    }

    inFile.close();

    std::string contAux=deBinarioATexto(contenido);
    std::cout<<contAux<<std::endl;


    return contAux;
}

std::string Banco::leerArchivoBinario(const std::string& nombreArchivo,const int& m, const int& n) { //toma un archivo binario y retorna su contenido en texto
    std::ifstream inFile(nombreArchivo, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return "";
    }

    std::string contenido;
    char caracter;
    while (inFile.get(caracter)) {
        contenido += caracter;
    }

    inFile.close();

    //std::string aux=deCodificar(contenido,m);
    std::string contAux=deBinarioATexto(contenido);
    std::cout<<contAux<<std::endl;
    std::string contenidoCodificado=codificar(contenido,m,n);
    std::string texto = deBinarioATexto(contenidoCodificado);

    return texto;
}

void Banco::escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto) { //recibe un archivo binario y escribe su representacion en un archivo de texto
    // Leer el contenido del archivo binario
    std::string contenidoTexto = leerArchivoBinario(archivoBinario);

    // Abrir el archivo de texto en modo escritura
    std::ofstream archivo_texto(archivoTexto);
    if (!archivo_texto.is_open()) {
        std::cerr << "No se pudo crear el archivo de texto." << std::endl;
        return;
    }

    // Escribir el contenido en el archivo de texto
    archivo_texto << contenidoTexto;
    archivo_texto.close();

}

void Banco::escribirArchivoTexto(const std::string archivoBinario, const std::string archivoTexto,const int& m,const int& n) { //recibe un archivo binario y escribe su representacion en un archivo de texto
    // Leer el contenido del archivo binario
    std::string contenidoTexto = leerArchivoBinario(archivoBinario,n,m);

    // Abrir el archivo de texto en modo escritura
    std::ofstream archivo_texto(archivoTexto);
    if (!archivo_texto.is_open()) {
        std::cerr << "No se pudo crear el archivo de texto." << std::endl;
        return;
    }

    // Escribir el contenido en el archivo de texto
    archivo_texto << contenidoTexto;
    archivo_texto.close();

}
