//
// Created by heutlett on 29/4/20.
//
#include "VSPointer.h"

garbageCollector * gc = garbageCollector::getInstance();

void printTests(){

    //Test#1
    cout << "Test #1:" << endl;
    VSPointer<int> myPtr = VSPointer<int>::New();
    gc->printElements();

    //Test#2
    cout << "Test #2:" << endl;
    *myPtr = 5;
    gc->printElements();

    //Test#3
    cout << "Test #3:" << endl;
    int a = &myPtr;
    cout << "The value of a: " << a << endl;

    //Test#4
    cout << "Test #4:" << endl;
    VSPointer<int> myptr2 = VSPointer<int>::New();
    myptr2 = myPtr;
    gc->printElements();

    //Test#5
    cout << "Test #5:" << endl;
    myPtr = 6;
    gc->printElements();

}

int main()
{

    //printTests();

    //Test#6
    //cout << "Test #6:" << endl;
    //gc->printElements();

    if(true){
        VSPointer<int> myPtr = VSPointer<int>::New( );
        *myPtr = 555;

        VSPointer<int> myPtr1 = VSPointer<int>::New( );
        myPtr1 = myPtr;

        VSPointer<int> myPtr5 = VSPointer<int>::New( );
        myPtr5 = myPtr;

        VSPointer<int> myPtr6 = VSPointer<int>::New( );
        myPtr6 = myPtr;

        VSPointer<int> myPtr7 = VSPointer<int>::New( );
        myPtr7 = myPtr6;

        VSPointer<int> myPtr8 = VSPointer<int>::New( );
        myPtr8 = myPtr5;

        VSPointer<int> myPtr9 = VSPointer<int>::New( );
        myPtr9 = myPtr7;


        VSPointer<int> myPtr3 = VSPointer<int>::New( );
        *myPtr3 = 1515;

        gc->printElements();

        myPtr = myPtr3;

        gc->printElements();

    }

    gc->printElements();
    //cout << "hola" << endl;
    return 0;
}
