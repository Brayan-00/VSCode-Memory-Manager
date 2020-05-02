#ifndef SMART_POINTERSTEST_LIBRARY_H
#define SMART_POINTERSTEST_LIBRARY_H
#include <iostream>
using namespace std;

template<typename T>
class VSPtr{
private:
    T* ptr_data;
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
    // Sin inicializar, no sobreescribe la inicializacion del puntero
    static void New();
};

#endif //SMART_POINTERSTEST_LIBRARY_H
