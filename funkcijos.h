#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED




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
void generuojamDesimt();
void generuojamSimta();
void generuojamTukstanti();
void generuojamDesimtTukstanciu();
void generuojamSimtaTukstanciu();
void nuskaitytiDesimt();
void nuskaitytiSimta();
void nuskaitytiTukstanti();
void nuskaitytiDesimtTukstanciu();
void nuskaitytiSimtasTukst();
void isskirtyti();
void spausdintiVargSaun();



#endif // FUNKCIJOS_H_INCLUDED
