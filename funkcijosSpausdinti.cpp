#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <deque>
#include <iomanip>


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


void spausdintiVargSaun()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<vargsiukai.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].vardas;
        std::cout<<std::setprecision(3)<<vargsiukai[i].galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<saunuoliai.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<saunuoliai[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<saunuoliai[i].vardas;
        std::cout<<std::setprecision(3)<<saunuoliai[i].galutinisVidurkis<<std::endl;
    }
}
void spausdintiVargSaun2()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<vargsiukai.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].vardas;
        std::cout<<std::setprecision(3)<<vargsiukai[i].galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<s.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<s[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<s[i].vardas;
        std::cout<<std::setprecision(3)<<s[i].galutinisVidurkis<<std::endl;
    }
}

void spausdintiVargSaunList()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (std::list<studentas>::const_iterator iterator =vargs.begin(), end=vargs.end(); iterator != end; ++iterator)
    {
        std::cout<<std::left<<std::setw(15)<<iterator->pavarde;
        std::cout<<std::left<<std::setw(15)<<iterator->vardas;
        std::cout<<std::setprecision(3)<<iterator->galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (std::list<studentas>::const_iterator iterator =saun.begin(), end=saun.end(); iterator != end; ++iterator)
    {
        std::cout<<std::left<<std::setw(15)<<iterator->pavarde;
        std::cout<<std::left<<std::setw(15)<<iterator->vardas;
        std::cout<<std::setprecision(3)<<iterator->galutinisVidurkis<<std::endl;
    }
}

void spausdintiVargSaunList2()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (std::list<studentas>::const_iterator iterator =vargs.begin(), end=vargs.end(); iterator != end; ++iterator)
    {
        std::cout<<std::left<<std::setw(15)<<iterator->pavarde;
        std::cout<<std::left<<std::setw(15)<<iterator->vardas;
        std::cout<<std::setprecision(3)<<iterator->galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (std::list<studentas>::const_iterator iterator =l.begin(), end=l.end(); iterator != end; ++iterator)
    {
        std::cout<<std::left<<std::setw(15)<<iterator->pavarde;
        std::cout<<std::left<<std::setw(15)<<iterator->vardas;
        std::cout<<std::setprecision(3)<<iterator->galutinisVidurkis<<std::endl;
    }
}

void spausdintiVargSaunDeque()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<vargsiuk.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<vargsiuk[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<vargsiuk[i].vardas;
        std::cout<<std::setprecision(3)<<vargsiuk[i].galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<d.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<saunuol[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<saunuol[i].vardas;
        std::cout<<std::setprecision(3)<<saunuol[i].galutinisVidurkis<<std::endl;
    }
}
void spausdintiVargSaunDeque2()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<vargsiuk.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<vargsiuk[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<vargsiuk[i].vardas;
        std::cout<<std::setprecision(3)<<vargsiuk[i].galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<d.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<d[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<d[i].vardas;
        std::cout<<std::setprecision(3)<<d[i].galutinisVidurkis<<std::endl;
    }
}
