#ifndef DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
#define DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H

#include <vector>
#include "garbageElement.h"
#include "list.h"

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

        /* Static access method. */
        int totalPtrCount = 0;

        static garbageCollector* getInstance();

        void printElements(){

            cout << endl << "LIST OF VSPOINTERS" << endl;

            for(int i = 0; i < garbageList->size(); i++){
                cout << "id: " << garbageList->at(i)->id << " | VSPtrAdress: " << garbageList->at(i)->vsptrAdress << " | " << "refAddress: " << garbageList->at(i)->getAddress() << " | Type: " << garbageList->at(i)->type << " | Value: " << garbageList->at(i)->getValue()  << " | Quantity: " << garbageList->at(i)->quantity << endl;
            }
        }

        bool deletePtr(string id){

            for(int i = 0; i < garbageList->size(); i++){

                if(garbageList->at(i)->id.compare(id)==0){

                    if(garbageList->at(i)->quantity == 0){

                        garbageList->erase(garbageList->begin() + i);

                    }else{

                        garbageList->at(i)->quantity--;

                    }

                }

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