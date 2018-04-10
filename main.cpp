#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <deque>
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
    clock_t t1, t2, t3, t4, t5;
    t1 = clock();
    generuojamSimta();
    t2 = clock();
    nuskaitytiSimta();
    t3 = clock();
    isskirtyti();
    t4 = clock();
    spausdintiVargSaun();
    t5 = clock();

    float laikasGeneravimo = (float)t2-(float)t1;
    float laikasNuskaitymo = (float)t3-(float)t2;
    float laikasIsskirtyti = (float)t4-(float)t3;
    float laikasSpausdinti = (float)t5-(float)t4;
    laikasGeneravimo = laikasGeneravimo / CLOCKS_PER_SEC;
    laikasNuskaitymo = laikasNuskaitymo / CLOCKS_PER_SEC;
    laikasIsskirtyti = laikasIsskirtyti / CLOCKS_PER_SEC;
    laikasSpausdinti = laikasSpausdinti / CLOCKS_PER_SEC;
    std::cout << laikasGeneravimo << " - sekundziu sugeneruoti failus"<< std::endl;
    std::cout << laikasNuskaitymo << " - sekundziu nuskaityti failus"<< std::endl;
    std::cout << laikasIsskirtyti << " - sekundziu isskirtyti i vargsiukus ir saunuolius"<< std::endl;
    std::cout << laikasSpausdinti << " - sekundziu atspausdinti"<< std::endl;



    return 0;
}
