#include <iostream>
#include <iomanip>
#include <iterator>
// #include "../Headers/Civilizacion.h"
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

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}
void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){return a.getEdad() >= 60;});
}
void Civilizacion::eliminarSalud(const int &salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2)
    {return a1.getNombre() < a2.getNombre();});
}
void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2)
    {return a1.getEdad() > a2.getEdad();});
}
void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2)
    {return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::mostrarAldeanos()
{
    cout << left << endl << "\t";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "GENERO";
    cout << setw(15) << "EDAD";
    cout << setw(15) << "SALUD";
    cout << left << endl << "\t";
    for(size_t i=0; i<50; i++){
        printf("%c",205);
    }
    cout << left << "\n\t";
    for(auto it = aldeanos.begin() ; it != aldeanos.end(); ++it){
        cout << setw(15) << it->getNombre();
        cout << setw(15) << it->getGenero();
        cout << setw(15) << it->getEdad();
        cout << setw(15) << it->getSalud() << "\n\t";
    }
}

Aldeano* Civilizacion::buscarAldeano(const string &n)
{
    Aldeano *i = nullptr;

    for(auto it = aldeanos.begin() ; it != aldeanos.end(); ++it){
        if(it->getNombre() == n)
            i = &(*it);
    }
    return i;
}
size_t Civilizacion::total(){
    return aldeanos.size();
}