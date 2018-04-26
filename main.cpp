#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>
#include <iomanip>
#include "funkcijos.h"


std::vector<int> pazymiai;

std::vector<studentas> s;
std::vector<studentas> vargsiukai;
std::vector<studentas> saunuoliai;

std::list<studentas> l;
std::list<studentas> vargs;
std::list<studentas> saun;

std::deque<studentas> d;
std::deque<studentas> vargsiuk;
std::deque<studentas> saunuol;

int main()
{


   clock_t t1, t2;
    generuojamSimta();
  t1 = clock();
   nuskaitytiSimta();
   isskirtyti2();
   t2 = clock();
   spausdintiVargSaun2();
   float laikas = (float)t2-(float)t1;
    laikas = laikas / CLOCKS_PER_SEC;
   std::cout <<std::setprecision(15)<< laikas << " - sekundziu"<< std::endl;
   std::cout <<s.size() << "  "<<vargsiukai.size()<< std::endl;


    return 0;
}
