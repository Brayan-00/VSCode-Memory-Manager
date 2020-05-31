//
// Created by heutlett on 31/5/20.
//


#ifndef VSPTR_DYNAMICLIBRARY_LIBRARY_H __attribute__((visibility("default")));
#define VSPTR_DYNAMICLIBRARY_LIBRARY_H

//#include "garbageCollector.h"


extern "C"{

    int Subtract(int, int);
    int Add(int, int);
    int cambia(int);
    int get(int);

}

#endif //VSPTR_DYNAMICLIBRARY_LIBRARY_H
