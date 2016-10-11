#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>


using namespace std;

class character
{
      private:
              int hp[2];    //hp[0] = current   hp[1] = maxhp
              string spell[4]; //4 attacks
              string name;
              string type;
              
      public:
             character();   //constructor
             void display();     //example "MycharsName --[lvl:01]--[53/120hp]"
             void setspell(string spell1, string spell2, string spell3, string spell4);
             void setname(string text);
             void setmaxhp(int number);
             void setchp(string op, int number);        //chp = current hp
             int getmaxhp();
             int gethp();
             string getname();
             
             void moves();      //Displays all moves/spells you got
             void items();      //coming soon!
             void change();     //coming soon!
             void flee();       //coming soon!
             
             void move(int number);      //do move/spell number!

};
#endif
