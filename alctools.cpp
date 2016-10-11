#include "alctools.hpp"

bool alctools::isnumber(string number)
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


int alctools::stringtonumber(string number)
{
    return atoi(number.c_str());
}
