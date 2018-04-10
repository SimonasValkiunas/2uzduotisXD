#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

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


void nuskaityti()
{
    std::fstream fd ("kursiokai.txt");

    std::string line;
    std::string ivertinimai;
    int pazymys;
    getline(fd,line);
    if (fd)
    {
        while(getline(fd,line))
        {
            studentas *stud = new studentas;
            (*stud).pazymiai.clear();
            std::istringstream ss(line);
            ss>>(*stud).pavarde>>(*stud).vardas;
            getline(ss,ivertinimai);
            std::istringstream sss(ivertinimai);
            for (int i=0; i<5; i++)
            {
                sss>>pazymys;
                (*stud).pazymiai.push_back(pazymys);
            }
            sort((*stud).pazymiai.begin(),(*stud).pazymiai.end());
            sss>>(*stud).egzoPazymys;
              float ndVidurkis;
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



    }
}

void pildyti (){
    std::cout<<"Ar norite nuskaityti duomenis iš failo? (Taip/Ne)"<<std::endl;
    std::string TaipNe;
    std::cin>> TaipNe;
    if (TaipNe == "Taip")
        {
            nuskaityti();
        }else{
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






int main()
{

   pildyti();
   spausdinti();

    return 0;
}
