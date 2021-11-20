#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Menu
{
protected:
    vector<string> items;
public:
    Menu();
    void print();
    void printCabecera(const string &c, size_t w);
};

#endif //MENU_H