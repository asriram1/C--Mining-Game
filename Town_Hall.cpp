#include "Town_Hall.h"
#include <iostream>
#include <iomanip>
using namespace std;


Town_Hall::Town_Hall():Game_Object('t',0) //Town_Hall constructor
{
    id_num = 0;
    state = 'o';
    amount = 0.0;
    cout << "Town_Hall defualt constructed." << endl;

}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc): Game_Object('t', inputId) //Town_Hall Constructor
{
    id_num = inputId;
    state = 'o';
    amount = 0.0;
    location = inputLoc;
    cout << "Town_Hall constructed" << endl;

}

Town_Hall::~Town_Hall() //Destructor
{
    cout << "Town_Hall destructed" << endl;
}



void Town_Hall::deposit_gold(double deposit_amount) 

{
    amount += deposit_amount;
}


bool Town_Hall::update()

{
    if (amount >= 50.0 && state!='u')

    {
        state = 'u';
        display_code = 'T';
        cout << "Town_Hall " << id_num << " has been upgraded."<<endl;
        return true;
    }
    else
    {
        return false;
    }

}



void Town_Hall::show_status() //Shows Status for Town Hall

{
    cout << "Town Hall status: ";
    cout << display_code << id_num << " at " << location;
    cout << " contains " << amount;
    cout << " of gold.";

    if (amount > 50.0)
    cout << " Upgraded." << endl;
    else
    cout << " Not yet upgraded. " << endl;
}
