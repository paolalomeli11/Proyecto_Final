#ifndef BARCO_H
#define BARCO_H

#include <iostream>
#include <stack>
#include "Guerrero.h"

using namespace std;

class Barco{
private:
    int id;
    int combustible;
    int velocidad;
    int armadura;
    stack<Guerrero> guerreros;

public:
    Barco();
    void setId(int v);
    void setCombustible(int v);
    void setVelocidad(int v);
    void setArmadura(int v);
    int getId();
    int getCombustible();
    int getVelocidad();
    int getArmadura();

    void agregarGuerrero(const Guerrero &g);
    void eliminarGuerrero();
    Guerrero tope();
    size_t totalGuerreros();
    void mostrarGuerreros();
};

#endif //BARCO_H