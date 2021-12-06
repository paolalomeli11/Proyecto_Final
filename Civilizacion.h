#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <list>
#include "Aldeano.h"
#include "Barco.h"

using namespace std;

class Civilizacion
{
private:
    string nombre;
    int X;
    int Y;
    int puntuacion;
    list<Aldeano> aldeanos;
    list<Barco*> barcos;

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
    
    //ADICION ALDEANOS
    void agregarInicio(const Aldeano &a);
    void agregarFinal(const Aldeano &a);
    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(const int &salud);
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    void mostrarAldeanos();
    Aldeano* buscarAldeano(const string &n);
    size_t total();

    //ADICION DE LECTURA/ESCRITURA DE ARCHIVOS TXT
    bool respaldar();
    bool recuperar();

    //ADICION DE BARCOS Y GUERREROS
    void agregarBarco(Barco *&b);
    void mostrarBarcos();
    Barco*& buscarBarco(int i);
    void eliminarBarcoId(int i);
    void eliminarBarcoCombustible(const int &i);
    size_t totalBarcos();
};

#endif //CIVILIZACION_H