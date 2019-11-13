#include "Miner.h"
#include "Game_Command.h"
#include <cmath>
#include "Cart_Point.h"
#include <iostream>
#include <iomanip>
#include "Input_Handling.h"
#include <exception>


void do_new_command(Model& model, char type, int object, double x, double y)

{

    model.handle_new_command(type, object, x, y);
}

void do_move_command (Model& model, View& view, int id, double x, double y)

{

    Person * ptr = model.get_Person_ptr(id);

   if (ptr == 0)

    throw Invalid_Input("Incorrect Object ID");

	else

  {
		ptr->start_moving(Cart_Point(x,y));
    model.display(view);
  }

}



//Makes miners work

void do_work_command(Model& model, View& view, int id1, int id2, int id3)
{
  

    Gold_Mine* mine = model.get_Gold_Mine_ptr(id2);
    Town_Hall* home = model.get_Town_Hall_ptr(id3);
    Person* miner = model.get_Person_ptr(id1);



    if(id1==1 ||id1==2 && id2==1 || id2==2 && id3==1)
    		{
    			
    			Person * m= model.get_Person_ptr(id1); //Casting

    			static_cast<Miner*>(m)->start_mining((model.get_Gold_Mine_ptr(id2)),(model.get_Town_Hall_ptr(id3)));
    			model.display(view);

        }

    	else if(id1==3||id1==4 && id2==1 || id2==2  && id3==1)

        {
    			model.get_Person_ptr(id1)->start_mining();
    			model.display(view);
    		}

  else if (miner == 0 || mine == 0 || home == 0)

    throw Invalid_Input("Incorrect Object ID");


}



void do_stop_command (Model& model,View& view, int id) //Makes miner stop working

{

  Person *ptr = model.get_Person_ptr(id);
	if (ptr == 0)
		throw Invalid_Input("Invalid ID entered.");

  else
		ptr->stop();
    model.display(view);
}




bool do_go_command(Model& model, View& view) //Updates 

{

    cout << "Advancing one tick." << endl;
    bool change = model.update();
    model.show_status();
    model.display(view);
    return change;

}


void do_run_command(Model& model, View& view)

{
    cout << "Advancing to next event" << endl;
    int count = 0;
    bool del = false;

    do {
        del = model.update();
        count++;
    }
      while (!del && count < 5);
      model.show_status();
      model.display(view);
}


void do_list_command (Model& model, View& view)

{
    model.show_status();
    model.display(view);
}

void do_attack_command(Model & model, int attackid, int targetid) //attacks
{

	Person *attacker_ptr = model.get_Person_ptr(attackid);

	if (attacker_ptr == 0)
	 throw Invalid_Input("Incorrect Object ID for attacker");

	else
 {
		Person *target_ptr = model.get_Person_ptr(targetid);
    if (target_ptr == 0)
         throw Invalid_Input("Incorrect Object ID for target.");

    else
		  attacker_ptr->start_attack(target_ptr);
	}
}
