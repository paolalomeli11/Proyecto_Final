#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <vector>
#include "Civilizacion.h"

using namespace std;

class VideoGame
{
private:
    string username;
    vector<Civilizacion> civilizaciones;
public:
    void agregarCivilizacion(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t p);
    void inicializar(const Civilizacion &c, size_t n);
    Civilizacion primeraC();
    Civilizacion ultimaC();
    void setUsername(string u);
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();
    void eliminar(const string &n);
    Civilizacion* buscar(const string &n);
    int total();
    void mostrar();
};

#endif //VIDEOGAME_H