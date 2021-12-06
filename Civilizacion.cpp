#include <iostream>
#include <iomanip>
#include <iterator>
#include <fstream>

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
    puntuacion = puntuacion +100;
}
void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
    puntuacion = puntuacion +100;
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            puntuacion = puntuacion -100;
            break;
        }
    }
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){return a.getEdad() >= 60;});
    puntuacion = puntuacion -100;
}
void Civilizacion::eliminarSalud(const int &salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
    puntuacion = puntuacion -100;
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

bool Civilizacion::respaldar()
{
    ofstream archivo(nombre + ".txt");

    bool exito = false;

    if(archivo.is_open()){  
      for(auto it=aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano &aldeano = *it;
            archivo << aldeano.getNombre() << endl;
            archivo << aldeano.getGenero() << endl;
            archivo << aldeano.getSalud() << endl;
            archivo << aldeano.getEdad() << endl;
        }
        exito = true;  
    }
    archivo.close();
    return exito;
}
bool Civilizacion::recuperar()
{   
    ifstream archivo(nombre + ".txt");
    bool exito = true;

    Aldeano ald;
    string s;
    int i;
    if(archivo.is_open()){
        while(true)
        {
            getline(archivo, s);
            if(archivo.eof())
                break;
            ald.setNombre(s);

            getline(archivo, s);
            ald.setGenero(s);

            getline(archivo, s);
            i = stoi(s);
            ald.setSalud(i);

            getline(archivo, s);
            i = stoi(s);
            ald.setEdad(i);

            agregarFinal(ald);
        }
        archivo.close();
    }
    else
        exito = false;
    return exito;
}

void Civilizacion::agregarBarco(Barco *&b)
{
    barcos.push_back(b);
}
void Civilizacion::mostrarBarcos()
{
    cout << left << endl << "\t";
    cout << setw(15) << "ID";
    cout << setw(15) << "COMBUSTIBLE";
    cout << setw(15) << "VELOCIDAD";
    cout << setw(15) << "ARMADURA";
    cout << left << endl << "\t";
    for(size_t i=0; i<60; i++){
        printf("%c",205);
    }
    cout << left << "\n\t";
    for(auto it = barcos.begin() ; it != barcos.end(); ++it){
        cout << setw(15) << (*it)->getId();
        cout << setw(15) << (*it)->getCombustible();
        cout << setw(15) << (*it)->getVelocidad();
        cout << setw(15) << (*it)->getArmadura() << "\n\t";
    }
}
Barco& Civilizacion::buscarBarco(int i)
{
    Barco *n;

    for(auto it = barcos.begin() ; it != barcos.end(); ++it){
        if((*it)->getId() == i){
            n = &(*(*it));
        }
    }
    return *n;
}
bool Civilizacion::barcoEncontrado(int i)
{
    bool found = false;

    for(auto it = barcos.begin() ; it != barcos.end(); ++it){
        if((*it)->getId() == i){
            found = true;
        }
    }
    return found;
}
void Civilizacion::eliminarBarcoId(int i)
{
    for(auto it = barcos.begin(); it != barcos.end(); it++){
        Barco *&b = *it;

        if(i == b->getId()){
            barcos.erase(it);
            cout << "\n\n\tOperacion exitosa.\n\n\t";
            system("pause");
            break;
        }
    }
}
void Civilizacion::eliminarBarcoCombustible(const int &i)
{
    barcos.remove_if([i](Barco*& b){return b->getCombustible() < i;});
}
size_t Civilizacion::totalBarcos()
{
    return barcos.size();
}