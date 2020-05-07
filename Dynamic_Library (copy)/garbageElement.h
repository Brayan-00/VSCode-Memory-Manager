//
// Created by brayanrv on 3/5/20.
//


#include "VSPtr.h"


template<class T>
class garbageElement {
private:
    static T* ptr;
    int id;
    int numRef;
    bool isReference;

public:
    garbageElement(T* newPtr, int newId, bool isRef)  {
        ptr = newPtr;
        id = newId;
        numRef = 1;
        isReference = isRef;
    }


    void newReference() {
        numRef++;
    }
    void deleteReference(){
        numRef--;
    }
};

