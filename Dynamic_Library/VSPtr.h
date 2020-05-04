#ifndef DYNAMIC_LIBRARY_VSPTR_H
#define DYNAMIC_LIBRARY_VSPTR_H

#include <iostream>
#include "garbageCollector.h"


using namespace std;
template<class T>
class VSPtr{


public:


    T *ptr; // Actual pointer
    garbageCollector<T>* gc = garbageCollector<T>::getInstance();




    // Constructor
    explicit VSPtr(T *p = NULL) {
       ptr = p;
       ge = garbageElement<T>(ptr, garbageCollector<T>::getInstance(), false);

    }

    // Destructor
    ~VSPtr() {
        delete (ptr);
        //Must call Garbage collector
    }

    // Overloading dereferencing operator
    T &operator*() {
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T *operator->() {
        return ptr;
    }

    T &operator=(const T &other) {
        if (typeid(&other) != typeid(VSPtr<T>) || typeid(VSPtr<T>) != typeid(this)) {
            return "Error: Invalid type for assignation";
            //Must copy VSPtr and its id to Garbage Collector
        } else {
            return &other;
        }

    }

};



#endif //DYNAMIC_LIBRARY_D_H