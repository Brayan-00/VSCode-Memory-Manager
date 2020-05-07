#ifndef DYNAMIC_LIBRARY_VSPTR_H
#define DYNAMIC_LIBRARY_VSPTR_H

#include <iostream>
#include "garbageCollector.h"


using namespace std;
template<class T>
class VSPtr{


public:


    T *ptr = nullptr; // Actual pointer
    //garbageCollector<T>* gc = garbageCollector<T>::getInstance();




    // Constructor
    static VSPtr<T> New(){
        VSPtr<T> newPtr;
       //ge = garbageElement<T>(ptr, garbageCollector<T>::getInstance(), false);
        return newPtr;
    }

    // Destructor
    ~VSPtr() {
        delete (ptr);
        //Must call Garbage collector
    }

    // Overloading dereferencing operator
    T& operator * () const {
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T * operator -> () {
        return ptr;
    }

    T operator &(){ return *ptr;}

    VSPtr& operator =(T newValue){

        ptr = new T(newValue);


    }

    VSPtr& operator =(VSPtr& other){
        ptr = other.ptr;
        return *this;
    }


};



#endif //DYNAMIC_LIBRARY_D_H