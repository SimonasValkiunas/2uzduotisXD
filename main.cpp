#include <iostream>
#include <vector>
#include <time.h>
#include "funkcijos.h"


std::vector<int> pazymiai;
std::vector<studentas> s;
std::vector<studentas> vargsiukai;
std::vector<studentas> saunuoliai;

int main()
{
    clock_t t1, t2;
    t1 = clock();
    generuojamSimta();
    nuskaitytiSimta();
    spausdinti();
    isskirtyti();
    spausdintiVargSaun();
    t2 = clock();

    float laikas = (float)t2-(float)t1;
    laikas = laikas / CLOCKS_PER_SEC;
    std::cout << laikas << " - sekundziu"<< std::endl;



    return 0;
}
