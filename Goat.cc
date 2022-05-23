#include <iostream>
#include "Goat.h"
using namespace std;

Goat::Goat(){
    life_point = 20;
}

char Goat::getdata(){
    return 'X';
}

bool Goat::bornbaby_age(){
    if(getAge() <= 55 && getAge() >=50)
        return true;
    else
        return false;
}

bool Goat::die(){
    if(getAge() >= 70 || life_point <= 0)
        return true;
    else
        return false;
}

void Goat::eat_grass(){
    life_point += 5;
}

void Goat::delete_point(){
    life_point--;
}
