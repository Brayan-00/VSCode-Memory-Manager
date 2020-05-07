#ifndef DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
#define DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H

#include <vector>
#include "garbageElement.h"

using namespace std;

class garbageCollector {

    private:
        /* Here will be the instance stored. */
        static garbageCollector* instance;

        /* Private constructor to prevent instancing. */
        garbageCollector(){
        }

    public:

        vector<garbageElement*> * garbageList = new vector<garbageElement*>;
        //implementar hashmap para guardar la cantidad de punteros

        /* Static access method. */
        int totalPtrCount = 0;

        static garbageCollector* getInstance();

        //Busca un puntero con la misma direccion en la lista, si lo encuentra devuelve su numero y lo aumenta
        //si no lo encuentra devuelve 0;
        /*
        string createOrIncreaseQuantity(void** address){

            for(int i = 0; i < garbageList->size(); i++){
                cout << "comparando " << address << " " << garbageList->at(i)->address << " con id" << garbageList->at(i)->id <<  endl;
                if(address == garbageList->at(i)->address){
                    totalPtrCount++;
                    garbageList->at(i)->quantity++;
                    cout << "El id del retido es " << garbageList->at(i)->id << endl;

                    return garbageList->at(i)->id;

                }

            }
            totalPtrCount++;
            return "";

        }
*/

        void increaseCounter() {

            totalPtrCount++;

        }

        void addPointer(void** address, string type, string pId, void ** vsptrAdress){

            cout << "Se va agregar el address : " << address << endl;



            totalPtrCount++;

            cout << "id es vacio" << endl;

            garbageList->push_back(new garbageElement(address, type, pId, vsptrAdress));
        }

        void printElements(){

            cout << endl << "LIST OF VSPOINTERS" << endl;

            for(int i = 0; i < garbageList->size(); i++){

                cout << "id: " << garbageList->at(i)->id << " | VSPtrAdress: " << garbageList->at(i)->vsptrAdress << " | " << "refAddress: " << garbageList->at(i)->address << " | Type: " << garbageList->at(i)->type << " | Quantity: " << garbageList->at(i)->quantity << endl;
                //cout << "value " << *reinterpret_cast<int*>(garbageList->at(i)->address) << endl;
            }

        }


};

garbageCollector* garbageCollector::instance = 0;

garbageCollector* garbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new garbageCollector();
    }

    return instance;
}


#endif