#ifndef DYNAMIC_LIBRARY_LIBRARY_H
#define DYNAMIC_LIBRARY_LIBRARY_H

#include <iostream>
#include "garbageCollector.h"
using namespace std;

// A generic smart pointer class 
template <class T>
class SmartPtr {

public:


    T* ptr; // Actual pointer
    garbageCollector * gc = garbageCollector::getInstance();

    // Constructor
    explicit SmartPtr(T* p = NULL) {
        ptr = p;
        garbageElement *g = new garbageElement(reinterpret_cast<void**>(&ptr));
        gc->addressList->push_back(g);
        cout << "Se ha creado el nuevo VSPointer, &ptr = " << &ptr << endl;
        cout << "Su valor inicial es, *ptr = "<< *ptr << endl;
        cout << "Se ha agregado la direccion de memoria en el GC: "<< gc->addressList->at(0)->address << endl;
        //free(reinterpret_cast<void**>(&gc->addressList->at(0)->address));
        //free(ptr);
        //cout << "Se ha limpiado la direccion de memoria en el GC: "<< gc->addressList->at(0)->address << endl;
    }

    // Destructor
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferncing operator
    T& operator*() {
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};

#endif //DYNAMIC_LIBRARY_D_H