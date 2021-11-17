#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <iomanip>

#include "VideoGame.h"
#include "mensajes.h"

using namespace std;

class Menu
{
public:
    void print();
    void printCabecera(const string &c, size_t w);
    Civilizacion pedirDatos();
    void op1(VideoGame &vg);
    void op2(VideoGame &vg);
    void op3(VideoGame &vg);
    void op4(VideoGame &vg);
    void op5(VideoGame &vg);
    void op6(VideoGame &vg);
    void op7(VideoGame &vg);
    void op8(VideoGame &vg);
    void op9(VideoGame &vg);
    void op10(VideoGame &vg);
    void op11(VideoGame &vg);
};

void Menu::print()
{
    printCabecera("MENU",30);
    cout << "\n\n\t 1) Establecer username";
    cout << "\n\t 2) Agregar civilizacion";
    cout << "\n\t 3) Insertar";
    cout << "\n\t 4) Inicializar";
    cout << "\n\t 5) Primera civilizacion";
    cout << "\n\t 6) Ultima civilizacion";
    cout << "\n\t 7) Ordenar";
    cout << "\n\t 8) Eliminar";
    cout << "\n\t 9) Buscar";
    cout << "\n\t10) Modificar";
    cout << "\n\t11) Resumen";
    cout << "\n\t12) Salir";
    cout << "\n\n\tOpcion: ";
}

void Menu::printCabecera(const string &c, size_t w)
{
    cout << "\n\t";
    for(size_t i=0; i < w; i++){
        printf("%c",205);
    }
    cout << "\n\t" << c << "\n\t";
    for(size_t i=0; i < w; i++){
        printf("%c",205);
    }
}

Civilizacion Menu::pedirDatos()
{
    Civilizacion c;
    string nombre;
    int x, y, puntuacion;

    fflush(stdin);
    cout << "\n\tNombre: ";
    getline(cin, nombre);

    cout << "\tUbicacion en X: ";
    cin >> x;

    cout << "\tUbicacion en Y: ";
    cin >> y;

    cout << "\tPuntuacion: ";
    cin >> puntuacion;
    
    c.setNombre(nombre);
    c.setX(x);
    c.setY(y);
    c.setPuntuacion(puntuacion);

    return c;
}

void Menu::op1(VideoGame &vg)
{
    string u;
    cout << "\n\tNombre de usuario (nuevo): ";
    cin >> u;

    vg.setUsername(u);
    mnsj_exito();
}

void Menu::op2(VideoGame &vg)
{
    system("cls");
    printCabecera("AGREGAR",45);
    Civilizacion c = pedirDatos();
    vg.agregarCivilizacion(c);
    mnsj_exito();
}

void Menu::op3(VideoGame &vg)
{
    size_t p;

    printCabecera("INSERTAR",45);
    cout << "\n\tPosicion a insertar: ";
    cin >> p;

    if(p < vg.total()){
       Civilizacion c = pedirDatos();
        vg.insertar(c, p);
        mnsj_exito();
    }
    else{
        mnsj_error();
    } 
}

void Menu::op4(VideoGame &vg)
{
    size_t n;
    
    printCabecera("INICIALIZAR",45);
    cout << "\n\tNumero de civilizaciones: ";
    cin >> n;

    Civilizacion c = pedirDatos();
    vg.inicializar(c, n);
    mnsj_exito();
}

void Menu::op5(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }

    printCabecera("Primera civilizacion", 75);

    Civilizacion c = vg.primeraC();
    c.print();
    getch();
}

void Menu::op6(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }

    printCabecera("Ultima civilizacion", 75);

    Civilizacion c = vg.ultimaC();
    c.print();
    getch();
}

void Menu::op7(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }
    size_t op;

    printCabecera("ORDENAR", 30);
    cout << "\n\n\t1) Por nombre";
    cout << "\n\t2) Por ubicacion en X";
    cout << "\n\t3) Por ubicacion en Y";
    cout << "\n\t4) Por puntuacion";
    cout << "\n\n\tOpcion: ";
    cin >> op;

    switch (op)
    {
    case 1:
        vg.ordenarNombre();
        mnsj_exito();
        break;
    case 2:
        vg.ordenarX();
        mnsj_exito();
        break;
    case 3:
        vg.ordenarY();
        mnsj_exito();
        break;
    case 4:
        vg.ordenarPuntuacion();
        mnsj_exito();
        break;
    default:
        mnsj_error();
        break;
    }
}

void Menu::op8(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }
    string n;
    printCabecera("ELIMINAR", 45);
    cout << "\n\tNombre de la civilizacion: "; cin.ignore();
    getline(cin, n);

    vg.eliminar(n);
}

void Menu::op9(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }
    string n;
    printCabecera("BUSCAR",45);
    cout << "\n\tNombre de la civilizacion: "; cin.ignore();
    getline(cin, n);

    system("cls");
    printCabecera("RESULTADO DE LA BUSQUEDA",75);
    vg.buscar(n);
    getch();
}

void Menu::op10(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }

    printCabecera("MODIFICAR",75);
    cout << "\n\n\tNombre de la civilizacion: "; cin.ignore();
    string n;
    getline(cin, n);

    cout << endl << endl;
    printCabecera("RESULTADO",75);
    Civilizacion *ptr = vg.buscar(n);
    if(ptr == nullptr){
        getch();
        return;
    }
    getch();
    system("cls");
    size_t op;

    printCabecera("MODIFICAR",25);
    cout << "\n\n\t1) Nombre";
    cout << "\n\t2) Ubicacion";
    cout << "\n\t3) Puntuacion";
    cout << "\n\t4) Regresar";
    cout << "\n\n\tOpcion: ";
    cin >> op;

    system("cls");
    printCabecera("INFORMACION ACTUAL", 75);
    ptr->print();

    cout << endl << endl << endl;
    printCabecera("INFORMACION NUEVA", 75);

    string s;
    int i;
    switch (op)
    {
    case 1:
        cout << "\n\tNombre: "; cin.ignore();
        getline(cin, s);
        ptr->setNombre(s);
        break;
    case 2:
        cout << "\n\tUbicacion en X: ";
        cin >> i;
        ptr->setX(i);

        cout << "\n\tUbicacion en Y: ";
        cin >> i;
        ptr->setY(i);
        break;
    case 3:
        cout << "\n\tPuntuacion: ";
        cin >> i;
        ptr->setPuntuacion(i);
        break;
    case 4:
        return;
        break;
    default:
        mnsj_error();
        return;
        break;
    }
    mnsj_exito();
}

void Menu::op11(VideoGame &vg)
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("CIVILIZACIONES",75);
    vg.mostrar();
    getch();
}
 

#endif // MENU_H