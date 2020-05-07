//
// Created by heutlett on 3/5/20.
//

#ifndef DYNAMIC_LIBRARY_GARBAGEELEMENT_H
#define DYNAMIC_LIBRARY_GARBAGEELEMENT_H

#include <string>
using namespace std;

class garbageElement{

public:

    void** address;
    void** vsptrAdress;
    int quantity = 1;
    string id;
    string type;
    string value;


    garbageElement(void ** newAddress, string pType, string pId, void** pVsptrAdress){

        address = newAddress;

        type = pType;

        id = pId;

        vsptrAdress = pVsptrAdress;

        //cout << "Se ha creado el garbage element: " << newAddress << endl;

    }


};

#endif //DYNAMIC_LIBRARY_GARBAGEELEMENT_H
