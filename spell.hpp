#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>


using namespace std;

class spell
{
      private:
              string idnr;
              string name;
              int basedamage;
              int r[2];      //rand()%3-1 = rand%r[0]-r[1]
              //bool healme;
              //int healvalue;
              int hitchance;
      public:
             spell();       //contructor
             void setidnr(string import);
             void setname(string import);
             void setbasedamage(int import);
             void setr(int import1, int import2);
             //void sethealme(bool import);
             //void sethealvalue(int import);
             void sethitchance(int import);
             
};
#endif
