#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>


#include "funkcijos.h"

extern std::vector<studentas> s;
extern std::vector<studentas> vargsiukai;
extern std::vector<studentas> saunuoliai;

extern std::list<studentas> l;
extern std::list<studentas> vargs;
extern std::list<studentas> saun;

extern std::deque<studentas> d;
extern std::deque<studentas> vargsiuk;
extern std::deque<studentas> saunuol;


void isskirtyti ()
{
    int studsize = s.size();
    for (int i=0; i<studsize; i++)
    {
        if(s[i].galutinisVidurkis < 5.0)
            {
                vargsiukai.push_back(s[i]);
            } else saunuoliai.push_back(s[i]);
    }
}
void isskirtyti2 ()
{

    for (int i=0; i<s.size(); i++)
    {
        if(s[i].galutinisVidurkis < 5.0)
            {
                vargsiukai.push_back(s[i]);
                s.erase(s.begin()+i);
                i--;
            }
    }
}


void isskirtytiList ()
{
    for (std::list<studentas>::const_iterator iterator =l.begin(), end=l.end(); iterator != end; ++iterator)
    {
        if(iterator->galutinisVidurkis < 5.0)
            {
                vargs.push_back(*iterator);
            } else saun.push_back(*iterator);
    }
}

void isskirtytiList2 ()
{



    for (std::list<studentas>::const_iterator iterator =l.begin(), end=l.end(); iterator != end; ++iterator)
    {
        if(iterator->galutinisVidurkis < 5.0)
            {
                vargs.push_back(*iterator);
                l.erase(iterator);
            }
    }

}

void isskirtytiDeque()
{
        int studsize = d.size();
    for (int i=0; i<studsize; i++)
    {
        if(d[i].galutinisVidurkis < 5.0)
            {
                vargsiuk.push_back(d[i]);
            } else saunuol.push_back(d[i]);
    }

}

void isskirtytiDeque2()
{

    for (int i=0; i < d.size(); i++)
    {
        if(d[i].galutinisVidurkis < 5.0)
            {
                vargsiuk.push_back(d[i]);
                d.erase(d.begin()+i);
                i--;
            }
    }

}
