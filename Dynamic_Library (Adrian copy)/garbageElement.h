//
// Created by heutlett on 3/5/20.
//

#ifndef DYNAMIC_LIBRARY_GARBAGEELEMENT_H
#define DYNAMIC_LIBRARY_GARBAGEELEMENT_H

#include <string>
using namespace std;

//template <class T>
class garbageElement{

public:

    void* ptrData;
    void* vsptrAdress;
    int quantity = 0;
    string id;
    string type;

    /**
     *
     * @param dataPtr
     * @param pType
     * @param pId
     * @param pVsptrAdress
     */
    garbageElement(void * dataPtr, string pType, string pId, void* pVsptrAdress){
        ptrData = dataPtr;
        type = pType;
        id = pId;
        vsptrAdress = pVsptrAdress;
        cout << "GarbageElement has been created, VSPointerAddress: " << vsptrAdress << ", Value: " << getValue() << ", refTo: " << ptrData << endl;
    }
    /**
     * Returns the value of the pointer in string
     * @return string
     */
    string getValue(){

        if(type.compare("i")==0){
            return to_string(*static_cast<int *>(ptrData));
        }
        if(type.compare("b")==0){
            return to_string(*static_cast<bool *>(ptrData));
        }
        if(type.compare("c")==0){
            string s(1, *static_cast<char *>(ptrData));
            return s;
        }
        if(type.compare("s")==0){
            return to_string(*static_cast<short *>(ptrData));
        }
        if(type.compare("l")==0){
            return to_string(*static_cast<long *>(ptrData));
        }
        if(type.compare("x")==0){
            return to_string(*static_cast<long long *>(ptrData));
        }
        if(type.compare("f")==0){
            return to_string(*static_cast<float *>(ptrData));
        }
        if(type.compare("d")==0){
            return to_string(*static_cast<double *>(ptrData));
        }
        if(type.compare("e")==0){
            return to_string(*static_cast<long double *>(ptrData));
        }
    }
    /**
     * Return de memory address of the pointer
     * @return void**
     */
    void ** getAddress(){
        return static_cast<void **>(ptrData);
    }
};

#endif //DYNAMIC_LIBRARY_GARBAGEELEMENT_H
