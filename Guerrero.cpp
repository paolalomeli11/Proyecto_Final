#include "Guerrero.h"
#include <iomanip>

Guerrero::Guerrero()
{

}
void Guerrero::setId(int v)
{
    id = v;
}
void Guerrero::setSalud(int v)
{
    salud = v;
}
void Guerrero::setFuerza(int v)
{
    fuerza = v;
}
void Guerrero::setEscudo(int v)
{
    escudo = v;
}
void Guerrero::setTipo(string v)
{
    tipo = v;
}
int Guerrero::getId()
{
    return id;
}
int Guerrero::getSalud()
{
    return salud;
}
int Guerrero::getFuerza()
{
    return fuerza;
}
int Guerrero::getEscudo()
{
    return escudo;
}
string Guerrero::getTipo()
{
    return tipo;
}
void Guerrero::print()
{
    cout << right << setw(7) << "\n\tID:\t" << id << endl;
    cout << right << setw(7) << "\tSALUD:\t" << salud << endl;
    cout << right << setw(7) << "\tFUERZA:\t" << fuerza << endl;
    cout << right << setw(7) << "\tESCUDO:\t" << escudo << endl;
    cout << right << setw(7) << "\tTIPO:\t" << tipo << endl;
}