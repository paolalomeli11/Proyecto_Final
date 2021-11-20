#include <iostream>
#include <conio.h>
// #include "Headers/VideoGame.h"
// #include "Menu/Menu_Principal.h"
// #include "Headers/mensajes.h"
#include "VideoGame.h"
#include "Menu_Principal.h"
#include "mensajes.h"

using namespace std;

int main(){
    VideoGame videogame;
    Menu_Principal menu(videogame);
    size_t op;

    do{
        system("cls");
        op = menu.selection();
        system("cls");
    }while(op!=12);

    return 0;
}