//
// Created by heutlett on 29/4/20.
//
#include "VSPtr.h"
#include "iostream"

int main()
{
    VSPtr<int> ptr = VSPtr<int>::New();
    *ptr = 20;

    //VSPtr<int> ptr2 = ptr;

    cout << endl << "El valor de *ptr es " << *ptr << endl;
    cout << "La direccion de memoria de &ptr es "<< &ptr << endl;
    //cout << "La cantidad de referencias a ptr son " << garbageCollector::getInstance()->addressList->at(0)->count;

    return 0;
}
