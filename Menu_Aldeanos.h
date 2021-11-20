#ifndef MENU_ALDEANOS_H
#define MENU_ALDEANOS_H

#include "Menu.h"
// #include "../Headers/Civilizacion.h"
#include "Civilizacion.h"

class Menu_Aldeanos : public Menu
{
private:
    Civilizacion cv;
public:
    Menu_Aldeanos(Civilizacion &c);
    size_t selection();
    void process_1();
    void process_2();
    void process_3();
    void process_4();
    void process_5();
    void process_6();
};


#endif //MENU_ALDEANOS_H