#ifndef DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
#define DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H

#include <vector>
#include "../Data Structures/List.h"
#include "VSPtr.h"



using namespace std;

template<class T>
class garbageCollector {
public:
    int lastId;
    int getLastId();
    void addElement(garbageElement<T>);

    /* Static access method. */
    static garbageCollector *getInstance();


private:
    /* Here will be the instance stored. */
    static garbageCollector *instance;

    /* Private constructor to prevent instancing. */
    garbageCollector() {
        lastId = 0;
    }
    static LinkedList<garbageElement<T>> list;




};

#endif