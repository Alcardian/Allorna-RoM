#include "spell.hpp"
spell::spell()
{
       
}


void spell::setidnr(string import)
{
     idnr = import;
}


void spell::setname(string import)
{
     name = import;
}


void spell::setbasedamage(int import)
{
     basedamage = import;
}


void spell::setr(int import1, int import2)
{
     r[0] = import1;
     r[1] = import2;
}


void spell::sethitchance(int import)
{
     hitchance = import;
}

