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

        cout << "la direccion de ptr es " << ptr << " y la de this " << this << endl << endl;

        cout << "VSPointer: " << &ptr << " type: (" << type << ") has been created" << endl;
        gc->addPointer(reinterpret_cast<void**>(ptr), type, id, (void**)this);

        //cout << "address is " << *reinterpret_cast<int*>(ptr) <<endl;


    }

    T operator &(){return *ptr;}

    // Destructor
    ~VSPointer() { delete (ptr); }

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
        updateList();

    }
    //Se ejecuta cuando se hace un ptr3 = ptr;
    VSPointer& operator=(VSPointer& other){


        cout << "Other.ptr es " << reinterpret_cast<void**>(&other.ptr) << endl;
        ptr = other.ptr;
        string type = typeid(*ptr).name();

        for(int i = 0; i < gc->garbageList->size(); i++){
            cout << "comparando " << reinterpret_cast<void**>(&ptr) << " " << gc->garbageList->at(i)->address << " con " << gc->garbageList->at(i)->id <<  endl;
            if(reinterpret_cast<void**>(other.ptr) == gc->garbageList->at(i)->address){
                //gc->totalPtrCount++;
                gc->garbageList->at(i)->quantity++;

                cout << "i am this " << &this->ptr << endl;

                for(int e = 0; e < gc->garbageList->size(); e++){

                    if(gc->garbageList->at(e)->vsptrAdress == reinterpret_cast<void**>(this)){
                        gc->garbageList->at(e)->id = gc->garbageList->at(i)->id;
                        gc->garbageList->at(e)->address = gc->garbageList->at(i)->address;
                    }

                }



                cout << "El id del retido es " << gc->garbageList->at(i)->id << endl;

                //gc->garbageList->push_back(new garbageElement(reinterpret_cast<void**>(&ptr), type, gc->garbageList->at(i)->id));
                return *this;
            }

        }

        //gc->addPointer(reinterpret_cast<void**>(&ptr), type);
        cout << "El valor de vspointer es " << to_string(*ptr) << endl;

    }

    void updateList(){

        cout << "entre";

    }

};

#endif //DYNAMIC_LIBRARY_D_H