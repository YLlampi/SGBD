#include "Controller.h"

int main(){
    srand(time(NULL));
    
    Controller c1;
    c1.menu();



    /*
    string opcion;
    int cont = 0;
    vector<string> colums;w
    string valColumn;

    do{
        cout << "Desea agregar un campo columna? SI/NO: ";cin>>opcion;
        if(opcion == "SI" or opcion == "si"){
            cont++;
            cout << "Nombre de la Columna: "; cin>>valColumn;
            colums.push_back(valColumn); 

        }

    }while(opcion == "SI" or opcion == "si");

    const int numsBuck = 10;

    Hash h(numsBuck, colums);

    // MENU 
    int opcion__menu;
    do{
        cout << "\tMENU" << '\n';
        cout << "1. Insertar Valor" << '\n';
        cout << "2. Eliminar Dato" << '\n';
        cout << "3. Mostrar Tabla" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opcion: "; cin>>opcion__menu;

        if(opcion__menu == 1){
            insertarDato(h, colums);
        }
        else if(opcion__menu == 2){
            int id__eliminar;
            cout << "Id a Eliminar: "; cin>>id__eliminar;
            h.deleteItem(id__eliminar);
        }
        else if(opcion__menu == 3){
            h.displayHash();
        }

    }while(opcion__menu != 4);
    */
    
    return 0;
}
