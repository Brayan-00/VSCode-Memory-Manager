//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"
#include "iostream"

int main()
{
    garbageCollector * gc = garbageCollector::getInstance();

    /*
     * Tipos de datos nativos
     *
     * int, bool, char, short, long, long long, float, double, long double
     *
     */

    VSPointer<int> ptr(new int(222));

    VSPointer<bool> ptr1(new bool(true));

    VSPointer<char> ptr2(new char('a'));

    VSPointer<short> ptr3(new short(4));

    VSPointer<long> ptr4(new long(12345678912345));

    VSPointer<long long> ptr5(new long long(1234567890234567890));

    VSPointer<float> ptr6(new float(213.22));

    VSPointer<double> ptr7(new double(4123.22));

    VSPointer<long double> ptr8(new long double(123213123.21312313232));




    gc->printElements();

    return 0;
}
