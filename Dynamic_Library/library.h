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
public:
    //Constructor
    VSPtr(T* p = NULL);
    //Destructor
    ~VSPtr();
    T& operator*();
    T* operator->();
    T& operator=(const T& other);
    static T New();

};



#endif //SMART_POINTERSTEST_LIBRARY_H
