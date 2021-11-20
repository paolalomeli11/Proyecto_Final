#include "Menu.h"

Menu::Menu()
{

}
void Menu::print()
{
    for(size_t i=0; i<items.size(); i++){
        cout << "\n\t" << right << setw(2) << i+1 << ") " << items[i];
    }
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
