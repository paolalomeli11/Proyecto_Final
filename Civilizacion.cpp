#include <iostream>
#include <iomanip>
#include "Civilizacion.h"

Civilizacion::Civilizacion()
{
    X = 0;
    Y = 0;
    puntuacion = 0;
}
Civilizacion::Civilizacion(const string &n, const int &uX, const int &uY, const int &pts)
{
    nombre = n;
    X = uX;
    Y = uY;
    puntuacion = pts;
}
void Civilizacion::setNombre(const string &n)
{
    nombre = n;
}
void Civilizacion::setX(const int &uX)
{
    X = uX;
}
void Civilizacion::setY(const int &uY)
{
    Y = uY;
}
void Civilizacion::setPuntuacion(const int &pts)
{
    puntuacion = pts;
}

void Civilizacion::print()
{
    cout << left << endl << "\t";
    cout << setw(20) << "Nombre:";
    cout << setw(20) << "Ubicacion en X:";
    cout << setw(20) << "Ubicacion en Y:";
    cout << setw(20) << "Puntuacion:\n";
    cout << setw(20) << nombre;
    cout << setw(20) << X;
    cout << setw(20) << Y;
    cout << setw(20) << puntuacion;
}

string Civilizacion::getNombre()
{
    return nombre;
}
int Civilizacion::getX()
{
    return X;
}
int Civilizacion::getY()
{
    return Y;
}
int Civilizacion::getPuntuacion()
{
    return puntuacion;
}