#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <iostream>
#include <string>
#include <iomanip>

// #include "../Headers/VideoGame.h"
#include "VideoGame.h"
#include "Menu.h"

using namespace std;

class Menu_Principal : public Menu
{
private:
    VideoGame vg;
public:
    Menu_Principal(VideoGame &v);
    size_t selection();
    Civilizacion pedirDatos();
    void process_1();
    void process_2();
    void process_3();
    void process_4();
    void process_5();
    void process_6();
    void process_7();
    void process_8();
    void process_9();
    void process_10();
    void process_11();
    void process_12();
};

#endif // MENU_PRINCIPAL_H