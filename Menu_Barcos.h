#ifndef MENU_BARCOS_H
#define MENU_BARCOS_H

#include "Menu.h"
#include "Civilizacion.h"

class Menu_Barcos : public Menu
{
private:
    Civilizacion *cv;

public:
    Menu_Barcos(Civilizacion &c);
    size_t selection();
    void process_1();
    void process_2();
    void process_3();
    void process_4();
    void process_5();
};

#endif //MENU_BARCOS_H