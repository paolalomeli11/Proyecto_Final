#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
// #include "../Headers/VideoGame.h"
// #include "../Headers/mensajes.h"
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
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
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

void VideoGame::respaldar()
{
    bool exito = true;

    ofstream archivo("Civilizaciones.txt");
    if(!archivo.is_open()){
        mnsj_error_desconocido();
        return;
    }

    for (auto it=civilizaciones.begin(); it < civilizaciones.end(); it++)
    {
        Civilizacion &civilizacion = *it;
        archivo << civilizacion.getNombre() << endl;
        archivo << civilizacion.getX() << endl;
        archivo << civilizacion.getY() << endl;
        archivo << civilizacion.getPuntuacion() << endl;

        exito = it->respaldar();
    }
    archivo.close();
    if(exito)
        mnsj_exito();
    else
        mnsj_error_desconocido();
}
void VideoGame::recuperar()
{
    ifstream archivo("Civilizaciones.txt");

    if(!archivo.is_open()){
        mnsj_error_desconocido();
        return;
    }

    civilizaciones.clear();
    Civilizacion civ;
    string s;
    int i;

    while(true)
    {
        getline(archivo, s);
        if(archivo.eof())
            break;
        civ.setNombre(s);

        getline(archivo, s);
        i = stoi(s);
        civ.setX(i);

        getline(archivo, s);
        i = stoi(s);
        civ.setY(i);

        getline(archivo, s);
        i = stoi(s);
        civ.setPuntuacion(i);

        agregarCivilizacion(civ);
    }
    archivo.close();

    for (auto it=civilizaciones.begin(); it!=civilizaciones.end(); it++)
    {
        it->recuperar();
    }
    mnsj_exito();
}
