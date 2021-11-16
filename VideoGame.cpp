#include <iostream>
#include <algorithm>
#include <iomanip>
#include "VideoGame.h"
#include "mensajes.h"

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}
void VideoGame::insertar(const Civilizacion &c, size_t p)
{
    civilizaciones.insert(civilizaciones.begin()+p, c);
}
void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

Civilizacion VideoGame::primeraC()
{
    Civilizacion fC = civilizaciones.front();
    return fC;
}
Civilizacion VideoGame::ultimaC()
{
    Civilizacion bC = civilizaciones.back();
    return bC;
}

void VideoGame::setUsername(string u)
{
    username = u;
}

void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}
void VideoGame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}
void VideoGame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getY() < c2.getY();});
}
void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}

void VideoGame::eliminar(const string &n)
{
    vector<Civilizacion>::iterator i = civilizaciones.end();

    for(auto it = civilizaciones.begin() ; it != civilizaciones.end(); ++it){
        if(it->getNombre() == n)
            i = it;
    }
    if(i == civilizaciones.end()){
        mnsj_error();
        return;
    }
    civilizaciones.erase(i);
    mnsj_exito();
}

Civilizacion* VideoGame::buscar(const string &n)
{
    Civilizacion *i = nullptr;

    for(auto it = civilizaciones.begin() ; it != civilizaciones.end(); ++it){
        if(it->getNombre() == n)
            i = &(*it);
    }
    if(i == nullptr)
        cout << "\n\tNo se encontro la civilizacion.";
    else
        i->print();
    
    return i;
}

int VideoGame::total()
{
    return civilizaciones.size();
}

void VideoGame::mostrar()
{
    cout << left << endl << "\t";
    cout << setw(20) << "Nombre:";
    cout << setw(20) << "Ubicacion en X:";
    cout << setw(20) << "Ubicacion en Y:";
    cout << setw(20) << "Puntuacion:\n";
    cout << left << "\n\t";

    for(size_t i = 0; i < civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << setw(20) << civilizaciones[i].getNombre();
        cout << setw(20) << civilizaciones[i].getX();
        cout << setw(20) << civilizaciones[i].getY();
        cout << setw(20) << civilizaciones[i].getPuntuacion() << "\n\t";
    }
}