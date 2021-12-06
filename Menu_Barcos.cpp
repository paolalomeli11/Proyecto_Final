#include "Menu_Barcos.h"

Menu_Barcos::Menu_Barcos(Civilizacion &c)
{
    cv = &c;
    items = {"Agregar", "Mostrar todo", "Buscar", "Eliminar", "Salir"};
}
size_t Menu_Barcos::selection()
{
    system("cls");
    string cab = "BARCOS " + cv->getNombre();
    printCabecera(cab,50);
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
    
    default:
        break;
    }
    return op;
}
void Menu_Barcos::process_1()
{
    Barco *b = new Barco();
    size_t id = cv->totalBarcos() + 1000;

    printCabecera("AGREGAR BARCO",45);
    cout << "\n\n\tCombustible: ";
    int c;
    cin >> c;

    b->setCombustible(c);
    
    b->setId(id);
    cv->agregarBarco(b);
    cout << "\n\n\tOperacion exitosa.\n\n\t";
    system("pause");
}
void Menu_Barcos::process_2()
{
    if(cv->totalBarcos() == 0){
        system("cls");
        cout << "\n\n\tNada que mostrar.\n\n\t";
        system("pause");
        return;
    }

    cv->mostrarBarcos();
    cout << "\n\n\t";
    system("pause");
}
void Menu_Barcos::process_3()
{
    if(cv->totalBarcos() == 0){
        system("cls");
        cout << "\n\n\tNada que mostrar.\n\n\t";
        system("pause");
        return;
    }

    cout << "\n\n\tID: ";
    int id;
    cin >> id;
    Barco *b = &(cv->buscarBarco(id));

    if(!cv->barcoEncontrado(id)){
        cout << "\n\n\tNo se encontro el elemento.\n\n\t";
        system("pause");
        return;
    }

    size_t op;

    do{
        system("cls");
        printCabecera("GUERREROS",45);
        cout << "\n\t1) Agregar";
        cout << "\n\t2) Eliminar";
        cout << "\n\t3) Mostrar ultimo";
        cout << "\n\t4) Mostrar todos";
        cout << "\n\t5) Regresar";
        cout << "\n\n\tOpcion: ";
        cin >> op;

        if(op == 1){
            system("cls");
            printCabecera("AGREGAR GUERRERO",45);
            Guerrero g;

            int i;
            cout << "\n\n\tID: ";
            cin >> i;
            g.setId(i);

            cout << "\tSalud: ";
            cin >> i;
            g.setSalud(i);

            cout << "\tFuerza: ";
            cin >> i;
            g.setFuerza(i);

            cout << "\tEscudo: ";
            cin >> i;
            g.setEscudo(i);

            size_t tipo;

            do{
                system("cls");
                cout << "\n\tTipo: ";
                cout << "\n\t1) Asesino";
                cout << "\n\t2) Luchador";
                cout << "\n\t3) Tirador";
                cout << "\n\t4) Mago";
                cout << "\n\n\tOpcion: ";

                cin >> tipo;

                switch (tipo)
                {
                case 1:
                    g.setTipo("Asesino");
                    break;
                case 2:
                    g.setTipo("Luchador");
                    break;
                case 3:
                    g.setTipo("Tirador");
                    break;
                case 4:
                    g.setTipo("Mago");
                    break;
                default:
                    break;
                }
                cout << "\r\b\b\b ";
            }while(tipo > 4 | tipo < 1);

            b->agregarGuerrero(g);
        }
        else if(op == 2){
            if(b->totalGuerreros() == 0){
                system("cls");
                cout << "\n\n\tNada que mostrar.\n\n\t";
                system("pause");
            }
            else{
                b->eliminarGuerrero();  
            }
        }
        else if(op == 3){
            system("cls");
            if(b->totalGuerreros() == 0){
                cout << "\n\n\tNada que mostrar.\n\n\t";
                system("pause");
            }
            else{
                Guerrero g = b->tope();
                g.print();
                cout << "\n\n\t";
                system("pause");
            }
        }
        else if(op == 4){
            system("cls");
            if(b->totalGuerreros() == 0){
                cout << "\n\n\tNada que mostrar.\n\n\t";
                system("pause");
            }
            else{
                b->mostrarGuerreros();
                cout << "\n\n\t";
                system("pause");
            }
        }
    }while(op != 5);
}
void Menu_Barcos::process_4()
{
    if(cv->totalBarcos() == 0){
        system("cls");
        cout << "\n\n\tNada que mostrar.\n\n\t";
        system("pause");
        return;
    }

    printCabecera("ELIMINAR BARCOS",45);
    cout << "\n\n\t1) Por ID";
    cout << "\n\t2) Por combustible";
    cout << "\n\n\tOpcion: ";
    size_t op;
    cin >> op;

    system("cls");

    if(op == 1)
    {
        printCabecera("ELIMINAR BARCO",45);
        cout << "\n\n\tID: ";
        int id;
        cin >> id;

        cv->eliminarBarcoId(id);

    }
    else if(op == 2)
    {
        printCabecera("ELIMINAR BARCO",45);
        cout << "\n\n\tCombustible: ";
        int com;
        cin >> com;
        cv->eliminarBarcoCombustible(com);
    }

}
void Menu_Barcos::process_5()
{

}