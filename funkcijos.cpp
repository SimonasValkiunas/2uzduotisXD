#include <iostream>
#include <string.h>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <limits>
#include <ctime>
#include "funkcijos.h"

std::ofstream outDesimtukas ("desimtukas.txt");
std::ofstream outSimtukas ("simtukas.txt");
std::ofstream outTukstantukas ("tukstantukas.txt");
std::ofstream outDesimtTukst ("desimtTukst.txt");
std::ofstream outSimtasTukst ("simtasTukst.txt");

extern std::vector<int> pazymiai;
extern std::vector<studentas> s;
extern std::vector<studentas> vargsiukai;
extern std::vector<studentas> saunuoliai;


float vidurkis()
{
    float ndVidurkis;
    ndVidurkis = (float)std::accumulate(pazymiai.begin(),pazymiai.end(),0)/(float)pazymiai.size();
    return ndVidurkis;
}


float mediana()
{
    float ndMediana;
    sort(pazymiai.begin(),pazymiai.end());
    int pozicija = pazymiai.size();
    if (pozicija%2==0)
    {
        ndMediana = (float)(pazymiai[(pozicija/2)-1]+pazymiai[pozicija/2])/2;
    }
    else ndMediana = pazymiai[pozicija/2];

    return ndMediana;
}

void pildyti()
{
    std::string vardas;
    std::string pavarde;
    studentas *stud = new studentas;
    bool retry = true;

    while (retry){
                try {
        std::cout <<"Iveskite varda" << std::endl;
        std::cin>> (*stud).vardas;
        if ((*stud).vardas < "a" || (*stud).vardas > "zzzzzzzzzzzzzzz" || !std::cin ) {throw 1;} else {retry = false;}
        }
        catch (int x){
            std::cout <<"Varde negali buti skaiciu" << std::endl;
        }
    }

    retry = true;
    while (retry){
         try {
    std::cout <<"Iveskite pavarde" << std::endl;
    std::cin>> (*stud).pavarde;
    if ((*stud).pavarde < "a" || (*stud).pavarde > "zzzzzzzzzzzzzzz") {throw 2;} else {retry = false;}
    }
           catch (int x){
            std::cout <<"Pavardeje negali buti skaiciu" << std::endl;
        }
    }


    int ndpazimys=0;
    bool tesiam = true;
    bool tempbool = false;
    std::cout <<"Iveskite pazymius. Noredami baigti iveskite skaiciu 0=>skaicius=>10"<<std::endl;



    bool tmp = true;
    while (tmp){

       std::cin >> ndpazimys;
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000000, '\n');
            std::cout << "Netinkamas simbolis" << std::endl;
            std::cin >> ndpazimys;
        }
    if ( ndpazimys >=0 && ndpazimys <=10)pazymiai.push_back(ndpazimys) ;
    else tmp = false;
    }



    std::cout <<"Iveskite egzamino pazymi (0=>egzopazymys=>10)"<< std::endl;
    std::cin >> (*stud).egzoPazymys;
            while (std::cin.fail() || (*stud).egzoPazymys < 0 || (*stud).egzoPazymys >= 11 ){
            std::cin.clear();
            std::cin.ignore(10000000, '\n');
            std::cout << "Netinkama verte" << std::endl;
            std::cin >> (*stud).egzoPazymys;
        }

    (*stud).galutinisVidurkis = (float)(vidurkis()*0.4)+(float)(*stud).egzoPazymys*0.6;
    (*stud).galutinisMediana = (float)(mediana()*0.4)+(float)(*stud).egzoPazymys*0.6;
     s.push_back(*stud);
     std::string pasirinkimas;
     std::cout <<"Ar norite toliau pildyti sarasa (taip/ne)"<< std::endl;
     std::cin>>pasirinkimas;
     if (pasirinkimas == "taip") pildyti();
}



void spausdinti()
{
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<s.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<s[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<s[i].vardas;
        std::cout<<std::left<<std::setw(20)<<std::setprecision(3)<<s[i].galutinisMediana;
        std::cout<<std::setprecision(3)<<s[i].galutinisVidurkis<<std::endl;
    }
}

void rikiuotiStudentus()
{

    int i=0;
    int n = s.size();
    for(i; i<n; i++)
    {
        int j=i+1;
        for (j; j<n; j++)
        {
            if(s[i].pavarde > s[j].pavarde)
            {
                auto temp = s[i];
                s[i]= s[j];
                s[j]= temp;
            }

        }

    }
}

void menu()
{
    std::string pasirinkimas1;
    std::cout <<"Norite pazymius ivesti ar nuskaityti iš failo? (ivesti/nuskaityti)" << std::endl;
    std::cin>>pasirinkimas1;
    if (pasirinkimas1 == "ivesti"){
        pildyti();
        spausdinti();
    }else if(pasirinkimas1 == "nuskaityti")
    {
        nuskaityti();
        rikiuotiStudentus();
        spausdinti();
    }else
    {
     std::cout<<"Negalimas pasirinkimas" << std::endl;
     menu();
    }
}




void nuskaityti()
{
    std:: fstream fd("kursiokai.txt");
    std::string line;
    std::string ivertinimai;
    int pazymys;
    getline(fd,line);
    if (fd)
    {
        while(getline(fd,line))
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

void generuojamDesimt()
{

    srand( time(NULL));
    for (int i=0; i<10; i++)
    {
        outDesimtukas<<std::left<<"Vardas"<<std::setw(5)<< i;
        outDesimtukas<<std::left<<"Pavarde"<<std::setw(5)<<i;

        for (int i=0; i<5; i++)
        {

            outDesimtukas<<std::left<<std::setw(3)<<rand() % 11-0;
        }

       outDesimtukas<<std::left<<std::setw(3)<<rand() % 11-0<< std::endl;


    }

}

void generuojamSimta()
{
 for (int i=0; i<100; i++)
    {
        outSimtukas<<std::left<<"Vardas"<<std::setw(5)<< i;
        outSimtukas<<std::left<<"Pavarde"<<std::setw(5)<<i;

        for (int i=0; i<5; i++)
        {

            outSimtukas<<std::left<<std::setw(3)<<rand() % 11-0;
        }

       outSimtukas<<std::left<<std::setw(3)<<rand() % 11-0;
       outSimtukas << " " << std::endl;

    }
}

  void generuojamTukstanti()
  {
        for (int i=0; i<1000; i++)
    {
        outTukstantukas<<std::left<<"Vardas"<<std::setw(7)<< i;
        outTukstantukas<<std::left<<"Pavarde"<<std::setw(7)<<i;

        for (int i=0; i<5; i++)
        {

            outTukstantukas<<std::left<<std::setw(3)<<rand() % 11-0;
        }

       outTukstantukas<<std::left<<std::setw(3)<<rand() % 11-0;
       outTukstantukas << " " << std::endl;

    }
  }

  void generuojamDesimtTukstanciu ()
  {
       for (int i=0; i<10000; i++)
    {
        outDesimtTukst<<std::left<<"Vardas"<<std::setw(10)<< i;
        outDesimtTukst<<std::left<<"Pavarde"<<std::setw(10)<<i;

        for (int i=0; i<5; i++)
        {

            outDesimtTukst<<std::left<<std::setw(3)<<rand() % 11-0;
        }

       outDesimtTukst<<std::left<<std::setw(3)<<rand() % 11-0;
       outDesimtTukst << " " << std::endl;

    }
  }

void generuojamSimtaTukstanciu()
{
    for (int i=0; i<100000; i++)
    {
        outSimtasTukst<<std::left<<"Vardas"<<std::setw(10)<< i;
        outSimtasTukst<<std::left<<"Pavarde"<<std::setw(10)<<i;

        for (int i=0; i<5; i++)
        {

            outSimtasTukst<<std::left<<std::setw(3)<<rand() % 11-0;
        }

       outSimtasTukst<<std::left<<std::setw(3)<<rand() % 11-0;
       outSimtasTukst << " " << std::endl;

    }
}


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
void spausdintiVargSaun()
{
    std::cout << "VARGSIUKAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<vargsiukai.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<vargsiukai[i].vardas;
        std::cout<<std::left<<std::setw(20)<<std::setprecision(3)<<vargsiukai[i].galutinisMediana;
        std::cout<<std::setprecision(3)<<vargsiukai[i].galutinisVidurkis<<std::endl;
    }
    std::cout << "SAUNUOLIAI:"<< std::endl;
    std::cout <<std::left<<std::setw(15)<< "Pavarde" <<std::setw(15)<<"Vardas"<<std::setw(20)<<"Galutinis - mediana"<<std::setw(20)<< "Galutinis - vidurkis"<<std::endl;
    for (int i=0; i<saunuoliai.size(); i++)
    {
        std::cout<<std::left<<std::setw(15)<<saunuoliai[i].pavarde;
        std::cout<<std::left<<std::setw(15)<<saunuoliai[i].vardas;
        std::cout<<std::left<<std::setw(20)<<std::setprecision(3)<<saunuoliai[i].galutinisMediana;
        std::cout<<std::setprecision(3)<<saunuoliai[i].galutinisVidurkis<<std::endl;
    }
}
