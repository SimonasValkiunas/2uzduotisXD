#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <string.h>
#include <sstream>
#include <algorithm>
#include "funkcijos.h"

extern std::vector<int> pazymiai;
extern std::vector<studentas> s;
extern std::vector<studentas> vargsiukai;
extern std::vector<studentas> saunuoliai;
extern std::list<studentas> l;
extern std::list<studentas> vargs;
extern std::list<studentas> saun;
extern std::deque<studentas> d;
extern std::deque<studentas> vargsiuk;
extern std::deque<studentas> saunuol;

void nuskaitytiDesimt()
{
     std::cout <<"Duomenys is failo desimtukas.txt: " << std::endl;
    std::ifstream inDesimtukas ("desimtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtukas)
    {
        while(getline(inDesimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            s.push_back(*stud);

        }
    }
}

void nuskaitytiSimta()
{
    std::cout <<"Duomenys is failo simtukas.txt: " << std::endl;
    s.clear();
    std::ifstream inSimtukas ("simtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtukas)
    {
        while(getline(inSimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            s.push_back(*stud);

        }
    }
}
void nuskaitytiTukstanti()
{
    std::cout <<"Duomenys is failo tukstantukas.txt: " << std::endl;
    s.clear();
    std::ifstream inTukstantukas ("tukstantukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inTukstantukas)
    {
        while(getline(inTukstantukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            s.push_back(*stud);

        }



    }
}
void nuskaitytiDesimtTukstanciu()
{
    std::cout <<"Duomenys is failo desimtTukst.txt: " << std::endl;
    s.clear();
    std::ifstream inDesimtTukst ("desimtTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtTukst)
    {
        while(getline(inDesimtTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            s.push_back(*stud);

        }
    }
}
void nuskaitytiSimtasTukst()
{
    std::cout <<"Duomenys is failo simtasTukst.txtt: " << std::endl;
    s.clear();
    std::ifstream inSimtasTukst ("simtasTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtasTukst)
    {
        while(getline(inSimtasTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            s.push_back(*stud);

        }
    }
}


void nuskaitytiDesimtList()
{
     std::cout <<"Duomenys is failo desimtukas.txt: " << std::endl;
    std::ifstream inDesimtukas ("desimtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtukas)
    {
        while(getline(inDesimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            l.push_back(*stud);

        }
    }

}
void nuskaitytiDesimtDeque()
{
     std::cout <<"Duomenys is failo desimtukas.txt: " << std::endl;
    std::ifstream inDesimtukas ("desimtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtukas)
    {
        while(getline(inDesimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            d.push_back(*stud);

        }
    }
}
void nuskaitytiSimtaList()
{
    std::cout <<"Duomenys is failo simtukas.txt: " << std::endl;
    s.clear();
    std::ifstream inSimtukas ("simtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtukas)
    {
        while(getline(inSimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            l.push_back(*stud);
        }
    }
}
void nuskaitytiTukstantiList()
{
    std::cout <<"Duomenys is failo tukstantukas.txt: " << std::endl;
    l.clear();
    std::ifstream inTukstantukas ("tukstantukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inTukstantukas)
    {
        while(getline(inTukstantukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            studentas *stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            l.push_back(*stud);

        }
    }
}
void nuskaitytiDesimtTukstanciuList()
{
    std::cout <<"Duomenys is failo desimtTukst.txt: " << std::endl;
    s.clear();
    std::ifstream inDesimtTukst ("desimtTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtTukst)
    {
        while(getline(inDesimtTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            l.push_back(*stud);

        }
    }
}
void nuskaitytiSimtasTukstList()
{
    std::cout <<"Duomenys is failo simtasTukst.txtt: " << std::endl;
    s.clear();
    std::ifstream inSimtasTukst ("simtasTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtasTukst)
    {
        while(getline(inSimtasTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            l.push_back(*stud);

        }
    }
}
void nuskaitytiSimtaDeque()
{
    std::cout <<"Duomenys is failo simtukas.txt: " << std::endl;
    s.clear();
    std::ifstream inSimtukas ("simtukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtukas)
    {
        while(getline(inSimtukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            d.push_back(*stud);
        }
    }
}
void nuskaitytiTukstantiDeque()
{
    std::cout <<"Duomenys is failo tukstantukas.txt: " << std::endl;
    s.clear();
    std::ifstream inTukstantukas ("tukstantukas.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inTukstantukas)
    {
        while(getline(inTukstantukas,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            d.push_back(*stud);
        }
    }
}
void nuskaitytiDesimtTukstanciuDeque()
{
    std::cout <<"Duomenys is failo desimtTukst.txt: " << std::endl;
    s.clear();
    std::ifstream inDesimtTukst ("desimtTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inDesimtTukst)
    {
        while(getline(inDesimtTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            d.push_back(*stud);

        }
    }
}
void nuskaitytiSimtasTukstDeque()
{
    std::cout <<"Duomenys is failo simtasTukst.txtt: " << std::endl;
    s.clear();
    std::ifstream inSimtasTukst ("simtasTukst.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    if (inSimtasTukst)
    {
        while(getline(inSimtasTukst,line))
        {
            pazymiai.clear();
            std::istringstream ss(line);
            auto stud = new studentas;
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                if (sss.fail() || pazymys <0 || pazymys >=11 ){
                sss.clear();
                sss.ignore(10000000, '\n');
                } else {pazymiai.push_back(pazymys);}

            }
            sort(pazymiai.begin(),pazymiai.end());
            sss>>(*stud).egzoPazymys;
            (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
            (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
            d.push_back(*stud);

        }
    }
}
