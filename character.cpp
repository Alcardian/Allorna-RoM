#include "character.hpp"

//#include <string>

//using namespace std;

character::character()
{
     hp[0] = 0;
     hp[1] = 0;
     name = "";
     type = "none";
     spell[0] = "0000";
     spell[1] = "0000";
     spell[2] = "0000";
     spell[3] = "0000";
}


void character::display()
{
     cout << name << "--[lvl:01]--[" << hp[0] << "/" << hp[1] << "]" <<endl;
}


void character::setspell(string spell1, string spell2, string spell3, string spell4)
{
     spell[0] = spell1;
     spell[1] = spell2;
     spell[2] = spell3;
     spell[3] = spell4;
}
     

void character::setname(string text)
{
     name = text;
}


void character::setmaxhp(int number)
{
     hp[1] = number;
}


void character::setchp(string op, int number)
{
     if(op == "+")
     {
           hp[0] += number;
           if(hp[0] > hp[1])
           {
                    hp[0] = hp[1];
           }
     }
     else if(op == "full")
     {
          hp[0] == hp[1];
     }
     else if(op == "-")
     {
          hp[0] -= number;
          if(hp[0] < 0)
          {
                   hp[0] = 0;
          }
          
     }
}


int character::getmaxhp()
{
    return hp[1];
}
int character::gethp()
{
    return hp[0];
}


string character::getname()
{
       return name;
}
void character::moves()
{
     cout << "1: Slash" << endl;
     cout << "2: --" << endl;
     cout << "3: --" << endl;
     cout << "4: --" << endl;
}


void character::items()
{
     //coming soon!
}


void character::change()
{
     //coming soon!
}


void character::flee()
{
     //coming soon!
}


void move(int number)
{
     if(number == 1)
     {
               
     }
}

