#include "BufferManager.h"

class Nodo{
    private:
        int id;
        vector<string> val;
    public:
        Nodo(int id, vector<string>& vals) : id(id){
            this->val = vals;
        }

        int getId() const {
            return this->id;
        }

        void toString() const {
            cout << this->id << "-";
            for(auto i : val){
                cout << i << "\t";
            }
        }

};