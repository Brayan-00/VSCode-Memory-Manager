//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

int main()
{
    garbageCollector * gc = garbageCollector::getInstance();

    VSPointer<int> ptr(new int());
    *ptr = 20;

    VSPointer<char> ptr1(new char());
    *ptr1 = 'a';

    VSPointer<bool> ptr2(new bool());
    *ptr2 = false;

    cout << endl<< "copio referencia " << endl << endl;
    VSPointer<int> ptr3(new int());
    ptr3 = ptr;

    VSPointer<int> ptr4(new int());
    ptr4 = ptr3;


    gc->printElements();

    //VSPointer<int> ptr2 = ptr;

    //cout << endl << "El valor de *ptr es " << *ptr << endl;
    //cout << "La direccion de memoria de &ptr es "<< &ptr << endl;
    //cout << "La cantidad de referencias a ptr son " << garbageCollector::getInstance()->garbageList->at(0)->count;

    return 0;
}
