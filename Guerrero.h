#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>

using namespace std;

class Guerrero{
private:
    int id;
    int salud;
    int fuerza;
    int escudo;
    string tipo;
public:
    Guerrero();
    void setId(int v);
    void setSalud(int v);
    void setFuerza(int v);
    void setEscudo(int v);
    void setTipo(string v);
    int getId();
    int getSalud();
    int getFuerza();
    int getEscudo();
    string getTipo();
    void print();
};

#endif //GUERRERO_H