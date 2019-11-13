#ifndef Town_Hall_hpp
#define Town_Hall_hpp
#include "Cart_Point.h"
#include "Game_Object.h"

class Town_Hall:public Game_Object
{

public:
    Town_Hall();
    Town_Hall(int, Cart_Point);
    ~Town_Hall();


    void deposit_gold(double);
    bool update();
    void show_status();

private:

    int id_num;
    double amount;

};

#endif
