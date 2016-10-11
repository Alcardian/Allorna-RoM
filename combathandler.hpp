#ifndef COMBATHANDLER_HPP
#define COMBATHANDLER_HPP

#include "character.hpp"
#include "alctools.hpp"

class combathandler
{
      private:
             character player[6];
             character enemy[6];
             void teamdisplay(character player, character enemy);
             int turn(int speed1, int speed2);
      public:
             void start(character player1, character enemy1);
};
#endif
