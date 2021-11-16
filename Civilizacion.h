#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>

using namespace std;

class Civilizacion
{
private:
    string nombre;
    int X;
    int Y;
    int puntuacion;

public:
    Civilizacion();
    Civilizacion(const string &n, const int &uX, const int &uY, const int &pts);
    void setNombre(const string &n);
    void setX(const int &uX);
    void setY(const int &uY);
    void setPuntuacion(const int &pts);
    void print();
    string getNombre();
    int getX();
    int getY();
    int getPuntuacion();
};

#endif //CIVILIZACION_H