#include <iostream>
#include <conio.h>

#include "mensajes.h"

using namespace std;

void mnsj_error()
{
    cout << "\n\n\tNo se puede realizar la accion.";
    cout << "\n\tPresione cualquier tecla para continuar...\n\n";
    getch();
}

void mnsj_exito()
{
    cout << "\n\n\tLa operacion fue un exito.";
    cout << "\n\tPresione cualquier tecla para continuar. . .\n\n";
    getch();
}

void mnsj_despedida()
{
    cout << "\n\tAdios. . . :)\n";
    getch();
}