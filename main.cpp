#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

#include "character.hpp"
#include "spell.hpp"
#include "alctools.hpp"
#include "combathandler.hpp"
#include "characterloader.hpp"

int startmenu();
void DemoMenu();
void fighters(character enemy1, character player1);
int spellhandler(int bd, int r1, int r2);
int turn(int speed1, int speed2);
void combatmessage(string attacker, string attacked, string spellname, int damage);
bool isnumber(string number);
int stringtonumber(string number);
//character[] figherloader(character[]);

void fighthandler(character player1, character enemy1);

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    int mode = 0;
    
    DemoMenu();
    cin >> mode;
    if(mode == 2)
    {
            return 0;
    }
    
    
    character player[6];
    characterloader loader;
    //player[0].setname("Henrik");
    //player[0].setmaxhp(1337);
    //player[0].setchp("+", 9000);
    
    loader.readchars();     //reads chars from file
    for(int a=0; a < 6; a++)
    {
            player[a] = loader.getchars(a);    //gets characters from loader's memory
    }
    
    character enemy1;
    enemy1.setname("Bobeck");
    enemy1.setmaxhp(1000);
    enemy1.setchp("+", 9000);
    
    fighthandler(player[0], enemy1);
    
    for(int a=0; a < 6; a++)
    {
            loader.loadchars(player[a], a);
    }
    loader.writechars();
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


int startmenu()
{
    int number = 0;
    while(number != 1 && number != 2 && number != 3)
    {
                 string temp;
                 cout << "Options" << endl;
                 cout << "1: Continue" <<endl;
                 cout << "2: New Game" <<endl;
                 cout << "3: Exit Game" <<endl;
                 cout << "Number: ";
                 cin >> temp;
                 
                 if(isnumber(temp))
                 {
                                   number = stringtonumber(temp);
                 }
                 system("cls");
    }
}
void DemoMenu()
{
          cout << "1: Test Battle" << endl;
          cout << "2: Exit" << endl;
          cout << "Choose: ";
}

void fighters(character enemy1, character player1)
{
     system("cls");
     enemy1.display();
     cout << endl << endl << endl << endl << endl << endl << endl << endl;
     
     player1.display();
     cout <<endl;
}


int spellhandler(int bd, int r1, int r2)
{
    /*int temp;
    temp = rand()%r1+r2;
    temp += bd;*/
    return bd + (rand()%r1+r2);
}


int turn(int speed1, int speed2)
{
    int total = speed1 + speed2;
    int turn = rand()%total+1;
    if(turn > 0 && turn <= speed1)
    {
            return 1;
    }
    else
    {
        return 0;
    }
    
}


void combatmessage(string attacker, string attacked, string spellname, int damage)
{
     cout << attacker << " used " << spellname << " for " << damage << " damage on " << attacked << "." << endl;
     system("PAUSE");
}


bool isnumber(string number)
{
     bool a = true;
     string temp;
     for(int b=0;b < number.length(); b++)
     {
             temp = number.at(b);
             if( temp == "0" || temp == "1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8" || temp == "9")
             {
                     
             }
             else
             {
                 a = false;  //false if it is not a number
             }
     }
     return a;
}


int stringtonumber(string number)
{
    return atoi(number.c_str());
}


/*character[] figherloader(character player[])
{*/
void fighthandler(character player1, character enemy1)     
{
     int damage;
     
     while(enemy1.gethp() != 0 && player1.gethp() != 0)
     {
            
            //system("PAUSE");
            int attack = 0;
            
            while(attack != 1)
            {
                   fighters(enemy1, player1);
                   player1.moves();
                   cout << "Attack: ";
                   string temp;
                   cin >> temp;
                   if(isnumber(temp))
                   {
                              attack = stringtonumber(temp);
                   }
            }
            if(turn(50, 50) == 1)      //if = player1s turn first, else enemy1 first
            {
                        damage = spellhandler(100, 95, 5);
                        enemy1.setchp("-", damage);
                        fighters(enemy1, player1);
                        combatmessage(player1.getname(), enemy1.getname(), "Slash", damage);
                        
                        if(enemy1.gethp() != 0)
                        {
                                          damage = spellhandler(100, 95, 5);
                                          player1.setchp("-", damage);
                                          fighters(enemy1, player1);
                                          combatmessage(enemy1.getname(), player1.getname(), "Slash", damage);
                        }
            }
            else
            {
                        damage = spellhandler(100, 95, 5);
                        player1.setchp("-", damage);
                        fighters(enemy1, player1);
                        combatmessage(enemy1.getname(), player1.getname(), "Slash", damage);
                        
                        if(player1.gethp() != 0)
                        {
                                           damage = spellhandler(100, 95, 5);
                                           enemy1.setchp("-", damage);
                                           fighters(enemy1, player1);
                                           combatmessage(player1.getname(), enemy1.getname(), "Slash", damage);
                        }
            }
            if(enemy1.gethp() == 0)
            {
                              fighters(enemy1, player1);
                              cout << enemy1.getname() << " has been killed!" << endl;
            }
            if(player1.gethp() == 0)
            {
                             fighters(enemy1, player1);
                             cout << player1.getname() << " has been killed!" << endl;
     }
     }
}
