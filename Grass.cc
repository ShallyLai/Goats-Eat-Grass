#include "Grass.h"
#include <iostream>
using namespace std;

Grass::Grass(){
    
}

char Grass::getdata(){
    return 'I';
}

bool Grass::bornbaby_age(){
    if(getAge() >= 3 && getAge() <=5)
        return true;
    else
        return false;
}

bool Grass::die(){
    if(getAge() >= 6)
        return true;
    else
        return false;
}
