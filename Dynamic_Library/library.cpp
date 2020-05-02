#include "library.h"
template<typename T>

VSPtr<T>::VSPtr(T *p) {
    ptr_data = p;
}

template<typename T>
VSPtr<T>::~VSPtr() {
    delete(ptr_data);
    //Debe llamar al Garbage Collector
}

template<typename T>
T &VSPtr<T>::operator*() {
    return *ptr_data;
}

template<typename T>
T *VSPtr<T>::operator->() {
    return ptr_data;
}

template<typename T>
T VSPtr<T>::New() {
    VSPtr<T>();
}

template<typename T>
//Must check same type data
T& VSPtr<T>::operator=(const T& other) {
    if(typeid(this) == typeid(&other)){
        return "Error: Invalid type for assignation";
        //Must copy VSPtr and its id to Garbage Collector
    }else{
        return &other;
    }


}


