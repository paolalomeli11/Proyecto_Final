#include <iostream>
#include <conio.h>
#include "VideoGame.h"
#include "Menu.h"
#include "mensajes.h"

using namespace std;

int main(){
    VideoGame videogame;
    Menu menu;
    size_t op;

    do{
        system("cls");
        menu.print();
        cin >> op;
        system("cls");

        switch(op){
        case 1:
            menu.op1(videogame);
            break;
        case 2:
            menu.op2(videogame);
            break;
        case 3:
            menu.op3(videogame);
            break;
        case 4:
            menu.op4(videogame);
            break;
        case 5:
            menu.op5(videogame);
            break;
        case 6:
            menu.op6(videogame);
            break;
        case 7:
            menu.op7(videogame);
            break;
        case 8:
            menu.op8(videogame);
            break;
        case 9:
            menu.op9(videogame);
            break;
        case 10:
            menu.op10(videogame);
            break;
        case 11:
            menu.op11(videogame);
            break;
        case 12:
            mnsj_despedida();
            break;
        default:
            mnsj_error();
            break;
        }
        system("cls");
    }while(op!=12);

    return 0;
}