#include "Gold_Mine.h"

Gold_Mine::Gold_Mine():Game_Object('G',0) //Constructor

{
   id_num = 0;
   state = 'f';
   amount = 100.0;
   cout << "Gold_Mine default constructed" << endl;
}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc)//Constructor

{

   state = 'f';
   amount = 100.0;
   id_num = inputId;
   location = inputLoc;
   cout << "Gold_Mine constructed" << endl;

}

Gold_Mine::~Gold_Mine()

{
   cout << "Gold_Mine destructed" << endl;

}

bool Gold_Mine::is_empty()
{
 if (amount == 0)
 {
   return true;
 }
 else {
   return false;
      }
}

double Gold_Mine::dig_gold(double amount_to_dig = 35.0) //digs gold
{
   if (amount >= amount_to_dig)
   {
       amount -= amount_to_dig;
       return amount_to_dig;
   }

else

   {
       double temp = amount;
       amount = 0;
       return temp;
   }
}

bool Gold_Mine::update()//Update function
{
   if(is_empty() && state!= 'e')
   {
       state = 'e';
       display_code = 'g';
       cout << "Gold_Mine " << id_num << " has been depleted."<<endl;
       return true;
   }
   else
       return false;
}

void Gold_Mine::show_status()
{
   cout << "Gold Mine Status: ";
   cout << display_code << id_num << " at location " << location;
   cout << setprecision(5);
   cout << " Contains " << amount << "." <<endl;

}
