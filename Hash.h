#include "Nodo.h"

class Hash{
    int BUCKET;

    list<Nodo*> *table;
    vector<string> vals;

    vector<int> all_data;

public:
    Hash(int V, vector<string>& colums);

    void insertItem(Nodo* x);

    void deleteItem(int key);

    int hashFunction(int x){
        return (x % BUCKET);
    }

    vector<int>& getData() {
        return this->all_data;
    }

    void displayHash();
};

Hash::Hash(int b, vector<string>& colums){
    this->BUCKET = b;
    table = new list<Nodo*>[BUCKET];
    this->vals = colums;
}

void Hash::insertItem(Nodo* key){
    int index = hashFunction(key->getId());
    table[index].push_back(key);
    this->all_data.push_back(key->getId());
}

void Hash::deleteItem(int key){
    this->all_data[key] = -1;
    int index = hashFunction(key);


    list<Nodo*>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++){
        if ((*i)->getId() == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash(){
    for(auto i : vals){
        cout << i << "\t";
    }
    cout << '\n';
    for(int i = 0; i < BUCKET; i++){
        cout << i << ": ";
        for(auto x : table[i]){
            x->toString();
            //this->all_data.push_back(x->getId());
        }
        cout << '\n';
    }
    /*for (int i = 0; i < BUCKET; i++){
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x->getId() << "| ";
        cout << endl;
    }
    */
}