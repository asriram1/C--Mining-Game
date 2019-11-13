#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include <iomanip>
#include <iostream>


using namespace std;

class Gold_Mine:public Game_Object{
public:
    Gold_Mine();
    Gold_Mine(int, Cart_Point);
    ~Gold_Mine();
    bool is_empty();
    double dig_gold(double);
    bool update();
    void show_status();


private:
    int id_num;
    double amount;

};

#endif
