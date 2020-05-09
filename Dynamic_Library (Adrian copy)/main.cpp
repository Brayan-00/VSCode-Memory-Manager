//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

garbageCollector * gc = garbageCollector::getInstance();


int main()
{

    VSPointer<int> ptr(new int());
    *ptr = 123;

    VSPointer<int> ptr1(new int());
    ptr1 = ptr;

    VSPointer<int> ptr10(new int());
    *ptr10 = 444;

    VSPointer<int> ptr2(new int());
    ptr2 = ptr1;

    ptr2 = ptr10;


    gc->printElements();

    return 0;
}
