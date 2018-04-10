#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>

struct studentas{
std::string vardas;
std::string pavarde;
std::vector<int> pazymiai;
float egzoPazymys;
float galutinisMediana;
float galutinisVidurkis;
};

std::vector<studentas> s;
int ndpazymis =0;


void pildyti (){
    studentas *stud = new studentas;
    std::cout<<"Studento vardas"<<std::endl;
    std::cin>>(*stud).vardas;
    std::cout<<"Studento pavarde"<<std::endl;
    std::cin>>(*stud).pavarde;
    std::string pasirinkimas;
    std::cout<<"Norite ivesti ar generuoti namu darbu pazymius (Ivesti/Generuoti)"<<std::endl;
    std::cin>>pasirinkimas;
    if(pasirinkimas == "Ivesti"){

    std::cout<<"Iveskite pazymius. Kai noresit sustoti iveskite raide"<<std::endl;
    while(!std::cin.fail())
        {
            std::cin>>ndpazymis;
            if(ndpazymis>=0 && ndpazymis <=10){
            (*stud).pazymiai.push_back(ndpazymis);
           }
        }
    std::cout<<"Iveskite egzamino pazymi"<<std::endl;
    std::cin>> (*stud).egzoPazymys;
} else if (pasirinkimas == "Generuoti")
{
    int kiekis;
    std::cout<<"Kiek pazymiu sugeneruoti?"<<std::endl;
    std::cin>>kiekis;
    for(int i=0; i<kiekis;i++){
        ndpazymis = rand() % 11-0;
        (*stud).pazymiai.push_back(ndpazymis);

    }
    (*stud).egzoPazymys = rand() % 11-0;

}   float ndVidurkis;
    ndVidurkis = (float)std::accumulate((*stud).pazymiai.begin(),(*stud).pazymiai.end(),0)/(float)(*stud).pazymiai.size();
    float ndMediana;
    std::sort((*stud).pazymiai.begin(),(*stud).pazymiai.end());
    int pozicija = (*stud).pazymiai.size();
    if (pozicija%2==0)
    {
        ndMediana = (float)((*stud).pazymiai[(pozicija/2)-1]+(*stud).pazymiai[pozicija/2])/2;
    }
    else ndMediana = (*stud).pazymiai[pozicija/2];
    (*stud).galutinisVidurkis = (float)(ndVidurkis*0.4)+(float)(*stud).egzoPazymys*0.6;
    (*stud).galutinisMediana = (float)(ndMediana*0.4)+(float)(*stud).egzoPazymys*0.6;
    s.push_back(*stud);

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



int main()
{

   pildyti();
   spausdinti();

    return 0;
}
