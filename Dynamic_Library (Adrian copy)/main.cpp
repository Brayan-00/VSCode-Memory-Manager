//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

int main()
{
    garbageCollector * gc = garbageCollector::getInstance();


    VSPointer<int> ptr(new int(222));

    VSPointer<bool> ptr1(new bool(true));

    VSPointer<char> ptr2(new char('a'));




    gc->printElements();

    return 0;
}
