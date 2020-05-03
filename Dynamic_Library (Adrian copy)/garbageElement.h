//
// Created by heutlett on 3/5/20.
//

#ifndef DYNAMIC_LIBRARY_GARBAGEELEMENT_H
#define DYNAMIC_LIBRARY_GARBAGEELEMENT_H

class garbageElement{

public:

    void** address;
    int count;

    garbageElement(void ** newAddress){

        address = newAddress;
        count = 0;

    }

    void increaseCount(){

        count++;

    }

};

#endif //DYNAMIC_LIBRARY_GARBAGEELEMENT_H
