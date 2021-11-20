#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

// #include "../Menu/Menu_Principal.h"
// #include "../Menu/Menu_Aldeanos.h"
// #include "../Headers/mensajes.h"
#include "Menu_Principal.h"
#include "Menu_Aldeanos.h"
#include "mensajes.h"


using namespace std;

Menu_Principal::Menu_Principal(VideoGame &v)
{
    vg = v;
    items = {"Establecer username", "Agregar civilizacion", "Insertar", "Inicializar", "Primera civilizacion", "Ultima civilizacion","Ordenar", "Eliminar", "Buscar", "Modificar", "Resumen", "Salir"};
}

size_t Menu_Principal::selection()
{
    printCabecera("MENU",30);
    print();
    cout << "\n\n\tOpcion: ";

    size_t op;
    cin >> op;

    system("cls");
    switch(op){
    case 1:
        process_1();
        break;
    case 2:
        process_2();
        break;
    case 3:
        process_3();
        break;
    case 4:
        process_4();
        break;
    case 5:
        process_5();
        break;
    case 6:
        process_6();
        break;
    case 7:
        process_7();
        break;
    case 8:
        process_8();
        break;
    case 9:
        process_9();
        break;
    case 10:
        process_10();
        break;
    case 11:
        process_11();
        break;
    case 12:
        mnsj_despedida();
        break;
    default:
        mnsj_error();
        break;
    }
    return op;
}

Civilizacion Menu_Principal::pedirDatos()
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

void Menu_Principal::process_1()
{
    string u;
    cout << "\n\tNombre de usuario (nuevo): ";
    cin >> u;

    vg.setUsername(u);
    mnsj_exito();
}

void Menu_Principal::process_2()
{
    system("cls");
    printCabecera("AGREGAR",45);
    Civilizacion c = pedirDatos();
    vg.agregarCivilizacion(c);
    mnsj_exito();
}

void Menu_Principal::process_3()
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

void Menu_Principal::process_4()
{
    size_t n;
    
    printCabecera("INICIALIZAR",45);
    cout << "\n\tNumero de civilizaciones: ";
    cin >> n;

    Civilizacion c = pedirDatos();
    vg.inicializar(c, n);
    mnsj_exito();
}

void Menu_Principal::process_5()
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

void Menu_Principal::process_6()
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

void Menu_Principal::process_7()
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

void Menu_Principal::process_8()
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

void Menu_Principal::process_9()
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
    Civilizacion *ptr = vg.buscar(n);
    getch();
    system("cls");

    if(ptr == nullptr)
        return;

    Menu_Aldeanos m_a(*ptr);
    size_t op;
    do{
        op = m_a.selection();
    }while(op < 7);
}

void Menu_Principal::process_10()
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

void Menu_Principal::process_11()
{
    if(vg.total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("CIVILIZACIONES",75);
    vg.mostrar();
    getch();
}
 