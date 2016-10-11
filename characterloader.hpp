#ifndef CHARACTERLOADER_HPP
#define CHARACTERLOADER_HPP

#include <iostream>
#include <fstream>

#include "character.hpp"
#include "alctools.hpp"

using namespace std;

class characterloader
{
      private:
              character player[6];
      public:
             characterloader();
             void readchars();    //reads characters from file
             void writechars();   //writes characters from file
             void loadchars(character temp, int number);   //loads a character so it can be written to file
             character getchars(int number);    //gets/imports 1 character
};
#endif
