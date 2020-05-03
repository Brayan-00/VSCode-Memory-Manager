//
// Created by heutlett on 2/5/20.
//

#ifndef DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
#define DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H


class garbageCollector {

    private:
        /* Here will be the instance stored. */
        static garbageCollector* instance;

        /* Private constructor to prevent instancing. */
        garbageCollector();

    public:
        /* Static access method. */
        static garbageCollector* getInstance();
        static int counter;
        static void increaseCounter();


};


#endif //DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
