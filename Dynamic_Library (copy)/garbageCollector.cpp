//
// Created by heutlett on 2/5/20.
//

#include "garbageCollector.h"

/* Null, because instance will be initialized on demand. */
garbageCollector* garbageCollector::instance = 0;

garbageCollector* garbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new garbageCollector();
    }

    return instance;
}

garbageCollector::garbageCollector()
{

    counter = 0;

}
void garbageCollector::increaseCounter() {

    counter++;

}