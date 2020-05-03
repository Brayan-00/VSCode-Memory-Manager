//
// Created by heutlett on 29/4/20.
//
#include "library.h"
#include "iostream"

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}
