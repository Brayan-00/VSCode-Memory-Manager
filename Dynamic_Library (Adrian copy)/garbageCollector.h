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

        void increaseCounter() {

            totalPtrCount++;

        }

        void addPointer(void** address, string type, string pId, void ** vsptrAdress){

            totalPtrCount++;

            garbageList->push_back(new garbageElement(address, type, pId, vsptrAdress));
        }

        void printElements(){

            cout << endl << "LIST OF VSPOINTERS" << endl;

            for(int i = 0; i < garbageList->size(); i++){

                cout << "id: " << garbageList->at(i)->id << " | VSPtrAdress: " << garbageList->at(i)->vsptrAdress << " | " << "refAddress: " << garbageList->at(i)->refAddress << " | Type: " << " | Value: " << garbageList->at(i)->value << garbageList->at(i)->type << " | Quantity: " << garbageList->at(i)->quantity << endl;
                //cout << "value " << *reinterpret_cast<int*>(garbageList->at(i)->refAddress) << endl;
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