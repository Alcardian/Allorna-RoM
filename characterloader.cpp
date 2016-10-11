#include "characterloader.hpp"


characterloader::characterloader()
{
     //no need for this atm
}


void characterloader::readchars()
{
     ifstream read;
     read.open("characters.txt");
     if(read)
     {
             string stringtemp = "";
             string buffer;
             int inttemp = 0; int inttemp2 = 0;
             cin.ignore(1000, '\n');
             alctools tool;
             while(getline(read, buffer))
             {
                                 stringtemp = "";
                                 for(int a=0; a < buffer.find("%"); a++)
                                 {
                                         stringtemp += buffer.at(a);
                                 }
                                 player[inttemp].setname(stringtemp);
                                 
                                 stringtemp = "";
                                 for(size_t a=buffer.find("%") + 1; a < buffer.length(); a++)
                                 {
                                            stringtemp += buffer.at(a);
                                 }
                                 if(tool.isnumber(stringtemp))
                                 {
                                            inttemp2 = tool.stringtonumber(stringtemp);
                                 }
                                 player[inttemp].setmaxhp(inttemp2);
                                 player[inttemp].setchp("+", inttemp2);
                                 inttemp++;
                                
            }
            read.close();
    }
}


void characterloader::writechars()
{
     ofstream write;
     write.open("characters.txt");
     if(write)
     {
              for(int a=0; a < 6; a++)
              {
                      write << player[a].getname() << "%" << player[a].getmaxhp() << "\n";
              }
     }
}


void characterloader::loadchars(character temp, int number)
{
     player[number].setname(temp.getname());
     player[number].setmaxhp(temp.getmaxhp());
}


character characterloader::getchars(int number)
{
    return player[number];
}
