#ifndef DYNAMIC_LIBRARY_VSPOINTER_H
#define DYNAMIC_LIBRARY_VSPOINTER_H

#include <iostream>
#include "garbageCollector.h"
using namespace std;

// A generic smart pointer class 
template <class T>
class VSPointer {

public:

    T* ptr = nullptr; // Actual pointer
    garbageCollector * gc = garbageCollector::getInstance();
    string id;

    // Constructor
    explicit VSPointer(T* p = nullptr) {
        ptr = p;
        string type = typeid(*ptr).name();
        string id = "id" + to_string(gc->totalPtrCount);

        //cout << "la direccion de ptr es " << ptr << " y la de this " << this << endl << endl;

        cout << "VSPointer: " << this << " refTo: " << ptr <<" type: (" << type << ") has been created" << endl;
        gc->addPointer(reinterpret_cast<void**>(ptr), type, id, (void**)this);

        //cout << "refAddress is " << *reinterpret_cast<int*>(ptr) <<endl;


    }

    T operator &(){return *ptr;}

    // Destructor
    ~VSPointer() { delete (ptr); }

    // Overloading dereferncing operator
    T& operator*() {

        cout << "el valor es " << *ptr << endl;

        for(int i = 0; i < gc->garbageList->size(); i++){

            if(gc->garbageList->at(i)->refAddress == reinterpret_cast<void**>(this->ptr)){

                gc->garbageList->at(i)->value = to_string(*ptr);

            }

        }
        cout << "damn" << endl;
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
        updateList();

    }
    //Se ejecuta cuando se hace un ptr3 = ptr;
    VSPointer& operator=(VSPointer& other){

        ptr = other.ptr;
        string type = typeid(*ptr).name();

        for(int i = 0; i < gc->garbageList->size(); i++){

            //Busca el elemento en el garbageCollector para aumentar en uno su cantidad
            if(reinterpret_cast<void**>(other.ptr) == gc->garbageList->at(i)->refAddress){

                gc->garbageList->at(i)->quantity++;

                //Busca el puntero nuevo para hacerlo apuntar al puntero ya creado y copiarle su id
                for(int e = 0; e < gc->garbageList->size(); e++){

                    if(gc->garbageList->at(e)->vsptrAdress == reinterpret_cast<void**>(this)){
                        gc->garbageList->at(e)->id = gc->garbageList->at(i)->id;
                        gc->garbageList->at(e)->refAddress = gc->garbageList->at(i)->refAddress;
                        //cout << "el valor es " << *reinterpret_cast<int*>(gc->garbageList->at(e)) << endl;
                    }

                }
                return *this;
            }

        }
        cout << "El valor de vspointer es " << to_string(*ptr) << endl;
    }

    void updateList(){

        cout << "entre";

    }

};

#endif //DYNAMIC_LIBRARY_D_H