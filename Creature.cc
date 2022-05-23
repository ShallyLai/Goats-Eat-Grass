#include <iostream>
#include "Creature.h"
using namespace std;

Creature::Creature(){
    age = -1;
    move = true;//the creature can't act in its first born pass
}

char Creature::getdata(){
    return ' ';
}

bool Creature::bornbaby_age(){
    return false;
}

int Creature::getAge(){
    return age;
}

bool Creature::die(){
    return false;
}

void Creature::age_increase(){
    age++;
}

void Creature::HadMove(){
    move = true;
}

bool Creature::getHadMove(){
    return move;
}

void Creature::reset_GetHadMove(){
    move = false;
}
