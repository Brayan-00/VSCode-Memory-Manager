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
        gc->adressList->push_back(reinterpret_cast<void**>(&ptr));
        cout << "El primer address es: "<< gc->adressList->at(0) << endl;
    }

    // Destructor
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferncing operator
    T& operator*() { return *ptr; }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};

#endif //DYNAMIC_LIBRARY_D_H