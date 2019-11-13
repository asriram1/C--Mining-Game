#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Cart_Point.h"
#include "Cart_Vector.h"

class Game_Object

{
   public:

    Game_Object(char, int);
    Game_Object(char, int, Cart_Point);

    virtual ~Game_Object();

    Cart_Point get_location();
    virtual bool is_alive();
    virtual int get_id();
    virtual void show_status();
    virtual bool update() = 0; 
    void drawself(char*);

protected:

    Cart_Point location;
    char display_code;
    char state;

private:
    int id_num;
};



#endif
