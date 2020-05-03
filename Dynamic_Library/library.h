#ifndef SMART_POINTERSTEST_LIBRARY_H
#define SMART_POINTERSTEST_LIBRARY_H
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
class VSPtr{
private:
    static T* ptr_data;
    int id;
    int references;
public:
    //Constructor
    VSPtr(T* p = NULL){
        ptr_data = p;
    }
    //Destructor
    ~VSPtr(){
        delete(ptr_data);
    }
    T& operator*(){
        return *ptr_data;
    }
    T* operator->(){
        return ptr_data;
    }
    T& operator= (const T& other){
        if(typeid(this) == typeid(&other)){
            return "Error: Invalid type for assignation";
            //Must copy VSPtr and its id to Garbage Collector
        }else{
            return &other;
        }

    }
    static T New(){
        return *ptr_data;

    }

};



#endif //SMART_POINTERSTEST_LIBRARY_H
