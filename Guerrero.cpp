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
    cout << left << endl << "\t";
    cout << setw(15) << "ID";
    cout << setw(15) << "SALUD";
    cout << setw(15) << "FUERZA";
    cout << setw(15) << "ESCUDO";
    cout << setw(15) << "TIPO";
    cout << left << endl << "\t";
    for(size_t i=0; i<75; i++){
        printf("%c",205);
    }
    cout << left << "\n\t";

    cout << setw(15) << id;
    cout << setw(15) << salud;
    cout << setw(15) << fuerza;
    cout << setw(15) << escudo;
    cout << setw(15) << tipo << "\n\t";

}