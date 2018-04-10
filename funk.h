#ifndef FUNK_H_INCLUDE
#define FUNK_H_INCLUDE


struct studentas
{
    std::string vardas;
    std::string pavarde;
    float egzoPazymys;
    float galutinisVidurkis;
    float galutinisMediana;

};



float vidurkis();
float mediana();
void spausdinti();
void rikiuotiStudentus();
void nuskaityti();
void pildyti();
void menu();


#endif
