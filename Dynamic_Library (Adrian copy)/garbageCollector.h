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
                 garbageList->at(i)->toString();
            }

            cout << endl;
        }
/*
        bool deletePtr(string id, void** address){

            for(int i = 0; i < garbageList->size(); i++){
                if(garbageList->at(i)->id.compare(id)==0 && garbageList->at(i)->vsptrAdress==address){

                    if(garbageList->at(i)->quantity == 0){
                        garbageList->erase(garbageList->begin() + i);
                        totalPtrCount--;
                        return true;
                    }else{
                        garbageList->at(i)->quantity--;
                        return false;
                    }
                }
            }
        }*/

        garbageElement* getGarbageElement(string id){
            for(int i = 0; i < garbageList->size(); i++){

                if(garbageList->at(i)->id.compare(id) == 0){
                    return garbageList->at(i);
                }
            }
            return nullptr;
        }

        garbageElement* getGarbageElement(string id, void** address){
            for(int i = 0; i < garbageList->size(); i++){

                if(garbageList->at(i)->id.compare(id) == 0 && garbageList->at(i)->vsptrAdress == address){
                    return garbageList->at(i);
                }
            }
            return nullptr;
        }

        void deleteGarbageElement(string id, void** address){
            for(int i = 0; i < garbageList->size(); i++){

                if(garbageList->at(i)->id.compare(id) == 0 && garbageList->at(i)->vsptrAdress == address){

                    garbageList->erase(garbageList->begin() + i);
                    totalPtrCount--;

                }
            }
        }

        void updateReference(string id, string newId, void** address){
            garbageElement * gNewReference = getGarbageElement(id, address);

            if(gNewReference== nullptr){

                garbageElement * gOriginal = getGarbageElement(id);
                garbageElement * gReference = gOriginal->getGarbageReference(address);
                garbageElement * gNewOriginal = getGarbageElement(newId);
                gOriginal->deleteReference(address);
                gReference->id = newId;
                gNewOriginal->listOfReferences->push_back(gReference);

            }else{

                deleteGarbageElement(id, address);
                garbageElement * gOriginalReference = getGarbageElement(newId);
                gNewReference->id = newId;
                gOriginalReference->listOfReferences->push_back(gNewReference);

            }
        }

        //Si es el ptr original devuelve true, sino false
        bool deletePtr(string id, void ** address){

            garbageElement * original = getGarbageElement(id, address);

            if(original != nullptr){

                deleteGarbageElement(id, address);
                return true;

            }else{

                garbageElement * reference = getGarbageElement(id);
                reference->deleteReference(address);
                return false;

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