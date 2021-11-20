#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>

using namespace std;

class Aldeano
{
private:
    string nombre;
    string genero;
    int salud;
    size_t edad;
public:
    Aldeano();
    void setNombre(string n);
    void setGenero(string g);
    void setSalud(int s);
    void setEdad(size_t e);
    void print();
    string getNombre() const;
    string getGenero();
    int getSalud() const;
    size_t getEdad() const;
};

#endif //ALDEANO_H