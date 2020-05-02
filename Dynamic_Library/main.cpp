//
// Created by heutlett on 29/4/20.
//
#include "library.h"
#include "iostream"

int main(){
    VSPtr<int> a = VSPtr<int>::New();
    *a = 10;

    std::cout << *a <<endl;
}