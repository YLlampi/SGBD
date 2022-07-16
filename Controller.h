#include "Hash.h"

class Controller{
private:
    string opcion;
    int cont = 0;
    vector<string> colums;
    string valColumn;

    const int cantPaginas = 3;

    BufferManager* bm;

    int contador_id;
public:
    Controller(){
        this->contador_id = 0;
    }

    void clearScreen() {
        printf("\033[2J\033[1;1H");
    }

    void insertarDato(Hash& h, vector<string>& colums){
        vector<string> pas(colums.size());
        for(int i = 0; i < colums.size(); i++){
            cout << colums[i] << ": "; cin>>pas[i];
        }
        //Nodo* p = new Nodo(stoi(pas[0]),pas);
        Nodo* p = new Nodo(this->contador_id++, pas);
        h.insertItem(p);
    }

    void menu(){
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
            cout << "4. Buffer Manager(Consultas)" << '\n';
            cout << "5. Salir" << '\n';
            cout << "Seleccione una opcion: "; cin>>opcion__menu;

            if(opcion__menu == 1){
                insertarDato(h, colums);
                clearScreen();
            }
            else if(opcion__menu == 2){
                int id__eliminar;
                cout << "Id a Eliminar: "; cin>>id__eliminar;
                h.deleteItem(id__eliminar);
                clearScreen();
            }
            else if(opcion__menu == 3){
                h.displayHash();
            }
            else if(opcion__menu == 4){
                bm = new BufferManager(this->cantPaginas, h.getData());
            }

        }while(opcion__menu != 5);
    }
};