#ifndef GOAT_H
#define GOAT_H

#include "Creature.h"

class Goat:public Creature{
    public:
        Goat();
        ~Goat(){};
        virtual char getdata();
        virtual bool bornbaby_age();
        virtual bool die();
        virtual void eat_grass();
        virtual void delete_point();
    private:
        int life_point;
};

#endif // GOAT_H
