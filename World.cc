#include <iostream>
#include <cstdlib>
#include "World.h"
using namespace std;

World::World(int numPasses, int seed){
    srand(seed);
    total_pass_num = numPasses;
    step = 0;
    for(int a=0;a<20;a++){
        for(int b=0;b<35;b++){
            field[a][b] = NULL;
        }
    }
    for(int a=0;a<5;a++){//born goats
        int x = rand() % 20;
        int y = rand() % 35;
        if(field[x][y] == NULL){
            field[x][y] = new Goat();
            field[x][y] -> age_increase();
        }
        else
            a--;
    }
    for(int a=0;a<10;a++){//grow grass
        int x = rand() % 20;
        int y = rand() % 35;
        if(field[x][y] == NULL){
            field[x][y] = new Grass();
            field[x][y] -> age_increase();
        }
        else
            a--;
    }
    showfield();
}

void World::mainLoop(int displayInterval){
    while(step < total_pass_num){
        reset();//reset the world(let new born creatures can act)
        for(int a=0;a<20;a++){
            for(int b=0;b<35;b++){
                if(field[a][b] != NULL && field[a][b] -> getAge() >= 0 && field[a][b] -> getHadMove() == false){//can move or born baby
                    field[a][b] -> age_increase();//one year older
                    FindPlace(a, b);//find position that creature can do sth
                    if(field[a][b] -> getdata() == 'X'){//goat
                        field[a][b] -> delete_point();//delete one point
                        if(field[a][b] -> bornbaby_age() == true){
                            if(correct_position(find_x, find_y) == true && field[find_x][find_y] == NULL){//only born baby
                                field[find_x][find_y] = new Goat();
                            }
                            else if(correct_position(find_x, find_y) == true && field[find_x][find_y] -> getdata() == 'I'){//eat grass and born baby
                                field[a][b] -> eat_grass();
                                creature_disappear(find_x, find_y);//the grass was eaten by goat
                                field[find_x][find_y] = new Goat();
                            }
                        }
                        else{
                            if(correct_position(find_x, find_y) == true && field[find_x][find_y] == NULL){//only move
                                field[find_x][find_y] = field[a][b];
                                field[a][b] = NULL;
                                field[find_x][find_y] -> HadMove();//mark that this creature has moved
                            }
                            else if(correct_position(find_x, find_y) == true && field[find_x][find_y] -> getdata() == 'I'){//eat grass and move
                                field[a][b] -> eat_grass();
                                creature_disappear(find_x, find_y);//the grass was eaten by goat
                                field[find_x][find_y] = field[a][b];
                                field[a][b] = NULL;
                                field[find_x][find_y] -> HadMove();//mark that this creature has moved
                            }
                        }
                    }
                    else if(field[a][b] -> getdata() == 'I'){//grass
                        if(field[a][b] -> bornbaby_age() == true){
                            if(correct_position(find_x, find_y) == true && field[find_x][find_y] == NULL){
                                field[find_x][find_y] = new Grass();
                            }
                        }
                    }
                }
            }
        }
        if(step % displayInterval == 0 && step != 0)
            showfield();
        step++;
    }
}

void World::showfield(){
    cout << "  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << endl;
    for(int a=0;a<20;a++){
        cout << (a % 10);
        for(int b=0;b<35;b++){
            if(field[a][b] != NULL){
                cout << ' ' << field[a][b] -> getdata();
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
}

void World::creature_disappear(int x, int y){
    delete field[x][y];
    field[x][y] = NULL;
}

void World::FindPlace(int a, int b){
    int dir = rand() % 4;
    switch(dir){
        case 0://up
            find_x = a;
            find_y = b - 1;
            break;
        case 1://down
            find_x = a;
            find_y = b + 1;
            break;
        case 2://left
            find_x = a - 1;
            find_y = b;
            break;
        case 3://right
            find_x = a + 1;
            find_y = b;
            break;
    }
}

bool World::correct_position(int x, int y){
    if(x >= 0 && x < 20 && y >= 0 && y < 35)
        return true;
    else
        return false;
}

void World::reset(){
    for(int a=0;a<20;a++){
        for(int b=0;b<35;b++){
            if(field[a][b] != NULL){
                field[a][b] -> reset_GetHadMove();//let creature can act in next pass
                if(field[a][b] -> getAge() == -1)
                    field[a][b] -> age_increase();//let the new born creature can act
                if(field[a][b] -> die() == true)
                    creature_disappear(a, b);//kill the old creature
            }
        }
    }
}
