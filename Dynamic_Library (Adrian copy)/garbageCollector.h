#ifndef DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H
#define DYNAMIC_LIBRARY_GARBAGECOLLECTOR_H

#include <vector>

using namespace std;

class garbageCollector {



    private:
        /* Here will be the instance stored. */
        static garbageCollector* instance;

        /* Private constructor to prevent instancing. */
        garbageCollector(){
        }

    public:

        vector<void**> * adressList = new vector<void**>;
        /* Static access method. */
        static int counter;

        static garbageCollector* getInstance();

        void increaseCounter() {

            counter++;

        }


};

garbageCollector* garbageCollector::instance = 0;

garbageCollector* garbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new garbageCollector();
    }

    return instance;
}


#endif