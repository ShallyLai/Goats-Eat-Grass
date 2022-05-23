#ifndef GRASS_H
#define GRASS_H

#include "Creature.h"

class Grass:public Creature{
    public:
        Grass();
        ~Grass(){};
        virtual char getdata();
        virtual bool bornbaby_age();
        virtual bool die();
};

#endif // GRASS_H
