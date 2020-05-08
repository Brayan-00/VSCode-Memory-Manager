//
// Created by heutlett on 3/5/20.
//

#ifndef DYNAMIC_LIBRARY_GARBAGEELEMENT_H
#define DYNAMIC_LIBRARY_GARBAGEELEMENT_H

#include <string>
using namespace std;


//template <class T>
class garbageElement{

private:
        char * charPtr = nullptr;
        short * shortPtr = nullptr;
        int * intPtr = nullptr;
        long * longPtr = nullptr;
        long long * longlongptr = nullptr;
        float * floatPtr = nullptr;
        double * doublePtr = nullptr;
        long double * longdoublePtr = nullptr;
        bool * boolPtr = nullptr;
        //void * voidptr = nullptr;

        string getDataValue(string type){

            if(type.compare("c")==0){
                string s(1, *charPtr);
                return s;
            }

            if(type.compare("s")==0){

                return to_string(*shortPtr);

            }

            if(type.compare("i")==0){

                return to_string(*intPtr);

            }

            if(type.compare("l")==0){

                return to_string(*longPtr);

            }

            if(type.compare("x")==0){

                return to_string(*longlongptr);

            }

            if(type.compare("f")==0){

                return to_string(*floatPtr);

            }

            if(type.compare("d")==0){

                return to_string(*doublePtr);

            }

            if(type.compare("e")==0){

                return to_string(*longdoublePtr);

            }

            if(type.compare("b")==0){

                return to_string(*boolPtr);

            }
        }

        void** getData(string type){

            if(type.compare("c")==0){

                return reinterpret_cast<void**>(charPtr);

            }

            if(type.compare("s")==0){

                return reinterpret_cast<void**>(shortPtr);

            }

            if(type.compare("i")==0){

                return reinterpret_cast<void**>(intPtr);

            }

            if(type.compare("l")==0){

                return reinterpret_cast<void**>(longPtr);

            }

            if(type.compare("x")==0){

                return reinterpret_cast<void**>(longlongptr);

            }

            if(type.compare("f")==0){

                return reinterpret_cast<void**>(floatPtr);

            }

            if(type.compare("d")==0){

                return reinterpret_cast<void**>(doublePtr);

            }

            if(type.compare("e")==0){

                return reinterpret_cast<void**>(longdoublePtr);

            }

            if(type.compare("b")==0){

                return reinterpret_cast<void**>(boolPtr);

            }
        }

public:

    void* vsptrAdress;
    int quantity = 0;
    string id;
    string type;

    void initPtr(void * dataPtr){

        if(type.compare("i")==0){

            intPtr = static_cast<int *>(dataPtr);
            cout << "GarbageElement has been created, VSPointerAddress: " << vsptrAdress << ", Value: " << *intPtr << ", refTo: " << intPtr << endl;

        }

        if(type.compare("c")==0){

            charPtr = static_cast<char *>(dataPtr);
            cout << "GarbageElement has been created, VSPointerAddress: " << vsptrAdress << ", Value: " << *charPtr << ", refTo: " << charPtr << endl;

        }

        if(type.compare("b")==0){

            boolPtr = static_cast<bool *>(dataPtr);
            cout << "GarbageElement has been created, VSPointerAddress: " << vsptrAdress << ", Value: " << *boolPtr << ", refTo: " << boolPtr << endl;

        }

    }
    /**
     * 
     * @param dataPtr
     * @param pType
     * @param pId
     * @param pVsptrAdress
     */
    garbageElement(void * dataPtr, string pType, string pId, void* pVsptrAdress){

        type = pType;
        id = pId;
        vsptrAdress = pVsptrAdress;
        initPtr(dataPtr);
    }

    /**
     * Returns the value of the pointer in string
     * @return string
     */
    string getValue(){
        return getDataValue(type);
    }
    /**
     * Return de memory address of the pointer
     * @return void**
     */
    void ** getAddress(){
        return getData(type);
    }

};

#endif //DYNAMIC_LIBRARY_GARBAGEELEMENT_H
