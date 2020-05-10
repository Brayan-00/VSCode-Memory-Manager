//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

garbageCollector * gc = garbageCollector::getInstance();


int main()
{

    VSPointer<int> ptr1 = VSPointer<int>();
    *ptr1 = 5;
    VSPointer<int> ptr2 = VSPointer<int>();
    *ptr2 = 2;

    ptr1 = 5555;

    gc->printElements();


    return 0;
}
