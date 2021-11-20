//#include "../Headers/Aldeano.h"
#include "Aldeano.h"
#include <iomanip>

Aldeano::Aldeano()
{
    salud = 0;
    edad = 0;
}

void Aldeano::setNombre(string n)
{
    nombre = n;
}
void Aldeano::setGenero(string g)
{
    genero = g;
}
void Aldeano::setSalud(int s)
{
    salud = s;
}
void Aldeano::setEdad(size_t e)
{
    edad = e;
}
void Aldeano::print()
{
    cout << right << setw(7) << "Nombre:\t" << nombre;
    cout << right << setw(7) << "Genero:\t" << genero;
    cout << right << setw(7) << "Salud:\t" << salud;
    cout << right << setw(7) << "Edad:\t" << edad;
}
string Aldeano::getNombre() const
{
    return nombre;
}
string Aldeano::getGenero()
{
    return genero;
}
int Aldeano::getSalud() const
{
    return salud;
}
size_t Aldeano::getEdad() const
{
    return edad;
}
