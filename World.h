#ifndef WORLD_H
#define WORLD_H

#include "RandomNum.h"
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"

class World{
    public:
        World(int, int);
        ~World(){};
        void mainLoop(int);
        void showfield();
        void creature_disappear(int, int);
        void FindPlace(int, int);
        bool correct_position(int, int);
        void reset();
    private:
        Creature *field[20][35];
        int total_pass_num;
        int step;
        int find_x;
        int find_y;
};

#endif // WORLD_H
