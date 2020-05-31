#include <iostream>
#include "lib/library.h"
#include "lib/person.h"

using namespace std;

//target_link_libraries(project ${CMAKE_SOURCE_DIR}/lib/libVSPtr_DynamicLibrary)


int main(){

    cout << "Hola casa";
    
     
    std::cout << VSPTR_DYNAMICLIBRARY_LIBRARY_H::CountPeople() << std::endl;
    person *p1 = new person(1,2);
    person *p2 = new person(3,4);
    std::cout << VSPTR_DYNAMICLIBRARY_LIBRARY_H::CountPeople() << std::endl;
    delete(p1);
    delete(p2);
    std::cout << VSPTR_DYNAMICLIBRARY_LIBRARY_H::CountPeople() << std::endl;
    //char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
    //Array<char> a(arr, 5);
    //a.print();
    //return 0;
    //vsp
    return 0;

}