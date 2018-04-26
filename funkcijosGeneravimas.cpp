#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include "funkcijos.h"

std::ofstream outDesimtukas ("desimtukas.txt");
std::ofstream outSimtukas ("simtukas.txt");
std::ofstream outTukstantukas ("tukstantukas.txt");
std::ofstream outDesimtTukst ("desimtTukst.txt");
std::ofstream outSimtasTukst ("simtasTukst.txt");

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
       outDesimtTukst <<" "<<std::endl;


    }
    outDesimtukas.close();
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
     outSimtukas.close();
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
    outTukstantukas.close();
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
    outDesimtTukst.close();
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
    outSimtasTukst.close();
}
