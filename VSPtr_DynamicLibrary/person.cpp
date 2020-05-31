//
// Created by heutlett on 31/5/20.
//

#include <iostream>
#include "person.h"

int person::size = 0;

person::person(int id, int otherId)
{
    this->id = id;
    this->otherId = otherId;
    person::size++;
};
person::~person() {
    person::size--;
}