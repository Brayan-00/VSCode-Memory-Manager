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
    //void** idVsptr;

    // Constructor
    explicit VSPointer(T* p) {
        ptr = p;
        string type = typeid(*ptr).name();
        id = "id" + to_string(gc->totalPtrCount);
        cout << "VSPointer: " << this << ", refTo: " << ptr <<" type: (" << type << "), Value: " << to_string(*ptr) << " has been created" << endl;
        gc->garbageList->push_back(new garbageElement(ptr, type, id, (void**)this));
        gc->totalPtrCount++;
    }

    static VSPointer* New(T* p){

        return VSPointer(p);

    }

    T operator &(){return *ptr;}

    // Destructor
    ~VSPointer() {
        if(gc->deletePtr(id, reinterpret_cast<void**>(this))){

            delete (ptr);

        }


    }

    // Overloading dereferncing operator
    T& operator*() {
        //gc->increaseReference(id);
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }

    VSPointer& operator=(T newValue){
        *ptr = newValue;
    }
    //Se ejecuta cuando se hace un ptr3 = ptr;
    VSPointer& operator=(VSPointer& other){

        string type = typeid(*ptr).name();
        string type2 = typeid(*other).name();

        if(type.compare(type2)==0){
            ptr = other.ptr;
            gc->updateReference(id, other.id, reinterpret_cast<void**>(this));
            id = other.id;
        }

    }

};

#endif //DYNAMIC_LIBRARY_D_H