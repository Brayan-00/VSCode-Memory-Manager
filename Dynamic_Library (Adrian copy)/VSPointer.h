#ifndef DYNAMIC_LIBRARY_VSPOINTER_H
#define DYNAMIC_LIBRARY_VSPOINTER_H

#include <iostream>
#include "garbageCollector.h"
using namespace std;

// A generic smart pointer class 
template <class T>
class VSPointer {

private:

    T* ptr; // Actual pointer


public:

    garbageCollector * gc = garbageCollector::getInstance();
    string id;
/*
    VSPointer(){

    // Constructor
    explicit VSPointer() {
        //ptr = (typeof(*ptr)*)malloc(sizeof(*ptr));
        string type = typeid(*ptr).name();
        id = "id" + to_string(gc->totalPtrCount);
        cout << "VSPointer: " << this << ", refTo: " << ptr <<" type: (" << type << "), Value: " << to_string(*ptr) << " has been created" << endl;
        gc->garbageList->push_back(new garbageElement(ptr, type, id, (void**)this));
        gc->totalPtrCount++;
    }

    }
*/

    VSPointer() {

    }
    // Constructor
    VSPointer(int i) {
        ptr = (typeof(*ptr)*)malloc(sizeof(*ptr));
        string type = typeid(*ptr).name();
        id = "id" + to_string(gc->totalPtrCount);
        cout << "VSPointer: " << this << ", refTo: " << ptr <<" type: (" << type << "), Value: " << to_string(*ptr) << " has been created" << endl;
        gc->garbageList->push_back(new garbageElement(ptr, type, id, (void**)this));
        gc->totalPtrCount++;
    }

    static VSPointer New(){

        return VSPointer(1);

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
        return *ptr;
    }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }


    //Se ejecuta cuando se hace un ptr3 = ptr;

    VSPointer& operator=(VSPointer& other){

        string type = typeid(ptr).name();
        string type2 = typeid(other.ptr).name();

        if(type.compare(type2)==0){
            ptr = other.ptr;
            gc->updateReference(id, other.id, reinterpret_cast<void**>(this));
            id = other.id;
        }else{
            cout << "Operation fail, the types dont match" << endl;
        }

    }

    void validateType(string type, T newValue){
        string type2 = typeid(ptr).name();
        if(type.compare(type2) == 0){
            *ptr = newValue;
        }else{
            cout << "Operation failed, the types dont match" << endl;
        }
    }

    VSPointer& operator=(int newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(bool newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(char newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(short newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(long newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(long long newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(float newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(double newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

    VSPointer& operator=(long double newValue){
        validateType(typeid(&newValue).name(), newValue);
    }

};

#endif //DYNAMIC_LIBRARY_D_H