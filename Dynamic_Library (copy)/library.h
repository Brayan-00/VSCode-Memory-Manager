#ifndef SMART_POINTERSTEST_LIBRARY_H
#define SMART_POINTERSTEST_LIBRARY_H
#include <iostream>
#include <typeinfo>
#include <string>
#include "garbageCollector.h"
using namespace std;

template<typename T>
class VSPtr{
private:

public:

    static garbageCollector* gc;
    T* ptr = nullptr;
    string id;
    string type;

    //Constructor
    //VSPtr(T* p = NULL);
    //Destructor
    //~VSPtr();


    static VSPtr<T> New(){

        VSPtr<T> newPtr;
        cout << "Created VSPtr: " << &newPtr.ptr << endl;
        newPtr.type = typeid(*newPtr.ptr).name();
        //newPtr.id = gc->counter;
        //gc->increaseCounter();

        return newPtr;

    }

    T& operator * () const { return *ptr;}


    T * operator -> (){ return ptr;}

    T operator & (){ return *ptr;}

    VSPtr& operator =(T newValue){

        ptr = new T(newValue);
        type = typeid(*ptr).name();
    }

    VSPtr& operator =(VSPtr& other){

        ptr = other.ptr;
        id = other.id;
        return *this;

    }




};



#endif //SMART_POINTERSTEST_LIBRARY_H
