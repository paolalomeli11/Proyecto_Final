#include "Barco.h"
#include <iomanip>

Barco::Barco()
{
    velocidad = 0;
    combustible = 100;
    armadura = 100;
}
void Barco::setId(int v)
{
    id = v;
}   
void Barco::setCombustible(int v)
{
    combustible = v;
}
void Barco::setVelocidad(int v)
{
    velocidad = v;
}
void Barco::setArmadura(int v)
{
    armadura = v;
}
int Barco::getId()
{
    return id;
}
int Barco::getCombustible()
{
    return combustible;
}
int Barco::getVelocidad()
{
    return velocidad;
}
int Barco::getArmadura()
{
    return armadura;
}

void Barco::agregarGuerrero(const Guerrero &g)
{
    guerreros.push(g);
}
void Barco::eliminarGuerrero()
{
    guerreros.pop();
}
Guerrero Barco::tope()
{
    return guerreros.top();
}
size_t Barco::totalGuerreros()
{
    return guerreros.size();
}
void Barco::mostrarGuerreros()
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
    
    stack<Guerrero> copia = guerreros;

    while(!copia.empty())
    {
        cout << setw(15) << copia.top().getId();
        cout << setw(15) << copia.top().getSalud();
        cout << setw(15) << copia.top().getFuerza();
        cout << setw(15) << copia.top().getEscudo();
        cout << setw(15) << copia.top().getTipo() << "\n\t";

        copia.pop();
    }
}