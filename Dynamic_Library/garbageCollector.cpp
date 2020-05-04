//
// Created by brayanrv on 3/5/20.
//
#include "garbageCollector.h"
garbageCollector* garbageCollector::instance = 0;

garbageCollector* garbageCollector::getInstance(){
    if (instance == 0){
        static garbageCollector<T> instance;
        return &instance;
    }

    return instance;
}

garbageCollector* garbageCollector::addElement(garbageElement) {
    list.add(garbageElement);
}
garbageCollector* garbageCollector::getLastId(){
    return lastId;
}