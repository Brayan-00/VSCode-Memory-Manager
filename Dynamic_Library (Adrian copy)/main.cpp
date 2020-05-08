//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

garbageCollector * gc = garbageCollector::getInstance();

void deletingTest(){

    //VSPointer<int> ptr(new int());
    //*ptr = 666;
    //gc->printElements();

    VSPointer<int> ptr(new int());
    *ptr = 123;

    ptr = 5;

    VSPointer<int> ptr9(new int());

    ptr9 = ptr;

    VSPointer<int> ptr10(new int());

    ptr10 = ptr9;

    VSPointer<bool> ptr1(new bool());
    *ptr1 = true;

    VSPointer<char> ptr2(new char());
    *ptr2 = 'a';

    VSPointer<short> ptr3(new short());
    *ptr3 = 4;

    VSPointer<long> ptr4(new long());
    *ptr4 = 12345678912345;

    VSPointer<long long> ptr5(new long long());
    *ptr5 = 1234567890234567890;

    VSPointer<float> ptr6(new float());
    *ptr6 = 213.22;

    VSPointer<double> ptr7(new double());
    *ptr7 = 4123.22;

    VSPointer<long double> ptr8(new long double());
    *ptr8 = 123213123.21312313232;

    gc->printElements();
}

int main()
{


    /*
     * Tipos de datos nativos
     *
     * int, bool, char, short, long, long long, float, double, long double
     *
     */

    //TESTING

    //VSPointer<int> ptr(new int());
    //*ptr = 123;

    //int a = &ptr;

    //cout << "El valor de a es :" << a << endl << endl;

    deletingTest();

    VSPointer<int> ptr9(new int());

    //ptr9 = ptr;

    //*ptr = 666;

    //cout << "El valor de ptr9 es " << &ptr9 << endl << endl;

    //TESTING



    gc->printElements();

    return 0;
}
