#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{

private:
    std::string cedula;
    std::string contrasena;
    double saldo;

public:
    Usuario() : saldo(0.0) {}
    void setCedula(const std::string &ced);
    void setContrasena(const std::string &cont);
    void setSaldo(double sal);
    std::string getCedula() const;
    std::string getContrasena() const;
    double getSaldo() const;
    void consultarSaldo() const;
    void retirarDinero(double cantidad);
    std::string toString() const;
    //void fromString(const std::string &data);
};

#endif // USUARIO_H
