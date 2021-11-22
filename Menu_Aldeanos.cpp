// #include "../Menu/Menu_Aldeanos.h"
// #include "../Headers/mensajes.h"
#include <conio.h>
#include "Menu_Aldeanos.h"
#include "mensajes.h"

Menu_Aldeanos::Menu_Aldeanos(Civilizacion &c)
{
    cv = &c;
    items = {"Agregar", "Eliminar", "Clasificar", "Buscar", "Modificar", "Mostrar", "Regresar"};
}
size_t Menu_Aldeanos::selection()
{ 
    system("cls");
    printCabecera("ALDEANOS",20);
    print();
    cout << "\n\n\tOpcion: ";
    size_t op;
    cin >> op;

    system("cls");
    switch (op)
    {
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
        break;
    default:
        mnsj_error();
        break;
    }
    return op;
}

Aldeano pedir_datos()
{
    Aldeano a;
    string s;
    int i;

    cout << "\n\tNombre: "; cin.ignore();
    getline(cin, s);
    a.setNombre(s);

    cout << "\tGenero: ";
    getline(cin, s);
    a.setGenero(s);

    cout << "\tSalud:  ";
    cin >> i;
    a.setSalud(i);

    cout << "\tEdad:   ";
    cin >> i;
    a.setEdad(i);

    return a;
}

void process_1_1(Civilizacion *cv)
{
    Aldeano a = pedir_datos();
    cv->agregarInicio(a);
    mnsj_exito();
}
void process_1_2(Civilizacion *cv)
{
    Aldeano a = pedir_datos();
    cv->agregarFinal(a);
    mnsj_exito();
}
void Menu_Aldeanos::process_1()
{
    system("cls");
    printCabecera("AGREGAR",20);
    cout << "\n\t 1) Al inicio";
    cout << "\n\t 2) Al final";
    cout << "\n\n\t Opcion: ";
    size_t op;
    cin >> op;

    system("cls");
    printCabecera("AGREGAR",20);

    switch(op)
    {
    case 1:        
        process_1_1(cv);
        break;
    case 2:
        process_1_2(cv);
        break;
    default:
        mnsj_error();
        break;
    }
}

void process_2_1(Civilizacion *cv)
{
    cout << "\n\tNombre: "; cin.ignore();
    string n;
    getline(cin, n);

    cv->eliminarNombre(n);
    mnsj_exito();
}
void process_2_2(Civilizacion *cv)
{
    cout << "\n\tSalud: ";
    int s;
    cin >> s;

    cv->eliminarSalud(s);
    mnsj_exito();
}
void process_2_3(Civilizacion *cv)
{
    system("cls");
    cv->eliminarEdad();
    mnsj_exito();
}
void Menu_Aldeanos::process_2()
{
    if(cv->total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("ELIMINAR",20);
    cout << "\n\t 1) Por nombre";
    cout << "\n\t 2) Por salud";
    cout << "\n\t 3) Por edad";
    cout << "\n\n\t Opcion: ";
    size_t op;
    cin >> op;

    system("cls");
    printCabecera("ELIMINAR",20);
    switch (op)
    {
    case 1:
        process_2_1(cv);
        break;
    case 2:
        process_2_2(cv);
        break;
    case 3:
        process_2_3(cv);
        break;
    default:
        mnsj_error();
        break;
    }
}

void Menu_Aldeanos::process_3()
{
    if(cv->total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("CLASIFICAR",20);
    cout << "\n\t 1) Por nombre";
    cout << "\n\t 2) Por salud";
    cout << "\n\t 3) Por edad";
    cout << "\n\n\t Opcion: ";
    size_t op;
    cin >> op;

    system("cls");
    printCabecera("CLASIFICAR",45);
    switch (op)
    {
    case 1:
        cv->ordenarNombre();
        mnsj_exito();
        break;
    case 2:
        cv->ordenarSalud();
        mnsj_exito();
        break;
    case 3:
        cv->ordenarEdad();
        mnsj_exito();
        break;
    default:
        mnsj_error();
        break;
    }
}

void Menu_Aldeanos::process_4()
{
    if(cv->total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("BUSCAR",20);
    cout << "\n\tNombre: "; cin.ignore();
    string n;
    getline(cin, n);

    Aldeano *ptr = cv->buscarAldeano(n);
    if(ptr == nullptr){
        cout << "\n\n\tNo se encontro el elemento.";
        getch();
        return;
    }
    system("cls");
    printCabecera("ALDEANO", 30);
    ptr->print();
    getch();
}

void process_5_1(Aldeano *a)
{
    cout << "\n\tNombre: "; cin.ignore();
    string n;
    getline(cin, n);

    a->setNombre(n);
    mnsj_exito();
}
void process_5_2(Aldeano *a)
{
    cout << "\n\tSalud: ";
    int i;
    cin >> i;

    a->setSalud(i);
    mnsj_exito();
}
void process_5_3(Aldeano *a)
{
    cout << "\n\tEdad: ";
    int i;
    cin >> i;

    a->setEdad(i);
    mnsj_exito();
}
void Menu_Aldeanos::process_5()
{
    if(cv->total() == 0){
        mnsj_error();
        return;
    }
    printCabecera("MODIFICAR",20);
    cout << "\n\tNombre: "; cin.ignore();
    string n;
    getline(cin, n);

    Aldeano *ptr = cv->buscarAldeano(n);
    if(ptr == nullptr){
        cout << "\n\n\tNo se encontro el elemento.";
        getch();
        return;
    }
    ptr->print();

    system("cls");
    printCabecera("MODIFICAR",20);
    cout << "\n\t 1) Nombre";
    cout << "\n\t 2) Salud";
    cout << "\n\t 3) Edad";
    cout << "\n\n\t Opcion: ";
    size_t op;
    cin >> op;

    system("cls");
    printCabecera("MODIFICAR",20);
    switch (op)
    {
    case 1:
        process_5_1(ptr);
        break;
    case 2:
        process_5_2(ptr);
        break;
    case 3:
        process_5_3(ptr);
        break;
    default:
        mnsj_error();
        break;
    }
}

void Menu_Aldeanos::process_6()
{
    if(cv->total() == 0){
        mnsj_error();
        return;
    }
    cv->mostrarAldeanos();
    getch();
}