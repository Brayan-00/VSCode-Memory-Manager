#ifndef DYNAMIC_LIBRARY_VSPOINTER_H
#define DYNAMIC_LIBRARY_VSPOINTER_H

#include <iostream>
#include "garbageCollector.h"
using namespace std;

// A generic smart pointer class 
template <class T>
class VSPointer {

public:

    T* ptr; // Actual pointer
    garbageCollector * gc = garbageCollector::getInstance();
    string id;

    // Constructor
    explicit VSPointer(T* p) {
        ptr = new T(*p);
        //cout << endl << "la direccion de memoria del valor de ptr es " << &(*ptr) << endl;
        //cout << "la direccion de memoria de ptr es " << ptr << endl;
        string type = typeid(*ptr).name();
        id = "id" + to_string(gc->totalPtrCount);
        cout << "VSPointer: " << this << ", refTo: " << ptr <<" type: (" << type << "), Value: " << to_string(*ptr) << " has been created" << endl;
        gc->garbageList->push_back(new garbageElement(ptr, type, id, (void**)this));
        gc->totalPtrCount++;
    }

    T operator &(){return *ptr;}

    // Destructor
    ~VSPointer() {
        delete (ptr);
        gc->deletePtr(id);


    }

    // Overloading dereferncing operator
    T& operator*() {
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }

    VSPointer& operator=(T newValue){

        ptr = newValue;
        cout << "entre";

    }
    //Se ejecuta cuando se hace un ptr3 = ptr;
    VSPointer& operator=(VSPointer& other){

    }

};

#endif //DYNAMIC_LIBRARY_D_H