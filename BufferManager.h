#include <bits/stdc++.h>
using namespace std;

class BufferManager{
private:
    int cantPaginas;
    vector<int> data_files;
        
public:
    //BufferManager() {

    //}

    BufferManager(int cantPaginas, vector<int>& data_files) : cantPaginas{cantPaginas}{
        this->data_files = data_files;
        //metodo_clock();
        metodo_lru();
    }

    void imprimir(vector<string>& vect){
        for (int i = 0; i < vect.size(); i++){
            if (i != vect.size() - 1)
                cout << vect[i] << ' ';
            else
                cout << vect[i];
        }
        cout << '\n';
    }

    void metodo_lru(){
        int contFallos = 0;
        vector<string> pagAlojadas;
        vector<string> paginas;
        
        string input2;
        
        //while(cin>>input2){
            //paginas.push_back(input2);
        //}

        // valores aleatorios
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        int index = 7 + rand() % 20; // Numeros de paginas a Consultar (pueden ser Repetidos)
        for(int i = 0; i < index; i++){
            int index_a = 0 + rand() % (this->data_files.size()-1 + 1 - 0);
            //paginas[i] = to_string(this->data_files[index]);
            if(this->data_files[index_a] == -1) continue;
            paginas.push_back(to_string(this->data_files[index_a]));
        }
        
        //paginas.resize(paginas.size());

        cout << "-----------------LRU-----------------" << '\n';
        cout << "-------------------------------------" << '\n';
        cout << "Pag.   Cont. de Frames" << '\n';
        cout << "----   ---------------" << '\n';
        for (int i = 0; i < paginas.size(); i++){
            if (pagAlojadas.size() < cantPaginas and
                find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) == pagAlojadas.end()){
                pagAlojadas.push_back(paginas[i]); // añadir pagina
                contFallos++;
                cout << paginas[i] << " M    ";
                imprimir(pagAlojadas);
            }
            // si la pagina ya existe
            else if (find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) != pagAlojadas.end()){
                cout << paginas[i] << "      ";
                imprimir(pagAlojadas);
            }

            // pagina a reemplazar(nuevo) *no esta*
            else{
                int k;
                int maxIndex = INT_MAX; // Indice las antiguo
                int remplazarPag = 0;
                int flag = 0; // Para ver si hay alguna coincidencia
                for (int j = 0; j < pagAlojadas.size(); j++){
                    flag = 0;
                    
                    // Busca el elemento mas antiguo comparando la cadena desde el actual
                    // disminuyendo uno en uno
                    for (k = i - 1; k >= 0; k--){
                        
                        //cout << '\n';
                        //cout << "I-J-k: " << i << "-" << j << "-" << k << '\n';
                        //cout << "paginas[k]-pagAlojadas[j]: " << paginas[k] << "-" << pagAlojadas[j] << '\n';
                        if (paginas[k] != pagAlojadas[j]){
                            //cout << "estoy dentro" << '\n';
                            continue;
                        }
                            
                        else{
                            flag = 1;
                            if (k < maxIndex){
                                maxIndex = k;
                                remplazarPag = j;
                                //cout << "J ---> " << j << '\n';
                            }
                            break;
                        }
                    }
                    //cout << "Valor de J-I-K: [" << j << "-" << i << "-" << k << "]" <<'\n';
                    // reemplazo nueva pagina
                    /*
                    if (flag == 0){
                        pagAlojadas[j] = paginas[i];
                        contFallos++;
                        cout << paginas[i] << " *    ";
                        
                        imprimir(pagAlojadas);
                        break;
                    }
                    */
                }
                if (flag == 1){ // ya esta en memoria
                    pagAlojadas[remplazarPag] = paginas[i];
                    contFallos++;
                    cout << paginas[i] << " M    ";
                    imprimir(pagAlojadas);
                }
            }
        }

        cout << "-------------------------------------" << '\n';
        cout << "Numero de fallos de pagina = " << contFallos << '\n';
    }


    void metodo_clock(){
        int contFallos = 0;
        int arm = 0;
        vector<string> pagAlojadas;
        vector<string> paginas;
        bool useBit[cantPaginas];

        string input2;
        
        //while(cin>>input2){
            //paginas.push_back(input2);
        //}

        // valores aleatorios
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        int index = 7 + rand() % 20; // Numeros de paginas a Consultar (pueden ser Repetidos)
        for(int i = 0; i < index; i++){
            int index_a = 0 + rand() % (this->data_files.size()-1 + 1 - 0);
            //paginas[i] = to_string(this->data_files[index]);
            paginas.push_back(to_string(this->data_files[index_a]));
        }

        cout << "----------------CLOCK----------------" << '\n';
        cout << "-------------------------------------" << '\n';
        cout << "Pag.   Cont. de Frames" << '\n';
        cout << "----   ---------------" << '\n';
        for (int i = 0; i < paginas.size(); i++){
            auto it = find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]);
            // si no esta completo los frames y se tiene una nueva pagina
            if (pagAlojadas.size() < cantPaginas &&
                find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) == pagAlojadas.end()){
                pagAlojadas.push_back(paginas[i]); // agregados pagina
                useBit[i] = true;
                contFallos++;
                cout << paginas[i] << " M    ";
                imprimir(pagAlojadas);
            }
            // La pagina existe en el vector

            else if (it != pagAlojadas.end()){
                useBit[it - pagAlojadas.begin()] = true;
                cout << paginas[i] << "      ";
                imprimir(pagAlojadas);
            }

            // nueva pagina - vector lleno (caso de fallo)
            else{
                int allPassed = 0; // Bandera para el caso de que todas las páginas sean verdaderas
                while (allPassed == 0){
                    for (int j = 0; j < pagAlojadas.size(); j++){
                        if (useBit[arm] == true){
                            useBit[arm] = false;
                            arm++;
                            if (arm == pagAlojadas.size()) // Reiniciar reloj
                                arm = 0;
                        }
                        else{
                            pagAlojadas[arm] = paginas[i];
                            useBit[arm] = true;
                            arm++;
                            if (arm == pagAlojadas.size()) // Reiniciar reloj
                                arm = 0;
                            allPassed = 1;
                            break;
                        }
                    }
                }

                contFallos++;
                cout << paginas[i] << " M    ";
                imprimir(pagAlojadas);
            }
        }

        cout << "-------------------------------------" << '\n';
        cout << "Numero de fallos de pagina = " << contFallos << '\n';
    }
};